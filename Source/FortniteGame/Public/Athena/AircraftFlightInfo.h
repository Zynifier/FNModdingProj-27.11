// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "AircraftFlightInfo.generated.h"

USTRUCT(BlueprintType)
struct FAircraftFlightInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	FVector_NetQuantize100 FlightStartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	FRotator FlightStartRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	float FlightSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	float TimeTillFlightEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	float TimeTillDropStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	float TimeTillDropEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	bool bEjectPlayersAtDropZoneExit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AircraftFlightInfo")
	bool bVisiblePostAthenaAircraftPhase;

};

