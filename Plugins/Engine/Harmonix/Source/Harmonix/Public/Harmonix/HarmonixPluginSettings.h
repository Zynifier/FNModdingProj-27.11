// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HarmonixPluginSettings.generated.h"

UCLASS(Config=Engine, DefaultConfig, meta=(DisplayName="Harmonix"))
class HARMONIX_API UHarmonixPluginSettings : public UDeveloperSettings
{
	GENERATED_BODY()

};

