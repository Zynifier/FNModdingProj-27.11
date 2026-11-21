// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilityTypes.h"
#include "Building/BuildingSMActor.h"
#include "BuildingPoolHarvestResourceSpawnsComponent.generated.h"

class AActor;
class AController;
class AFortPlayerPawn;
class UBuildingPoolHarvestResourceSpawnsComponent;
class UPrimitiveComponent;

USTRUCT()
struct FBuildingPoolHarvestResourceSpawnsData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBuildingPoolHarvestResourceSpawnsComponent> OwningComponent;

	UPROPERTY(Transient)
	FBuildingSMActorAttemptSpawnResourcesParams AttemptSpawnResourcesParams;

	UPROPERTY(Transient)
	FFortGameplayEffectContext FortEffectContextCopy;

};

UCLASS()
class UBuildingPoolHarvestResourceSpawnsComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void DestroyUnusedComponentTimerExpired();

	UFUNCTION()
	void HandleInstigatorPawnDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnOwnerBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void SpawnResourcesTimerExpired(AFortPlayerPawn* InstigatorPawn);

	UPROPERTY(Transient)
	TMap<TObjectPtr<AFortPlayerPawn>, FBuildingPoolHarvestResourceSpawnsData> PoolHarvestResourceSpawnsByInstigatorPawnMap;

};

