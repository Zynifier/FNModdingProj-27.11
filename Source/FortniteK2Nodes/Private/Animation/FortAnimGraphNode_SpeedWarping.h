// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_SpeedWarping.h"
#include "FortAnimGraphNode_SpeedWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_SpeedWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_SpeedWarping Node;

};

