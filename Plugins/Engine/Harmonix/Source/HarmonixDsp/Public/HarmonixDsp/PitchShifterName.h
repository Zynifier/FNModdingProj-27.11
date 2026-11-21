// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PitchShifterName.generated.h"

// struct with detail customization for drop down selection of registered factories

USTRUCT()
struct HARMONIXDSP_API FPitchShifterName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Pitch Shifter")
	FName Name;

};

