// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_AutoUpright.generated.h"

class URockVehicleAbility_Dodge;

USTRUCT()
struct FRockVehicleAbilityInContinuous_AutoUpright : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 LastWorldContactFrame;

	UPROPERTY(Transient)
	bool bWheelsOnGround;

	UPROPERTY(Transient)
	bool bAnyWheelsOnGround;

	UPROPERTY(Transient)
	bool bDodgeActive;

	UPROPERTY(Transient)
	bool bBodyContact;

	UPROPERTY(Transient)
	float TimeSinceLastBodyContact;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent_AutoUpright : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_AutoUpright : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoUpright")
	FRockScalableFloat RollTorque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoUpright")
	FRockScalableFloat PitchTorque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoUpright")
	FRockScalableFloat PushForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoUpright")
	FRockScalableFloat MinActiveSeconds;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_Dodge> DodgeAbility;

	UPROPERTY(Transient)
	int32 LastWorldContactFrame;

	UPROPERTY(Transient)
	FVector LastContactNormal;

	UPROPERTY(Transient)
	bool bWheelsOnGround;

	UPROPERTY(Transient)
	bool bAnyWheelsOnGround;

	UPROPERTY(Transient)
	bool bDodgeActive;

	UPROPERTY(Transient)
	bool bBodyContact;

	UPROPERTY(Transient)
	float TimeSinceLastBodyContact;

};

