// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "AudioWorldizationSettings.h"
#include "GameFeatureAction_SetAudioWorldizationSettings.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Set Audio Worldization Settings"))
class UGameFeatureAction_SetAudioWorldizationSettings : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameFeatureAction_SetAudioWorldizationSettings")
	FAudioWorldizationSettings Settings;

};

