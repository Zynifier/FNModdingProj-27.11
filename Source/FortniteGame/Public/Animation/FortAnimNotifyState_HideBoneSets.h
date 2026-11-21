// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotifyState_HideBoneSets.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_HideBoneSets : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_HideBoneSets")
	FGameplayTagContainer BoneSetTags;

};

