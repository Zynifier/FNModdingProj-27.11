// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_VehicleBase.h"
#include "FortObjectiveProcessor_LandVehicleTrick.generated.h"

UENUM(BlueprintType)
enum class EFortTrickIncrementType : uint8
{
	// Increment the objective by 1 when the filter passes

	Single = 0,
	// The distance traveled in the air, from when the trick started to when it was successfully landed

	AirDistance = 1,
	// The highest height reached in the trick

	AirHeight = 2,
	// The amount of time the vehicle was in the air during the trick

	AirTime = 3,
	// The number of unique stunts performed in this trick

	TrickCount = 4,
	// The total number of points earned in this trick

	TrickPoints = 5,
};

USTRUCT(meta=(DisplayName="Land Vehicle Trick"))
struct FFortObjectiveFilter_LandVehicleTrick : public FFortObjectiveFilter_VehicleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(DisplayPriority="-1"))
	EFortTrickIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(InlineEditConditionToggle))
	uint8 bUseTrickPoints : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(InlineEditConditionToggle))
	uint8 bUseTrickCount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(InlineEditConditionToggle))
	uint8 bUseAirDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(InlineEditConditionToggle))
	uint8 bUseAirHeight : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(InlineEditConditionToggle))
	uint8 bUseAirTime : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(EditCondition="bUseTrickPoints", UIMin="0"))
	FInt32Range TrickPoints;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(EditCondition="bUseTrickCount", UIMin="0"))
	FInt32Range TrickCount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(EditCondition="bUseAirDistance", ForceUnits="Meters", UIMin="0"))
	FFloatRange AirDistance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(EditCondition="bUseAirHeight", ForceUnits="Meters", UIMin="0"))
	FFloatRange AirHeight;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_LandVehicleTrick", meta=(EditCondition="bUseAirTime", UIMin="0"))
	FFloatRange AirTime;

};

UCLASS()
class UFortObjectiveProcessor_LandVehicleTrick : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

