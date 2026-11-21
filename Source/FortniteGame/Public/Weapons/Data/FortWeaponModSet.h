// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Items/FortItemEntryNameModifierInterface.h"
#include "FortWeaponModSet.generated.h"

class UFortWeaponModItemDefinition;
class UFortWeaponModSetData;

USTRUCT()
struct FFortModSetModEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortModSetModEntry", meta=(TitleProperty="DisplayName"))
	TObjectPtr<UFortWeaponModItemDefinition> ModDefinition;

};

USTRUCT()
struct FFortWeaponModSetRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetRow")
	FGameplayTag BucketTag;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetRow")
	TObjectPtr<UFortWeaponModSetData> Set;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetRow")
	float RandomWeight;

};

UCLASS(BlueprintType, Blueprintable)
class UFortWeaponModSetData : public UDataAsset, public IFortItemEntryNameModifierInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="FortWeaponModSetData")
	FText ModSetName;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetData", meta=(DisplayName="Common / Gray Mods", TitleProperty="ModDefinition"))
	TArray<FFortModSetModEntry> CommonRarityMods;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetData", meta=(DisplayName="Uncommon / Green Mods", TitleProperty="ModDefinition"))
	TArray<FFortModSetModEntry> UncommonRarityMods;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetData", meta=(DisplayName="Rare / Blue Mods", TitleProperty="ModDefinition"))
	TArray<FFortModSetModEntry> RareRarityMods;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetData", meta=(DisplayName="Epic / Purple Mods", TitleProperty="ModDefinition"))
	TArray<FFortModSetModEntry> EpicRarityMods;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModSetData", meta=(DisplayName="Legendary / Orange Mods", TitleProperty="ModDefinition"))
	TArray<FFortModSetModEntry> LengdaryRarityMods;

};

