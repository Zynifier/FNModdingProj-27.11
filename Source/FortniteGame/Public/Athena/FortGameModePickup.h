// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/FortPickupAthena.h"
#include "FortGameModePickup.generated.h"

UCLASS(MinimalAPI)
class AFortGameModePickup : public AFortPickupAthena
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalBeginLongUse();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalInterrupt();

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortGameModePickup")
	FScalableFloat InteractionTime;

};

