// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "FortCustomRepGraphNode.generated.h"

class UFortReplicationGraphNode_Custom;
class UObject;

USTRUCT()
struct FFortCustomRepNodeClassMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCustomRepNodeClassMapping")
	TSubclassOf<UFortReplicationGraphNode_Custom> NodeClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomRepNodeClassMapping")
	TArray<TSoftClassPtr<UObject>> ClassesToRoute;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomRepNodeClassMapping")
	bool bShouldDisableSquadNodes;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomRepNodeClassMapping")
	bool bShouldDisableHighFrequencyPawnRouting;

};

UCLASS(MinimalAPI)
class UFortReplicationGraphNode_Custom : public UReplicationGraphNode
{
	GENERATED_BODY()

};

