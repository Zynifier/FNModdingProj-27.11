// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Tasks/AITask.h"
#include "FortAITask_AdjustToSlot.generated.h"

UCLASS()
class UFortAITask_AdjustToSlot : public UAITask
{
	GENERATED_BODY()

public:
	UFortAITask_AdjustToSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY()
	FVector SlotLocation;

	UPROPERTY()
	FVector SlotDirection;

};

