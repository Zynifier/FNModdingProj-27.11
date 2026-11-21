// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotify_GameplayTag.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Gameplay Tag Window"))
class UFortAnimNotifyState_GameplayTag : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_GameplayTag")
	FGameplayTag NotifyTag;

};

UCLASS(EditInlineNew, HideCategories=("Object", "Object"), meta=(DisplayName="Gameplay Tag"))
class FORTNITEGAME_API UFortAnimNotify_GameplayTag : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAnimNotify_GameplayTag")
	FGameplayTag NotifyTag;

};

