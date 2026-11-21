// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_AttackIK.h"
#include "FortAnimGraphNode_AttackIK.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_AttackIK : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_AttackIK Node;

};

