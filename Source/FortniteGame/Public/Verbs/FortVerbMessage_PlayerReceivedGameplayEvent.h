// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_PlayerReceivedGameplayEvent.generated.h"

USTRUCT(meta=(DisplayName="Player Received Gameplay Event"))
struct FFortVerbMessage_PlayerReceivedGameplayEvent : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerReceivedGameplayEvent")
	FGameplayTag GameplayEventTag;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerReceivedGameplayEvent")
	bool bAuthorIsTarget;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerReceivedGameplayEvent")
	bool bAuthorIsInstigator;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_PlayerReceivedGameplayEvent")
	FGameplayEventWeakData EventData;

};

