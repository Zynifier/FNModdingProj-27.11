// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_DefaultBRMapOverride.generated.h"

class UWorld;

UCLASS(MinimalAPI, meta=(DisplayName="Default BR Map Override"))
class UFortGameFeatureAction_DefaultBRMapOverride : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Map")
	TSoftObjectPtr<UWorld> OverrideMap;

};

