// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomMatchOptions.generated.h"

USTRUCT()
struct FSavedCustomMatchOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FString> CustomMatchOptions;

};

