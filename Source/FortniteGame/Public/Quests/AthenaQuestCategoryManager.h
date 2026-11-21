// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "AthenaQuestCategoryManager.generated.h"

class IQuestInstanceInterface;
class UFortMcpProfileSubgame;
class UFortQuestItem;
class UFortQuestItemDefinition_Athena;
class UQuestCategoryData;
enum class ESubGame : uint8;

UCLASS(MinimalAPI)
class UAthenaQuestCategoryManager : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UQuestCategoryData>> QuestCategoryList;

private:
	UFUNCTION()
	void HandleParticipantQuestAdded(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION()
	void HandleParticipantQuestRemoved(const TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION()
	void HandlePlayerProfileInit();

	UFUNCTION()
	void HandleQuestManagerCreated(const ESubGame SubGame, UFortMcpProfileSubgame* McpProfile);

	UFUNCTION()
	void HandleQuestsCompleted(const TArray<UFortQuestItem*>& Quests);

	UFUNCTION()
	void HandleRebuildEvent();

	UFUNCTION()
	void HandleTeamMemberLeavingGame(const FUniqueNetIdRepl& LeavingPlayerId);

	UFUNCTION()
	void HandleTransientQuestAdded(const UFortQuestItem* QuestItem);

	UFUNCTION()
	void HandleTransientQuestRemoved(const UFortQuestItem* QuestItem);

	UFUNCTION()
	void HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

};

