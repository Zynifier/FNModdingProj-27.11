// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortAISpawnerUtilityComponent.generated.h"

class AActor;
class AController;
class AFortMinigame;
class AFortPawn;
class IFortSpatialGameplayInterface;
class UEnvQuery;
class UFortAthenaAISpawnerDataComponentList;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnvironmentQueryFinished, const TArray<FVector>&, QueryResultLocations);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnownedPawnDied, AFortPawn*, FortPawn);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAISpawnerUtilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Spawning")
	void HandleUnownedPawnSpawned(AFortPawn* FortPawn);

	UFUNCTION(BlueprintPure, Category="Spawning")
	bool IsSpawnCountCapped() const;

	UFUNCTION(BlueprintCallable, Category="Spawning")
	int32 RequestSpawn(UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList, const FTransform& SpawnTransform);

	UFUNCTION(BlueprintCallable, Category="EQS")
	void SetEQSQuery(TSoftObjectPtr<UEnvQuery> SelectedEQSQuery);

	UFUNCTION(BlueprintCallable)
	void SetMinigame(const AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable, Category="EQS")
	void SetQueryRadius(float Radius);

	UFUNCTION(BlueprintCallable, Category="EQS")
	void StartEnvironmentQuery();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	FGameplayTag AIPawnSpawnTypeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EQS")
	TObjectPtr<UEnvQuery> EnvironmentQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	TArray<FEnvNamedValue> QueryParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float QueryRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float QueryMinDistance;

	UPROPERTY(BlueprintAssignable, Category="EQS")
	FOnEnvironmentQueryFinished OnEnvironmentQueryFinishedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnUnownedPawnDied OnUnownedPawnDiedDelegate;

	UPROPERTY()
	TArray<FVector> FreeSpawnSlots;

private:
	UFUNCTION()
	void OnUnownedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Transient)
	TScriptInterface<IFortSpatialGameplayInterface> CachedFortSpatialGameplay;

};

