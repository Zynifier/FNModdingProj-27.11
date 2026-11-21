// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/AthenaLTMTraversePoint.h"
#include "AthenaChromeTraversePoint.generated.h"

class AAthenaHoldingArea;

UCLASS(HideCategories=("AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "AI", "Foliage", "Input", "Rendering", "Team", "Interaction", "Movement", "Building", "Damage", "Navigation", "GridSnapping", "Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaChromeTraversePoint : public AAthenaLTMTraversePoint
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<AAthenaHoldingArea> HoldingArea;

};

