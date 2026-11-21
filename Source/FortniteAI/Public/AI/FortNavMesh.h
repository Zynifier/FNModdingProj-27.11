// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavMesh/RecastNavMesh.h"
#include "FortNavMesh.generated.h"

class UFortAIHotSpotManager;

UCLASS(MinimalAPI, HideCategories=("Input", "Rendering", "Tags", "Transformation", "Actor", "Layers", "Replication"))
class AFortNavMesh : public ARecastNavMesh
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortAIHotSpotManager> HotspotManager;

};

