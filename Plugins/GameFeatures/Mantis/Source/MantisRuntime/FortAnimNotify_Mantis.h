// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortMantisTypes.h"
#include "FortAnimNotify_Mantis.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Mantis Window", ShowWorldContextPin))
class UFortAnimNotifyState_Mantis : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis")
	EFortMantisNotifyWindow MantisNotifyWindow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis")
	FGameplayTag MantisNotifyTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyWindow == EFortMantisNotifyWindow::RootMotionWarp && bWarpTranslation", EditConditionHides))
	EFortMantisNotifyTranslationWarpLimitRule TranslationWarpLimitRule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyWindow == EFortMantisNotifyWindow::RootMotionWarp && bWarpTranslation && TranslationWarpLimitRule == EFortMantisNotifyTranslationWarpLimitRule::Custom", EditConditionHides))
	float TranslationWarpLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyWindow == EFortMantisNotifyWindow::RootMotionWarp && bWarpRotation", EditConditionHides))
	EFortMantisNotifyRotationWarpRateRule RotationRateWarpRule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyWindow == EFortMantisNotifyWindow::RootMotionWarp", EditConditionHides))
	uint8 bWarpRotation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyWindow == EFortMantisNotifyWindow::RootMotionWarp", EditConditionHides))
	uint8 bWarpTranslation : 1;

};

UCLASS(EditInlineNew, HideCategories=("Object", "Object"), meta=(DisplayName="Mantis Event", ShowWorldContextPin))
class UFortAnimNotify_Mantis : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis")
	EFortMantisNotifyEvent MantisNotifyEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyEvent == EFortMantisNotifyEvent::Branch", EditConditionHides))
	EFortMantisBranchRule MantisBranchRule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mantis", meta=(EditCondition="MantisNotifyEvent == EFortMantisNotifyEvent::Branch", EditConditionHides))
	EFortMantisBranchPath MantisBranchPath;

};

