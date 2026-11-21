// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "Animation/FortAnimNode_CurveFilterSlot.h"
#include "FortAnimGraphNode_CurveFilterSlot.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_CurveFilterSlot : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_CurveFilterSlot Node;

};

