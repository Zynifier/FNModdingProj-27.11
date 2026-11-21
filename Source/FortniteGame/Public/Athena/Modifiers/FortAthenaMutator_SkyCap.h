// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SkyCap.generated.h"

class AAthenaSkyCap;

UENUM(BlueprintType)
enum class ESkyCapState : uint8
{
	Hidden = 0,
	StormStarting = 1,
};

USTRUCT()
struct FSkyCapPositionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SkyCapPositionData")
	FScalableFloat MoveTime;

	UPROPERTY(EditAnywhere, Category="SkyCapPositionData")
	FScalableFloat Height;

	UPROPERTY(EditAnywhere, Category="SkyCapPositionData")
	FScalableFloat WaitTime;

};

USTRUCT()
struct FSkyCapTargetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float TargetHeight;

	UPROPERTY()
	float MoveTime;

};

UCLASS()
class AAthenaSkyCap : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_SkyCapState();

	UFUNCTION()
	void OnStopMovement(const FHitResult& ImpactResult, float Time);

	UFUNCTION(BlueprintImplementableEvent)
	void StormStarting_Client();

	UPROPERTY()
	FSkyCapTargetData TargetData;

	UPROPERTY(ReplicatedUsing=OnRep_SkyCapState)
	ESkyCapState SkyCapState;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SkyCap : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Sky Cap Class")
	TSubclassOf<AAthenaSkyCap> SkyCapClass;

	UPROPERTY()
	TObjectPtr<AAthenaSkyCap> SkyCap;

	UPROPERTY(EditAnywhere, Category="Position Data")
	FScalableFloat SpawnHeight;

	UPROPERTY(EditAnywhere, Category="Position Data")
	FScalableFloat InitialDelay;

	UPROPERTY(EditAnywhere, Category="Position Data")
	TArray<FSkyCapPositionData> PositionData;

};

