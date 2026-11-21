// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaJackalVehicle.h"
#include "FortCampaignJackalVehicle.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortCampaignJackalVehicle : public AFortAthenaJackalVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleOnPlayerDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	bool bVehicleLeftAnalogStrafing;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float VehicleLeftAnalogStrafingMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float MinSpeedToWallRun;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	float AggroRangeOverride;

};

