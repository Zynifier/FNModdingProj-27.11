// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HightowerTapasBody.generated.h"

class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HightowerTapasBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	TSoftObjectPtr<UAnimMontage> TapasDanceMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	FVector WindVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float CrouchingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float ElbowRightAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float ElbowLeftAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float LatStretchRightAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float IsWearingCapeAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float HalfIsWearingCapeAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasBody")
	float TapasMontageAlpha;

};

