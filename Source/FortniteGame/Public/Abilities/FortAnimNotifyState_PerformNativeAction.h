// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotifyState_PerformNativeAction.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Object"), meta=(DisplayName="State - Perform Native Action", ShowHiddenSelfPins))
class UFortAnimNotifyState_PerformNativeAction : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Sound", meta=(Categories="Gameplay.Action"))
	FGameplayTag NativeAction;

};

UCLASS(EditInlineNew, BlueprintType, Blueprintable, HideCategories=("Object", "Object"), meta=(DisplayName="Instant - Perform Native Action", ShowHiddenSelfPins))
class UFortAnimNotify_PerformNativeAction : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Sound", meta=(Categories="Gameplay.Action"))
	FGameplayTag NativeAction;

};

