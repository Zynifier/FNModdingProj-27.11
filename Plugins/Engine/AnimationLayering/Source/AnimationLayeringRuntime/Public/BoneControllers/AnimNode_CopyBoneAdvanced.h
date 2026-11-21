// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimTypes.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "Math/MathFwd.h"
#include "AnimNode_CopyBoneAdvanced.generated.h"

/**
 *	Controller to copy a bone's transform to another one, with individual per-component alphas.
 */
USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct ANIMATIONLAYERINGRUNTIME_API FAnimNode_CopyBoneAdvanced : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	/** Source Bone Name to get transform from */
	UPROPERTY(EditAnywhere, Category="Copy")
	FBoneReference SourceBone;

	/** Name of bone to control. This is the main bone chain to modify from. */
	UPROPERTY(EditAnywhere, Category="Copy")
	FBoneReference TargetBone;

	/** Per-axis translation weight to copy from source to target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Copy", meta=(AllowPreserveRatio, PinHiddenByDefault))
	FVector TranslationWeight;

	/** Rotation angle weight to copy from source to target. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Copy", meta=(PinHiddenByDefault))
	float RotationWeight;

	/** Scale weight to copy from source to target (not separated per-axis to avoid non-uniform scales) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Copy", meta=(AllowPreserveRatio, PinHiddenByDefault))
	float ScaleWeight;

	/** Space to convert transforms into prior to copying components */
	UPROPERTY(EditAnywhere, Category="Copy")
	TEnumAsByte<EBoneControlSpace> ControlSpace;

	/** Name of the bone Translation Weight is relative to.
		If left empty, the axes are in source bone space.
		If unchecked, the axes are in component space. */
	UPROPERTY(EditAnywhere, Category="Copy", meta=(EditCondition="bTranslationInCustomBoneSpace"))
	FBoneReference TranslationSpaceBone;

	// If disabled, the translation weight axes are in component-space

	UPROPERTY(EditAnywhere, Category="Settings", meta=(InlineEditConditionToggle))
	bool bTranslationInCustomBoneSpace;

	// If disabled, the translation weight axes are in component-space

	UPROPERTY(EditAnywhere, Category="Advanced")
	bool bPropagateToChildren;

};

