// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortVehicleAudioController.h"
#include "Sound/FortAudioTypes.h"
#include "FortTankVehicleAudioController.generated.h"

class AFortTankVehicle;
class UAudioComponent;
class UFortLayeredAudioComponent;

USTRUCT(BlueprintType)
struct FTankAudioUpdateContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	bool bIsAwake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float SpeedParamValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float LeftTrackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float RightTrackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float TurningParamValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	int32 CurrentGear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float AccelSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float LastGearChangeTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float AccelWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	bool bTurningRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	bool bTurningLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	bool bPreviousTryMotion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float LastForwardSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float TimeUntilAccelOneShotFade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float DecelSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	float EngineIdleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	FVector2D WeaponsMovementThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	FName CannonSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	FName TurretSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TankAudioUpdateContext")
	int32 SurfaceID;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="TankAudioUpdateContext", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> DecelOneShot;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="TankAudioUpdateContext", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AccelOneShot;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="TankAudioUpdateContext", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> TurningOneShot;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="TankAudioUpdateContext", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> TracksLeftAudio;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="TankAudioUpdateContext", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> TracksRightAudio;

};

UCLASS(BlueprintType, Blueprintable)
class AFortTankVehicleAudioController : public AFortVehicleAudioController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AudioController")
	AFortTankVehicle* GetTankVehicleActor() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayAccelOneShot();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDecelOneShot();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayTurningOneShot();

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter SpeedParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter TurnPowerParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter OutOfFuelParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter IdleParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter TurningParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter ForwardParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter ReverseParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter SurfaceParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter IsInWaterParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter IsInAirParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter BoostParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter CannonHorizontalMovementParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter CannonVerticalMovementParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter TurretHorizontalMovementParam;

	UPROPERTY(EditDefaultsOnly, Category="FortTankVehicleAudioController")
	FFortAudioFloatParameter TurretVerticalMovementParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTankVehicleAudioController")
	FTankAudioUpdateContext Context;

};

