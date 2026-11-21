// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "Engine/EngineTypes.h"
#include "FortAnimNode_AttackIK.generated.h"

USTRUCT()
struct FAttackIKHandsDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Attack IK")
	FBoneReference IKHandBone;

	UPROPERTY(EditAnywhere, Category="Attack IK")
	FBoneReference AttackTargetBone;

	UPROPERTY(EditAnywhere, Category="Attack IK")
	float TargetBoneOffset;

	UPROPERTY(EditAnywhere, Category="Attack IK")
	FName HandOnGroundCurveName;

};

USTRUCT()
struct FFortAnimNode_AttackIK : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Attack IK", meta=(DisplayName="IK Hand Root Bone"))
	FBoneReference IKHandRootBone;

	UPROPERTY(EditAnywhere, Category="Attack IK", meta=(DisplayName="Hand Bones"))
	TArray<FAttackIKHandsDefinition> HandsDefinitions;

	UPROPERTY(EditAnywhere, Category="Attack IK")
	TEnumAsByte<ECollisionChannel> HandTraceChannel;

	UPROPERTY(EditAnywhere, Category="Attack IK")
	float MaxCastLength;

};

