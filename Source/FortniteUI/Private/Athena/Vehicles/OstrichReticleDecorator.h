// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "OstrichReticleDecorator.generated.h"

class AFortCharacterVehicle_Ostrich;

UCLASS()
class UOstrichReticleDecorator : public UFortHUDElementWidget, public IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Setup MID"))
	void OnSetupComplete();

	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Rocket Cooldown"))
	void RocketCooldown(float Percent);

	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Rocket Loaded"))
	void RocketLoaded(float Percent, int32 Total);

	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Rockets Fired"))
	void RocketsFired();

	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Shotgun Reload Start"))
	void ShotgunReload(float Duration);

	UPROPERTY(EditAnywhere, Category="Visuals")
	float RocketCooldownUpdateFrequency;

	UPROPERTY(BlueprintReadOnly, Category="Ostrich")
	TObjectPtr<AFortCharacterVehicle_Ostrich> OwningOstrichVehicle;

};

