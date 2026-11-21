// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FrontEnd/ItemPreview/StateTransitionController.h"
#include "FortCameraTargetPedestal.generated.h"

class AFortItemPreviewActor;
class UChildActorComponent;
class UFortAccountItemDefinition;
class UFortItem;
class UFortItemDefinition;
enum class EFortItemType : uint8;

UENUM()
enum class EItemPreviewRestrictionMode : uint8
{
	/**
	 * Replace any cosmetics that are introducing restrictions and blocking the target cosmetic. Useful in shop
	 * previews so the player always sees what they are about to purchase.
	 */
	AlwaysShowTargetCosmetic = 0,
	/**
	 * Hide the restricted cosmetic, even if it is the primary target for our preview. This is how in-game restrictions 
	 * are handled. Useful in locker previews so the player sees how their loadout will appear in-game.
	 */
	HideTargetCosmetic = 1,
};

USTRUCT()
struct FVaultVariantOverrideOption
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag VariantChannelOverride;

	UPROPERTY()
	FGameplayTag VariantTagOverride;

	UPROPERTY()
	FString CustomDataPayload;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> OptionalItemVariantIsUsedFor;

};

USTRUCT()
struct FItemPreviewSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemPreviewSettings")
	TObjectPtr<UFortAccountItemDefinition> ItemToView;

	UPROPERTY(EditAnywhere, Category="ItemPreviewSettings")
	int32 SubSlotIndex;

	UPROPERTY()
	FGameplayTagContainer PreviewExcludedTags;

	UPROPERTY()
	int32 ItemVariantPreviewIndex;

	UPROPERTY()
	bool bHasEtherealBackground;

	UPROPERTY()
	TArray<FVaultVariantOverrideOption> VariantOverrides;

	UPROPERTY()
	TObjectPtr<UFortItem> SourceItemInstance;

};

UCLASS()
class AFortCameraTargetPedestal : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemDisplayed(EFortItemType ItemType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemPreviewCleared();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsPendingTransitionOut(const FStateTransitionControllerHandle& TransitionController);

private:
	UPROPERTY(EditAnywhere, Category="FortCameraTargetPedestal", meta=(AllowPrivateAccess="TRUE", Categories="UI.Pedestal"))
	FGameplayTag CameraTargetTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortCameraTargetPedestal", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> PedestalBaseComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCameraTargetPedestal", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UFortItem> CurrentPrimaryItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCameraTargetPedestal", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<AFortItemPreviewActor> ItemPreviewActor;

};

