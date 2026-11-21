// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "SoundLibraryTag.generated.h"

/**
 *	FSoundLibraryTag - Simple wrapper for FGameplayTag that is auto-scoped to "SoundLibrary." tags
 */
USTRUCT(BlueprintType, meta=(Categories="SoundLibrary"))
struct FSoundLibraryTag : public FGameplayTag
{
	GENERATED_BODY()

};

/**
 *	USoundLibraryTagHelperFunctions - Helper functions to circumvent not being able to put UFUNCTION's inside USTRUCT's
 */
UCLASS()
class USoundLibraryTagHelperFunctions : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Sound Library")
	static FSoundLibraryTag MakeSoundLibraryTag(const FGameplayTag& Tag);

};

