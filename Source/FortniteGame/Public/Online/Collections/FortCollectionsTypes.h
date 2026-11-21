// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "FortCollectionsTypes.generated.h"

UENUM(BlueprintType)
enum class EFortCollectedState : uint8
{
	/** Not collected and not known to player */
	Unknown = 0,
	/** Not collected but known to player, state not yet seen by player */
	New = 1,
	/** Not collected but known to player, state seen by player */
	Known = 2,
	/** Collected, state not yet seen by player */
	NewlyCollected = 3,
	/** Collected and seen by player */
	Collected = 4,
	/** New personal best */
	NewBest = 5,
	/** New record amongst friends */
	NewRecord = 6,
	/** A new location is found and not seen by player */
	NewLocation = 7,
	/** Has been completed and not seen yet by player */
	NewlyCompleted = 8,
	/** All completed and player has seen */
	Complete = 9,
};

UENUM()
enum class EFortCollectedVariantClientUpdate : int32
{
	NewVariant = 0,
	CollectedCount = 1,
	Improvement = 2,
	HiddenImprovement = 3,
};

USTRUCT()
struct FFortMcpCollectedItemProperties
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString VariantTag;

	UPROPERTY()
	TArray<FString> ContextTags;

	UPROPERTY()
	FJsonObjectWrapper Properties;

	UPROPERTY()
	EFortCollectedState SeenState;

	UPROPERTY()
	int32 Count;

};

