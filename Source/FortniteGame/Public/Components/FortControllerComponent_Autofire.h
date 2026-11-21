// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Autofire.generated.h"

class AActor;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Autofire : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> AutoFireReticleTarget;

	UPROPERTY(Transient)
	FTimerHandle AutofireTimerHandle;

	UPROPERTY(Transient)
	FTimerHandle DelayedStopAutofireTimerHandle;

};

