// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SpringInterpolator.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimInstance.h"
#include "Animation/FortAnimTypes.h"
#include "FortOstrichAnimInstance.generated.h"

class AFortCharacterVehicle_Ostrich;
class UAnimMontage;
class UAnimNotify;
class UAnimSequence;
class UAnimSequenceBase;
class UBlendSpace1D;
class UFortAnimWorldStriderComponent;
class USkeletalMeshComponent;

UCLASS(HideCategories=("AnimInstance"))
class UFortOstrichAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_AnimNotify_AmmoCheck(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_AnimNotify_AmmoHide(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_AnimNotify_Mech_OnCoolDown(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_EmptyPoseState(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_JumpEnter(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_MechBeginFire(const UAnimNotify* Notify);

	UFUNCTION(BlueprintPure)
	float GetMechWalkPlayRateValue() const;

	UFUNCTION(BlueprintPure)
	float GetMechWalkSpeedWarpingValue() const;

	UFUNCTION(BlueprintPure)
	UAnimSequenceBase* GetPivotAnimation() const;

	UFUNCTION(BlueprintPure)
	float GetPivotAnimPosition() const;

	UFUNCTION(BlueprintPure)
	float GetPivotTurnYawCorrection() const;

	UFUNCTION(BlueprintPure)
	UAnimSequenceBase* GetStartAnimation() const;

	UFUNCTION(BlueprintPure)
	float GetStartAnimPosition() const;

	UFUNCTION(BlueprintPure)
	float GetStartTurnYawCorrection() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	virtual UFortAnimWorldStriderComponent* GetWorldStriderComponent() const;

	UFUNCTION()
	virtual void OnEmoteMontageBlendingOut(UAnimMontage* EmoteMontage, bool bInterrupted);

	UFUNCTION()
	virtual void OnEmoteMontageStarted(UAnimMontage* EmoteMontage);

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void OnFiredSingleRocket(const int32& NumRocketsLeft);

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void OnFireShotgun();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void OnReloadShotgun();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StartSeatTransition_DriverEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StartSeatTransition_DriverExit();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StartSeatTransition_PassengerEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StartSeatTransition_PassengerExit();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StopSeatTransition_DriverEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StopSeatTransition_DriverExit();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StopSeatTransition_PassengerEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void StopSeatTransition_PassengerExit();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	TSoftObjectPtr<UAnimMontage> EmoteMeshSpecialMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	TObjectPtr<UAnimMontage> MechMeshSpecialMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	bool bDoingSpecialEmote;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	bool bIsCosmeticPreview;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Impact")
	FFortAnimInput_VelocityImpact VelocityImpactInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsMoving2D : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bWasMoving2DLastFrame : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsShotgunFired : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsMechBeginFired : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsFallingWithDriver : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsSkyTubingWithDriver : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsInAirWithDriver : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bStartTransitionTriggeredAndEnableStarts : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerBlendPerBoneAlpha")
	float RocketCurveValueFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Shotgun")
	float ShotgunAmmo_SlideValue;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortCharacterVehicle_Ostrich> Ostrich;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Export, Category="Weapon", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> EmoteMeshToCopy;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Impact")
	FVector ImpactDisplacement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TurnInPlace")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Turning")
	float YawDeltaCurrentTick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	FVector ActorLocationLastTick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	FRotator ActorRotationLastTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	float SlopeWarpingAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlopeWarping")
	FVector2D SlopeWarpingAlphaSpeedInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlopeWarping")
	FVector2D SlopeWarpingAlphaSpeedOutputRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SlopeWarping")
	float SlopeWarpingAlphaInterpSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	float Speed2D;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float LocalAimYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float GunnerAimTargetDeltaYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float GunnerAimTargetDeltaPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	EFortCardinalDirection LocalAimCardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	float LocalAimYawDeadZoneAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float LocalVelocityYawAngle;

	UPROPERTY(EditAnywhere, Category="Weapon")
	FFloatRK4SpringInterpolator LocalVelocityYawAngleInterpolator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float LocalVelocityYawAngleInterpolated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Weapon")
	float LocalAccelerationYawAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	float LocomotionDeadZoneAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Locomotion")
	FVector WorldSpaceAimPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsDashing : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsDashAnimDurationElapsed : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsChargingJump : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bHasDriver : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bHasGunner : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsEmoting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsOnGround : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bIsRocketOnCooldown : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldApplyShoulderPadsAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldRightArmLookAt : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bPassengerBootUp : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsEmptyOnFirstLoad : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bJustDidStompInAir : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsStompInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bWasStompInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldPlayJumpCharging : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bHadDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bJustGotDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bJustLostDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bWasDashing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bStartedDash : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bHadGunner : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bJustGotGunner : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bJustLostGunner : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldPlayJogStop : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldBringAmmoBack : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bHasAnyPlayer : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsOnCoolDown : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldPlayNormalJump : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldPlayChargedJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bIsSkyTubing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldPlaySkyTubingLoop : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bStartTransitionTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bStartEarlyOut : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bPivotTransitionTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bPivotEarlyOut : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	uint8 bShouldEarlyOutStompLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float JumpApexLoopAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float StatusStartPositionAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float InMotionAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float DashLeansAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShotgunShellsAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float GunnerJogBounceAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	FRotator AimYawRotationValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float GunnerAimYawBlendIn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float GunnerAimYawBlendOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float RightArmNoAdditiveAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float BaseAdditiveAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float GunnerAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float JoyStickAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShellOneAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShellTwoAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShellThreeAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShellFourAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float ShellsPlayRateValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float RecoilAmountAlphaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOstrichAnimInstance")
	float LowerBodyRecoilAdditiveAlphaValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="FortOstrichAnimInstance")
	float ChargeJumpFloatValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float InMotionAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float DashLeansAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float GunnerJogBounceAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float RightArmNoAdditiveInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float JoyStickAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableInterpSpeedValues")
	float GunnerAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float StatusStartPositionAlphaWhemIsEmptyOnFirstLoad;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float DashLeansAlphaWhenGunner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float DashLeansAlphaNoGunner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShotgunShellsAlphaWhenShotgunFires;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShotgunShellsAlphaNoShotgunFiring;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float BaseAdditiveAlphaWhenMontageIsPlaying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float BaseAdditiveAlphaNoMontagePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float JoyStickAlphaWithGunner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float GunnerAlphaWithGunner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShellOneAlphaAmmoCountAt3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShellTwoAlphaAmmoCountAt2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShellThreeAlphaAmmoCountAt1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShellFourAlphaAmmoCountAt0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float ShellsPlayRateWhenNoMoreAmmoAndShouldBringAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float RecoilAmountAlphaWhenMontagePlayingAndShotgunFires;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float LowerBodyRecoilAdditiveAlphaWithDriver;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float LowerBodyRecoilAdditiveAlphaNoDriver;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float JumpApexLoopAlphaNotChargingJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float JumpApexLoopAlphaWhenIsChargingJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TunableAlphaValues")
	float RigidBodyAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MechAnimMontage")
	TObjectPtr<UAnimMontage> MechShotgunReload;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MechAnimMontage")
	TObjectPtr<UAnimMontage> MechShotgunFireA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MechAnimMontage")
	TObjectPtr<UAnimMontage> MechShotgunFireB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MechAnimMontage")
	TObjectPtr<UAnimMontage> MechRocketFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MechAnimMontage")
	TObjectPtr<UAnimMontage> MechRocketFireSettle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> ChargedJumpApexSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> ChargedJumpFallSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UBlendSpace1D> ChargedJumpLandSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> ChargedJumpLandPredictedSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> NormalJumpApexSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> NormalJumpFallSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UBlendSpace1D> NormalJumpLandSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpAnimTunableShot")
	TObjectPtr<UAnimSequence> NormalJumpLandPredictedSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JumpAnimDefault")
	TObjectPtr<UAnimSequence> JumpBaseApexSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JumpAnimDefault")
	TObjectPtr<UAnimSequence> JumpBaseFallSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JumpAnimDefault")
	TObjectPtr<UBlendSpace1D> JumpBaseLandSeq;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JumpAnimDefault")
	TObjectPtr<UAnimSequence> JumpBaseLandPredictedSeq;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_To_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_BootUp_To_Movement : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Turn_To_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Stop_To_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DashLoop_To_Default : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DashLoop_To_DashOutro : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerBlendPerBoneAlpha")
	float NotJustGotDriverFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerBlendPerBoneAlpha")
	float IsShotgunFiredFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UpperBodyLag")
	FRotator UpperBodyLagOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagMaxRecoverySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagRecoverySmoothness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagRecoveryMass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagRecoveryDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagOffsetLimitDuringTurns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagOffsetLimitDuringTurnsInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagOffsetLimitWhileStill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UpperBodyLagTunables")
	float UpperBodyLagOffsetLimitWhileStillInterpSpeed;

	UPROPERTY(Transient)
	float CurrentUpperBodyLagRecoverySpeed;

	UPROPERTY(Transient)
	float TimeUntilNextUpperBodyLagRecovery;

	UPROPERTY(Transient)
	float CurrentUpperBodyLagOffsetLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StartTunables")
	bool bEnableStarts;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="World Strider", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortAnimWorldStriderComponent> WorldStriderComponent;

};

