// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAccoladeTypes.generated.h"

UENUM()
enum class EFortAccoladeSubtype : uint8
{
	NotSet = 0,
	// This accolade type is not set (or undefined)

	Action = 1,
	Discovery = 2,
	XpToken = 3,
};

UENUM(BlueprintType)
enum class EFortAccoladeType : uint8
{
	Acknowledgement = 0,
	// you did a thing

	Accolade = 1,
	// that was kinda cool

	Medal = 2,
};

UENUM(BlueprintType)
enum class EXPEventPriorityType : uint8
{
	// This means it will show up in the near-reticle pop up before going to the feed

	NearReticle = 0,
	// this means it won't show up anywhere but the XP bar

	XPBarOnly = 1,
	// this means it will show up in the top center slot before going to the feed

	TopCenter = 2,
	// This means it only shows up in the feed before going to the XP bar

	Feed = 3,
};

USTRUCT(BlueprintType)
struct FAccoladeSecondaryXpType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AccoladeSecondaryXpType")
	FGameplayTag Type;

	UPROPERTY(EditAnywhere, Category="AccoladeSecondaryXpType")
	FScalableFloat XpAmount;

};

