// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Math/Color.h"
#include "Athena/Squads/AthenaSquadDisplayData.h"
#include "Frontend/FortItemPlacementActor.h"
#include "FortTeamMemberPedestal.generated.h"

class AAthenaSquadPedestalGroup;
class UFortAnimInputEvent;
class UFortHero;
class UFortTeamMemberEntryBase;
class UMaterialInterface;
class UPrimitiveComponent;
class UStaticMeshComponent;
class UTexture2D;
class UWidgetComponent;
enum class EGameReadiness : uint8;

USTRUCT()
struct FCachedComponentMaterials
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UMaterialInterface>> OriginalMaterials;

};

UCLASS(Abstract)
class AFortTeamMemberPedestal : public AFortItemPlacementActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyUniformOverrideMaterial(UMaterialInterface* OverrideMaterial);

	UFUNCTION(BlueprintCallable)
	void ClearOverrideMaterial();

	UFUNCTION(BlueprintPure)
	int32 GetCurrentTeamSize() const;

	UFUNCTION(BlueprintPure)
	FString GetTeamMemberDisplayName() const;

	UFUNCTION(BlueprintCallable)
	void HandleOnAnimInstanceEventReceived(const UFortAnimInputEvent* AnimInputEvent);

	UFUNCTION(BlueprintCallable)
	virtual void InitializePlaceholderMesh(UStaticMeshComponent* PlaceholderMesh);

	UFUNCTION(BlueprintPure)
	bool IsCurrentMemberLocal() const;

	UFUNCTION(BlueprintPure)
	bool IsInFrontend() const;

	UFUNCTION(BlueprintPure)
	bool IsInLocalSquadGroup() const;

	UFUNCTION(BlueprintPure)
	bool IsValidTeamMember() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAvatarChanged(UTexture2D* AvatarImage, FColor AvatarBackground, FColor HighlightColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnConnectedToCampaignLobby();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisconnectedToCampaignLobby();

	UFUNCTION(BlueprintImplementableEvent)
	void OnGameReadinessChanged(EGameReadiness GameReadiness);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCurrentlyInMatchChanged(bool bIsInMatch);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewSquadEstablished(bool bMultipleSquadsPopulated, bool bOwningSquadContainsLocalPlayer, const FAthenaTeamDisplayInfo& OwningSquadStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwningPedestalGroupEstablished(int32 SquadIdx, bool bSquadHasLocalPlayer, bool bIsPopulated);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPedestalIsPopulatedChanged(bool bIsPopulated, bool bOwningSquadContainsLocalPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamMemberSet(bool bHasValidTeamMember);

private:
	UFUNCTION()
	void HandlePlaceholderMeshBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void HandlePlaceholderMeshClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void HandlePlaceholderMeshEndCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void HandlePlaceholderMeshInputTouchEnd(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	UPROPERTY(Transient)
	TArray<FCachedComponentMaterials> CachedComponentMaterials;

	UPROPERTY(Transient)
	TObjectPtr<AAthenaSquadPedestalGroup> OwningPedestalGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTeamMemberPedestal", meta=(AllowPrivateAccess="TRUE"))
	int32 AssignedMemberIndex;

	UPROPERTY(EditAnywhere, Category="FortTeamMemberPedestal")
	int32 VisualOrderIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortTeamMemberPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_MemberInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortTeamMemberPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_FillOpenSlot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortTeamMemberPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_BattlePassInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortTeamMemberPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_CompletedFeatInfo;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PlaceholderMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortTeamMemberEntryBase>> MemberWidgetEntries;

	UPROPERTY(Transient)
	TObjectPtr<UFortHero> MemberHeroItem;

	UPROPERTY()
	float LocalLoadoutFailureTimeout;

	UPROPERTY()
	bool bTimeToPawnLoadedEnabled;

};

