// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimTypes.h"
#include "BoneMaskTypes.h"
#include "AnimNode_BoneMask.generated.h"

class UBoneMaskDefinitionDataAsset;

USTRUCT(BlueprintType)
struct FBoneMaskBodyPartNameContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Defaults")
	TArray<FName> Names;

};

/**
 * This node is heavily based on AnimNode_LayeredBoneBlend but replacing both BranchFilter and BlendMask option with a single input param that represents different body parts.
 * Each body parts has a list of BranchFilter that maps to actual bones. Blending is done in the order the body parts are created and in local space first and mesh space after.
 * Unlike AnimNode_LayeredBoneBlend, with this node we can change the mask dynamically.
*/
USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct ANIMATIONLAYERINGRUNTIME_API FAnimNode_BoneMask : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	/** The source pose */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Links")
	FPoseLink BasePose;

	/** Each layer's blended pose */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, Category="Links", meta=(BlueprintCompilerGeneratedDefaults))
	TArray<FPoseLink> BlendPoses;

	/** The weights of each layer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, Category="Runtime", meta=(BlueprintCompilerGeneratedDefaults, PinShownByDefault))
	TArray<float> BlendWeights;

	/** Mask with all the body part dynamic values */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runtime", meta=(BlueprintCompilerGeneratedDefaults, PinShownByDefault))
	FBoneMask BoneMask;

	/** Mask with all the body part static values */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Runtime", meta=(PinShownByDefault))
	TObjectPtr<UBoneMaskDefinitionDataAsset> BoneMaskDefinitionDataAsset;

	/**
	 * List of BodyParts that want to use different Poses
	 * When adding a new input pose to the node (right click on the node Add Input Pose)
	 * an entry to this array is automatically added allowing the user to specify the body part(s) that should use that pose
	 */
	UPROPERTY(EditAnywhere, EditFixedSize, Category="Runtime")
	TArray<FBoneMaskBodyPartNameContainer> BodyParts;

	/** How to blend the layers together */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TEnumAsByte<ECurveBlendOption::Type> CurveBlendOption;

	/*
	 * Max LOD that this node is allowed to run
	 * For example if you have LODThreadhold to be 2, it will run until LOD 2 (based on 0 index)
	 * when the component LOD becomes 3, it will stop update/evaluate
	 * currently transition would be issue and that has to be re-visited
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Performance", meta=(DisplayName="LOD Threshold"))
	int32 LODThreshold;

};

