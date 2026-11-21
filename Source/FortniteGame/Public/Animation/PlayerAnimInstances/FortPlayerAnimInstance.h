// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_RandomizeMontageSection.h"
#include "Animation/AnimInputs/FortAnimInput_SlopeInfo.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/AnimInputs/FortAnimInput_TransitionProperties.h"
#include "Animation/AnimInputs/FortAnimInput_WeaponAdditiveAnimAsset.h"
#include "Animation/AnimSets/FortLocomotionAnimSet.h"
#include "Animation/AnimSets/FortTacticalStateAnimSet.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimInstance.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortLinkedAnimGraphsData.h"
#include "Animation/FortMovementLeans.h"
#include "Animation/FortPlayMontageForGameplayTagQueryInterface.h"
#include "Animation/FortPlayerAnimAssets.h"
#include "Customization/GameplayTagAnimation.h"
#include "FortCombatTypes.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "FortPlayerAnimInstance.generated.h"

class AFortPlayerController;
class AFortPlayerPawn;
class UAnimMontage;
class UAnimNotify;
class UAnimSequence;
class UFortItemChooserData;
class UFortPlayerGliderAnimSet;
class UFortWeaponAdditiveAnimSet;
class UFortWeaponAnimSet;
class UProxyTable;
enum class EFortCardinalDirection : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance : public UFortAnimInstance, public IFortPlayMontageForGameplayTagQueryInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_PlayFireFX(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_PlaySecondaryFireFX(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_PlayWeaponInspect(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_SkydiveAdditiveEnd(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_StopFireFX(const UAnimNotify* Notify);

	UFUNCTION(BlueprintCallable, Category="EmoteTesting")
	UAnimMontage* FindEmoteToPlay(AFortPlayerController* FortPlayerController, EFortCustomBodyType::Type InBodyType, EFortCustomGender::Type InGender);

	UFUNCTION(BlueprintPure, Category="GeneralGameplay")
	float GetRelativeAngle(float MovementAngle, EFortCardinalDirection Direction, bool bMirrorBackside) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayMontageFromGameplayTagQuery(const FGameplayTagQuery& MatchingQuery, UAnimMontage* MontagePlaying);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetIsPatrolling(bool NewValue);

	UFUNCTION(BlueprintCallable, Category="Tactical Sprint")
	void UpdateTacticalSprint();

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FFortLinkedAnimGraphsData LinkedAnimGraphsData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float DeltaTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditDefaultsOnly, Category="FallPrediction")
	float FallAnimDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FallPrediction")
	float FallPlayRate;

	UPROPERTY(BlueprintReadOnly, Category="Locomotion")
	FFortAnimInput_SpeedWarping SpeedWarping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float JogStartSpeedWarpingAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Locomotion")
	FFortAnimInput_SpeedWarping JogStartSpeedWarping;

	UPROPERTY(Transient)
	FFortAnimInput_CommonVehicle CommonVehicleInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY()
	FFortAnimInput_RandomizeMontageSection RandomizeMontageSectionInput;

	UPROPERTY(BlueprintReadOnly, Category="Slope")
	FFortAnimInput_SlopeInfo SlopeInfoInput;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	FFortAnimInput_TransitionProperties TransitionPropertiesInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNO")
	float DBNOTurnPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNO")
	float DBNOTurnPlayRateAbs;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Emote")
	FVector EmoteAnimOffset;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAimBase;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAimAthena;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAim;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFortAnimInput_SpringGlider SpringGlider;

	UPROPERTY(BlueprintReadWrite, Category="HandIK")
	FFortAnimInput_HandIK HandIKInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ADSToNonADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float NonADSToADSBlendTime;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float BlendOutOfWallBlockTime;

	UPROPERTY(Transient)
	float BlendOutOfWallBlockTimeRemaining;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float HandIKRetargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float RightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LeftHandFKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LegIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float OneHandedTransitionHackAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Skydiving")
	FFortAnimInput_Skydiving Skydiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Skydiving")
	float FreeFall_AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeSliding")
	bool bIsSlopeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float JumpAdditiveLayerAlpha;

	UPROPERTY(EditDefaultsOnly, Category="Layers")
	FCachedAnimStateData JumpAdditiveLayerPassthrough;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float JumpAdditiveLeanAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float DisableRightArmAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float DisableArmsHeadAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float DisableIKRootAdditiveCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Layers")
	float DisableUpperBodyAdditiveMeshSpaceCurveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	float UpperBodySlotLowerBodyMaskAlpha;

	UPROPERTY(Transient)
	float UpperBodySlotLowerBodyMaskBlendProgress;

	UPROPERTY(EditDefaultsOnly, Category="DBNO")
	TObjectPtr<UProxyTable> DBNOCarryProxyTable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_WeaponAdditiveAnimAsset CurrentWeaponAdditiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortLocomotionAnimSet CurrentLocomotionAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortTacticalStateAnimSet CurrentTacticalStateAnimSet;

	UPROPERTY(Transient)
	TArray<FName> BonesHiddenByAnimSet;

	UPROPERTY(Transient)
	float AimPitchAdjustment;

	UPROPERTY(Transient)
	float AimYawAdjustment;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	float PlayMeleeAttackAO;

	UPROPERTY(Transient)
	FTransform LastFramePawnTransform;

	UPROPERTY(Transient)
	FWeaponModAnimData WeaponModAnimData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	TObjectPtr<UAnimSequence> WeaponModLeftHandPoseOffset;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float MaxAimYawAdjustment;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float MaxPitch;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float MaxYaw;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float ReticleAimDistance;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float AimAdjustmentInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	float WeaponFireBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	TObjectPtr<UFortItemChooserData> ItemChooserData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	FVector SlopeWarpingFloorOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Consumable")
	TObjectPtr<UAnimSequence> ConsumableOffsetPose;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> MissingCosmeticUpperBodyOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> MissingCosmeticLowerBodyOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MissingCosmeticAnimOverride")
	TObjectPtr<UAnimSequence> MissingCosmeticLowerBodyInMotionOverride;

	UPROPERTY(BlueprintReadWrite, Category="MissingCosmeticAnimOverride")
	uint8 bEnableMissingCosmeticOverride : 1;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	uint8 bAimWeaponTowardsReticle : 1;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	uint8 bDebugWeaponAiming : 1;

	UPROPERTY(Transient)
	uint8 bCachedPawnTransform : 1;

	UPROPERTY(Transient)
	uint8 bHasValidWeaponMuzzleSocket : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Pelvis")
	uint8 bShouldUseCrouchUpperBodySlot : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Pelvis")
	uint8 bShouldUseCrouchInPlaceAdditiveSlot : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	uint8 bUseCustomFloorOffset : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsTargetingConsumableThrow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bPlayUpperBodyTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bPlayingRootMotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsStunned : 1;

	UPROPERTY(Transient)
	uint8 bIsMontagePlaying : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(Transient)
	uint8 bRecentlyFiredAbility : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bDisableUpperBodySlotOnLowerBodyInIdle : 1;

	UPROPERTY(Transient)
	uint8 bWasRelaxedLevel1 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bTempIsRelaxedLevel1 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bUseRidingNonTargetingPose : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouchMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bIsDiveJumping : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bSwimmingIsWaterLanding : 1;

	UPROPERTY(Transient)
	uint8 bSwimmingHasReachedJumpBottom : 1;

	UPROPERTY(Transient)
	uint8 bSwimmingHeadUnderWaterDuringWaterLand : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bSwimmingJumpInitiatedFromWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsAccelerating2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsMoving2D : 1;

	UPROPERTY(Transient)
	uint8 bWasMoving2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsAboveMinimumLocomotionSpeed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsBackpedaling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldWalkRightFootFwd : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayJogStartTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayJogStopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayJogPivotTransition : 1;

	UPROPERTY(Transient)
	uint8 bStartTransitionActive : 1;

	UPROPERTY(Transient)
	uint8 bStopTransitionActive : 1;

	UPROPERTY(Transient)
	uint8 bPivotTransitionActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldPlayPostPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutStartState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutStopState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bShouldEarlyOutPivotState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bSkipJumpStart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bExitLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNO")
	uint8 bIsDBNO : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DBNO")
	uint8 bIsBeingInterrogated : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsUsingJetpack : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Locomotion")
	bool bGoopJumpExecuted;

	UPROPERTY(Transient)
	uint8 bIsUsingRemoteControlPawn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsInVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsValetDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsValetPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsInShoppingCart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsInCannon : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsFiredFromCannon : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsDBNOCarrying : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsDBNOCarried : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gender")
	uint8 bIsFemale : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bIsHidingInProp : 1;

	UPROPERTY(Transient)
	uint8 bStopJogDoOnceTriggered : 1;

	UPROPERTY(Transient)
	uint8 bStartJogDoOnceTriggered : 1;

	UPROPERTY(Transient)
	uint8 bPivotTransitionDoOnceTriggered : 1;

	UPROPERTY(Transient)
	uint8 bPostPivotTransitionDoOnceTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	uint8 bIsBalloonInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Balloons")
	uint8 bHasBalloons : 1;

	UPROPERTY(Transient)
	uint8 bIsGhost : 1;

	UPROPERTY(Transient)
	uint8 bHasIcyFeet : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emotes")
	uint8 bIsMovingAndInMotionEmote : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emotes")
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	float FullBodyToUpperBodyInMotionBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseUpperBodyInMotionSlot : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bPlayLowerBodyLocomotionOverFullBodySlot : 1;

	UPROPERTY(Transient)
	uint8 bIsGrappleRopeActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bHasSourcePoseOverride : 1;

	UPROPERTY(EditDefaultsOnly, Category="FullBodyInAir")
	float FullBodyInAirFallTimeThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FullBodyInAir")
	float FullBodyInAirLowerBodyWeight;

	UPROPERTY(Transient)
	float TargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	bool bHasMeleeTwistCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float MeleeTwistCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float JumpUpperBodyBlendWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float RightArmMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float LeftArmMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float UpperBodyNoAdditivesMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	float FullBodyAimOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocomotionAdditiveAlpha;

	UPROPERTY(Transient)
	float BaseLocomotionAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalAccelYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float MaxSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float VelocityZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float RidingSpeed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngleMinusJogBlendSpaceRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngleMinusMeleeTwist;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalAccelVelocityYawDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float SpeedAdjustedPlayrate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LeanAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float SprintYawAngle;

	UPROPERTY(Transient)
	float StartStateRotationMultiplier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleNorth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleEast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleSouth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StartAnimDeltaAngleWest;

	UPROPERTY(Transient)
	float StopStateRotationMultiplier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float StopAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float JogPrePivotTimer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float PrePivotAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float PostPivotAnimDeltaAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float TransitionPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	float YawDeltaCurrentTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	float YawDeltaLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	float YawDeltaSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	float AbsYawDeltaSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(Transient)
	float SavedWeaponAbilityLastFireTime;

	UPROPERTY(Transient)
	float SwimmingImmersionDepth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FVector WorldAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FVector LocalAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FVector WorldVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FVector LocalVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FVector ActorSpaceVelocityDirPreTurn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Turning")
	FRotator ActorRotationLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnimForEmptyHands;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	TObjectPtr<UFortWeaponAnimSet> DefaultWeaponAnimSet;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FFortPlayerAnimAssets DefaultAnimAssets;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FFortPlayerAnimAssets HeavyWeaponAnimAssets;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSet;

	UPROPERTY(Transient)
	FFortPlayerAnimAssets WeaponAnimAssets;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TObjectPtr<UFortWeaponAnimSet> WeaponOverrideAnimSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponAdditiveAnimSet> WeaponAdditiveAnimSet;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	TObjectPtr<UFortWeaponAnimSet> WeaponAnimSetForEmptyHands;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	float FirstPersonAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	uint8 bWeaponHolstered : 1;

	UPROPERTY(Transient)
	uint8 bPreviousWeaponHolstered : 1;

	UPROPERTY(Transient)
	uint8 bPreviousIsInFirstPerson : 1;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortPlayerGliderAnimSet> CurrentGliderAnimSetDataAsset;

	UPROPERTY(Transient)
	EFortCardinalDirection PreviousFrameLocomotionCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(Transient)
	EFortCardinalDirection StartTransitionInitialDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection StopCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection PrePivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection PostPivotCardinalDirection;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	float JumpUpperBodyBlendSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredCrouchSprintSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredCrouchWalkSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredCrouchJogSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredSprintSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Locomotion")
	float AuthoredWalkSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredJogBwdSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredJogFwdSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float AuthoredJogStrafeSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float LeanFadeInSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Locomotion")
	float LeanFadeOutSpeed;

	UPROPERTY()
	uint8 bIsShieldUp : 1;

	UPROPERTY(BlueprintReadWrite, Category="Locomotion")
	uint8 bIsJumpBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bEnableAimOffsets : 1;

	UPROPERTY(BlueprintReadWrite, Category="Jump")
	uint8 bShouldProcessFullAnimUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Category="Locomotion")
	uint8 bIsInAir : 1;

	UPROPERTY(BlueprintReadOnly, Category="Locomotion")
	uint8 bEnterLanding : 1;

	UPROPERTY(BlueprintReadWrite, Category="Jump")
	uint8 bIsWaterJump : 1;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	uint8 bPlayWeaponInspect : 1;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	uint8 bInterruptWeaponInspect : 1;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	uint8 bInterruptWeaponInspectNoBlend : 1;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	uint8 bPlayRelaxedEntry : 1;

	UPROPERTY(Transient)
	uint8 bIsGrapplerActive : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bSwimmingIsWaterPaddlingToSurface : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bIsRelaxedLevel1AndNotJumpingFromWater : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Swimming")
	uint8 bIsRelaxedLevel2AndNotJumpingFromWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Swimming")
	uint8 bSwimIdleNoiseBlendTrigger : 1;

	UPROPERTY(BlueprintReadWrite, Category="Melee")
	uint8 bIsMeleeGuarding : 1;

	UPROPERTY(BlueprintReadWrite, Category="Melee")
	uint8 bIsMeleeDeflecting : 1;

	UPROPERTY(Transient)
	uint8 bUsingUncleBrolly : 1;

	UPROPERTY(BlueprintReadWrite, Category="Locomotion")
	uint8 bIsPlayingForwardMotionAnim : 1;

	UPROPERTY()
	uint8 bIsPatrolling : 1;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FName HeadTrackingReticleSocketName;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Weapon")
	float HeadTrackingReticleInterpSpeed;

	UPROPERTY(Transient)
	FRotator HeadTrackingReticleAdjustment;

	UPROPERTY(BlueprintReadOnly, Category="Animation")
	FGameplayTagAnimations GameplayTagAnimations;

	UPROPERTY(BlueprintReadWrite, Category="Idle")
	FVector StandardIdlePelvisOffset;

	UPROPERTY(EditDefaultsOnly, Category="Idle")
	FVector LargeFemaleIdlePelvisOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Idle")
	FVector IdlePelvisOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Idle")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(Transient)
	int32 PawnLOD;

	UPROPERTY(Transient)
	float WeaponInspectDelayTimeRemaining;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	float MinDelayBetweenWeaponInspects;

	UPROPERTY(Transient)
	float DisabledFullBodySprintTimeRemaining;

	UPROPERTY(Transient)
	uint8 bIsFullBodySprintTransitionDisabled : 1;

	UPROPERTY(Transient)
	float MaxParaGlideDeployCurveValue;

	UPROPERTY(Transient)
	bool bPreviousIsParachuteOpened;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance")
	uint8 bParaGlide_OpenGlider : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tactical Sprint")
	uint8 bIsTacticalSprint : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsTacticalJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsTacticalInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsNormalJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsNormalFall : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsDoorBashExit : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsInWater : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Hurdle")
	uint8 bIsHurdleFall : 1;

	UPROPERTY(Transient)
	uint8 bWantsGliderAnimAssetUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_FullBody_Sprinting : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_FullBody_TacticalSprint : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_Swimming_FullBody_Sprinting : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_NewFallAditive_NewFallLandAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_FullBody_Stunned : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_FullBody_DBNOMove : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_FullBody_DBNOTurn : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bEarlyOut_Lowerbody_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_LowerBody_Shuffle : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_LowerBody_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_LocomotionAdditive_CrouchTurning : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bLocomotion_Idles_to_Turns : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_Sprinting_to_Conduit : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_DBNOSwimIdle_to_DBNOSwimTurn : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_SwimJumpSurfaceLoop_to_SwimJumpSurfaceEnd : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_SwimJumpSurfaceLoop_to_IdleAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransition_NewJumpLoopAdditive_to_NewFallAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bIsUmbrellaFailing : 1;

	UPROPERTY(Transient)
	uint8 bEnableEmptyHands : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bHideWeaponForEmptyHands : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance")
	uint8 bSupressJogStartAdditiveForLiveEvent : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseFullBodyJumpAdditivesLinkedGraph : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseFullBodyStateLinkedGraph : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bIsWalking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bIsRiding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bIsReloading : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance")
	uint8 bEnableRigidBodyPBA : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseFacialCurves : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bLinkedDebugGraphActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	TObjectPtr<UProxyTable> ItemProxyTable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseProceduralLayering : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	uint8 bUseMotionMatchingWithoutProceduralLayering : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerAnimInstance")
	FFortMovementLeans AdditiveLeanData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	float ADSLeanWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	bool bPoseDebugEnabled;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	int32 DebugPoseIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	bool bDebugDisableUpperBody;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	bool bDebugLocomotionAdditives;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance")
	bool bUseNoWeaponPoseDebug;

	UPROPERTY(Transient)
	bool bAimYawSmoothingActive;

private:
	UPROPERTY(Transient)
	bool bWasFallingLastTick;

};

