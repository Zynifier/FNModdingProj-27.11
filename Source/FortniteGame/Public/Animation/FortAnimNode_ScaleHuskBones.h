// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "FortAnimNode_ScaleHuskBones.generated.h"

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FFortAnimNode_ScaleHuskBones : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Links")
	FPoseLink PreScalePose;

};

