// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "Items/FortQuickBars.h"
#include "McpCommandContexts.h"
#include "McpProfileRequestTypes.h"
#include "Online/FortMcpProfile.h"
#include "Quests/FortQuestTypes.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "FortMcpProfileWorld.generated.h"

class AFortInventory;
class UFortMcpProfileWorld;

USTRUCT()
struct FFortBatchUpdatePlayer_DeployableBaseUpdate
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl AccountId;

	UPROPERTY()
	FString DeployableBaseItemId;

	UPROPERTY()
	FFortCloudSaveInfo CloudSaveInfo;

};

USTRUCT()
struct FFortBatchUpdatePlayer_Update
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl AccountId;

	UPROPERTY()
	int32 TheaterNum;

	UPROPERTY()
	FMcpProfileChangeRequest TheaterItemUpdate;

	UPROPERTY()
	int32 OutpostNum;

	UPROPERTY()
	FMcpProfileChangeRequest OutpostItemUpdate;

	UPROPERTY()
	TArray<FFortQuestObjectiveCompletion> QuestObjectiveUpdates;

};

USTRUCT()
struct FFortProfileAndQuestSaveIdPair
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortWorldPlayerLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bPlayerIsNew;

	UPROPERTY()
	FQuickBar PrimaryQuickBarRecord;

	UPROPERTY()
	FQuickBar SecondaryQuickBarRecord;

	UPROPERTY()
	int32 ZonesCompleted;

};

USTRUCT()
struct FFortWorldProfileUpdateRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortMcpProfileWorld>> WorldProfilesToSave;

	UPROPERTY()
	int32 NumberOfRequests;

};

USTRUCT()
struct FItemIdAndQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	int32 Quantity;

};

USTRUCT()
struct FItemTransferOperation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemId;

	UPROPERTY()
	int32 Quantity;

	UPROPERTY()
	bool ToStorage;

	UPROPERTY()
	FString NewItemIdHint;

};

UCLASS(MinimalAPI)
class UFortMcpProfileWorld : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void BatchUpdatePlayers(const TArray<FFortBatchUpdatePlayer_Update>& Updates, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execBatchUpdatePlayers);

	UFUNCTION(ServiceRequest(MCP))
	void BatchUpdatePlayers_DeployableBase(const TArray<FFortBatchUpdatePlayer_Update>& Updates, const TArray<FFortBatchUpdatePlayer_DeployableBaseUpdate>& DeployableBaseUpdates, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execBatchUpdatePlayers_DeployableBase);

	UFUNCTION(ServiceRequest(MCP))
	void BatchUpdatePlayers_Outpost(const TArray<FFortBatchUpdatePlayer_Update>& Updates, const FString& OutpostId, const FFortOutpostCoreInfo& OutpostInfo, const FFortCloudSaveInfo& CloudSaveInfo, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execBatchUpdatePlayers_Outpost);

	UFUNCTION(ServiceRequest(MCP))
	void CraftWorldItem(const FString& TargetSchematicItemId, int32 NumTimesToCraft, const FString& TargetSchematicTier, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCraftWorldItem);

	UFUNCTION(ServiceRequest(MCP))
	void DepositPostResources(const TArray<FString>& itemsToDepositIds, const TArray<int32>& itemCountsToDeposit, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execDepositPostResources);

	UFUNCTION(ServiceRequest(MCP))
	void DestroyWorldItems(const TArray<FString>& ItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDestroyWorldItems);

	UFUNCTION(ServiceRequest(MCP))
	void DisassembleWorldItems(const TArray<FItemIdAndQuantityPair>& TargetItemIdAndQuantityPairs, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDisassembleWorldItems);

	UFUNCTION(ServiceRequest(MCP))
	void ModifyQuickbar(const TArray<FString>& PrimaryQuickbarChoices, const FString& SecondaryQuickbarChoice, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execModifyQuickbar);

	UFUNCTION(ServiceRequest(MCP))
	void StorageTransfer(const TArray<FItemTransferOperation>& TransferOperations, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execStorageTransfer);

protected:
	UFUNCTION(ServiceRequest(MCP))
	void InitializeTheater(const FString& TheaterGuid, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execInitializeTheater);

	UPROPERTY()
	TArray<FFortWorldProfileUpdateRequest> UpdateRequests;

	UPROPERTY()
	FFortWorldPlayerLoadout CachedPlayerLoadout;

	UPROPERTY()
	AFortInventory* FortInventory;

	UPROPERTY()
	bool bIsInventoryInitialized;

private:
	UFUNCTION(ServiceRequest(MCP))
	void LockProfiles(const FString& Code, int32 Timeout, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execLockProfiles);

	UFUNCTION()
	void OnHotbarUpdated();

	UFUNCTION(ServiceRequest(MCP))
	void UnlockProfiles(const FString& Code, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUnlockProfiles);

};

