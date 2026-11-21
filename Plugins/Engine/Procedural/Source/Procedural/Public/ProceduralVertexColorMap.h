// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDataMap.h"
#include "ProceduralTextureColorChannel.h"
#include "ProceduralVertexColorMap.generated.h"

UCLASS(MinimalAPI, HideCategories=("Object", "Object"), AutoExpandCategories=("Source", "DataMapping"))
class UProceduralVertexColorMap : public UProceduralFloatDataMap
{
	GENERATED_BODY()

public:
	/** Color Channel to read from static mesh's Vertex Color. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Source")
	EProceduralTextureColorChannel Channel;

};

