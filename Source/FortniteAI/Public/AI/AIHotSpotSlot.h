// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AIHotSpotSlot.generated.h"

class AAIController;
class AAIHotSpot;
enum class EAIHotSpotSlot : uint8;

UENUM(meta=(ScriptName="AIHotSpotSlotType"))
enum class EAIHotSpotSlot : uint8
{
	Free = 0,
	Claimed = 1,
	Occupied = 2,
	Blocked = 3,
	Disabled = 4,
};

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UAIHotSpotSlot : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual void ClearSlot();

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	AAIHotSpot* GetHotSpot() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	FBox GetSlotBounds() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	float GetSlotHeight() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	int32 GetSlotIndex() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	FVector GetSlotLocation() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	AAIController* GetSlotOwner() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	float GetSlotRadius() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	FRotator GetSlotRotation() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	EAIHotSpotSlot GetSlotState() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	int32 GetSlotUserId() const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	bool HasUserId() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	bool IsAIAllowed(const AAIController* AI) const;

	UFUNCTION(BlueprintPure, Category="AI|Hotspot")
	bool IsEnabled() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="AI|Hotspot")
	void OnStateChanged(AAIController* SlotOwner, EAIHotSpotSlot NewState);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual void SetSlotEnabled(bool bNewEnabled);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual void SetSlotOwnerAndState(AAIController* NewOwner, EAIHotSpotSlot NewState);

	UFUNCTION(BlueprintCallable, Category="AI|Hotspot")
	virtual void SetSlotState(EAIHotSpotSlot NewState);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slot", meta=(MakeEditWidget))
	FTransform LocalTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slot")
	float Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slot")
	float Radius;

	UPROPERTY(Transient)
	float DistanceToFocusActor;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Slot")
	int32 UserId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Slot")
	uint8 bStartEnabled : 1;

	UPROPERTY()
	uint8 bHasCachedAgentData : 1;

	UPROPERTY(Transient)
	uint8 bHasOverlappingSlots : 1;

	UPROPERTY(Transient)
	uint8 bHasDistanceToFocusActor : 1;

	UPROPERTY(Transient)
	uint8 bIsBlockingOthers : 1;

	UPROPERTY(Transient)
	uint8 bIsEnabled : 1;

	UPROPERTY(Transient)
	TObjectPtr<AAIController> Owner;

	UPROPERTY(Transient)
	int32 SlotIndex;

	UPROPERTY(Transient)
	EAIHotSpotSlot SlotState;

};

