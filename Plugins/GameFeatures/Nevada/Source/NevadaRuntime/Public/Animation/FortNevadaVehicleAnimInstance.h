// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortNevadaVehicleAnimInstance.generated.h"

class AFortNevadaVehicle;
class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortNevadaVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortNevadaVehicle> NevadaVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_IsAttached;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_IsCharging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_IsActive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_IsInactive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_IsOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_HasTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	bool bTractorBeam_ShouldApplyCustomAO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	float TractorBeam_LookAtPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Tractor Beam")
	float TractorBeam_LookAtYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float LeanLeftRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float LeanForwardBackward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float LeanValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float PreviousLeanValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float VelocityZValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float LeanDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bTurnAgain;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bHadDriver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bJustGotDriver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bJustLostDriver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bWasBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	int32 PreviousBoostCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	int32 BoostCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bIsBoostingAgain;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float WingsPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float TractorBeamAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float AimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bIsFiringCannon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float DistanceFromGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bIsLanding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bHasLanded;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	float LandingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bNotLandingMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bHadBattery;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bOutOfBattery;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bJustGotBattery;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bLaunchToDepart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nevada Vehicle")
	bool bLaunchToIdle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Nevada Vehicle")
	bool bIsPartsLanding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Tractor Beam")
	FName TractorBeamSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Tractor Beam")
	FName TractorBeamAimCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	FName NevadaVehicleInterruptName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	FName LandingTraceRightName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	FName LandingTraceLeftName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float MaxLeanDeltaInterruptMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float MinForwardSpeedToBeMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float MinForwardSpeedToPlayWings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float MinWingsPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float MaxWingsPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float WingsPlayRateInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	TSoftObjectPtr<UAnimMontage> CannonFiringMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Nevada Vehicle")
	float LandingGearTraceLength;

};

