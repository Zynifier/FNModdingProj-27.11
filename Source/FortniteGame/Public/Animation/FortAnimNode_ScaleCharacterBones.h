// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "FortAnimNode_ScaleCharacterBones.generated.h"

USTRUCT()
struct FBoneReferenceScale
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FFortAnimNode_ScaleCharacterBones : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

};

