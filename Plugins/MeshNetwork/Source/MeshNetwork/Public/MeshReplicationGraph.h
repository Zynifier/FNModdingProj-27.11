// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "MeshReplicationGraph.generated.h"

class UReplicationGraphNode_ActorList;

UCLASS()
class MESHNETWORK_API UMeshReplicationGraph : public UReplicationGraph
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_ActorList> AlwaysRelevantNode;

};

UCLASS()
class MESHNETWORK_API UMeshReplicationGraphConnection : public UNetReplicationGraphConnection
{
	GENERATED_BODY()

};

