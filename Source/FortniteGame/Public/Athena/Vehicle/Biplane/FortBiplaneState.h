// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortVehicleState.h"
#include "FortBiplaneState.generated.h"

UENUM()
enum class EAileronRollDirection : uint8
{
	None = 0,
	Right = 1,
	Left = 2,
};

UENUM()
enum class EBiplaneSimEvent : uint8
{
	EngineStart = 0,
	EngineStop = 1,
	Takeoff = 2,
	Landing = 3,
	BoostBegin = 4,
	BoostEnd = 5,
	BoostChargeAboveThreshold = 6,
	AileronRoll = 7,
	ControlContextChange = 8,
};

UENUM()
enum class EDoghouseControlMode : uint8
{
	GroundControls = 0,
	AirControls = 1,
	MaxCount = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FAileronRoll
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flight")
	FFortRechargingActionTimer Action;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Flight")
	EAileronRollDirection Direction;

};

USTRUCT()
struct FBiplaneDerived : public FFortVehicleDerived
{
	GENERATED_BODY()

};

USTRUCT()
struct FBiplaneSimAux : public FVehicleSimAux
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
	float PitchAlphaNoPilot;

	UPROPERTY()
	float TurnAlphaNoPilot;

	UPROPERTY()
	float RollAlphaNoPilot;

	UPROPERTY()
	float AileronRollAlphaStart;

	UPROPERTY()
	bool bHadPassengers;

	UPROPERTY()
	float NoPassengerStallTimerStart;

	UPROPERTY()
	float StuckTimerStart;

	UPROPERTY()
	bool bRollRight;

	UPROPERTY()
	bool bRollLeft;

	UPROPERTY()
	float AileronRollDoubleClickTimerStart;

	UPROPERTY()
	FAileronRoll AileronRoll;

	UPROPERTY()
	FFortRechargingActionTimer BoostAction;

	UPROPERTY()
	float VehicleFuelPercent;

	UPROPERTY()
	bool bIsStallingFromAltitude;

};

