// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimationBlueprintLibraryCustomization.generated.h"

USTRUCT(BlueprintType)
struct FLogicTreeBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FLogicTreeBranch : public FLogicTreeBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FLogicTreeLeaf : public FLogicTreeBase
{
	GENERATED_BODY()

};

