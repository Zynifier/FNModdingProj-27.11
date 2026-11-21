// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_ActivateStyleTheme.generated.h"

/**
 * Activates given style theme when a plugin is activated.
 */
UCLASS(MinimalAPI, meta=(DisplayName="Activate Style Theme"))
class UGameFeatureAction_ActivateStyleTheme : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Style Sheets")
	FName ThemeName;

};

