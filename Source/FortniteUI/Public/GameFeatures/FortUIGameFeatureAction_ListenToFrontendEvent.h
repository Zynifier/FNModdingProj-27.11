// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortUIGameFeatureAction_ListenToFrontendEvent.generated.h"

class UCommonActivatableWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Listen To Frontend Event"))
class UFortUIGameFeatureAction_ListenToFrontendEvent : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_ListenToFrontendEvent")
	TSoftClassPtr<UCommonActivatableWidget> CustomUIScreenClass;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_ListenToFrontendEvent")
	FEventMessageTag MessageTag;

};

