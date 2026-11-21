// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "GameFeatures/FortGameFeatureData.h"
#include "FortValetGameFeatureData.generated.h"

class ABuildingProp;
class AFortAthenaVehicleSpawner;
class UFortVehicleItemDefinition;

USTRUCT(BlueprintType)
struct FVehiclePropReplacementData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropReplacement", meta=(AssetBundles="ServerAthena"))
	TSoftObjectPtr<UFortVehicleItemDefinition> FortVehicleItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PropReplacement")
	FVector TransOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PropReplacement")
	FRotator RotOffset;

};

UCLASS()
class UFortValetGameFeatureData : public UFortGameFeatureData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PropReplacement", meta=(AssetBundles="ServerAthena"))
	TMap<TSoftClassPtr<ABuildingProp>, FVehiclePropReplacementData> PropReplacements;

	UPROPERTY(EditAnywhere, Category="PropReplacement", meta=(AssetBundles="ServerAthena"))
	TSoftClassPtr<AFortAthenaVehicleSpawner> VehicleSpawnerClass;

	UPROPERTY(EditAnywhere, Category="PropReplacement")
	ESpawnActorCollisionHandlingMethod SpawnActorCollisionHandlingMethod;

};

