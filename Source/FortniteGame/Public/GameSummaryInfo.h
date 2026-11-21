// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameSummaryInfo.generated.h"

USTRUCT(BlueprintType)
struct FGameSummaryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameSummaryInfo")
	FString GameSessionID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameSummaryInfo")
	bool Completed;

};

