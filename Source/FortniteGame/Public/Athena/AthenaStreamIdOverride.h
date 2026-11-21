// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaStreamIdOverride.generated.h"

USTRUCT()
struct FAthenaStreamIdOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SourceName;

	UPROPERTY()
	FString OverriddenId;

};

