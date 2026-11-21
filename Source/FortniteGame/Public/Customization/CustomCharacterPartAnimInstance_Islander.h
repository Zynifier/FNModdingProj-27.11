// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Islander.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Islander : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector GravityOverride_SwimSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector GravityOverride_SkyDiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector GravityOverride_NormalGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector2D ThighRotationUpRight_MinMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector2D ThighRotationUpLeft_MinMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector2D KneeRotationUpRight_MinMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Islander|Settings")
	FVector2D KneeRotationUpLeft_MinMax;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Islander")
	float ThighRotationUpRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Islander")
	float ThighRotationUpLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Islander")
	float KneeRotationUpRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Islander")
	float KneeRotationUpLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Islander")
	FVector GravityOverride;

};

