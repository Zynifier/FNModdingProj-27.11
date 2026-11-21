// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_OverrideMotdWidgets.generated.h"

class UUserWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Override Motd Widgets"))
class UFortUIGameFeatureAction_OverrideMotdWidgets : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_OverrideMotdWidgets")
	TSoftClassPtr<UUserWidget> MotdTeaserWidget;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_OverrideMotdWidgets")
	TSoftClassPtr<UUserWidget> MotdFullScreenWidgetClass;

};

