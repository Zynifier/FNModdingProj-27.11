// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_RegisterStandaloneLocker.generated.h"

class UFortStandaloneFrontend;

UCLASS(MinimalAPI, meta=(DisplayName="Register Standalone Locker Screen"))
class UFortUIGameFeatureAction_RegisterStandaloneLockerScreen : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_RegisterStandaloneLockerScreen")
	TSoftClassPtr<UFortStandaloneFrontend> LockerScreenClass;

};

