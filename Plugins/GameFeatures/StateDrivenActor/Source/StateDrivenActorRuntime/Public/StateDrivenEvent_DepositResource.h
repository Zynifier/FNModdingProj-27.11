// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent_InteractionBase.h"
#include "StateDrivenEvent_DepositResource.generated.h"

class UFortItemDefinition;

USTRUCT(meta=(DisplayName="DepositResource"))
struct FStateDrivenEvent_DepositResource : public FStateDrivenEvent_InteractionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_DepositResource")
	TSoftObjectPtr<UFortItemDefinition> DepositItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_DepositResource")
	int32 DepositAmount;

};

