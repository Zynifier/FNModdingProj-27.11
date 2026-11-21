// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_PredictiveSlopeWarping.h"
#include "FortAnimGraphNode_PredictiveSlopeWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_PredictiveSlopeWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_PredictiveSlopeWarping Node;

};

