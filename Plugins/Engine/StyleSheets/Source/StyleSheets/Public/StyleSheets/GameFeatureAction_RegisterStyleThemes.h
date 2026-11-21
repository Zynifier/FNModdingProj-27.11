// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_RegisterStyleThemes.generated.h"

class UStyleThemeConfig;

/**
 * Registers style themes when plugin is activated.
 */
UCLASS(MinimalAPI, meta=(DisplayName="Register Style Themes"))
class UGameFeatureAction_RegisterStyleThemes : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Style Sheets")
	TSoftObjectPtr<UStyleThemeConfig> StyleThemeConfig;

};

