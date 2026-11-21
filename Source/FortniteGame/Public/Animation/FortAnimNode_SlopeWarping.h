// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "Engine/SpringInterpolator.h"
#include "Math/MathFwd.h"
#include "FortAnimNode_SlopeWarping.generated.h"

USTRUCT()
struct FFortSlopeWarpingFootData
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSlopeWarpingFootDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference IKFootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference FKFootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 NumBonesInLimb;

};

USTRUCT()
struct FFortAnimNode_SlopeWarping : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Legs Root Bone"))
	FBoneReference PelvisBone;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Legs IK Foot Root Bone"))
	FBoneReference IKFootRootBone;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Legs Feet Definitions"))
	TArray<FFortSlopeWarpingFootDefinition> FeetDefinitions;

	UPROPERTY(Transient)
	TArray<FFortSlopeWarpingFootData> FeetData;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Legs Root Bone Offset Interpolator"))
	FVectorRK4SpringInterpolator PelvisOffsetInterpolator;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(PinHiddenByDefault))
	FVector GravityDir;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Biped Only", meta=(PinHiddenByDefault))
	FVector CustomFloorOffset;

	UPROPERTY(Transient)
	float CachedDeltaTime;

	UPROPERTY(Transient)
	FVector TargetFloorNormalWorldSpace;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FVectorRK4SpringInterpolator FloorNormalInterpolator;

	UPROPERTY(Transient)
	FVector TargetFloorOffsetLocalSpace;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	FVectorRK4SpringInterpolator FloorOffsetInterpolator;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(PinHiddenByDefault))
	bool bUseFloorOffsetInterpolator;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	float MaxStepHeight;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Biped Only")
	uint8 bKeepMeshInsideOfCapsule : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Pull Limbs Root Bone Down"))
	uint8 bPullPelvisDown : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="Maximum Downward Limb Root Pull Distance"))
	float PullPelvisDownMaxDistance;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Biped Only", meta=(PinHiddenByDefault))
	uint8 bUseCustomFloorOffset : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(PinHiddenByDefault))
	uint8 bShouldAdjustRootBone : 1;

	UPROPERTY(Transient)
	uint8 bWasOnGround : 1;

	UPROPERTY(Transient)
	uint8 bShowDebug : 1;

	UPROPERTY(Transient)
	uint8 bFloorSmoothingInitialized : 1;

	UPROPERTY(Transient)
	uint8 bRequiresMovementComponentToEvaluateAsValid : 1;

	UPROPERTY(Transient)
	FVector ActorLocation;

protected:
	UPROPERTY(Transient)
	FVector GravityDirCompSpace;

};

