// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayMessageTypes.generated.h"

// Match rule for message receivers

UENUM(BlueprintType)
enum class EGameplayMessageMatchType : uint8
{
	// An exact match will only receive messages with exactly the same channel
// (e.g., registering for "A.B" will match a broadcast of A.B but not A.B.C)

	ExactMatch = 0,
	// A partial match will receive any messages rooted in the same channel
// (e.g., registering for "A.B" will match a broadcast of A.B as well as A.B.C)

	PartialMatch = 1,
};

/**
* Wrapper of FGameplayTag for use in GameplayMessages which enforces a root prefix in the tag's hierarchy.
* Automatically filters searches in blueprint to only contain tags with this prefix.
* Required prefix: EventMessage
*/
USTRUCT(BlueprintType, meta=(Categories="EventMessage", HasNativeMake))
struct GAMEPLAYMESSAGES_API FEventMessageTag : public FGameplayTag
{
	GENERATED_BODY()

};

UCLASS(meta=(ScriptName="EventMessageTagLibrary"))
class GAMEPLAYMESSAGES_API UBlueprintEventMessageTagLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Converts an FGameplayTag to an FEventMessageTag.
	 * This is intended to support calling base FGameplayTag functions which have the base return type on an already existing FEventMessageTag.
	 * This SHOULD NOT be used as a way to cast from random other FGameplayTags.
	 *
	 * @param	InTag The tag to convert
	 * @return	Will return the corresponding FEventMessageTag or an empty one if InTag does not contain the required prefix.
	 */
	UFUNCTION(BlueprintPure, Category="GameplayMessages")
	static FEventMessageTag GetEventMessageTagFromGameplayTag(FGameplayTag InTag);

};

