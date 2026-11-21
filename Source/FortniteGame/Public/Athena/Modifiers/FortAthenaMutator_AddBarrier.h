// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_AddBarrier.generated.h"

class AAthenaBigBaseWall;

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AddBarrier : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AAthenaBigBaseWall* GetBigBaseWall() const;

	UFUNCTION(BlueprintPure)
	bool IsBarrierUp() const;

protected:
	UPROPERTY(EditAnywhere, Category="Wall")
	TSubclassOf<AAthenaBigBaseWall> BigBaseWallClass;

	UPROPERTY(EditDefaultsOnly, Category="Wall")
	bool bStartTimerAtSafeZone;

	UPROPERTY(EditDefaultsOnly, Category="Wall")
	bool bSpawnAtMidFlightPathDuringBusLockedPhase;

	UPROPERTY(EditDefaultsOnly, Category="Wall")
	FScalableFloat TimeToBringDownWall;

	UPROPERTY(EditDefaultsOnly, Category="Wall")
	FScalableFloat WallGravity;

	UPROPERTY(EditDefaultsOnly, Category="Wall")
	FScalableFloat WallZLevel;

private:
	UPROPERTY(Replicated)
	TObjectPtr<AAthenaBigBaseWall> BigBaseWall;

};

