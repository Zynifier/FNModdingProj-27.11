// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortGender.h"
#include "GameplayTagAnimation.generated.h"

class UAnimMontage;

USTRUCT()
struct FGameplayTagAnimationData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameplayTagAnimationData")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="GameplayTagAnimationData")
	TEnumAsByte<EFortCustomGender::Type> ValidGenders;

	UPROPERTY(EditAnywhere, Category="GameplayTagAnimationData")
	TSoftObjectPtr<UAnimMontage> AnimMontage;

};

USTRUCT(BlueprintType)
struct FGameplayTagAnimations
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameplayTagAnimations")
	TArray<FGameplayTagAnimationData> GameplayTagAnimData;

};

