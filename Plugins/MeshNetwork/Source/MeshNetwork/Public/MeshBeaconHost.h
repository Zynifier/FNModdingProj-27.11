// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHost.h"
#include "MeshBeaconHost.generated.h"

UCLASS()
class MESHNETWORK_API AMeshBeaconHost : public AOnlineBeaconHost
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	int32 MaxConnections;

};

