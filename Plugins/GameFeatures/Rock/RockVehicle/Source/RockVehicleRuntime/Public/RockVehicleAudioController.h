// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "FortVehicleAudioController.h"
#include "RockVehicleAudioController.generated.h"

class ARockVehicle;
class UAudioComponent;
class UAudioMotorModelComponent;

UCLASS()
class ARockVehicleAudioController : public AFortVehicleAudioController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UAudioMotorModelComponent* GetMotorSimComponent() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnInAirUpdated(const bool bNewInAir);

	UFUNCTION(BlueprintCallable)
	void SetBoosting(const bool bNewBoosting);

	UFUNCTION(BlueprintCallable)
	void SetSurfaceTypeParam(const float NewSurfaceParam);

	UPROPERTY(EditAnywhere, Category="RockVehicleAudioController")
	FRuntimeFloatCurve SideSpeedToSkidVolume;

	UPROPERTY(EditAnywhere, Category="RockVehicleAudioController")
	float SurfaceTypeInterpSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="RockVehicleAudioController", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> TireSurfaceComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="RockVehicleAudioController", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AirLoopComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="RockVehicleAudioController", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SuperSonicComponent;

	UPROPERTY(BlueprintReadWrite, Category="RockVehicleAudioController")
	bool bInWater;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="RockVehicleAudioController", meta=(EditInline="true"))
	TObjectPtr<UAudioMotorModelComponent> MotorModel;

	UPROPERTY(Transient)
	TObjectPtr<ARockVehicle> CachedVehicle;

};

