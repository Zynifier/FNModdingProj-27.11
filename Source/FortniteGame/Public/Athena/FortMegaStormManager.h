// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Building/StructuralSupport/BuildingStructuralSupportSystem.h"
#include "FortMegaStormManager.generated.h"

class ABuildingSMActor;

UENUM(BlueprintType)
enum class EMegaStormState : uint8
{
	//Gathering a list of building actors the storm will damage.

	GatheringActorList = 0,
	//Iterating our list of actor and Damaging/Destroying them.

	DamagingActors = 1,
};

USTRUCT()
struct FMegaStormCircle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FBuildingSupportCellIndex GridCenter;

	UPROPERTY()
	int32 NumCellsFromCenter;

	UPROPERTY()
	int32 CurrentQuadrant;

	UPROPERTY()
	FBuildingSupportCellIndex GridAt;

	UPROPERTY()
	int32 RadiusInGridCells;

	UPROPERTY()
	int32 XAdvanceAccumulation;

	UPROPERTY()
	int32 YAdvanceAccumulation;

	UPROPERTY()
	int32 GridRadiusSquaredX4;

	UPROPERTY()
	int32 NumPlots;

	UPROPERTY()
	FVector WorldCenter;

	UPROPERTY()
	float WorldRadius;

	UPROPERTY()
	TArray<TWeakObjectPtr<ABuildingSMActor>> ActorsInMegaStorm;

	UPROPERTY()
	EMegaStormState MegaStormState;

};

UCLASS(Config=Game)
class AMegaStormManager : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	float MaxSecondsInMegaStormUpdate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	int32 NumBuildingActorMegaStormShouldDamagePerFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	float SleepTimeAfterDamagingBuildingActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	float MinDelayTimeBeforeDestruction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	bool bFloorRadiusToGridConversion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="MegaStorm")
	int32 GridRadiusCellOffset;

private:
	UPROPERTY(Transient)
	float MegaStormStartTime;

	UPROPERTY(Transient)
	float SleepTimeRemaining;

	UPROPERTY(Transient)
	TArray<FMegaStormCircle> MegaStormCircles;

};

