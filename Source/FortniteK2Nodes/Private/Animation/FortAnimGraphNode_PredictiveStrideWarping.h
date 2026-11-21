// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_PredictiveStrideWarping.h"
#include "FortAnimGraphNode_PredictiveStrideWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_PredictiveStrideWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_PredictiveStrideWarping Node;

};

