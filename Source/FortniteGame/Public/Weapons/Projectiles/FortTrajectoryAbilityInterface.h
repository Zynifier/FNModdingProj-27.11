// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "FortTrajectoryAbilityInterface.generated.h"

class AFortProjectileTrajectory;

UINTERFACE(BlueprintType, Blueprintable)
class UFortTrajectoryAbilityInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortTrajectoryAbilityInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	void CleanupTrajectoryIndicatorOnUnequip();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	TSubclassOf<AFortProjectileTrajectory> GetProjectileTrajectoryActor() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	void GetProjectileTrajectoryPoints(TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, FHitResult& OutHitResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	void InitTrajectoryVariables();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="TrajectoryInterface")
	bool ShouldOnlyShowTrajectoryOnUse() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	AFortProjectileTrajectory* SpawnTrajectoryIndicator(bool bSpawnOnEquip);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="TrajectoryInterface")
	void UpdateTrajectory();

};

