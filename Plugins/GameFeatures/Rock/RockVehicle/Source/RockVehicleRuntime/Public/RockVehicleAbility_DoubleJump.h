// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_DoubleJump.generated.h"

class URockVehicleAbility_Jump;

USTRUCT()
struct FRockVehicleAbilityInPersistent_DoubleJump : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_DoubleJump : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DoubleJump")
	FRockScalableFloat JumpVelocity;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_Jump> JumpAbility;

};

