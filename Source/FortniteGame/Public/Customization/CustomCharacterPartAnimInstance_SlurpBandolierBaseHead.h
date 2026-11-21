// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance_SlurpLegendsBase.h"
#include "CustomCharacterPartAnimInstance_SlurpBandolierBaseHead.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_SlurpBandolierBaseHead : public UCustomCharacterPartAnimInstance_SlurpLegendsBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_SlurpBandolierBaseHead")
	float WPOMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_SlurpBandolierBaseHead")
	FName MorphTargetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_SlurpBandolierBaseHead")
	bool bUpdateMaterialAO;

};

