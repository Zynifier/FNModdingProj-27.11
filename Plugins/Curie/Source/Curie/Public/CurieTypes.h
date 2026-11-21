// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "CurieTypes.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct CURIE_API FCurieEffectContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CurieEffectContainer")
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditDefaultsOnly, Category="CurieEffectContainer")
	TSubclassOf<UGameplayEffect> GameplayEffect;

};

USTRUCT(BlueprintType)
struct CURIE_API FCurieElementHandle
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct CURIE_API FCurieStateHandle
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class CURIE_API UCurieElementGameplayEffectOwner : public UObject
{
	GENERATED_BODY()

};

