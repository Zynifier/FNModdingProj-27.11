// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "FortAnimNode_GrindRailSlopeWarping.h"
#include "FortAnimGraphNode_GrindRailSlopeWarping.generated.h"

UCLASS(MinimalAPI)
class UFortAnimGraphNode_GrindRailSlopeWarping : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	FFortAnimNode_GrindRailSlopeWarping Node;

};

