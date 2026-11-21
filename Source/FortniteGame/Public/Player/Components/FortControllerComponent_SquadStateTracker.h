// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SquadStateTracker.generated.h"

class AFortPawn;
class APawn;
enum class EUnconvertReason : uint8;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SquadStateTracker : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnAIPawnConverted(AFortPawn* Converted);

	UFUNCTION()
	void OnAIPawnUnconverted(AFortPawn* Unconverted, EUnconvertReason UnconvertedReason);

	UFUNCTION()
	void OnPawnChanged(APawn* MyOldPawn, APawn* MyNewPawn);

};

