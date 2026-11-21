// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/ContentBeaconHostObjectV2.h"
#include "FortContentBeaconHostObjectV2.generated.h"

UENUM()
enum class EClientsReadyToJoinPhase : uint8
{
	Uninitialized = 0,
	WaitingForPlaylistInitialize = 1,
	WaitingForPartyLeader = 2,
	WaitingForLoadContentCall = 3,
	ReadyToJoin = 4,
};

UCLASS(MinimalAPI)
class AFortContentBeaconHostObjectV2 : public AContentBeaconHostObjectV2
{
	GENERATED_BODY()

};

