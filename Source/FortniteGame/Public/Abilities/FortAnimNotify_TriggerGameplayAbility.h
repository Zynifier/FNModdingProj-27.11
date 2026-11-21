// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "FortAnimNotify_TriggerGameplayAbility.generated.h"

UCLASS(EditInlineNew, HideCategories=("Object", "Object"), meta=(DisplayName="Trigger Ability"))
class UFortAnimNotify_TriggerGameplayAbility : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Ability")
	FGameplayTag ApplicationTag;

	UPROPERTY(EditAnywhere, Category="Ability")
	FName MontageSectionIfBlocked;

	UPROPERTY(EditAnywhere, Category="Ability")
	bool bSetNextSectionIfBlocked;

	UPROPERTY(EditAnywhere, Category="Ability")
	FName MontageSectionIfTargetInvalid;

};

