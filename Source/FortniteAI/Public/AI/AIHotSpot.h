// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTaskOwnerInterface.h"
#include "Math/MathFwd.h"
#include "AIHotSpot.generated.h"

class AAIController;
class AActor;
class UAIHotSpotSlot;
class UAIHotSpotSlotGenerator;
class UBillboardComponent;
class UNavigationQueryFilter;
class UPrimitiveComponent;
enum class EAIHotSpotAssignmentFilter : uint8;
enum class EAIHotSpotSlot : uint8;
enum class EAIHotSpotSlotFilter : uint8;

UENUM()
enum class EAIHotSpotAssignmentFilter : uint8
{
	All = 0,
	WithSlots = 1,
	WaitingList = 2,
};

UENUM()
enum class EAIHotSpotSlotFilter : uint8
{
	All = 0,
	AvailableOnly = 1,
	UnavailableOnly = 2,
};

UCLASS(MinimalAPI, HideCategories=("Object", "Actor", "Input", "Rendering"))
class AAIHotSpot : public AActor, public IGameplayTaskOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	void AssignFromWaitingList();

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual int32 AssignGroupToHotspot(TArray<AAIController*> GroupOfAI);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual bool AssignToHotspot(AAIController* AI);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual bool AssignToSlotByIndex(AAIController* AI, int32 Index);

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	bool CanUseSlotByIndex(const AAIController* AI, int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	virtual int32 FindBestSlotIndex(AAIController* AI) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	virtual TArray<int32> FindBestSlotIndices(TArray<AAIController*> AI) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	TArray<AAIController*> GetAssignedAI(EAIHotSpotAssignmentFilter Filter = EAIHotSpotAssignmentFilter::All) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	int32 GetAssignedAICount(EAIHotSpotAssignmentFilter Filter = EAIHotSpotAssignmentFilter::All) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	UAIHotSpotSlot* GetSlotByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	UAIHotSpotSlot* GetSlotByOwner(const AAIController* AIOwner) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	int32 GetSlotCount(EAIHotSpotSlotFilter Filter = EAIHotSpotSlotFilter::All) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	int32 GetSlotIndexByOwner(const AAIController* AIOwner) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	FVector GetSlotLocationByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	AAIController* GetSlotOwnerByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	FRotator GetSlotRotationByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	EAIHotSpotSlot GetSlotStateByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	EAIHotSpotSlot GetSlotStateByOwner(const AAIController* AIOwner) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	int32 GetSlotUserIdByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	bool HasAssignedAI(const AAIController* AI, EAIHotSpotAssignmentFilter Filter = EAIHotSpotAssignmentFilter::All) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	bool HasEnabledSlots() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	bool IsAIAllowed(const AAIController* AI) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	bool IsEnabled() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot|Info")
	bool IsSlotlessAssignmentAllowed() const;

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual bool OccupySlotByIndex(int32 Index);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	bool OnAssignedClaimedBehavior(AAIController* AI, int32 Index, int32 UserId, bool bWasOnWaitingList);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	bool OnAssignedOccupiedBehavior(AAIController* AI, int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	bool OnAssignedSlotlessBehavior(AAIController* AI);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnHotSpotDisabled();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnHotSpotEnabled();

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnRemovedBehavior(AAIController* AI, int32 Index, int32 UserId, EAIHotSpotSlot PrevState, bool bWasOnWaitingList);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnRemovedSlotlessBehavior(AAIController* AI, bool bIsClamingSlot);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotBlocked(AAIController* AI, int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotClaimed(AAIController* AI, int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotDisabled(int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotEnabled(int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotFreed(AAIController* AI, int32 Index, int32 UserId);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnSlotOccupied(AAIController* AI, int32 Index, int32 UserId);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot", meta=(AdvancedDisplay="1"))
	virtual bool RemoveFromHotspot(AAIController* AI, bool bAssignFromWaitingList = true);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual int32 RemoveGroupFromHotspot(TArray<AAIController*> GroupOfAI);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual void SetEnabled(bool bEnabled);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnMoveToSlotFinished(AAIController* AI, int32 Index, int32 UserId, bool bResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slots")
	TArray<TObjectPtr<UAIHotSpotSlot>> UserSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slots")
	TObjectPtr<UAIHotSpotSlotGenerator> SlotGenerator;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="Slots")
	TArray<TObjectPtr<UAIHotSpotSlot>> Slots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HotSpot")
	TObjectPtr<AActor> FocusActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Navigation")
	TSubclassOf<UNavigationQueryFilter> FilterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Navigation", meta=(EditCondition="bCustomNavmeshSearchExtent"))
	FVector CustomNavmeshSearchExtent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HotSpot")
	uint8 bStartEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="HotSpot")
	uint8 bAllowSlotlessAssignment : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="HotSpot")
	uint8 bAllowClaimingMultipleSlots : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="HotSpot")
	uint8 bTrackOverlappingSlots : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Navigation")
	uint8 bProjectSlotsOnNavmesh : 1;

	UPROPERTY()
	uint8 bCustomNavmeshSearchExtent : 1;

	UPROPERTY(Transient)
	uint8 bIsEnabled : 1;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AAIController>> NoSlotAssignees;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> RenderingComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;

};

