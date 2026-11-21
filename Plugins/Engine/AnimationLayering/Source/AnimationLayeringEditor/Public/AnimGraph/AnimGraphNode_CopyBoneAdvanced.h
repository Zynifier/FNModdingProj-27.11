// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "BoneControllers/AnimNode_CopyBoneAdvanced.h"
#include "AnimGraphNode_CopyBoneAdvanced.generated.h"

UCLASS(MinimalAPI)
class UAnimGraphNode_CopyBoneAdvanced : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	FAnimNode_CopyBoneAdvanced Node;

};

