// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent_InteractionBase.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_InsertItem.generated.h"

USTRUCT(meta=(DisplayName="InsertItem"))
struct FStateDrivenEvent_InsertItem : public FStateDrivenEvent_InteractionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_InsertItem")
	FStateDrivenTagQuery EquippedItemTagQuery;

};

