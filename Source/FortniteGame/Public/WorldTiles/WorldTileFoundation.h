// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingFoundation.h"
#include "WorldTileFoundation.generated.h"

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class AWorldTileFoundation : public ABuildingFoundation
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Replicated)
	uint8 NumRotations;

};

