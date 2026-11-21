// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Player/FortCheatManager.h"
#include "MidmatchRiftPoiCheatManager.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UMidmatchRiftPoiCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly, Category="Rift Poi")
	void MidmatchRiftPoiSpawnFurthestFromPawnLocation();

	UFUNCTION(Exec, BlueprintAuthorityOnly, Category="Rift Poi")
	void MidmatchRiftPoiSpawnNearestToPawnLocation();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Rift Poi")
	void SpawnMidmatchPoiFurthestLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent, Category="Rift Poi")
	void SpawnMidmatchPoiNearestLocation(const FVector& Location);

};

