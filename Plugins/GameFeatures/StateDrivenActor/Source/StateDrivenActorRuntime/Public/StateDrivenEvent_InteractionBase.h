// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_InteractionBase.generated.h"

USTRUCT(BlueprintType, meta=(Hidden))
struct STATEDRIVENACTORRUNTIME_API FStateDrivenEvent_InteractionBase : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_InteractionBase")
	FStateDrivenTagQuery PlayerTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_InteractionBase")
	FText InteractionStringOverride;

};

