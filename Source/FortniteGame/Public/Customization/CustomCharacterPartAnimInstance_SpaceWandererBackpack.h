// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_SpaceWandererBackpack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_SpaceWandererBackpack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SpaceWandererBackpack")
	FRotator SpinnerRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SpaceWandererBackpack")
	float JumpAlpha;

};

