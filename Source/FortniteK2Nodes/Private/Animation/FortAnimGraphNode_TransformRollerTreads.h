// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_TransformRollerTreads.h"
#include "FortAnimGraphNode_TransformRollerTreads.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_TransformRollerTreads : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_TransformRollerTreads Node;

};

