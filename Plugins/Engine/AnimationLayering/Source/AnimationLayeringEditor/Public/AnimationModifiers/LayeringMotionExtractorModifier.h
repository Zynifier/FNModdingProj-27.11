// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimationModifier.h"
#include "MotionExtractorTypes.h"
#include "LayeringMotionExtractorModifier.generated.h"

/** Extracts motion from a bone in the animation and bakes it into a curve 
	or multiple curves. This modifier is meant to be used w/ the CopyMotion Anim Graph Node. */// @todo: Bake these to custom attributes or calculate at runtime instead.

UCLASS()
class ULayeringMotionExtractorModifier : public UAnimationModifier
{
	GENERATED_BODY()

public:
	/** Bone we are going to generate the curve from */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	FName BoneName;

	/** Bone which space we'll use as reference to generate this curve */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	FName BoneSpaceName;

	/** Type of motions to extract */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default", meta=(Bitmask, BitmaskEnum="/Script/AnimationModifierLibrary.EMotionExtractor_MotionType"))
	int32 MotionTypes;

	/** Axis to get the value from */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	EMotionExtractor_Axis Axis;

	/** Whether we want to remove the curve when we revert or re-apply modifier 
		Disabling this allows you to modify settings and create a new curve each time you re-apply the modifier
		Enabling this is the preferred setting when using a modifier that's applied in bulk and you may want to remove/rename curves */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	bool bRemoveCurveOnRevert;

	/** Whether to convert the final value to absolute (positive) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	bool bAbsoluteValue;

	// @todo: This crashes with certain orders, and certain configurations of curves. Figure out why.
// Whether to apply any filter to the resulting curve.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter")
	bool bApplyFilter;

	// Whether to use a High Pass filter. Will use Low Pass if disabled.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter", meta=(EditCondition="bApplyFilter"))
	bool bHighPass;

	// Whether to use the Butterworth. Will use Chebyshev if disabled. 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter", meta=(EditCondition="bApplyFilter"))
	bool bButterworth;

	/** Normalized between 0-1. In a low pass filter, the lower the value is the smoother the output. In a high pass filter the higher the value the smoother the output.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter", meta=(EditCondition="bApplyFilter", UIMax="1", UIMin="0"))
	float CutoffFrequency;

	/** The number of samples used to filter in the time domain. It maps how steep the roll off is for the filter. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter", meta=(EditCondition="bApplyFilter", UIMax="8", UIMin="1"))
	int32 Order;

	/** Optional math operation to apply on the extracted value before add it to the generated curve */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifiers")
	EMotionExtractor_MathOperation MathOperation;

	/** Right operand for the math operation selected */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifiers", meta=(EditCondition="MathOperation != EMotionExtractor_MathOperation::None"))
	float Modifier;

	/** Whether we want a normalized value (0 - 1) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifiers")
	bool bNormalize;

	/** Rate used to sample the animation */
	UPROPERTY(EditAnywhere, Category="Default", meta=(ClampMin="1"))
	int32 SampleRate;

	/** Whether we want to specify a custom name for the curve. If false, the name of the curve will be auto generated based on the data we are going to extract */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default", meta=(InlineEditConditionToggle))
	bool bUseCustomCurveName;

	/** Custom name for the curve we are going to generate. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default", meta=(EditCondition="bUseCustomCurveName"))
	FName CustomCurveName;

};

