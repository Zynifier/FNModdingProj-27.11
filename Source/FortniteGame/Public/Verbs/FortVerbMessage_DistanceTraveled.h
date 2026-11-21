// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_DistanceTraveled.generated.h"

USTRUCT(meta=(DisplayName="Distance Traveled"))
struct FFortVerbMessage_DistanceTraveled : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	float TotalDistance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	float VerticalDistance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	float HorizontalDistance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled", meta=(DisplayName="Travel Mode"))
	EDistanceTravelMode AllowedTravelModes;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	bool bIsInVehicle;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	bool bIsVehicleInAir;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	FSubjectTagsPair Vehicle;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled")
	FVector LastLocationTracked;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_DistanceTraveled", meta=(DisplayName="Vehicle Surface"))
	EVehicleSurfaceType AllowedVehicleSurfaces;

};

