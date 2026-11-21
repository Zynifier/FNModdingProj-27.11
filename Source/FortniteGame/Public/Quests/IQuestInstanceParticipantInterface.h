// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IQuestInstanceParticipantInterface.generated.h"

class IQuestInstanceInterface;

UINTERFACE(MinimalAPI, NotBlueprintable)
class UQuestInstanceParticipantInterface : public UInterface
{
	GENERATED_BODY()
};

class IQuestInstanceParticipantInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Find Quest Instance for Participant"))
	virtual TScriptInterface<IQuestInstanceInterface> FindQuestInstance(const FString& QuestID) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsQuestInstanceCompleted(const FString& QuestID) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsQuestInstanceObjectiveActive(const FString& QuestID, const FName& ObjectiveName) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsQuestInstanceObjectiveCompleted(const FString& QuestID, const FName& ObjectiveName) const;

};

