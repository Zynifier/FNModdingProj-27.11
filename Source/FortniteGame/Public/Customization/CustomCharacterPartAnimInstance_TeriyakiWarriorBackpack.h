// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_TeriyakiWarriorBackpack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector PistonJitterA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector PistonJitterB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector PistonJitterC;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector PistonJitterD;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector StretchA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector StretchB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector StretchC;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	FVector StretchD;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_TeriyakiWarriorBackpack")
	float FallingAlpha;

};

