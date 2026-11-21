// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectNPCGiveItem.generated.h"

UCLASS(meta=(DisplayName="Effect: NPC Give Item"))
class UFortControllerEffect_NPCGiveItem : public UFortControllerEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag GiftItemRequiredFilteringTag;

};

