// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortHeroClassGameplayDefinition.generated.h"

class AFortPlayerPawn;
class UFortAbilityKit;
class UFortHeroType;

UCLASS(MinimalAPI)
class UFortHeroClassGameplayDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Abilities")
	static TArray<UFortAbilityKit*> GetAbilityKitsForClassPerks(const UFortHeroType* HeroDefinition);

private:
	UPROPERTY(EditDefaultsOnly, Category="HeroClass", meta=(AssetBundles="ItemDetails"))
	TSoftClassPtr<AFortPlayerPawn> OverridePawnClass;

	UPROPERTY(EditDefaultsOnly, Category="HeroClass", meta=(AssetBundles="ItemDetails"))
	FGameplayTagContainer HeroClassTags;

	UPROPERTY(EditDefaultsOnly, Category="HeroClass")
	FDataTableRowHandle LegacyStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="HeroClass", meta=(AssetBundles="ItemDetails"))
	TArray<TSoftObjectPtr<UFortAbilityKit>> ClassAbilityKits;

};

