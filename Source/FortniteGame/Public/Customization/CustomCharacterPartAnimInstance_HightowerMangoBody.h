// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HightowerMangoBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HightowerMangoBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	FVector GravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	FVector VectorForce;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	float ClothAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	float FrontEndRearAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	float ThighRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	float ThighRotationRight;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_HightowerMangoBody")
	bool bIsWearingLongCape;

};

