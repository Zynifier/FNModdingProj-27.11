// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Math/MathFwd.h"
#include "FortBuildingWallDoorComponent.generated.h"

class APlayerState;

UCLASS(MinimalAPI, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UFortBuildingWallDoorComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Replicated)
	TWeakObjectPtr<APlayerState> LastDoorOpenerState;

private:
	UPROPERTY(Transient, Replicated)
	FRotator3f DoorDesiredRotation;

	UPROPERTY(Transient, Replicated)
	FVector3f DoorDesiredLocation;

	UPROPERTY(Transient, Replicated)
	FRotator3f DoorDesiredRotOffset;

};

