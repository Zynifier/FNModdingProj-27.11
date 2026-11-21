// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortComponentPropertyProxy.generated.h"

USTRUCT(BlueprintType)
struct FFortComponentPropertyProxy
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortComponentPropertyProxy")
	FString PropertyPath;
#endif

};

