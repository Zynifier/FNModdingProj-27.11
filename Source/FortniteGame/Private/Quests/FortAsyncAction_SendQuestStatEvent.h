// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_SendQuestStatEvent.generated.h"

class UFortAsyncAction_SendQuestStatEvent;
class UFortQuestManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortSendQuestStatEventDelegate);

UCLASS()
class UFortAsyncAction_SendQuestStatEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_SendQuestStatEvent* SendClientStatEvent(UFortQuestManager* QuestManager, FDataTableRowHandle ObjectiveStat, int32 Count = 1);

	UFUNCTION(BlueprintCallable, Category="Quests", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_SendQuestStatEvent* SendClientStatEventWithTags(UFortQuestManager* QuestManager, FGameplayTagContainer TargetTags, FGameplayTagContainer SourceTags, FGameplayTagContainer ContextTags, int32 Count = 1);

	UPROPERTY(BlueprintAssignable)
	FFortSendQuestStatEventDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FFortSendQuestStatEventDelegate OnIgnored;

	UPROPERTY(BlueprintAssignable)
	FFortSendQuestStatEventDelegate OnFailure;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortQuestManager> QuestManager;

	UPROPERTY(Transient)
	FDataTableRowHandle ObjectiveStat;

	UPROPERTY(Transient)
	FGameplayTagContainer TargetTags;

	UPROPERTY(Transient)
	FGameplayTagContainer SourceTags;

	UPROPERTY(Transient)
	FGameplayTagContainer ContextTags;

	UPROPERTY(Transient)
	int32 Count;

};

