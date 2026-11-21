// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "Animation/FortAnimNode_AnimSetDrivenRandom.h"
#include "FortAnimGraphNode_RandomPetAnim.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_RandomPetAnim : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_AnimSetDrivenRandom Node;

};

