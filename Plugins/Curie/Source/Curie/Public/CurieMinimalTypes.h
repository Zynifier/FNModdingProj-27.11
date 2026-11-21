// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CurieMinimalTypes.generated.h"

UENUM()
enum class ECurieEntityType : uint8
{
	/** Invalid entity type */
	Invalid = 0,
	/** Material entities cannot cause state changes or be applied to other materials */
	Material = 1,
	/** Element entities can cause state changes on materials or other elements during their application */
	Element = 2,
};

USTRUCT(BlueprintType)
struct CURIE_API FCurieContainerHandle
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct CURIE_API FCurieInteractHandle
{
	GENERATED_BODY()

};

