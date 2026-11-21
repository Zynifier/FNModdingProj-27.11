// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlayerViewModel.generated.h"

UENUM(BlueprintType)
enum class EFortHitPointModificationReason : uint8
{
	Invalid = 0 UMETA(Hidden),
	// The hit point value is being established for the first time

	InitalSet = 1,
	// Increased due to automatic regeneration

	AutoRegen = 2,
	// Increased from a distinct event (i.e. used an item)

	ItemRegen = 3,
	// Decreased due to damage over time effect

	DamageOverTime = 4,
	// Decreased due to distinct event (i.e. hit by enemy)

	DamageReceived = 5,
};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortPlayerViewModel : public UObject
{
	GENERATED_BODY()

};

