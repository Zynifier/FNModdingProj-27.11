// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaLivingWorldPreloader.generated.h"

class AActor;
class UFortAthenaLivingWorldManager;
class UFortAthenaSpawnerDataBase;

USTRUCT()
struct FFortAthenaLivingWorldPreloader
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLivingWorldManager> LivingWorldManager;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UFortAthenaSpawnerDataBase>> LoadedSpawnerDataClass;

	UPROPERTY(Transient)
	TArray<TSubclassOf<AActor>> LoadedActorClasses;

};

