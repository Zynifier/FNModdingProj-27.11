// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_AdjustedAim.generated.h"

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FFortAnimInput_AdjustedAimOffset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Aiming")
	float YawOffset;

	UPROPERTY(EditAnywhere, Category="Aiming")
	float PitchOffset;

	UPROPERTY(EditAnywhere, Category="Aiming")
	float TargetingYawOffset;

	UPROPERTY(EditAnywhere, Category="Aiming")
	float TargetingPitchOffset;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_AdjustedAim
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Aiming", meta=(ArraySizeEnum="/Script/FortniteGame.EFortWeaponCoreAnimation"))
	FFortAnimInput_AdjustedAimOffset WeaponOffsets[35];

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float YawOffset;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float PitchOffset;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float YawScale;

	UPROPERTY(EditDefaultsOnly, Category="Aiming")
	float PitchScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ResultingYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ResultingPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aiming")
	FName ZeroOutPitchWeightCurveName;

private:
	UPROPERTY(Transient)
	float ReloadPitchBlendOutTime;

	UPROPERTY(Transient)
	float ReloadPitchBlendAlpha;

	UPROPERTY(Transient)
	uint8 bIsReloading : 1;

};

