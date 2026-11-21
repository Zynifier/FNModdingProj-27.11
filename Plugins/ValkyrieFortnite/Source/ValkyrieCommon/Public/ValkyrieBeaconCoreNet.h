// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/ActorChannel.h"
#include "Engine/NetConnection.h"
#include "Engine/NetDriver.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieBeaconCoreNet.generated.h"

UCLASS()
class UValkyrieBeaconActorChannel : public UActorChannel
{
	GENERATED_BODY()

};

UCLASS()
class UValkyrieBeaconNetConnection : public UNetConnection
{
	GENERATED_BODY()

};

UCLASS(Transient)
class UValkyrieBeaconPackageMap : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UValkyrieLiveEditNetDriver : public UNetDriver
{
	GENERATED_BODY()

};

