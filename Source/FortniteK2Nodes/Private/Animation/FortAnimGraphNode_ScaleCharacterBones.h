// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "Animation/FortAnimNode_ScaleCharacterBones.h"
#include "FortAnimGraphNode_ScaleCharacterBones.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_ScaleCharacterBones : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_ScaleCharacterBones Node;

};

