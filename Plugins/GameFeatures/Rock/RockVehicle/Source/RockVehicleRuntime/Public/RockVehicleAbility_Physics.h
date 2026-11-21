// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "RockVehicleAbility.h"
#include "RockVehicleAbility_Physics.generated.h"

USTRUCT()
struct FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortAthenaVehicleInputState InputState;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FRockVehicleAbilityOutContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bShouldStayActive;

};

USTRUCT()
struct FRockVehicleAbilityOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ActiveSeconds;

};

UCLASS(Abstract)
class URockVehicleAbility_Physics : public URockVehicleAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bShouldStayActive;

	UPROPERTY(Transient)
	FFortAthenaVehicleInputState InputState;

};

