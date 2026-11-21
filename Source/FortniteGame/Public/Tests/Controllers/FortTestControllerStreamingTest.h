// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Tests/Controllers/FortTestControllerBase.h"
#include "FortTestControllerStreamingTest.generated.h"

USTRUCT()
struct FStreamingTestPOIVector
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString POI;

	UPROPERTY()
	FVector Location;

};

USTRUCT()
struct FStreamingTestSkydivePath
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FStreamingTestPOIVector DropLocation;

	UPROPERTY()
	FStreamingTestPOIVector GlideLocation;

	UPROPERTY()
	FStreamingTestPOIVector LandingLocation;

	UPROPERTY()
	FString TargetPOI;

	UPROPERTY()
	FString CalendarEvent;

};

UCLASS(Config=AutomationConfig)
class UFortTestControllerStreamingTest : public UFortTestControllerBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FStreamingTestSkydivePath> SkydivePathArray;

	UPROPERTY(Config)
	float PostSkydiveMinWait;

};

