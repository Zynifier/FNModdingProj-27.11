// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "Engine/SpringInterpolator.h"
#include "Animation/FortAnimNode_SlopeWarping.h"
#include "FortAnimNode_QuadrupedSlopeWarping.generated.h"

USTRUCT()
struct FFortAnimNode_QuadrupedSlopeWarping : public FFortAnimNode_SlopeWarping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FBoneReference SkeletonRootBone;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FBoneReference ArmsRootBone;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FBoneReference ArmsIKFootRootBone;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	TArray<FFortSlopeWarpingFootDefinition> ArmsFeetDefinitions;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	int32 NumSpineBones;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FVectorRK4SpringInterpolator ArmsRootBoneOffsetInterpolator;

	UPROPERTY(Transient)
	TArray<FFortSlopeWarpingFootData> ArmsFeetData;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayAfter="Pull Limbs Root Bone Down"))
	float MaxMovementDistBeforeNewTrace;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayAfter="Pull Limbs Root Bone Down"))
	uint8 bUseMovementComponentFloorInfoInsteadOfTraces : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayAfter="Pull Limbs Root Bone Down"))
	uint8 bOnlyAffectSkeletonRootBone : 1;

};

