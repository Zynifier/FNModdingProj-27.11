// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNodes/AnimNode_Slot.h"
#include "FortAnimNode_CurveFilterSlot.generated.h"

UENUM()
enum class ECurveFilterSlotMode : uint8
{
	Open = 0 UMETA(DisplayName="Open (Only blocks listed Curves)"),
	Closed = 1 UMETA(DisplayName="Closed (Only allows listed Curves)"),
};

USTRUCT()
struct FFortAnimNode_CurveFilterSlot : public FAnimNode_Slot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FName MontageSlotName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	ECurveFilterSlotMode FilterMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	TArray<FName> CurveNames;

};

