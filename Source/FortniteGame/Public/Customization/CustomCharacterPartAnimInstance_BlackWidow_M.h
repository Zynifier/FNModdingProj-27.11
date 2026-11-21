// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_BlackWidow_M.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_BlackWidow_M : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FRotator BackpackRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapOutputRange;

};

