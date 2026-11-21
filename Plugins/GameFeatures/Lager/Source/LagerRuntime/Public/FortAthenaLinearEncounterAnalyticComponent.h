// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortAthenaLinearEncounterAnalyticComponent.generated.h"

class AActor;
class AController;
class AFortPickup;
class UFortAthenaLivingWorldEncounterInstance;
class UPrimitiveComponent;

USTRUCT()
struct FFortAthenaLinearEncounterPlayerParticipationData
{
	GENERATED_BODY()

};

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortAthenaLinearEncounterAnalyticComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnEncounterEnd();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnEncounterStart(UFortAthenaLivingWorldEncounterInstance* InAttackerEncounter, UFortAthenaLivingWorldEncounterInstance* InDefenderEncounter);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnStageCompleted(const TArray<AFortPickup*>& SpawnedRewards);

private:
	UFUNCTION()
	void OnAttackerSpawned(AActor* SpawnedAttacker);

	UFUNCTION()
	void OnDefenderDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnDefenderDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnDefenderDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnDefenderSpawned(AActor* SpawnedDefender);

};

