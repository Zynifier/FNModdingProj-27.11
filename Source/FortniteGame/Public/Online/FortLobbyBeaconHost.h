// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LobbyBeaconHost.h"
#include "FortLobbyBeaconHost.generated.h"

UCLASS(Abstract)
class AFortLobbyBeaconHost : public ALobbyBeaconHost
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	uint8 bAllowReservationsToProceedToLobby : 1;

	UPROPERTY(Transient)
	uint8 bWorldRecordLoaded : 1;

	UPROPERTY()
	int32 LastReservationCountForPermissionTimeoutChange;

	UPROPERTY()
	float LobbyPermissionTimeout;

};

