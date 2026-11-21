// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortMantisLayerAnimInstance.h"
#include "FortKatanaWeaponAnimInstance.generated.h"

class AFortPlayerPawn;
class AFortWeapon;
class UFortKatanaLayerAnimInstance;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortKatanaWeaponAnimInstance : public UFortMantisLayerAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	AFortPlayerPawn* AsFortPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	AFortWeapon* BMeleeKatanaAsWeapon;

	UPROPERTY(BlueprintReadWrite, Category="KatanaWeapon/Nativized")
	bool IsBMeleeKatana;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	float LocalLeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	float LocalRightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsDashCharge;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsDashAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	float SwordPlayRate;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsInAirAttack_Leap;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsInAirAttack_Slam;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	UFortKatanaLayerAnimInstance* KatanaPlayer;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool EarlyExitfromDashOutro;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsDashOutro;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FVector ScabbardLoc;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FRotator ScabbardRot;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FVector ScabbardLocOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FRotator ScabbardRotOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsSurfaceSwimming;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsTechniqueActive;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FVector SwordLoc;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FRotator SwordRot;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FVector SwordLocOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FRotator SwordRotOffset;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsRidingSwing;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsPrimaryAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsPrimaryAttack2;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool ExitFromPrimaryAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool ExitFromPrimaryAttack2;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool NonPrimaryAttackState;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsComboAttack;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool TransitionRuleToDefaultPose;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool ExitFromInAirLand;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	bool IsGrindRailSwing;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	int32 CurrentTechniqueBranch;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	int32 PreviousTechniqueBranch;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FName PelvisSocket;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FVector ScabbardLocOffsetVeh;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	FRotator ScabbardRotOffsetVeh;

	UPROPERTY(BlueprintReadOnly, Category="KatanaWeapon/Nativized")
	float DashChargePlayRate;

};

