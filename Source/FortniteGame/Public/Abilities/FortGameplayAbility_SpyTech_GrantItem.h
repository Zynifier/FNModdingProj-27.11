// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/FortGameplayAbility_SpyTech.h"
#include "FortGameplayAbility_SpyTech_GrantItem.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerPawnAthena;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FSpyTechLevelUpgradeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpyTechLevelUpgradeData")
	FGameplayTagContainer LevelUpgradeTags;

	UPROPERTY(EditAnywhere, Category="SpyTechLevelUpgradeData")
	FScalableFloat IsLevelUpgradeEnabled;

	UPROPERTY(EditAnywhere, Category="SpyTechLevelUpgradeData")
	FScalableFloat MaxLevelUpgrade;

};

USTRUCT(BlueprintType)
struct FSpyTechUpgradeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpyTechUpgradeData")
	FGameplayTagContainer UpgradeTags;

	UPROPERTY(EditAnywhere, Category="SpyTechUpgradeData")
	FScalableFloat IsUpgradeEnabled;

	UPROPERTY(EditAnywhere, Category="SpyTechUpgradeData")
	FPrimaryAssetId UpgradedItemAssetID;

};

USTRUCT(BlueprintType)
struct FSpyTechWeaponUpgradeRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpyTechWeaponUpgradeTable")
	TSoftObjectPtr<UFortItemDefinition> UpgradedItemToGrant;

};

UCLASS()
class UFortGameplayAbility_SpyTech_GrantItem : public UFortGameplayAbility_SpyTech
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpyTech")
	FPrimaryAssetId ItemToGrantAssetID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpyTech")
	FScalableFloat NumberOfItemToGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpyTech")
	bool bSkipUpgradeCheck;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpyTech")
	bool bRechargeStackOnGrant;

protected:
	UFUNCTION()
	void LevelUpgradeTagApplied(const FGameplayTag InTag, int32 NewCount);

	UFUNCTION()
	void UpgradeTagApplied(const FGameplayTag InTag, int32 NewCount);

	UPROPERTY()
	TObjectPtr<AFortPlayerControllerAthena> FortPlayerController;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawnAthena> FortPlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpyTech")
	TArray<FSpyTechUpgradeData> UpgradeData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpyTech")
	FSpyTechLevelUpgradeData LevelUpgradeData;

	UPROPERTY()
	FString TextItemSource;

};

