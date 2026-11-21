// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_Flap.h"
#include "FortAnimGraphNode_Flap.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_Flap : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_Flap Node;

};

