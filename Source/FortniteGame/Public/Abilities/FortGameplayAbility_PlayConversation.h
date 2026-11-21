// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_PlayConversation.generated.h"

class UFortConversation;

UCLASS()
class UFortGameplayAbility_PlayConversation : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_PlayConversation")
	TObjectPtr<UFortConversation> ConversationToPlay;

};

