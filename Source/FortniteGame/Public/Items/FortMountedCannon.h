// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortMountedTurret.h"
#include "FortMountedCannon.generated.h"

class AFortPawn;
class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortMountedCannon : public AFortMountedTurret
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnLaunchPawn(AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnPostExitVehicle(AFortPawn* ExitingPawn, const int32 SeatIndex);

};

