// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DevicesPlayStateContext.generated.h"

class APlayspace;

USTRUCT(BlueprintType)
struct FDevicesPlayStateContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DevicesPlayStateContext")
	bool bPlaying;

	UPROPERTY(BlueprintReadWrite, Category="DevicesPlayStateContext")
	TObjectPtr<APlayspace> EventOwner;

};

