// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIRequestTypes.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddFrontendTab.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Frontend Tab"))
class UFortUIGameFeatureAction_AddFrontendTab : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AddFrontendTab")
	FExternalDynamicTabParams TabParameters;

};

