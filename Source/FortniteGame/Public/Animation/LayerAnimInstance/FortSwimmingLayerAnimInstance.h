// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortGender.h"
#include "FortSwimmingLayerAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortSwimmingLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintThreadSafe))
	void SetDiveGroundLandingRemainingTime(float RemainingAnimTime);

	UPROPERTY(EditDefaultsOnly, Category="SwimmingSettings")
	FCachedAnimRelevancyData SwimStartRelevancyData;

	UPROPERTY(EditDefaultsOnly, Category="SwimmingSettings")
	FCachedAnimRelevancyData SwimStartAdditiveRelevancyData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAim;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FVector SwimmingWaterSurfaceNormal;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FRotator SwimmingWaterSurfaceWorldRotation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FRotator SwimmingMeleeTwistRotator;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FRotator SwimmingYawDeltaRotator;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	FVector IdlePelvisOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float PlayMeleeAttackAO;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float DisableArmsHeadAdditiveCurveAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float DisableIKRootAdditiveCurveAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingYawDeltaRatePerSecond;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingSpeedRelativeToFlow;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingYawDeltaRatePerSecondSmooth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingYawDeltaRatePerSecondSmoothClamped;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingSprintYawDeltaRatePerSecondSmooth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingDivePitch;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingDivePitchDeltaRatePerSec;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingVelocityAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingLocalAccelerationYawAngleSmooth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingNonZeroLocalAccelYawAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingResetStoppedDivingWhileUnderWaterTime;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingNonTargetingBlendspaceDir;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float AbsYawDeltaSmoothed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSwimmingLayerAnimInstance")
	float LocalAccelYawAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingLayerAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float MeleeTwistCurveValue;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float DBNOTurnPlayRateAbs;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimDiveJumpLayerAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float SwimmingDiveJumpingBlendOutTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ADSToNonADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float NonADSToADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	float UpperBodyLocomotionAdditiveMaskAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimIdleNoiseBlendTrigger : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingIsWaterPaddlingToSurface : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	uint8 bPlayUpperBodyTargeting : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsFemale : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsDBNO : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bEnableDiveJumpAimOffsets : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingDoveIntoGround : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsWaterJump : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bRecentlyFired : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsSprinting : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsAccelerating2D : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsMoving2D : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsOnGround : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsCrouching : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsTargeting : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsDiveJumping : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingAllowSlowSprint : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingIsWaterLanding : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingSharpAccelerationChange : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bStoppedDivingWhileUnderWater : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingPlayDBNOTurnEast : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bSwimmingSprintSlowEnoughTimePassed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsBuilding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_Swimming_FullBody_Sprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_Swimming_LowerBody_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_SwimSprintSlow_to_SwimSprintStart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_SwimSprintSlow_to_SwimSprint : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_SwimSprint_to_SwimSprintSlow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_Idles_to_SwimStart : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_SwimStart_to_SwimMovementAccel : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_SwimStartAdditive_to_SwimMovementAccelAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_SwimDiveLandOnGround_to_SplitBody : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_Sprinting_to_Conduit : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_InterruptSprintSwimming : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_DBNOSwimIdle_to_DBNOSwimTurn : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsHidingInProp : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSwimmingLayerAnimInstance")
	uint8 bIsDiveLandingOnGround : 1;

private:
	UPROPERTY(Transient)
	float DiveGroundLandingRemainingTime;

	UPROPERTY(Transient)
	uint8 bWasDiveJumpingLastTick : 1;

	UPROPERTY(Transient)
	uint8 bIsFlying : 1;

	UPROPERTY(Transient)
	uint8 bIsWaterSprintBoosting : 1;

	UPROPERTY(Transient)
	uint8 bDiveGameplayTagApplied : 1;

};

