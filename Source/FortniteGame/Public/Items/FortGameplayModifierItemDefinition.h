// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortAbilityTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortGameplayModifierItemDefinition.generated.h"

class AFortGameplayMutator;

UCLASS(MinimalAPI, BlueprintType)
class UFortGameplayModifierItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modifiers")
	bool IsHiddenInUI() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Modifiers")
	TArray<FFortGameplayEffectDeliveryInfo> PersistentGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category="Modifiers")
	TArray<FFortAbilitySetDeliveryInfo> PersistentAbilitySets;

	UPROPERTY(EditDefaultsOnly, Category="Modifiers", meta=(AssetBundles="Equipped"))
	TArray<TSoftClassPtr<AFortGameplayMutator>> Mutators;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Modifiers")
	bool bHiddenInUI;

	UPROPERTY(EditDefaultsOnly, Category="Playlist")
	FGameplayTagContainer DisallowedPlaylistNameTags;

	UPROPERTY(EditDefaultsOnly, Category="Playlist")
	FGameplayTagContainer DynamicPlaylistNameTags;

};

