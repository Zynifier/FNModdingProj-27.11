// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "BoneControllers/AnimNode_CopyMotion.h"
#include "AnimGraphNode_CopyMotion.generated.h"

UCLASS(meta=(DevelopmentStatus="Experimental"))
class ANIMATIONLAYERINGEDITOR_API UAnimGraphNode_CopyMotion : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	FAnimNode_CopyMotion Node;

};

