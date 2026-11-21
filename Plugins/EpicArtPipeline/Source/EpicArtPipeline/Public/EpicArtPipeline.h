// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicArtPipeline.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAppExecutionRequested);

USTRUCT(BlueprintType)
struct FEpicArtApp
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="EpicArtApp")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category="EpicArtApp")
	FString Tooltip;

	UPROPERTY(BlueprintReadWrite, Category="EpicArtApp")
	FString Section;

	UPROPERTY(BlueprintAssignable)
	FOnAppExecutionRequested AppDelegate;

};

