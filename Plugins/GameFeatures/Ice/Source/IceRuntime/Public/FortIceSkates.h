// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Movement/FortMovementComp_CharacterSubsystem.h"
#include "FortIceSkates.generated.h"

UCLASS(meta=(DisplayName="Ice Skates Movement Controls"))
class UFortIceSkatesMovementControls : public UFortMovementControls
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat TurnSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat Acceleration;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat UphillSlopeAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat DownhillSlopeAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat MaxSlopeAngle;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat MinSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat TargetSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat MaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Movement Controls|Ice Skates")
	FScalableFloat AirDrag;

};

