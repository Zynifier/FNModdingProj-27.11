// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Rebirth_Soldier_M.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Rebirth_Soldier_M : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ArmRightRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ArmLeftRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ClavicleRightRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ClavicleLeftRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float HeadRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float CalfRightRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float CalfLeftRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ThighRightRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float ThighLeftRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	float WeaponRaisedAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Rebirth_Soldier_M")
	bool bIsWearingBackbling;

};

