// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpProfileManager.generated.h"

class UMcpProfileGroup;

USTRUCT()
struct FProfileGroupEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMcpProfileGroup> ProfileGroup;

};

UCLASS(Config=Engine)
class MCPPROFILESYS_API UMcpProfileManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FProfileGroupEntry> ServerProfileGroups;

	UPROPERTY()
	TArray<FProfileGroupEntry> ClientProfileGroups;

	UPROPERTY(Config)
	int32 MaxItemsProcessedInInitialUpdatesPerTick;

};

