// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Rebirth_Soldier_F.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Rebirth_Soldier_F : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_F")
	float ThighLeftRotationAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_F")
	float ThighRightRotationAlpha;

};

