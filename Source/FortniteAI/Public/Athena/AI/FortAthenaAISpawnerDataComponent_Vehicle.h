// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_VehicleBase.h"
#include "FortAthenaAISpawnerDataComponent_Vehicle.generated.h"

class AFortAthenaVehicle;
class UFortAthenaAIBotSkillSet;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAI_API UFortAthenaAISpawnerDataComponent_Vehicle : public UFortAthenaAISpawnerDataComponent_VehicleBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AFortAthenaVehicle> VehicleToSpawnAndEnter;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	uint8 bSetInfiniteFuel : 1;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> VehicleSkillSets;

};

