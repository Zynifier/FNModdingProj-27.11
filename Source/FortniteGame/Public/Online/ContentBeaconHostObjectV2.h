// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "OnlineBeaconHostObject.h"
#include "Online/ContentBeaconUtilsV2.h"
#include "ContentBeaconHostObjectV2.generated.h"

UENUM()
enum class EContentBeaconHostGlobalState : uint8
{
	Initializing = 0,
	Running = 1,
	WaitingForUnload = 2,
	PendingShutdown = 3,
	Shutdown = 4,
};

USTRUCT()
struct FClientContentRequestId
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FUniqueNetIdRepl ClientName;

	UPROPERTY()
	FContentRequestId ContentRequestId;

};

UCLASS(Config=Game, MinimalAPI)
class AContentBeaconHostObjectV2 : public AOnlineBeaconHostObject
{
	GENERATED_BODY()

};

