// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/Biplane/FortBiplaneState.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortAthenaDoghouseVehicle.generated.h"

class UFortDoghouseVehicleConfigs;
enum class EAileronRollDirection : uint8;

UENUM()
enum class EFreelookMode : uint8
{
	None = 0,
	Mouse = 1,
	Analog = 2,
	Touch = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAileronRollEvent);

USTRUCT()
struct FBiplaneAsyncInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortDoghouseVehicleConfigs> FortAirVehicleConfigs;

};

USTRUCT()
struct FBiplaneAsyncOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIsEngineOn;

	UPROPERTY()
	bool bIsFlying;

	UPROPERTY()
	bool bAutoStartEngineInAir;

	UPROPERTY()
	bool bEngineStartIsBeingHeld;

	UPROPERTY()
	FAileronRoll AileronRoll;

	UPROPERTY()
	FFortRechargingActionTimer BoostAction;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFlightControlSurfaces
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FlightControlSurfaces")
	float RudderAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FlightControlSurfaces")
	float AileronAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FlightControlSurfaces")
	float ElevatorAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FlightControlSurfaces")
	float FlapAngle;

};

USTRUCT()
struct FReplicatedControlState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantizeNormal Up;

	UPROPERTY()
	FVector_NetQuantizeNormal Forward;

	UPROPERTY()
	uint8 bIsEngineOn : 1;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaDoghouseVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Vehicle")
	virtual bool GasPedalIsDown() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	EAileronRollDirection GetAileronRollDirection() const;

	UFUNCTION(BlueprintCallable, Category="Gun")
	FVector GetAimPoint();

	UFUNCTION(BlueprintCallable, Category="Gun")
	FVector GetAimPointLocal();

	UFUNCTION(BlueprintPure, Category="Flight")
	float GetAltitudeZ() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	FVector GetFlightControlForce() const;

	UFUNCTION()
	const FFlightControlSurfaces& GetFlightControlSurfaces() const;

	UFUNCTION()
	const FFlightControlSurfaces& GetFlightControlSurfaceTargets() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	FVector GetFlightControlTorque() const;

	UFUNCTION(BlueprintCallable, Category="Gun")
	FVector GetShootCenterPoint();

	UFUNCTION(BlueprintCallable, Category="Gun")
	FVector GetShootCenterPointLocal();

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetStandingInPlaceSteeringAngle() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	bool IsAileronRolling() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	bool IsEngineAutoStartingInAir() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	bool IsEngineOn() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsFlying() const;

	UFUNCTION(BlueprintPure)
	virtual bool IsFreelooking() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsRollingInverted() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsRollingLeft() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsRollingRight() const;

	UFUNCTION(BlueprintPure, Category="Flight")
	bool IsStallingFromAltitude() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsStandingInPlace() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Camera")
	void OnEngineStart();

	UFUNCTION(BlueprintImplementableEvent, Category="Camera")
	void OnEngineStop();

	UFUNCTION(BlueprintImplementableEvent, Category="Camera")
	void OnLanding();

	UFUNCTION(BlueprintImplementableEvent, Category="Camera")
	void OnTakeoff();

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AntiGravityScalerWhenEmpty;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraPitchInterpSpeed;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraYawInterpSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float PropSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float PropRotation;

	UPROPERTY(EditAnywhere, Config, Category="Flight")
	float AirbrakeDragCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flight")
	FFortRechargingActionTimer BoostAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flight")
	FAileronRoll AileronRoll;

	UPROPERTY(EditAnywhere, Config, Category="Flight")
	float AileronRollDoubleClickSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	bool bFreelookAutoRecenter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookPitchConstraintDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookYawConstraintDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float MouseSteerSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookInterpolation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookReturnAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float FreelookReturnDecelleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Gun")
	FName ShootCenterPointSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Gun")
	float ShootAimAheadDistance;

protected:
	UFUNCTION(NetMulticast, Unreliable)
	void MultiBeginAileronRoll(EAileronRollDirection Direction);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerBeginAileronRoll(EAileronRollDirection Direction);

	UPROPERTY(Transient)
	TObjectPtr<UFortDoghouseVehicleConfigs> FortAirVehicleConfigs;

	UPROPERTY()
	bool bIsFlying;

	UPROPERTY()
	bool bIsEngineOn;

	UPROPERTY()
	bool bAutoStartEngineInAir;

	UPROPERTY()
	bool bEngineStartIsBeingHeld;

private:
	UFUNCTION()
	void OnRep_ControlState();

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerUpdateControlState(FReplicatedControlState InControlState);

	UPROPERTY(ReplicatedUsing=OnRep_ControlState)
	FReplicatedControlState ControlState;

};

