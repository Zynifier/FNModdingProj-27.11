// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInstance.h"
#include "FortPushCannonAnimInstance.generated.h"

class AFortAthenaSKPushCannon;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPushCannonAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPushCannonAnimInstance")
	bool bHasDriver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPushCannonAnimInstance")
	bool bHasPassenger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	bool bIsCoolDownEnded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	bool bIsCannonFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaSKPushCannon> PushCannon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	FRotator CannonLocalRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	FRotator WheelSpinRotatorFR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	FRotator WheelSpinRotatorFL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	FRotator WheelSpinRotatorBR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PushCannon")
	FRotator WheelSpinRotatorBL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PushCannonTunables")
	float CooldownEndedOverheatThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PushCannonTunables")
	float OnFiredOverheatValue;

};

