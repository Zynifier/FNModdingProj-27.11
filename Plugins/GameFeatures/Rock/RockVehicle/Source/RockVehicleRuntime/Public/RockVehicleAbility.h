// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockVehicleAbility.generated.h"

class ARockVehicle;

UCLASS(Abstract)
class URockVehicleAbility : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetActiveSeconds() const;

	UFUNCTION(BlueprintPure)
	float GetInactiveSeconds() const;

	UFUNCTION(BlueprintPure)
	ARockVehicle* GetVehicle() const;

protected:
	UPROPERTY()
	TObjectPtr<ARockVehicle> Vehicle;

private:
	UPROPERTY()
	float ActiveSeconds;

	UPROPERTY()
	float LastDeactivationTimeSeconds;

};

