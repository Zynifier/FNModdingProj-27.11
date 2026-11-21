// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_TimeDilation.generated.h"

class UCurveFloat;
class UFortAthenaCustomTimeDilationManager;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_TimeDilation : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="End Game Time Dilation")
	TObjectPtr<UCurveFloat> EndGameTimeDilationCurve;

	UPROPERTY(EditDefaultsOnly, Category="End Game Time Dilation")
	FScalableFloat EndGameTimeDilationDuration;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaCustomTimeDilationManager> TimeDilationManager;

};

