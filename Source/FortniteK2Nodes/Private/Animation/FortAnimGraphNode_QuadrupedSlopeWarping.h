// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_QuadrupedSlopeWarping.h"
#include "FortAnimGraphNode_QuadrupedSlopeWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_QuadrupedSlopeWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_QuadrupedSlopeWarping Node;

};

