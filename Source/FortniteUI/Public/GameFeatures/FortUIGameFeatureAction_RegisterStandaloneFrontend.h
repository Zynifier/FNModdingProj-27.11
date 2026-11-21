// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_RegisterStandaloneFrontend.generated.h"

class UFortStandaloneFrontend;

UCLASS(MinimalAPI, meta=(DisplayName="Register Standalone Frontend Screen"))
class UFortUIGameFeatureAction_RegisterStandaloneFrontendScreen : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_RegisterStandaloneFrontendScreen")
	TSoftClassPtr<UFortStandaloneFrontend> FrontendScreenClass;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_RegisterStandaloneFrontendScreen")
	TSoftClassPtr<UFortStandaloneFrontend> MobileFrontendScreenClass;

};

