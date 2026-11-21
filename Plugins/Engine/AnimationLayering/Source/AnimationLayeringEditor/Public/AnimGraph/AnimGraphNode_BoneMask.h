// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_BlendListBase.h"
#include "AnimNode_BoneMask.h"
#include "AnimGraphNode_BoneMask.generated.h"

UCLASS(MinimalAPI)
class UAnimGraphNode_BoneMask : public UAnimGraphNode_BlendListBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FAnimNode_BoneMask Node;

};

