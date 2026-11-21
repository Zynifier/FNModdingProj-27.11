// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortMovementComp_CharacterAthena.h"
#include "PlateHawkMovementComponent.generated.h"

UCLASS()
class UPlateHawkMovementComponent : public UFortMovementComp_CharacterAthena
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PlateHawkMovementComponent")
	float WalkingBackwardsMaxSpeed;

};

