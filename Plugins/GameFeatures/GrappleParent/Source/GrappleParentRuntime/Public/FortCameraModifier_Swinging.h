// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortCameraModifier_Swinging.generated.h"

class AFortPlayerPawnAthena;
class AFortWeaponRangedDualSwing;
class UCurveFloat;

USTRUCT(BlueprintType)
struct FSpeedScaledAxisOffsetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpeedScaledAxisOffsetData")
	FScalableFloat OffsetModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpeedScaledAxisOffsetData")
	float BaseOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpeedScaledAxisOffsetData")
	float SpeedScaledOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpeedScaledAxisOffsetData")
	FVector2D SpeedBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpeedScaledAxisOffsetData")
	FVector2D SpeedMultiplierBounds;

};

UCLASS()
class UFortCameraModifier_Swinging : public UCameraModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config")
	float MaxVelocityDeltaPerSecond;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Blend")
	UCurveFloat* BlendInCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Blend")
	UCurveFloat* BlendOutCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FSpeedScaledAxisOffsetData ForwardOffsetData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FVector2D TotalForwardOffsetBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FSpeedScaledAxisOffsetData RightOffsetData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FVector2D RightForwardOffsetMultiplierBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FSpeedScaledAxisOffsetData UpOffsetData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FVector2D UpPositiveForwardOffsetMultiplierBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Offset")
	FVector2D UpNegativeForwardOffsetMultiplierBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|FOV")
	float FOVInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|FOV")
	FVector2D FOVBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Boost")
	UCurveFloat* BoostCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Config|Boost")
	FScalableFloat BoostModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Boost")
	float AttachBoostDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Boost")
	float AttachBoostMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Boost")
	float DetachBoostDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Boost")
	float DetachBoostMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Sliding")
	UCurveFloat* SlidingHeightCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Sliding")
	FGameplayTag SlidingGameplayTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Sliding")
	float SlideHeightTransitionDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Config|Sliding")
	float MaxSlidingSpeedMultiplierOffset;

protected:
	UFUNCTION(BlueprintNativeEvent)
	void CalculateDynamicMultipliers(float& OutFOVBoundsMultiplier, float& OutBoostOffsetMultiplier) const;

	UFUNCTION()
	void RemoveSelfFromCameraManager();

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCameraModifier_Swinging")
	AFortPlayerPawnAthena* CachedPlayer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCameraModifier_Swinging")
	AFortWeaponRangedDualSwing* CachedWeapon;

};

