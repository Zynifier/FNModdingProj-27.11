// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_EndOverlap.generated.h"

USTRUCT(meta=(DisplayName="EndOverlap"))
struct FStateDrivenEvent_EndOverlap : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_EndOverlap")
	FStateDrivenTagQuery OverlappingActorTagQuery;

};

