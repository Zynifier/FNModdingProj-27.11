// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Input/FortMappingContextOverlapFilter.h"
#include "FortEnhancedInputUserSettingsConfiguration.generated.h"

UCLASS(Config=Input, MinimalAPI)
class UFortEnhancedInputUserSettingsConfiguration : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="Overlaps")
	TArray<FFortMappingContextOverlapFilter> LegacyActionGroupOverlapFilters;

};

