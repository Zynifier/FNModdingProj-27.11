// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortSubGameTypes.h"
#include "FortGameFeatureAction_AddToSubGame.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Plugin To SubGame"))
class UFortGameFeatureAction_AddToSubGame : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="SubGame")
	FName PluginName;

	UPROPERTY(EditAnywhere, Category="SubGame")
	ESubGame SubGameToActivatePlugin;

};

