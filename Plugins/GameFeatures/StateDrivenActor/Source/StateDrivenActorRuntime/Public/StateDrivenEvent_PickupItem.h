// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent_BeginOverlap.h"
#include "StateDrivenEvent_PickupItem.generated.h"

USTRUCT(meta=(DisplayName="PickupItem"))
struct FStateDrivenEvent_PickupItem : public FStateDrivenEvent_BeginOverlap
{
	GENERATED_BODY()

};

