// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortAthenaJackalVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaJackalVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostMinPushForce;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostSteeringMultiplierRampTime;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float BoostCameraAdditionalOffset;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float SprintTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float SprintTopSpeedForceMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float SprintMinPushForce;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float AutoSprintDelay;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float MaxCombatSpeed;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float CombatTransitionDragCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="VehicleSprint")
	float CombatTransitionDragCoefficient2;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float SprintCameraAdditionalOffset;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TurnInPlaceSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AsyncTurnInPlaceSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxSpeedForTurnInPlaceKmH;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BlendOutExtraSpeedTurnInPlaceKmH;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float LandTopSpeedMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinJumpForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxJumpForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpChargeRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpChargeLossRate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinJumpChargeToActivate;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpRequiredVerticalAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float EmptyDragCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float EmptyDragCoefficient2;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxEmptyDragSpeed;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ForwardAlphaDeadZone;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ForwardInputCutoffForSharpTurn;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinRightInputForSharpTurn;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float SharpTurnLateralFrictionRuntimeMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinForwardAlphaForLeftAnalogTurn;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float EmptyLateralFrictionRuntimeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Vehicle")
	float BumpForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float InPlaceForwardPushForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxSpeedForInPlaceForwardPush;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float TorsionRollStiff;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float TorsionRollDamp;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float TorsionRollAirStiff;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float TorsionRollAirDamp;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float TorsionRollStrength;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float SteerRollFactor;

	UPROPERTY(EditAnywhere, Config, Category="TorsionSpring")
	float VehicleMaxRollAccel;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawMinVelocitySq;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawDotToleranceStart;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawDotToleranceEnd;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawStiff;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawDamp;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float CorrectionalYawMaxAccel;

	UPROPERTY(EditAnywhere, Config, Category="CorrectionalYaw")
	float MaxYawCorrectionIncline;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float AimSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float AimSteeringTurnMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="VehicleBoost")
	float AimSteeringStrafeMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bUseCameraAssistWhenADS;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bJumpForceWorldVertical;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bAutoSprintGamepadToggle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpPercentWorldUpForPureVertical;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpPercentSurfaceNormal;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bJumpInstantlyFullCharge;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bHolsterWeaponDuringBoostOnServer;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bHolsterWeaponDuringBoostOnClient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bPlayHolsterAnimsOnClient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bSwapDriveTagsDuringBoost;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bDisableReticleDuringBoost;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bUseViewRotationDuringSprint;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bAlwaysConstrainViewDuringCombat;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bAlwaysConstrainViewDuringCombatADS;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float GroundForwardToUpTolerance;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float GroundRightToUpTolerance;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TurnRateExponent;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinSpeedMaxSteeringAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxSpeedMaxSteeringAngle;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AllowSharpTurnForwardAlpha;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float SharpTurnSwitchOffAlpha;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	bool bUseLookAheadTraceInAir;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleCameraLeftAnalogMultiplierInAir;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxAutoFlipVelocitySquared;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float AutoFlipCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BalloonPitchStrengthModifier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinSpeedSquaredForCameraFollowInAir;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float JumpChargeSteeringMultiplier;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VerticalOnGroundEjectCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float OnSideOnGroundEjectCooldown;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxForwardSpeedForTurnInPlaceDrag;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TurnInPlaceDragCoefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TurnInPlaceDrag2Coefficient;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float VehicleAirCameraYawStrength;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxPitchForCameraSteer;

	UPROPERTY(EditAnywhere, Config, Category="WaterSpringParams")
	bool bOverrideWaterSpringParams;

	UPROPERTY(EditAnywhere, Config, Category="WaterSpringParams")
	float InWaterSpringLength;

	UPROPERTY(EditAnywhere, Config, Category="WaterSpringParams")
	float OutWaterSpringLength;

	UPROPERTY(EditAnywhere, Config, Category="WaterSpringParams")
	float InWaterSpringStiff;

	UPROPERTY(EditAnywhere, Config, Category="WaterSpringParams")
	float OutWaterSpringStiff;

};

