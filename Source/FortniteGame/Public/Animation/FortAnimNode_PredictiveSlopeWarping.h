// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "Engine/EngineTypes.h"
#include "Animation/FortAnimNode_SlopeWarping.h"
#include "FortAnimNode_PredictiveSlopeWarping.generated.h"

USTRUCT()
struct FFortAnimNode_PredictiveSlopeWarping : public FFortAnimNode_SlopeWarping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="IK Left Foot Prediction Bone"))
	FBoneReference LFootPrediction;

	UPROPERTY(EditAnywhere, Category="Slope Warping", meta=(DisplayName="IK Right Foot Prediction Bone"))
	FBoneReference RFootPrediction;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	float MaxMovementDistBeforeNewTrace;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	TEnumAsByte<ECollisionChannel> FootTraceChannel;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	uint8 bCorrectForMeshOffset : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping")
	uint8 bUseWorldGravityDirectionForOffset : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Foot Anim Curve")
	uint8 bAbsentCurveMeansFootDown : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Foot Anim Curve", meta=(DisplayName="IK Left Foot On Ground Anim Curve Name"))
	FName LFootOnGroundCurveName;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Foot Anim Curve")
	uint8 bLeftCurveHighMeansFootDown : 1;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Foot Anim Curve", meta=(DisplayName="IK Right Foot On Ground Anim Curve Name"))
	FName RFootOnGroundCurveName;

	UPROPERTY(EditAnywhere, Category="Slope Warping | Foot Anim Curve")
	uint8 bRightCurveHighMeansFootDown : 1;

};

