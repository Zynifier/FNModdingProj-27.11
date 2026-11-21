// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralScatter2DPoint.h"
#include "ProceduralScatterGeneratorTile.generated.h"

class UProceduralScatterGenerator;

/**
 *	Procedurally determines where to spawn points within a discrete area.
 *	Generally, a procedural scatter generation as a whole is composed of multiple tiles.
 *	Tiles are able to overlap one another as well to create a seamless appearance.
 *	Once generated, GetTilePoints can be called to returns scattered points
 */
UCLASS()
class PROCEDURAL_API UProceduralScatterGeneratorTile : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UProceduralScatterGenerator> Generator;

	UPROPERTY()
	TArray<FProceduralScatter2DPoint> GeneratedPoints;

};

