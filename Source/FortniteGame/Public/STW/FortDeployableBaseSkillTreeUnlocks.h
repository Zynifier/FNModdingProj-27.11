// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortDeployableBaseSkillTreeUnlocks.generated.h"

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FFortTaggedUnlockBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tag")
	FGameplayTag RequiredTag;

};

USTRUCT(BlueprintType)
struct FFortTaggedDeployableBaseLootUnlock : public FFortTaggedUnlockBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LootGrants")
	FName LootTierGroup;

};

USTRUCT(BlueprintType)
struct FFortTaggedDeployableBasePlotExpansionUnlock : public FFortTaggedUnlockBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlotSize")
	FIntVector CellExpansionVector;

};

UCLASS()
class UFortDeployableBaseSkillTreeUnlocks : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PlotSize")
	TArray<FFortTaggedDeployableBasePlotExpansionUnlock> PlotSizeUnlocks;

	UPROPERTY(EditDefaultsOnly, Category="LootGrants")
	TArray<FFortTaggedDeployableBaseLootUnlock> NeighborhoodLootGrantUnlocks;

	UPROPERTY(EditDefaultsOnly, Category="LootGrants")
	TArray<FFortTaggedDeployableBaseLootUnlock> CombatZoneStartLootGrantUnlocks;

	UPROPERTY(EditDefaultsOnly, Category="LootGrants")
	TArray<FFortTaggedDeployableBaseLootUnlock> CombatZoneWaveCompleteLootGrantUnlocks;

};

