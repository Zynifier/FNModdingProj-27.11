// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_Jump.generated.h"

USTRUCT()
struct FRockVehicleAbilityInPersistent_Jump : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class URockVehicleAbility_Jump : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump")
	FRockScalableFloat JumpVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump")
	FRockScalableFloat JumpAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump")
	FRockScalableFloat MinJumpSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jump")
	FRockScalableFloat MaxJumpSeconds;

};

