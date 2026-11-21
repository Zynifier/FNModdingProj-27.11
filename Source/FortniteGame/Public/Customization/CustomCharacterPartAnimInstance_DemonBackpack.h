// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_DemonBackpack.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_DemonBackpack : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DemonBackpack")
	float SprintSpeedRemap;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DemonBackpack")
	float PlayerForwardAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DemonBackpack")
	float PlayerSidewaysAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DemonBackpack")
	float DynamicsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_DemonBackpack")
	float RunSpeedRemap;

};

