// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_AirControl.generated.h"

class URockVehicleAbility_AutoUpright;
class URockVehicleAbility_Dodge;

USTRUCT()
struct FRockVehicleAbilityInContinuous_AirControl : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bAnyWheelsOnGround;

	UPROPERTY()
	bool bDodgeActive;

	UPROPERTY()
	bool bAutoUprightActive;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent_AirControl : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector TorqueAccel;

	UPROPERTY()
	FVector TorqueDamping;

	UPROPERTY()
	float DisableForDodgeTime;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class URockVehicleAbility_AirControl : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AirControl")
	FVector TorqueAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AirControl")
	FVector TorqueDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AirControl")
	float DisableForDodgeTime;

protected:
	UPROPERTY(Transient)
	bool bAnyWheelsOnGround;

	UPROPERTY(Transient)
	bool bDodgeActive;

	UPROPERTY(Transient)
	bool bAutoUprightActive;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_Dodge> DodgeAbility;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_AutoUpright> AutoUprightAbility;

};

