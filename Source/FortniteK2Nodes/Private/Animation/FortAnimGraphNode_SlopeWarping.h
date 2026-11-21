// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_SlopeWarping.h"
#include "FortAnimGraphNode_SlopeWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_SlopeWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_SlopeWarping Node;

};

