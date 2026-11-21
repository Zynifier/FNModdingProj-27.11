// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Creative/FortCreativeTags.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortPlayerAugmentItemDefinition.generated.h"

class UFortAbilitySet;
class UFortItemDefinition;
class UGameplayEffect;
class UTexture2D;

UCLASS(Config=Game, PerObjectConfig, MinimalAPI, BlueprintType)
class UFortPlayerAugmentItemDefinition : public UFortWorldItemDefinition, public IFortCreativeTagsBearer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	TSoftObjectPtr<UTexture2D> GetHUDEffectImage() const;

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortPlayerAugmentItemDefinition")
	bool bIsDisabledViaHotfix;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition")
	FGameplayTag ItemTag;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition")
	FGameplayTag CollectionEntryTag;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload,ServerAthenaPreload"))
	TSoftObjectPtr<UFortAbilitySet> AbilitySet;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition", meta=(AssetBundles="Equipped,RemotePlayerEquipped,ItemDetails,ClientAthenaPreload,ServerAthenaPreload"))
	TSoftClassPtr<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly, DuplicateTransient, Category="FortPlayerAugmentItemDefinition")
	TArray<TObjectPtr<UFortItemDefinition>> RequiredItemsToLoad;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition")
	bool bStackGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition")
	bool bStackAbilitySets;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition")
	FGameplayTagContainer GrantedPlayerTags;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAugmentItemDefinition", meta=(AssetBundles="ClientAthenaPreload,ItemDetails"))
	TSoftObjectPtr<UTexture2D> HUDEffectTexture;

};

