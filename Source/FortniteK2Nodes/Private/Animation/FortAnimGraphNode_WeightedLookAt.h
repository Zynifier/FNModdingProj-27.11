// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_WeightedLookAt.h"
#include "FortAnimGraphNode_WeightedLookAt.generated.h"

UCLASS(MinimalAPI, meta=(Keywords="Look At, Follow, Trace, Track"))
class UFortAnimGraphNode_WeightedLookAt : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimGraphNode_WeightedLookAt")
	FFortAnimNode_WeightedLookAt Node;

};

