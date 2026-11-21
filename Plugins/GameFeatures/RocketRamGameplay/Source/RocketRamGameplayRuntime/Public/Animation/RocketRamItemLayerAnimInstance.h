// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance.h"
#include "RocketRamItemLayerAnimInstance.generated.h"

class AFortPlayerPawn;
class AFortWeapon;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class URocketRamItemLayerAnimInstance : public UFortItemLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRWindUp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRSlowAcceleration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRActiveThrust;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRFreeFall;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRFastFreeFall;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRBraking;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRRecovery;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRRecoveryDelayed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRRRecoveryHalfSecDelay;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsRROff;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsFalling;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsSliding;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsCrouchingLocal;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float XInput;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float YInput;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float Pitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float Yaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float WallImpactPitch;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float WallImpactYaw;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	FVector WeaponLaunchDirection;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsBoneRotOn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsPitchAndYawRot;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsNoMortar;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsGoingUp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsJumpFromGround;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsMoving2DLocal;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float AdditiveSquatAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float JumpAddCurveAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float ArmsHeadAddAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float JumpAddOffsetAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsImpactWallBackup;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsLandingDetected;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsWallImpact;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bIsApexTimerEnd;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	AFortPlayerPawn* FortPlayerPawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	AFortWeapon* WeaponRocketRam;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float FBImpactGroundStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBGroundSlideToFBWait;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBThrustingToFBApex;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBApexToFBToMortar;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBOffGroundToFBImpactGround;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBOffWallToFBImpactWall;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBDetectGroundToFBToImpactGround;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float FBJumpStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float FBToApexStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBDetectSlideToFBToSlide;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bFBOffToFBWait;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float UBPullLeverStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float UBSquatStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	float UBJumpStateAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bUBSquatToUBJump;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bUBJumpToUBWait;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bUBJumpToUBToGroundImpact;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bUBWaitToUBImpactGround;

	UPROPERTY(BlueprintReadWrite, Transient, Category="RocketRam | Nativized")
	bool bUBOffToUBWait;

};

