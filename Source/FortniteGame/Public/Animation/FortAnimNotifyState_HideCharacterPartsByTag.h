// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayEffectTypes.h"
#include "FortAnimNotifyState_HideCharacterPartsByTag.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_HideCharacterPartsByTag : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Hide Character Parts by Tag")
	FGameplayTagRequirements PartRequirements;

};

