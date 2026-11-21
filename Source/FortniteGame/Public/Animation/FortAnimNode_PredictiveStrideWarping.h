// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "Animation/InputScaleBias.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "Engine/SpringInterpolator.h"
#include "Math/MathFwd.h"
#include "FortAnimNode_PredictiveStrideWarping.generated.h"

UENUM(BlueprintType)
enum class EPredictiveStrideWarpingAxisMode : uint8
{
	IKFootRootLocalX = 0,
	IKFootRootLocalY = 1,
	IKFootRootLocalZ = 2,
	WorldSpaceVectorInput = 3,
	ComponentSpaceVectorInput = 4,
	ActorSpaceVectorInput = 5,
};

USTRUCT()
struct FPredictiveStrideWarpingFootData
{
	GENERATED_BODY()

};

USTRUCT()
struct FPredictiveStrideWarpingFootDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference IKFootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference FKFootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference IKPredictionFootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 NumBonesInLimb;

};

USTRUCT()
struct FFortAnimNode_PredictiveStrideWarping : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference IKFootRootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	TArray<FPredictiveStrideWarpingFootDefinition> FeetDefinitions;

	UPROPERTY(Transient)
	TArray<FPredictiveStrideWarpingFootData> FeetData;

	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference PelvisBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	EPredictiveStrideWarpingAxisMode PredictiveStrideWarpingAxisMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	EPredictiveStrideWarpingAxisMode FloorNormalAxisMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	EPredictiveStrideWarpingAxisMode GravityDirAxisMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinShownByDefault))
	float SpeedScaling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FInputScaleBiasClamp SpeedScalingScaleBiasClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinHiddenByDefault))
	FVector ManualPredictiveStrideWarpingDir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinHiddenByDefault))
	FVector ManualFloorNormalInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinHiddenByDefault))
	FVector ManualGravityDirInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float PelvisPostAdjustmentAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	int32 PelvisAdjustmentMaxIter;

	UPROPERTY(EditAnywhere, Category="Settings")
	FVectorRK4SpringInterpolator PelvisAdjustmentInterp;

	UPROPERTY(EditAnywhere, Category="Settings")
	uint8 bAdjustThighBonesRotation : 1;

	UPROPERTY(EditAnywhere, Category="Settings")
	uint8 bClampIKUsingFKLeg : 1;

	UPROPERTY(EditAnywhere, Category="Settings")
	uint8 bOrientPredictiveStrideWarpingAxisBasedOnFloorNormal : 1;

	UPROPERTY(Transient)
	float CachedDeltaTime;

};

