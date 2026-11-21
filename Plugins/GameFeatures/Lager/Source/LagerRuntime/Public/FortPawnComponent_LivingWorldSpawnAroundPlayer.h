// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_LivingWorldSpawnAroundPlayer.generated.h"

class AFortAthenaPointAroundPlayerProvider;
class IFortAthenaLivingWorldPointProviderInterface;
class UFortAthenaLivingWorldEncounter;
class UFortAthenaLivingWorldEncounterInstance;

USTRUCT()
struct FLivingWorldSpawnAroundPlayerConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LivingWorldSpawnAroundPlayerConfiguration")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> Encounter;

	UPROPERTY(EditAnywhere, Category="LivingWorldSpawnAroundPlayerConfiguration")
	TArray<TSubclassOf<AFortAthenaPointAroundPlayerProvider>> PointProviderClasses;

	UPROPERTY(EditAnywhere, Category="LivingWorldSpawnAroundPlayerConfiguration")
	bool bRegisterReservoir;

};

USTRUCT()
struct FLivingWorldSpawnAroundPlayerRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> PointAroundPlayerProviders;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaLivingWorldEncounterInstance> Encounter;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPawnComponent_LivingWorldSpawnAroundPlayer : public UFortPawnComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FLivingWorldSpawnAroundPlayerRuntimeData> RuntimeData;

	UPROPERTY(EditAnywhere, Category="FortPawnComponent_LivingWorldSpawnAroundPlayer")
	TArray<FLivingWorldSpawnAroundPlayerConfiguration> PerPlayerConfigurations;

};

