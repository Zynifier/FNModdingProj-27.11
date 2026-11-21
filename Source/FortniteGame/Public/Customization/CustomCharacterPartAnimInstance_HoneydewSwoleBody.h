// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HoneydewSwoleBody.generated.h"

class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HoneydewSwoleBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	TSoftObjectPtr<UAnimMontage> MusclesLobbyMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float ThighRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float ThighRotationRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float ElbowRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float ElbowRotationRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float UpperarmRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float UpperarmRotationRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float EmoteAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HoneydewSwoleBody")
	float MusclesPosition;

};

