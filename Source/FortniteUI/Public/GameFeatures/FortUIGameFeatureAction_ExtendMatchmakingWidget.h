// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_ExtendMatchmakingWidget.generated.h"

class UObject;

UCLASS(MinimalAPI, meta=(DisplayName="Extend Matchmaking Widget"))
class UFortUIGameFeatureAction_ExtendMatchmakingWidget : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Extend Matchmaking Widget Action", meta=(MustImplement="/Script/FortniteUI.FortMatchmakingWidgetExtensionInterface"))
	TSubclassOf<UObject> ExtensionClass;

	UPROPERTY()
	TObjectPtr<UObject> ExtensionObject;

};

