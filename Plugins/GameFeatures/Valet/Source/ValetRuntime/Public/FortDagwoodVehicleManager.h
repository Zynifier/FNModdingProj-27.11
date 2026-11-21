// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortDagwoodVehicleManager.generated.h"

class AActor;
class AFortAthenaVehicle;
class UFortVehicleItemDefinition;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class VALETRUNTIME_API UFortDagwoodVehicleManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortDagwoodVehicleManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void CustomHandleActorStreamedInEditor(AActor* SourceActor);

	UFUNCTION()
	void OnVehicleSpawned(AFortAthenaVehicle* Vehicle);

	UFUNCTION()
	void OnVehicleSpawnsUpdated(UFortVehicleItemDefinition* VehicleItemDef, TArray<AActor*>& SpawnedVehicles, int32 NewVehicleCount);

	UFUNCTION()
	void UpdatePropReplacement();

private:
	UPROPERTY(Transient)
	bool bHasUpdatedPropReplacement;

	UPROPERTY(Transient)
	int32 NumVehiclesSpawnedWithTireMod;

};

