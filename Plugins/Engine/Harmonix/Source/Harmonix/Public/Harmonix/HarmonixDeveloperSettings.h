// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HarmonixDeveloperSettings.generated.h"

// base class for all settings you want to group with this plugin
// allows configuration to appear in the "Harmonix"

UCLASS(Abstract, EditInlineNew)
class HARMONIX_API UHarmonixDeveloperSettings : public UObject
{
	GENERATED_BODY()

};

