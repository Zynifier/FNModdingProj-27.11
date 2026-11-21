// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNodes/AnimNode_Slot.h"
#include "FortAnimNode_NoBlendCurveSlot.generated.h"

USTRUCT()
struct FFortAnimNode_NoBlendCurveSlot : public FAnimNode_Slot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName MontageSlotName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	TArray<FName> CurveNames;

};

