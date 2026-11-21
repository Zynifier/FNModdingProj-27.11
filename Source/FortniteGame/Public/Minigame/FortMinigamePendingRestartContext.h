// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMinigamePendingRestartContext.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFortMinigamePendingRestartContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortMinigamePendingRestartContext")
	bool bPendingRestart;

	UPROPERTY(BlueprintReadWrite, Category="FortMinigamePendingRestartContext")
	TObjectPtr<AActor> EventOwner;

};

