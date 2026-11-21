// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "Animation/FortAnimNode_SlopeWarping.h"
#include "FortAnimNode_GrindRailSlopeWarping.generated.h"

USTRUCT()
struct GRINDRAILRUNTIME_API FFortAnimNode_GrindRailSlopeWarping : public FFortAnimNode_SlopeWarping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Grind Rail", meta=(ClampMin="0.000000", ForceUnits="cm", PinHiddenByDefault, UIMin="0.000000"))
	float BaseSplineRadius;

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

	UPROPERTY(EditAnywhere, Category="Slope Warping | Settings")
	FBoneReference LeftFootFKBone;

};

