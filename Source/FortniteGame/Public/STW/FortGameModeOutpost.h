// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemEntry.h"
#include "STW/FortGameModePvE.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "FortGameModeOutpost.generated.h"

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeOutpost : public AFortGameModePvE
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="GameMode")
	const bool DoesOutpostStatusAllowMissionStart() const;

	UPROPERTY()
	TArray<FFortItemEntry> OwnerItemRefundCache;

	UPROPERTY()
	FFortOutpostCoreInfo CurrentCoreInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	bool bSavePlayerBuiltStructuresAtAllTimes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	int32 MinTotalContinuousOneHitResourcesDistributedForForcedSave;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	int32 MaxContinuousOneHitResourcesDistributedBeforeForcedSave;

	UPROPERTY(Config)
	bool bEnableLargeScaleDisassemblyForcedSaves;

	UPROPERTY(Config)
	bool bEnableUnsupportedStructureDisassembly;

	UPROPERTY(Config)
	bool bCheckNavMeshAvailability;

};

