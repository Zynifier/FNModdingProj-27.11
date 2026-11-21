// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenTagQuery_Simple.generated.h"

USTRUCT(meta=(DisplayName="Simple"))
struct FStateDrivenTagQuery_Simple : public FStateDrivenTagQuery_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenTagQuery_Simple")
	FGameplayTagQuery Query;

};

