// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "ObjectiveDebugger.generated.h"

USTRUCT()
struct FFilterMessageEventStateArgs
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FilterMessageEventStateArgs")
	FString EventName;

	UPROPERTY(VisibleAnywhere, Category="FilterMessageEventStateArgs")
	FString FailReason;

	UPROPERTY(VisibleAnywhere, Category="FilterMessageEventStateArgs")
	FInstancedStruct EventCache;

};

