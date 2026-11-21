// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectApplicationInfo.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FGameplayEffectApplicationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AbilitySet", meta=(AssetBundles="ItemDetails,Equipped"))
	TSoftClassPtr<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	float Level;

};

USTRUCT(BlueprintType)
struct FGameplayEffectApplicationInfoHard
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	float Level;

};

