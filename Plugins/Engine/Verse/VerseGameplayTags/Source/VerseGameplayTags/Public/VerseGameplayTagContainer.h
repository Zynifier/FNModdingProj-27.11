// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseGameplayTag.h"
#include "VerseGameplayTagContainer.generated.h"

/**
 * Custom derivation of FVerseGameplayTagContainer which allows special case handling of details customization 
 * and tag filtering when presenting verse tags in editor. Also provides abstraction allowing underlying implementaiton
 * to be switched out if require at a later date
 */
USTRUCT()
struct VERSEGAMEPLAYTAGS_API FVerseGameplayTagContainer
{
	GENERATED_BODY()

private:
	// For now allow direct access - but later may want to provide details customization that provides a User friendly layer between UI and this underlying data

	UPROPERTY(EditAnywhere, Category="Tags")
	TArray<FVerseGameplayTag> InternalTags;

};

