// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_OrientationWarping.h"
#include "FortAnimGraphNode_OrientationWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_OrientationWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_OrientationWarping Node;

};

