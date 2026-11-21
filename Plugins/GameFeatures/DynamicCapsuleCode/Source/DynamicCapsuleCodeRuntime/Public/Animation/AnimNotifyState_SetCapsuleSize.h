// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "AnimNotifyState_SetCapsuleSize.generated.h"

UCLASS(HideCategories=("Object"))
class UAnimNotifyState_SetCapsuleSize : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Capsule", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float TargetCapsuleRadius;

	UPROPERTY(EditAnywhere, Category="Capsule", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float TargetCapsuleHalfHeight;

	UPROPERTY(EditAnywhere, Category="Capsule", meta=(InlineEditConditionToggle))
	bool bAdjustRelativeMeshHeight;

	UPROPERTY(EditAnywhere, Category="Capsule", meta=(EditCondition="bAdjustRelativeMeshHeight"))
	float TargetRelativeMeshHeight;

	UPROPERTY(EditAnywhere, Category="Capsule")
	FGameplayTag CapsuleSizeTag;

};

