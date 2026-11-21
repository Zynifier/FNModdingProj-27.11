// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent.h"
#include "FortQuestItemComponent_UrgentQuest.generated.h"

class IQuestInstanceInterface;
class IQuestInstanceParticipantInterface;
class UFortQuestItemComponent_UrgentQuest;

UCLASS(MinimalAPI, BlueprintType)
class UFortQuestItemComponent_UrgentQuest : public UFortQuestItemComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerExpired, const UFortQuestItemComponent_UrgentQuest*, UrgentQuestItemComponent);

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float GetTimeRemaining() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasQuestFailureBeenTriggered() const;

	UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
	FOnTimerExpired OnTimerExpired;

private:
	UFUNCTION()
	void AuthorityHandleNewParticipantsRegistered(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

	UFUNCTION()
	void AuthorityHandleNewParticipantsUnregistered(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

};

