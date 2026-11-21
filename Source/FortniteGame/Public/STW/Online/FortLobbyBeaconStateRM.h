// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortLobbyBeaconState.h"
#include "FortLobbyBeaconStateRM.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLobbyBeaconStateRM : public AFortLobbyBeaconState
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnRep_LobbyTimeRemaining();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LobbyTimeRemaining)
	int32 LobbyTimeRemaining;

};

