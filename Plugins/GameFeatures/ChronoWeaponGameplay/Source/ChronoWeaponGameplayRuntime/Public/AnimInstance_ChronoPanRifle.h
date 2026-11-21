// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance_ChronoPanRifle.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class CHRONOWEAPONGAMEPLAYRUNTIME_API UAnimInstance_ChronoPanRifle : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimInstance_ChronoPanRifle")
	bool bIsFiring;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimInstance_ChronoPanRifle")
	bool bIsReloading;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimInstance_ChronoPanRifle")
	float MagRotationValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimInstance_ChronoPanRifle")
	FName ResetMagRotationCurveName;

};

