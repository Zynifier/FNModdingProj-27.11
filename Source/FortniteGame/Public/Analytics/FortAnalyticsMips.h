// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextureDefines.h"
#include "FortAnalyticsMips.generated.h"

USTRUCT()
struct FCapMipsTextureGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<TextureGroup> Group;

	UPROPERTY()
	int32 MaxLODMipCount;

};

