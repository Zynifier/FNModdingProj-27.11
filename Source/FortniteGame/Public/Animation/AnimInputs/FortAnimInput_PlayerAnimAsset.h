// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/FortAnimTypes.h"
#include "FortAnimInput_PlayerAnimAsset.generated.h"

class UAimOffsetBlendSpace;
class UAnimSequence;
class UBlendSpace;

USTRUCT(BlueprintType)
struct FFortAnimInput_StandingPawnAnimAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> UpperBodyAdditivePoseOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> IdleNoise;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> TargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> NonTargetingPose;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_PlayerAnimAsset : public FFortAnimInput_StandingPawnAnimAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bPlayUpperBodySlotOnFullBodyInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bDisableFullBodyAimOffsetDuringMelee;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bShouldApplyAimOffsetFullBody;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSet")
	float FullBodyAimOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSet")
	float UpperBodyAimOffsetAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bOverrideDisableArmsHeadAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet", meta=(EditCondition="bOverrideDisableArmsHeadAdditive"))
	float DisableArmsHeadAdditiveOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimPlayrateRange SprintPlayrateClampRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimPlayrateRange SprintTargetingPlayrateClampRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimPlayrateRange CrouchSprintPlayrateClampRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimPlayrateRange CrouchSprintTargetingPlayrateClampRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAimOffsetBlendSpace> TargetingAimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAimOffsetBlendSpace> NonTargetingAimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RelaxedPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RelaxedPoseLevel2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAimOffsetBlendSpace> RelaxedAimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> JogAdditiveBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> JogAdditiveBlendSpaceRelaxed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> JogAdditiveBlendSpaceRelaxedLevel2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> JogAdditiveBlendSpaceMeleeGuarding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SprintAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SprintTargetingAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> CrouchTargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> CrouchNonTargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> CrouchRelaxedPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RidingNonTargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> CrouchCoreTargetingBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> CrouchCoreNonTargetingBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> CrouchWalkAdditiveBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> CrouchJogAdditiveBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> CrouchJogAdditiveBlendSpaceRelaxed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> CrouchSprintAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> CrouchSprintTargetingAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimRelaxedPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimTargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimNonTargetingPose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UBlendSpace> SwimJogAdditiveBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimSprintAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAimOffsetBlendSpace> SwimTargetingAimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimIdleNoise;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> IdleNoise_AR_DownSights;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimJumpSurfaceEndAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimJumpSurfaceLoopAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimJumpFallLoopAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimJumpStartLoopAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimJumpStartAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> FlyModeLoopAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> FlyModeStartAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> ZipLineStartAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> JetPackJumpAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> JetPackStartAdditve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> FallAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> JumpLoopAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> JumpUpAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> WeaponChargeLoop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> SwimUpperBodyAdditivePoseOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> WeaponInspectAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bOverridePitchAndYawOffsets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet", meta=(EditCondition="bOverridePitchAndYawOffsets"))
	FFortAnimInput_AdjustedAimOffset AnimSetOffsets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TArray<FName> BonesToHide;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bOverrideHandIKRetargetingWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet", meta=(EditCondition="bOverrideHandIKRetargetingWeight"))
	float HandIKRetargetingWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	bool bForceKneeSliding;

};

