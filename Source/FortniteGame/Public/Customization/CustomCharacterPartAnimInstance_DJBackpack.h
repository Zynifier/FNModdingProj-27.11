// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_DJBackpack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_DJBackpack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bIsKillCelebrationActive;

	UPROPERTY(Transient)
	int32 KillCountLastFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_DJBackpack")
	int32 KillCount;

	UPROPERTY(Transient)
	float CurrentSpinRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DJBackpack")
	FRotator BallRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float BaseSpinRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float SpinRateMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float DefaultSpinRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float DefaultSpinRateInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float KillCelebrationSpinRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	float KillCelebrationSpinRateInterpSpeed;

};

