// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/GameFeatureActions/CreativeContentBrowserTabInitializer.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddCreativeContentBrowserTab.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Creative Content Browser Tab"))
class UFortUIGameFeatureAction_AddCreativeContentBrowserTab : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_AddCreativeContentBrowserTab")
	TArray<FCreativeContentBrowserTabInitializer> CreativeContentBrowserTabInitializersToAdd;

};

