// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "Animation/FortAnimNode_ScaleHuskBones.h"
#include "FortAnimGraphNode_ScaleHuskBones.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_ScaleHuskBones : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_ScaleHuskBones ScaleNode;

};

