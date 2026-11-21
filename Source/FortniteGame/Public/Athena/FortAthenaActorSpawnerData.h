// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaSpawnerDataBase.h"
#include "FortAthenaActorSpawnerData.generated.h"

class AActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaActorSpawnerData : public UFortAthenaSpawnerDataBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaActorSpawnerData")
	TSubclassOf<AActor> ActorClass;

};

