// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortMantisLayerAnimInstance.h"
#include "FortKatanaLayerAnimInstance.generated.h"

class AFortPlayerPawn;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortKatanaLayerAnimInstance : public UFortMantisLayerAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsDashCharge;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	AFortPlayerPawn* AsFortPlayerPawn;

	UPROPERTY(BlueprintReadWrite, Category="KatanaLayer/Nativized")
	bool IsBMeleeKatana;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float HandIKHipAttachAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector LeftAttachedHandIKLoc;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FRotator LeftAttachedhandIKRot;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector RightWeaponLoc;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FRotator RightWeaponRot;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector LeftAttachedHandIKLocOffsetMED;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FRotator LeftAttachedHandIKRotOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector RightWeaponLocOffsetMED;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FRotator RightWeaponRotOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float LocalLeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float LocalRightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsDashAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsDashOutro;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float PelvisAOAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float ClampedAimPitch;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool EarlyExitFromDashOutro;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsTechniqueActive;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsPrimaryAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float WeaponHipAttachAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector LeftAttachedHandIKLocOffsetLRG;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	FVector RightWeaponLocOffsetLRG;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	float FeetCorrectionAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsInAirAttackLeap;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool ShouldStartDashOutro;

	UPROPERTY(BlueprintReadWrite, Category="KatanaLayer/Nativized")
	bool StartedDashOutro;

	UPROPERTY(BlueprintReadWrite, Category="KatanaLayer/Nativized")
	FScalableFloat DashRootMotionDuration;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsPrimaryAttack2;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsAirAttackSlam;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool TransitionRuleToDefault;

	UPROPERTY(BlueprintReadOnly, Category="KatanaLayer/Nativized")
	bool IsGrindRailSwing;

	UPROPERTY(BlueprintReadWrite, Category="KatanaLayer/Nativized")
	float DashChargePlayRate;

};

