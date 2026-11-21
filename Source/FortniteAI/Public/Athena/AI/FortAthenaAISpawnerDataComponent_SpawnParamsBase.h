// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_SpawnParamsBase.generated.h"

class AAIController;
class APawn;
class UFortAthenaAISpawnerData;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_SpawnParamsBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	TSubclassOf<AAIController> GetAIControllerClass() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetInAirSpawnTraceEndHeight() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetInAirSpawnTraceSphereRadius() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetInAirSpawnTraceStartHeight() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	TSubclassOf<APawn> GetPawnClass() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	FDataTableRowHandle GetPawnStatHandle() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	TArray<TSubclassOf<UFortAthenaAISpawnerData>> GetSpawnerDataSpawnedAsChildren() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	float GetSpawnTracePadding() const;

	UFUNCTION(BlueprintCallable)
	void SetSpawnTransform(const FTransform& InSpawnTransform);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool ShouldCheckForOverlaps() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool ShouldSpawnInAir() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Spawn", meta=(AllowPrivateAccess="true"))
	FTransform SpawnTransform;

};

