// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotify_EarlyOutConditional.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Early-Out Conditional Window"))
class UFortAnimNotifyState_EarlyOutConditional : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_EarlyOutConditional")
	FGameplayTagContainer TagList;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_EarlyOutConditional")
	bool bApplyBlendOutTimeOverride;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_EarlyOutConditional", meta=(EditCondition="bApplyBlendOutTimeOverride"))
	float BlendOutTimeOverride;

};

