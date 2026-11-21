// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/FortGameModePickup.h"
#include "FortGameModePickup_Wax.generated.h"

UCLASS(MinimalAPI)
class AFortGameModePickup_Wax : public AFortGameModePickup
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPickedUp();

	UPROPERTY(Replicated)
	bool bIsFirstGeneration;

	UPROPERTY(Replicated)
	int32 AmountOfTokens;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	FScalableFloat HeightAboveTerrianDropPickupAt;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	FScalableFloat HeightAboveTerrainPickupLandAt;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	FScalableFloat RandomTossAngleTowardsCenter;

	UPROPERTY(EditDefaultsOnly, Category="Despawning")
	FScalableFloat TimeUntilDespawn_OutsideStorm;

	UPROPERTY(EditDefaultsOnly, Category="Despawning")
	FScalableFloat TimeUntilDespawn_InsideStorm;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FScalableFloat DrawOnCompassDistance;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FSlateBrush DrawOnCompassBrush;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FSlateBrush DrawOnMapBrush;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FText UseInteractText_SingleCoin;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	FText UseInteractText_MultipleCoins;

};

