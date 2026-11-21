// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "MeshReplicationGraph.h"
#include "FortMeshReplicationGraph.generated.h"

class UFortMeshReplicationGraphNode_PawnList;

UCLASS()
class UFortMeshReplicationGraph : public UMeshReplicationGraph
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortMeshReplicationGraphNode_PawnList> PawnListNode;

};

UCLASS()
class UFortMeshReplicationGraphNode_PawnList : public UReplicationGraphNode_ActorList
{
	GENERATED_BODY()

};

