// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_SafeZoneOrderOptimize.generated.h"

USTRUCT()
struct FSafeZoneOrderOptimizeMutatorRouteDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector StartLocation;

	UPROPERTY()
	FVector EndLocation;

	UPROPERTY()
	FText DebugName;

};

USTRUCT()
struct FSafeZoneOrderOptimizeMutatorRouteOrder
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<int32> RouteIDs;

	UPROPERTY()
	float TotalDistance;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SafeZoneOrderOptimize : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ChosenRouteOrder();

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SafeZoneOrderOptimize")
	FScalableFloat NumRouteOrdersToChooseFrom;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SafeZoneOrderOptimize")
	FScalableFloat NumRouteOrdersPerFrame;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SafeZoneOrderOptimize")
	FScalableFloat MaxPercentDeviationFromBestRoute;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	float MapUILineThickness;

private:
	UPROPERTY(Replicated)
	bool bInitialized;

	UPROPERTY(Replicated)
	bool bPaused;

	UPROPERTY(Replicated)
	TArray<FSafeZoneOrderOptimizeMutatorRouteDefinition> Routes;

	UPROPERTY(Replicated)
	int32 MaxRoutesPerOrder;

	UPROPERTY(Replicated)
	TArray<int32> LockedInRouteIDs;

	UPROPERTY(ReplicatedUsing=OnRep_ChosenRouteOrder)
	FSafeZoneOrderOptimizeMutatorRouteOrder ChosenRouteOrder;

	UPROPERTY(Replicated)
	FSafeZoneOrderOptimizeMutatorRouteOrder DebugShortestRouteOrder;

};

UCLASS()
class UFortCheatManager_SafeZoneOrderOptimize : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void SafeZoneOrderOptimizeDebug(float TextScale = 1.000000f);

};

