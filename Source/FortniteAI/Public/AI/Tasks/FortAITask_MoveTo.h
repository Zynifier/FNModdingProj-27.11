// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/AITask_MoveTo.h"
#include "FortAITask_MoveTo.generated.h"

UCLASS(MinimalAPI)
class UFortAITask_MoveTo : public UAITask_MoveTo
{
	GENERATED_BODY()

public:
	UFortAITask_MoveTo(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

