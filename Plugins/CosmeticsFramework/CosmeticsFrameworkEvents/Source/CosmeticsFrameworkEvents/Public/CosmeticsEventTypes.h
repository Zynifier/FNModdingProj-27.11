// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticsEventTypes.generated.h"

UENUM(BlueprintType, meta=(Bitflags))
enum class ECosmeticsEventBindingFlags : uint8
{
	None = 0 UMETA(Hidden),
	/** If the corresponding event is not blocked, then execute the delegate immediately */
	ExecuteImmediately = 2,
	/**
	 * Only run the delegate once. If the delegate is bound with both ExecuteImmediately and ExecuteOnce and the event
	 * is not blocked, then the delegate will *only* run immediately and not on subsequent broadcasts.
	 */
	ExecuteOnce = 4,
};

USTRUCT(BlueprintType)
struct FCosmeticsEventHandle
{
	GENERATED_BODY()

};

