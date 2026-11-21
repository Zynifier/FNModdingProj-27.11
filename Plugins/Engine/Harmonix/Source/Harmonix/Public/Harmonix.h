// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Harmonix.generated.h"

UCLASS()
class HARMONIX_API UHarmonixBlueprintUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Harmonix|Calibration")
	static float GetMeasuredUserExperienceAndReactionToAudioRenderOffsetMs();

	UFUNCTION(BlueprintCallable, Category="Harmonix|Calibration")
	static float GetMeasuredVideoToAudioRenderOffsetMs();

	UFUNCTION(BlueprintCallable, Category="Harmonix|Calibration")
	static void SetMeasuredUserExperienceAndReactionToAudioRenderOffsetMs(float Milliseconds);

	UFUNCTION(BlueprintCallable, Category="Harmonix|Calibration")
	static void SetMeasuredVideoToAudioRenderOffsetMs(float Milliseconds);

};

