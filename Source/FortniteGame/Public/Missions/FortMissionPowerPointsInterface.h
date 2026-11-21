// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMissionPowerPointsInterface.generated.h"

UINTERFACE()
class UFortMissionPowerPointsInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMissionPowerPointsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual float GetAvailabilityWeight(float DifficultyLevel) const;

	UFUNCTION()
	virtual float GetInitialRangeLerpValue(float PointsAvailable) const;

	UFUNCTION()
	virtual float GetMaxRangeLerpValue(float PointsAvailable, float PreviousLerpValue) const;

	UFUNCTION()
	virtual float GetPowerPointsCost(float LerpValue) const;

};

