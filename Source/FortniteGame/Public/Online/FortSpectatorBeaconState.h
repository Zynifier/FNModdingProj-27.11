// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "SpectatorBeaconState.h"
#include "FortSpectatorBeaconState.generated.h"

UCLASS()
class UFortSpectatorBeaconState : public USpectatorBeaconState
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FUniqueNetIdRepl GameSessionOwner;

};

