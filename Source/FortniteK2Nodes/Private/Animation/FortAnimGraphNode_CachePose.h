// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_CachePose.h"
#include "FortAnimGraphNode_CachePose.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_CachePose : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_CachePose Node;

};

