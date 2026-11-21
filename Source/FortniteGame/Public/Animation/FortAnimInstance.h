// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortAnimInstance.generated.h"

class AFortAIPawn;
class UAnimMontage;
class UAnimNotify;
class UFortAnimSet;
enum class EFortCardinalDirection : uint8;

UENUM(BlueprintType)
enum class EAnimRelaxedState : uint8
{
	None = 0,
	WeaponRaised = 1,
	RelaxedLevel1 = 2,
	RelaxedLevel2 = 3,
};

UENUM(BlueprintType)
enum class ERidingFootPhase : uint8
{
	FeetInAir = 0,
	FrontFeetPlanted = 1,
	BackFeetPlanted = 2,
	LeftBackFeetForward = 3,
	RightBackFeetForward = 4,
	LeftPlantedRightPass = 5,
	RightPlantedLeftPass = 6,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORTNITEGAME_API void AnimNotify_LeftFootStep(const UAnimNotify* Notify);

	UFUNCTION()
	FORTNITEGAME_API void AnimNotify_RightFootStep(const UAnimNotify* Notify);

	UFUNCTION(BlueprintPure, Category="GeneralGameplay")
	FORTNITEGAME_API EFortCardinalDirection GetCardinalDirectionFromAngle(float Angle, float DeadZoneAngle) const;

	UFUNCTION(BlueprintCallable, Category="Montage")
	FORTNITEGAME_API void StopMontageIncludingInactive(float InBlendOutTime, const UAnimMontage* Montage = nullptr);

	UPROPERTY(EditDefaultsOnly, Category="Updates")
	bool bUpdateAllPawnProperties;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Movement")
	float VelocityLerpAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	FVector PawnVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Movement")
	float MinSpeed2DThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	float PawnSpeed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	float PawnVelocityZ;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Movement")
	float PawnMovementDirectionAzimuth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	FRotator PawnRotationRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	FRotator PawnDeltaRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	FRotator PawnLastRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Movement")
	FVector PawnLastLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jump")
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jump")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jump")
	bool bSwingingLayerLinked;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Jump")
	bool bShouldPredictLanding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jump")
	bool bLandingPredicted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Jump")
	float PredictedFallTimeLeft;

	UPROPERTY(EditDefaultsOnly, Category="Jump")
	float FallLookAheadSubStepping;

	UPROPERTY(EditDefaultsOnly, Category="Jump")
	int32 FallLookAheadMaxIterations;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Jump")
	bool bDebugLandPrediction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Jump")
	bool bRecordJumpPositions;

	UPROPERTY(Transient)
	bool bIsRecordingJump;

	UPROPERTY(Transient)
	int32 RecordJumpFrameCount;

	UPROPERTY(Transient)
	FVector RecordJumpInitialJumpLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	float AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	float AimYaw;

	UPROPERTY(EditDefaultsOnly, Category="Relaxed")
	float TimeForRecentlyFired;

	UPROPERTY(EditDefaultsOnly, Category="Relaxed")
	float TimeToReachRelaxedLevel1;

	UPROPERTY(EditDefaultsOnly, Category="Relaxed")
	float TimeToReachRelaxedLevel2;

	UPROPERTY(EditDefaultsOnly, Category="Relaxed")
	float MinTimeAfterFiredBeforeWallRelaxed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Relaxed")
	bool bRecentlyFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Relaxed")
	bool bIsRelaxedLevel1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Relaxed")
	bool bIsRelaxedLevel2;

	UPROPERTY(Transient)
	bool bIsWeaponLoweredNearWall;

	UPROPERTY(Transient)
	bool bExitedRelaxedThisUpdate;

	UPROPERTY(EditDefaultsOnly, Category="Relaxed")
	bool bLowerWeaponNearWallDuringTargeting;

	UPROPERTY(Transient)
	float RelaxedLevelTimeCounter;

	UPROPERTY(Transient)
	float SavedWeaponLastFireTime;

	UPROPERTY(Transient)
	EAnimRelaxedState RequestedRelaxedState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Detail")
	uint8 bClothEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Detail")
	uint8 bAnimDynamicsEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Detail")
	uint8 bRigidBodyEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bIsInGoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInstance")
	bool bIsBeingRidden;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bIsSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bIsKneeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bIsBaseballSliding;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortAnimInstance")
	TObjectPtr<UFortAnimSet> AnimSetOverride;
#endif

protected:
	UFUNCTION(BlueprintPure, Category="Weapon")
	FORTNITEGAME_API void GetPreviousFrameAimPitchAndYaw(float& OutPitch, float& OutYaw) const;

	UFUNCTION(BlueprintPure, Category="Animation")
	FORTNITEGAME_API AFortAIPawn* TryGetFortAIPawn();

};

