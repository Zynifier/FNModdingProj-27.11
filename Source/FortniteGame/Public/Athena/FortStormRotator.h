// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortStormRotator.generated.h"

UCLASS(MinimalAPI)
class AFortStormRotator : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Postgame UI")
	void OnStormEffectsEnabled(bool bEnabled);

};

