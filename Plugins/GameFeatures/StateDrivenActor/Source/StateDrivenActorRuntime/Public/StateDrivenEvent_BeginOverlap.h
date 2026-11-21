// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_BeginOverlap.generated.h"

USTRUCT(meta=(DisplayName="BeginOverlap"))
struct FStateDrivenEvent_BeginOverlap : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_BeginOverlap")
	FStateDrivenTagQuery OverlappingActorTagQuery;

};

