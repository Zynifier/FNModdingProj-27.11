// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VkLaunchDataEnvelope.generated.h"

USTRUCT()
struct FVkLaunchData_JoinMatchmakingSession
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SessionId;

};

