// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstance_OstrichOccupant.h"
#include "FortPlayerAnimInstance_OstrichGunner.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_OstrichGunner : public UFortPlayerAnimInstance_OstrichOccupant
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerAnimInstance_OstrichGunner")
	float BodyRecoilAlphaValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float BodyRecoilAlphaWhenShotgunIsFired;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TunableAlphaValues")
	float BodyRecoilAlphaNoShotgunFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_OstrichGunner")
	uint8 bIsMechShotgunFired : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_OstrichGunner")
	uint8 bIsMechBeginFired : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_OstrichGunner")
	uint8 bIsRocketFiring : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Impact")
	FFortAnimInput_VelocityImpact GunnerVelocityImpactInput;

};

