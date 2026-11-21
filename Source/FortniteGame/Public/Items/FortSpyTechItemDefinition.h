// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortSpyTechItemDefinition.generated.h"

class UFortAbilitySet;
class UGameplayEffect;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Frontend", "Tooltips", "Functionality", "OwnedTags", "FrontendPreview", "Series"))
class UFortSpyTechItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Spy Tech")
	TSoftObjectPtr<UFortAbilitySet> AbilitySetSoftRef;

	UPROPERTY(EditAnywhere, Category="Spy Tech")
	TSoftClassPtr<UGameplayEffect> PerkGameplayEffectSoftRef;

	UPROPERTY(meta=(DeprecatedProperty))
	FGameplayTagContainer ItemTags;

	UPROPERTY(EditAnywhere, Category="Spy Tech")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, Category="Spy Tech")
	FGameplayTagContainer ExclusionTags;

	UPROPERTY(EditAnywhere, Category="Spy Tech")
	FGameplayTagContainer FilterTags;

	UPROPERTY(EditAnywhere, Category="Spy Tech")
	FScalableFloat IsEnabledAsFloat;

};

