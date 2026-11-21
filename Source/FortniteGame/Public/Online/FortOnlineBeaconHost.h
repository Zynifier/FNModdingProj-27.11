// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineBeaconHost.h"
#include "FortOnlineBeaconHost.generated.h"

UCLASS()
class AFortOnlineBeaconHost : public AOnlineBeaconHost
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FString> VerifyJoinFailOpenBeaconTypes;

};

