// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectiveProcessor.generated.h"

UCLASS(Abstract, NotBlueprintable)
class FORTNITEGAME_API UObjectiveProcessorBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class FORTNITEGAME_API UObjectiveProcessor : public UObjectiveProcessorBase
{
	GENERATED_BODY()

};

