// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_CurrentQuestsReady.generated.h"

class UFortAsyncAction_CurrentQuestsReady;
class UFortQuestItemDefinition;
class UFortQuestManager;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentQuestsReady, UFortQuestManager*, OwningQuestManager, bool, bFoundAllQuestsOnProfile);

UCLASS()
class UFortAsyncAction_CurrentQuestsReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_CurrentQuestsReady* CurrentQuestsReadyAsync(UObject* WorldContextObject, UFortQuestManager* QuestManager, const TArray<UFortQuestItemDefinition*>& QuestItemDefinitions);

	UPROPERTY(BlueprintAssignable)
	FOnCurrentQuestsReady OnCurrentQuestsReady;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortQuestManager> MyQuestManager;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItemDefinition>> MyQuestItemDefinitions;

};

