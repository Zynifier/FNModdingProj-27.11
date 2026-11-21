// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "StateDrivenEvent.h"
#include "StateDrivenFloat.h"
#include "StateDrivenEvent_Timer.generated.h"

USTRUCT(meta=(DisplayName="Timer"))
struct FStateDrivenEvent_Timer : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_Timer")
	FStateDrivenFloat Duration;

	UPROPERTY(BlueprintReadWrite, Category="StateDrivenEvent_Timer")
	FTimerHandle TimerTransitionEventHandle;

};

