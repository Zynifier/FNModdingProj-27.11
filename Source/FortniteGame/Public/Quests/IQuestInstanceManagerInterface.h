// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IQuestInstanceManagerInterface.generated.h"

class IQuestDefinitionInterface;
class IQuestInstanceInterface;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGenericBlueprintQuestEvent, TScriptInterface<IQuestInstanceInterface>, QuestInstance);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericQuestEvent, TScriptInterface<IQuestInstanceInterface>&, QuestInstance);

UINTERFACE(MinimalAPI, NotBlueprintable)
class UQuestInstanceManagerInterface : public UInterface
{
	GENERATED_BODY()
};

class IQuestInstanceManagerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void BindEventToOnQuestCompleted(UPARAM(DisplayName="Event") FOnGenericBlueprintQuestEvent DelegateSignature);

	UFUNCTION(BlueprintCallable)
	virtual void BindEventToOnQuestGranted(UPARAM(DisplayName="Event") FOnGenericBlueprintQuestEvent DelegateSignature);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Find Quest Instance for Manager"))
	virtual TScriptInterface<IQuestInstanceInterface> FindQuestInstance(const FString& QuestID) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual TScriptInterface<IQuestInstanceInterface> GrantQuest(const TScriptInterface<IQuestDefinitionInterface>& QuestDefinition);

	UFUNCTION(BlueprintCallable)
	virtual void UnbindAllEventsFromOnQuestCompleted(UObject* EventReceiver);

	UFUNCTION(BlueprintCallable)
	virtual void UnbindAllEventsFromOnQuestGranted(UObject* EventReceiver);

};

