// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingPrivateConfig.generated.h"

USTRUCT(BlueprintType)
struct FFortMatchmakingPrivateConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ServerFleetPlaylistOverride;

};

