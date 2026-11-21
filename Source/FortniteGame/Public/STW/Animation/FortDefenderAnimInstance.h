// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAIAnimInstance.h"
#include "FortGender.h"
#include "FortDefenderAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortDefenderAnimInstance : public UFortAIAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="AI")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	uint8 bShouldWalkRightFootForward : 1;

	UPROPERTY(BlueprintReadOnly, Category="Weapon")
	uint8 bIsChargingWeapon : 1;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float SpeedAdjustedPlayRate;

	UPROPERTY(EditAnywhere, Category="Movement")
	float AuthoredJogSpeed;

	UPROPERTY(EditAnywhere, Category="Movement")
	float AuthoredWalkSpeed;

};

