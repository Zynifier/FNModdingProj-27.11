// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIRequestTypes.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_DisableFrontendTabs.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Disable Frontend Tabs"))
class UFortUIGameFeatureAction_DisableFrontendTabs : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_DisableFrontendTabs")
	FFrontendDisabledTabs TabOptions;

};

