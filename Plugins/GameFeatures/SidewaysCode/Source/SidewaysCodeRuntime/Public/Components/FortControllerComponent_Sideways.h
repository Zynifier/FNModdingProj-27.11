// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Sideways.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortControllerComponent_Sideways : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FTimerHandle UpdateClosestSidewaysHandle;

};

