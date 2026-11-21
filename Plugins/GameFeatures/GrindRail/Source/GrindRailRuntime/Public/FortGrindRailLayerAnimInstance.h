// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortAnimInputGrindRail.h"
#include "FortGrindRailLayerAnimInstance.generated.h"

class AFortPlayerPawn;
class UAnimMontage;
class UAnimNotify;
class UCharacterMovementComponent;
class UFortPawnComponent_GrindRail;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortGrindRailLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_EntryEnter(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_EntryExit(const UAnimNotify* Notify);

	UFUNCTION()
	void AnimNotify_IdleEnter(const UAnimNotify* Notify);

	UFUNCTION()
	void HandleBegunGrinding(bool bWasAlreadyGrinding, bool bWasJumpingFromRail, bool bFromInteraction, FVector PreviousPlayerLocation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	TObjectPtr<UAnimMontage> LancePickaxeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	TObjectPtr<UAnimMontage> ScythePickaxeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	TObjectPtr<UAnimMontage> FruitCakePickaxeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	FName LeanAlphaCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	FName MeleeTwistCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	FName InterruptibleCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | SlopeWarping")
	TMap<FName, float> SlopeWarpingCurveMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	double LeanBwdVelocityThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail")
	FCachedAnimRelevancyData BwdStartCachedData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail", meta=(ClampMin="0.000000", ForceUnits="cm/s", UIMin="0.000000"))
	double IsMovingThresholdSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | NoisePlayRate", meta=(ClampMin="0.000000", ForceUnits="cm/s", UIMin="0.000000"))
	double NoisePlayRateSprintSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | NoisePlayRate")
	FVector2D NoisePlayRateNormalSpeedInputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | NoisePlayRate")
	FVector2D NoisePlayRateNormalSpeedOutputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | NoisePlayRate")
	FVector2D NoisePlayRateHighSpeedInputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | NoisePlayRate")
	FVector2D NoisePlayRateHighSpeedOutputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | CombatNoisePlayRate")
	FVector2D CombatNoisePlayRateSpeedInputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | CombatNoisePlayRate")
	FVector2D CombatNoisePlayRateSpeedOutputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | CombatNoiseAlpha", meta=(ClampMin="0.000000", UIMin="0.000000"))
	double CombatNoiseAlphaTargeting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | CombatNoiseAlpha", meta=(ClampMin="0.000000", UIMin="0.000000"))
	double CombatNoiseAlphaNonTargeting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail", meta=(ClampMin="0.000000", UIMin="0.000000"))
	double RootLeanAlphaInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | SlopeWarping", meta=(ClampMin="0.000000", UIMin="0.000000"))
	double SlopeWarpAlphaInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | Aim", meta=(ClampMax="180.000000", ClampMin="0.000000", ForceUnits="deg", UIMax="180.000000", UIMin="0.000000"))
	double SplineRelativeAimYawDeltaThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | Aim", meta=(ClampMin="0.000000", UIMin="0.000000"))
	double AimYawSmoothInterpolationCoefficient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | Aim", meta=(ClampMin="0.000000", ForceUnits="deg", UIMin="0.000000"))
	double IsSmoothingYawThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | Lean")
	double LeanBWDThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | MuteUpperBodyAlpha")
	double MuteUpperBodyAlphaMeleeWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | MuteUpperBodyAlpha")
	double MuteUpperBodyAlphaNonMeleeWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | MuteUpperBodyAlpha")
	double MuteUpperBodyAlphaFruitcakePickaxe;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Grind Rail | MuteUpperBodyAlpha")
	double MuteUpperBodyAlphaLanceSyctheOrDualWeild;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Lean")
	double BaseLeanDirection;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsGrinding;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	double CurrentSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Lean")
	double LeanDirection;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bSprinting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Lean")
	double LeanForward;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsWeaponActive;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	FRotator SplineRelativeAim;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	FFortAnimInput_GrindRail GrindRailInput;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Components")
	TWeakObjectPtr<UFortPawnComponent_GrindRail> GrindingComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Components")
	TWeakObjectPtr<UCharacterMovementComponent> MovementComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	TWeakObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsFalling;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Lean")
	double LeanAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsMoving;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	bool bShould180Turn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bShouldPlayEntry;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | NoisePlayRate")
	double NoisePlayRate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Lean")
	bool bIsLeanBwd;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	bool bIsLeft180Turn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	bool bShould180TurnAgain;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	bool bIsTurning;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bShouldExitLocomotion;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bEarlyExitFromEntry;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	bool bAimFWD;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	bool bAimBWD;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	bool bAimLFT;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	bool bAimRGT;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double AimFWDDeltaAngleDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double AimBWDDeltaAngleDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double AimLFTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	double NegativeYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	FRotator MeleeTwistRot;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	double BwdStartCachedTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	double Velocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bIsEntryLeft;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bIsEntryFromAir;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bIsEntryRight;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Entry")
	bool bEnteredFromInteraction;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | SlopeWarping")
	double SlopeWarpAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double SplineRelativeAimYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double AimYawSmoothed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsSmoothingYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | Aim")
	double LastSplineRelativeAimYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	double RootLeanAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | MuteUpperBodyAlpha")
	double MuteUpperBodyAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsLanceType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bWasSprinting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bStateRuleToBoostLoop;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsInAction;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | CombatNoisePlayRate")
	double CombatNoisePlayRate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | CombatNoiseAlpha")
	double CombatNoiseAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bIsTwoHandedMelee;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bShouldCorrectUpperBody;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail")
	bool bBothHandsDown;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	double TurnInPlaceAnimCurveValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Grind Rail | 180 Turn")
	double TurnRotationAmountCurveValue;

};

