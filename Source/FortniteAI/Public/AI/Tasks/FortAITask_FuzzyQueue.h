// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/AITask_MoveTo.h"
#include "FortAITask_FuzzyQueue.generated.h"

UCLASS()
class UFortAITask_FuzzyQueue : public UAITask_MoveTo
{
	GENERATED_BODY()

public:
	UFortAITask_FuzzyQueue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

