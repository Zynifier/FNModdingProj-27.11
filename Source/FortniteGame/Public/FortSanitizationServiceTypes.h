// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSanitizationServiceTypes.generated.h"

class UAsyncTaskQueue;

USTRUCT()
struct FSanitizationData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UAsyncTaskQueue> TaskQueue;

};

USTRUCT()
struct FSanitizedEntry
{
	GENERATED_BODY()

};

