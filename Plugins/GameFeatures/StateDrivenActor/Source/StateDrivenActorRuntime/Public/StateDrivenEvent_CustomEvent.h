// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateDrivenEvent.h"
#include "StateDrivenEvent_CustomEvent.generated.h"

USTRUCT(meta=(DisplayName="Custom Event"))
struct FStateDrivenEvent_CustomEvent : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_CustomEvent")
	FGameplayTag EventTag;

};

