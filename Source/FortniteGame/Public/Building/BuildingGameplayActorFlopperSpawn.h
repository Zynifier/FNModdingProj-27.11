// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorFlopperSpawn.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorFlopperSpawn : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void GetFlopperSpawnPositionAndRotation(float FXDistanceOffset, FVector& OutSpawnLocation, FRotator& OutSpawnRotation) const;

};

