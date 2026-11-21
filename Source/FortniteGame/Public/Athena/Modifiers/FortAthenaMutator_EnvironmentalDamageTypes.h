// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaMutator_EnvironmentalDamageTypes.generated.h"

UENUM(BlueprintType)
enum class EBuildingDamageTeamFilter : uint8
{
	Default = 0 UMETA(DisplayName="All"),
	OwnerOnly = 1 UMETA(DisplayName="Self Built"),
	TeamOnly = 2 UMETA(DisplayName="Team Built"),
	EnemyOnly = 3 UMETA(DisplayName="Enemy Built"),
	EnemyAndOwnerOnly = 4 UMETA(DisplayName="Enemy And Self Built"),
	None = 5,
};

UENUM(BlueprintType)
enum class EEnvironmentDamageFilter : uint8
{
	Off = 0,
	PlayerBuiltOnly = 1,
	All = 2,
};

