// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayCueInterface.h"
#include "FortAnimNotify_GameplayCue.generated.h"

UCLASS(EditInlineNew, HideCategories=("Object", "Object"), meta=(DisplayName="Gameplay Cue (Burst)"))
class UFortAnimNotify_GameplayCue : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAnimNotify_GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayCueTag Cue;

};

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="GameplayCue (Looping)"))
class UFortAnimNotify_GameplayCueState : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAnimNotify_GameplayCueState", meta=(Categories="GameplayCue"))
	FGameplayCueTag Cue;

};

