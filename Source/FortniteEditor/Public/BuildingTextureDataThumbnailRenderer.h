// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/TextureThumbnailRenderer.h"
#include "BuildingTextureDataThumbnailRenderer.generated.h"

UCLASS(Config=Editor)
class UBuildingTextureDataThumbnailRenderer : public UTextureThumbnailRenderer
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 DefaultSizeX;

	UPROPERTY(Config)
	int32 DefaultSizeY;

};

