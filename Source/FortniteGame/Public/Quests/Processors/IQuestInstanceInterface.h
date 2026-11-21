// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IQuestInstanceInterface.generated.h"

class IQuestInstanceInterface;
class IQuestInstanceParticipantInterface;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnParticipantsModifiedEvent, const TScriptInterface<IQuestInstanceInterface>&, QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>&, Participants);

UINTERFACE(MinimalAPI, NotBlueprintable)
class UQuestInstanceInterface : public UInterface
{
	GENERATED_BODY()
};

class IQuestInstanceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual FString GetQuestID() const;

	UFUNCTION(BlueprintCallable)
	virtual bool HasCompletedObjectiveInstance(FName BackendName) const;

};

