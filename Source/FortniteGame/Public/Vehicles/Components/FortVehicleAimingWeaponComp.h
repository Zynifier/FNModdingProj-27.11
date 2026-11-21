// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilityTargetingSourceEnum.h"
#include "Vehicles/Components/FortVehicleSeatWeaponComponent.h"
#include "FortVehicleAimingWeaponComp.generated.h"

UCLASS(BlueprintType, HideCategories=("Trigger", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortVehicleAimingWeaponComp : public UFortVehicleSeatWeaponComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_TargetLocalAimOrientationCorrectedRepped();

	UFUNCTION()
	void OnRep_TargetLocalAimOrientationRepped();

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bShouldResetCameraHorizontallyToBarrelWhenEntered;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bShouldResetCameraVerticallyToBarrelWhenEntered;

	UPROPERTY(Transient)
	float StartCameraResetToBarrelTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AimingAndCamera")
	bool bAllowCameraLocalVerticalRotationOnly;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	float AimBlendInSpeed;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	float AimBlendOutSpeed;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bSetDesiredPitchWhenUnmanned;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bSetDesiredYawWhenUnmanned;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bUseGlobalOnlyAiming;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	FVector LocalAimOffsetWhenPitchedUp;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	FVector LocalAimOffsetWhenPitchedFlat;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	FVector LocalAimOffsetWhenPitchedDown;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	float RotCyclesPerFullTurnHoriz;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	float RotCyclesPerFullTurnVert;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MountedWeapon")
	bool bCorrectAimFromCameraToMuzzle;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	bool bUseClientMuzzleLocationAuthority;

	UPROPERTY(Transient)
	float YawDiffRemaining;

	UPROPERTY(Transient)
	float PitchDiffRemaining;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	bool bInterpolateAimToDesired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAimingWeaponComp")
	float LastTickTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAimingWeaponComp")
	int32 TickCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAimingWeaponComp")
	float CameraAimBlendFactor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	FRotator TargetLocalAimOrientation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	FRotator TargetLocalAimOrientationCorrected;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	FRotator CurrentLocalAimOrientation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	FRotator CurrentLocalAimOrientationCorrected;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TargetLocalAimOrientationRepped, Category="AimingAndCamera")
	FRotator TargetLocalAimOrientationRepped;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TargetLocalAimOrientationCorrectedRepped, Category="AimingAndCamera")
	FRotator TargetLocalAimOrientationCorrectedRepped;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	float UnmannedDesiredPitch;

	UPROPERTY(EditDefaultsOnly, Category="AimingAndCamera")
	float UnmannedDesiredYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	float HorizAimRotDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AimingAndCamera")
	float VertAimRotDelta;

	UPROPERTY(BlueprintReadWrite, Category="AimingAndCamera")
	EFortAbilityTargetingSource AimSourceType;

	UPROPERTY(Transient)
	bool bPlayerEnteredThisFrame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MountedWeapon")
	bool bApplyOwnerRotationToAimWhenUnmanned;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	float MaxYawPerSecondThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	float MaxPitchPerSecondThreshold;

	UPROPERTY(EditDefaultsOnly, Config, Category="AimingAndCamera")
	float PitchConstraintAngleOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="AimingAndCamera")
	float AimInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="AimingAndCamera")
	float InitialCameraInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="AimingAndCamera")
	float InitialCameraLerpTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="AimingAndCamera")
	float MinDistanceForCorrection;

private:
	UFUNCTION(Server, Reliable)
	void ServerSetAnimatedMuzzleLocation(const FVector& NewValue);

	UPROPERTY(Transient)
	FVector AnimatedMuzzleLocation;

};

