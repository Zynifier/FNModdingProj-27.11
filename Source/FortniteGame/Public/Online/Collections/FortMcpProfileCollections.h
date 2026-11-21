// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "McpCommandContexts.h"
#include "McpProfile.h"
#include "Online/Collections/FortMcpCollectionsBulkUpdateEntry.h"
#include "FortMcpProfileCollections.generated.h"

class UFortCollectionData;
class UFortCollectionsTaskManager;
enum class EFortCollectedState : uint8;

UCLASS(MinimalAPI)
class UFortMcpProfileCollections : public UMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void AddToCollection(const FString& Category, const FString& Variant, const TArray<FString>& ContextTags, const FJsonObjectWrapper& Properties, EFortCollectedState SeenState, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execAddToCollection);

	UFUNCTION(ServiceRequest(MCP))
	void BulkUpdateCollections(const TArray<FFortMcpCollectionsBulkUpdateEntry>& Items, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execBulkUpdateCollections);

	UFUNCTION(ServiceRequest(MCP))
	void MarkCollectedItemsSeen(const TArray<FFortMcpCollectionsVariant>& Variants, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execMarkCollectedItemsSeen);

	UPROPERTY()
	TMap<FString, TObjectPtr<UFortCollectionData>> DataTables;

private:
	UPROPERTY()
	TObjectPtr<UFortCollectionsTaskManager> TaskManager;

};

