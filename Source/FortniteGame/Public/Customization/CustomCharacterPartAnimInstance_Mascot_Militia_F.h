// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Mascot_Militia_F.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Mascot_Militia_F : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Mascot_Militia_F")
	float CalfLeftRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Mascot_Militia_F")
	float CalfRightRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Mascot_Militia_F")
	float SpeedAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Mascot_Militia_F")
	bool bBackIsStatic;

};

