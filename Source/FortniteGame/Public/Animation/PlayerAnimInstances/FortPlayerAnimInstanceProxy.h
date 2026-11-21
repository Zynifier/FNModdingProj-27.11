// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_SlopeInfo.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/AnimInputs/FortAnimInput_TransitionProperties.h"
#include "Animation/AnimInputs/FortAnimInput_WeaponAdditiveAnimAsset.h"
#include "Animation/AnimSets/FortLocomotionAnimSet.h"
#include "Animation/AnimSets/FortTacticalStateAnimSet.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "Customization/GameplayTagAnimation.h"
#include "FortCombatTypes.h"
#include "FortGender.h"
#include "FortPlayerAnimInstanceProxy.generated.h"

class AFortPlayerPawn;
class UAnimSequence;
class UFortItemChooserData;
class UFortPlayerGliderAnimSet;
class UFortWeaponAdditiveAnimSet;
class UFortWeaponAnimSet;

UCLASS(HideCategories=("AnimInstance"))
class FORTNITEGAME_API UFortPlayerAnimInstanceProxy : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bUpdateOnWorkerThread;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float VelocityLerpAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector PawnVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MinSpeed2DThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PawnSpeed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PawnVelocityZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PawnMovementDirectionAzimuth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FRotator PawnRotationRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FRotator PawnDeltaRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FRotator PawnLastRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector PawnLastLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bSwingingLayerLinked;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bShouldPredictLanding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bLandingPredicted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PredictedFallTimeLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FallLookAheadSubStepping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	int32 FallLookAheadMaxIterations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bDebugLandPrediction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bRecordJumpPositions;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float TimeForRecentlyFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float TimeToReachRelaxedLevel1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float TimeToReachRelaxedLevel2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MinTimeAfterFiredBeforeWallRelaxed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bRecentlyFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsRelaxedLevel1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsRelaxedLevel2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsWeaponLoweredNearWall;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bExitedRelaxedThisUpdate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bClothEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bAnimDynamicsEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bRigidBodyEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsInGoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsBeingRidden;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsKneeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsBaseballSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DeltaTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FallAnimDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FallPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_SpeedWarping SpeedWarping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JogStartSpeedWarpingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_SpeedWarping JogStartSpeedWarping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_Zipline ZiplineInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_JackalVehicle JackalVehicleInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_CommonVehicle CommonVehicleInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_SlopeInfo SlopeInfoInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_TransitionProperties TransitionPropertiesInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DBNOTurnPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DBNOTurnPlayRateAbs;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector EmoteAnimOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_AdjustedAim AdjustedAim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_SpringGlider SpringGlider;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_HandIK HandIKInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float ADSToNonADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float NonADSToADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float BlendOutOfWallBlockTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float BlendOutOfWallBlockTimeRemaining;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float HandIKRetargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float RightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeftHandFKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LegIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float OneHandedTransitionHackAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_Skydiving Skydiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FreeFall_AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bIsSlopeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SlopeSlidingPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SlopeSlidingRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JumpAdditiveLayerAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JumpAdditiveLeanAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DisableRightArmAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DisableArmsHeadAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DisableIKRootAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float DisableUpperBodyAdditiveMeshSpaceCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortAnimInput_WeaponAdditiveAnimAsset CurrentWeaponAdditiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortLocomotionAnimSet CurrentLocomotionAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FFortTacticalStateAnimSet CurrentTacticalStateAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TArray<FName> BonesHiddenByAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PlayMeleeAttackAO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MaxAimYawAdjustment;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MaxPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MaxYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float ReticleAimDistance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AimAdjustmentInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UFortItemChooserData> ItemChooserData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float WeaponFireBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector SlopeWarpingFloorOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FName WeaponAimingFreezeCurveName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UAnimSequence> ConsumableOffsetPose;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UAnimSequence> MissingCosmeticUpperBodyOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UAnimSequence> MissingCosmeticLowerBodyOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UAnimSequence> MissingCosmeticLowerBodyInMotionOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bEnableMissingCosmeticOverride : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bAimWeaponTowardsReticle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bDebugWeaponAiming : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldUseCrouchUpperBodySlot : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldUseCrouchInPlaceAdditiveSlot : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUseCustomFloorOffset : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsTargetingConsumableThrow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bPlayUpperBodyTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bPlayingRootMotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsStunned : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsMontagePlaying : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bRecentlyFiredAbility : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bDisableUpperBodySlotOnLowerBodyInIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bWasRelaxedLevel1 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTempIsRelaxedLevel1 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUseRidingNonTargetingPose : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsCrouchMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInTetheredMovement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsDiveJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimmingIsWaterLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimmingHasReachedJumpBottom : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimmingHeadUnderWaterDuringWaterLand : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimmingJumpInitiatedFromWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsAccelerating2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsMoving2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bWasMoving2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsAboveMinimumLocomotionSpeed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsBackpedaling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldWalkRightFootFwd : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldPlayJogStartTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldPlayJogStopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldPlayJogPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bStartTransitionActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bStopTransitionActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bPivotTransitionActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldPlayPostPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldEarlyOutStartState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldEarlyOutStopState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldEarlyOutPivotState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSkipJumpStart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsDBNO : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsBeingInterrogated : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsUsingJetpack : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bGoopJumpExecuted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsUsingRemoteControlPawn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsValetDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsValetPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInShoppingCart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInCannon : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsFiredFromCannon : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsDBNOCarrying : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsDBNOCarried : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsFemale : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsHidingInProp : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsBalloonInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bHasBalloons : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsGhost : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bHasIcyFeet : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsMovingAndInMotionEmote : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsGrappleRopeActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bHasSourcePoseOverride : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FullBodyInAirFallTimeThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FullBodyInAirLowerBodyWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float TargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	bool bHasMeleeTwistCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MeleeTwistCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JumpUpperBodyBlendWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float RightArmMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeftArmMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float UpperBodyNoAdditivesMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float FullBodyAimOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocomotionAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocalAccelYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MaxSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float VelocityZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float RidingSpeed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocalVelocityYawAngleMinusJogBlendSpaceRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocalVelocityYawAngleMinusMeleeTwist;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LocalAccelVelocityYawDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SpeedAdjustedPlayrate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeanAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeanAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SprintYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StartStateRotationMultiplier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StartAnimDeltaAngleNorth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StartAnimDeltaAngleEast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StartAnimDeltaAngleSouth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StartAnimDeltaAngleWest;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StopStateRotationMultiplier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float StopAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JogPrePivotTimer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PrePivotAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PostPivotAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float TransitionPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float YawDeltaCurrentTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float YawDeltaLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float YawDeltaSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AbsYawDeltaSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SavedWeaponAbilityLastFireTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float SwimmingImmersionDepth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector WorldAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector LocalAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector WorldVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector LocalVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector ActorSpaceVelocityDirPreTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FRotator ActorRotationLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnimForEmptyHands;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UFortWeaponAnimSet> WeaponOverrideAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UFortWeaponAdditiveAnimSet> WeaponAdditiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSetForEmptyHands;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	TWeakObjectPtr<UFortPlayerGliderAnimSet> CurrentGliderAnimSetDataAsset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortCardinalDirection StartTransitionInitialDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortCardinalDirection StopCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortCardinalDirection PrePivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	EFortCardinalDirection PostPivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float JumpUpperBodyBlendSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredCrouchSprintSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredCrouchWalkSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredCrouchJogSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredSprintSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredWalkSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredJogBwdSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredJogFwdSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float AuthoredJogStrafeSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeanFadeInSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float LeanFadeOutSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsShieldUp : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsJumpBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bEnableAimOffsets : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bShouldProcessFullAnimUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsWaterJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bPlayWeaponInspect : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bInterruptWeaponInspect : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bInterruptWeaponInspectNoBlend : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bPlayRelaxedEntry : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsGrapplerActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimmingIsWaterPaddlingToSurface : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsRelaxedLevel1AndNotJumpingFromWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsRelaxedLevel2AndNotJumpingFromWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSwimIdleNoiseBlendTrigger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsMeleeGuarding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsMeleeDeflecting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUsingUncleBrolly : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsPlayingForwardMotionAnim : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FName HeadTrackingReticleSocketName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float HeadTrackingReticleInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FRotator HeadTrackingReticleAdjustment;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FGameplayTagAnimations GameplayTagAnimations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector StandardIdlePelvisOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector LargeFemaleIdlePelvisOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector IdlePelvisOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float WeaponInspectDelayTimeRemaining;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	float MinDelayBetweenWeaponInspects;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bParaGlide_OpenGlider : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsTacticalSprint : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsTacticalJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsTacticalInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsNormalJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsNormalFall : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsDoorBashExit : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsHurdleFall : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bWantsGliderAnimAssetUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_FullBody_Sprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_Swimming_FullBody_Sprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_NewFallAditive_NewFallLandAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_FullBody_Stunned : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_FullBody_DBNOMove : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_FullBody_DBNOTurn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bEarlyOut_Lowerbody_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_LowerBody_Shuffle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_LowerBody_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_LocomotionAdditive_CrouchTurning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bLocomotion_Idles_to_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_Sprinting_to_Conduit : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_DBNOSwimIdle_to_DBNOSwimTurn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_SwimJumpSurfaceLoop_to_SwimJumpSurfaceEnd : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_SwimJumpSurfaceLoop_to_IdleAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bTransition_NewJumpLoopAdditive_to_NewFallAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsUmbrellaFailing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bEnableEmptyHands : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bHideWeaponForEmptyHands : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bSupressJogStartAdditiveForLiveEvent : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUseFullBodyJumpAdditivesLinkedGraph : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUseFullBodyStateLinkedGraph : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsWalking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsRiding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bUseFacialCurves : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	FVector Ragdoll_InitialImpact_ThrowVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bLinkedDebugGraphActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bIsInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstanceProxy")
	uint8 bWeaponHolstered : 1;

};

