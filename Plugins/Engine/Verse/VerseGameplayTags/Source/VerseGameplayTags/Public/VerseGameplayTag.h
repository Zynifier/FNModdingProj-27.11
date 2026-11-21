// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseGameplayTag.generated.h"

class UVerseGameplayTagBase;

/**
 * Custom derivation of FVerseGameplayTag which allows special case handling of details customization
 * and tag filtering when presenting verse tags in editor. Also provides abstraction allowing underlying implementation
 * to be switched out if require at a later date
 */
USTRUCT()
struct VERSEGAMEPLAYTAGS_API FVerseGameplayTag
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Tag")
	TSubclassOf<UVerseGameplayTagBase> InternalTag;

};

