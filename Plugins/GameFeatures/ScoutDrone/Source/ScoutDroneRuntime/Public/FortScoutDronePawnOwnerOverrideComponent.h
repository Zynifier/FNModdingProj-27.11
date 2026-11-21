// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnOverrideComponent.h"
#include "FortScoutDronePawnOwnerOverrideComponent.generated.h"

class AFortScoutDrone;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortScoutDronePawnOwnerOverrideComponent : public UFortPawnOverrideComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortScoutDrone> ControlledDrone;

};

