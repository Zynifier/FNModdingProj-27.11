// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_LookAt.h"
#include "FortAnimNode_WeightedLookAt.generated.h"

USTRUCT()
struct FWeightedLookAtBoneWeightDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeightedLookAtBoneWeightDefinition")
	float Weight;

};

USTRUCT()
struct FFortAnimNode_WeightedLookAt : public FAnimNode_LookAt
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SkeletalControl", meta=(DisplayAfter="BoneToModify"))
	TArray<FWeightedLookAtBoneWeightDefinition> BoneWeightsToApply;

};

