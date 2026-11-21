// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticStatTypes.generated.h"

USTRUCT()
struct FFortCosmeticStatEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StatName;

	UPROPERTY()
	int32 StatValue;

};

