// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Weapons/FortWeapon.h"
#include "FortScoutDroneGlove.generated.h"

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortScoutDroneGlove : public AFortWeapon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Hold to Deploy")
	FScalableFloat HoldToDeployTime;

};

