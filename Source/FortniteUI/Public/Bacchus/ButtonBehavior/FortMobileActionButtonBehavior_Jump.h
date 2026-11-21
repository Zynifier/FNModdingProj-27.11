// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_Jump.generated.h"

class UAbilitySystemComponent;
class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_Jump : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TObjectPtr<UPaperSprite> ThrowSprite;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	FGameplayTagContainer PawnTagsCollapse;

};

