// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AthenaSeasonItemTypes.generated.h"

UENUM(BlueprintType)
enum class EAthenaSeasonMapIconState : uint8
{
	// Not discovered by the player

	Unknown = 0,
	// Found by the player, but not interacted with

	Found = 1,
	// Found and interacted with by the player

	Interacted = 2,
};

USTRUCT(BlueprintType)
struct FAthenaSeasonItemMCPState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemMCPState")
	FString ItemTag;

	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemMCPState")
	EAthenaSeasonMapIconState MapIconState;

};

USTRUCT(BlueprintType)
struct FAthenaSeasonItemRuntimeState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemRuntimeState")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemRuntimeState")
	EAthenaSeasonMapIconState MapIconState;

};

