// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortGameplayTagData.generated.h"

USTRUCT()
struct FTierTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TierTags", meta=(ArraySizeEnum="/Script/FortniteGame.EFortItemTier"))
	FGameplayTag TagForTier[6];

};

UCLASS(MinimalAPI)
class UFortGameplayTagData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag EnergyDamageTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag AllowHarvestingTools;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag EditingBuildingPermissionForcedTrue;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag DamageDoesNotInterruptInteractionTag;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	FGameplayTagQuery PreventDamageFromInterruptingInteractionsTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTagQuery ShouldCopyHarvestToolSecondaryAbilityTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag MainStWCampaignTheaterTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag AIRangeToAutomaticallyAddEnemyPawnGoalsTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTagContainer QuickbarUnslottableItemTags;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTagContainer IgnoreMovementCancellableActionTags;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag FakePawnTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag StarlightTheaterTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag NativeActionEmote;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag PawnHideTagCategory;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag ForceAutoRunOnTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagData")
	FGameplayTag AbilityFailureNoMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="HeldObject")
	FGameplayTag DropHeldObjectOnPlacementInputTag;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics|Save the World", meta=(ArraySizeEnum="/Script/FortniteGame.EFortRarity"))
	FTierTags CosmeticUnlockRequirementTagsForRarityAndTier[6];

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics|Save the World")
	FGameplayTagQuery AllowShadowStanceMaterialsTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics")
	FGameplayTag CosmeticSubGameExclusionTags[2];

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics")
	FGameplayTagQuery TransformationEmoteQuery;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics|MetaTags")
	FGameplayTagQuery CosmeticMetaTagFemaleCondition;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics|MetaTags")
	FGameplayTagQuery CosmeticMetaTagMaleCondition;

};

