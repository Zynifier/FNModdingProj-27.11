// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HoneydewBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HoneydewBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float ThighRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float ThighRotationRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float HeadRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float ClavicleLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float ClavicleRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float SkirtDynAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewBody")
	float IsCrouchingAndStillAlpha;

};

