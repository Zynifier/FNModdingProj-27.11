// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "PersistenceFramework/Example/ServiceWrapper/PFWExample_ServiceWrapper_ContainerInterface.h"
#include "PersistenceFramework/FortPersistenceFrameworkContainerInterface_InventoryService.h"
#include "PersistenceFramework/FortPersistenceFrameworkContainerInterface_MCP.h"
#include "PersistenceFramework/PersistenceFrameworkContainer.h"
#include "PersistenceFrameworkContainer_Quests.generated.h"

class IQuestInstanceInterface;

USTRUCT()
struct FPersistenceFrameworkSaveData_QuestObjective
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	int32 Count;

};

USTRUCT()
struct FPersistenceFrameworkSaveData_Quest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName QuestID;

	UPROPERTY()
	FPrimaryAssetId PrimaryAssetId;

	UPROPERTY()
	TArray<FPersistenceFrameworkSaveData_QuestObjective> Objectives;

	UPROPERTY()
	TArray<FString> TrackedData;

};

USTRUCT()
struct FPersistenceFrameworkSaveData_Quest_Version0
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PersistentName;

	UPROPERTY()
	FName QuestID;

	UPROPERTY()
	FPrimaryAssetId PrimaryAssetId;

	UPROPERTY()
	TArray<FPersistenceFrameworkSaveData_QuestObjective> Objectives;

};

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkContainer_Quests : public UPersistenceFrameworkContainer, public IFortPersistenceFrameworkContainerInterface_InventoryService, public IFortPersistenceFrameworkContainerInterface_MCP, public IPFWExample_ServiceWrapper_ContainerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCompletedInQuestManager(TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION()
	void OnNewAddedToQuestManager(TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UFUNCTION()
	void OnRemovedFromQuestManager(TScriptInterface<IQuestInstanceInterface>& QuestInstance);

	UPROPERTY()
	TArray<FName> RemovedQuestNames;

	UPROPERTY()
	TArray<FName> CompletedQuestName;

	UPROPERTY()
	TArray<FName> AbandonedQuestName;

	UPROPERTY()
	bool bManagerQuestListChanged;

};

