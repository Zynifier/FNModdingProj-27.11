// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/AthenaNavMesh.h"
#include "AthenaNavMesh_Big.generated.h"

UCLASS(MinimalAPI, HideCategories=("Input", "Rendering", "Tags", "Transformation", "Actor", "Layers", "Replication"))
class AAthenaNavMesh_Big : public AAthenaNavMesh
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	float MaximumDistanceToWaterForShallow;

};

