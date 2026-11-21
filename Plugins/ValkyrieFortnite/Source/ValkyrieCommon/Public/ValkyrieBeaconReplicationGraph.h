// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "ValkyrieBeaconReplicationGraph.generated.h"

class UValkyrieBeaconPackageMap;

UCLASS()
class VALKYRIECOMMON_API UValkyrieBeaconReplicationGraph : public UReplicationGraph
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UValkyrieBeaconPackageMap> DummyPackageMap;

};

UCLASS()
class UValkyrieBeaconReplicationGraphConnection : public UNetReplicationGraphConnection
{
	GENERATED_BODY()

};

