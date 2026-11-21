// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortCharacterCosmeticManager.generated.h"

UENUM()
enum class EManagedCosmeticType : uint8
{
	Glider = 0,
	GliderAnimSet = 1,
	Pickaxe = 2,
	Pet = 3,
	ItemWrap = 4,
	Charm = 5,
	MAX_COUNT = 6 UMETA(Hidden),
};

UCLASS()
class UFortCharacterCosmeticManager : public UWorldSubsystem
{
	GENERATED_BODY()

};

