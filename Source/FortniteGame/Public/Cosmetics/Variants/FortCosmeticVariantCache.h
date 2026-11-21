// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticVariantCache.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FCosmeticVariantCache
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefFor;

};

