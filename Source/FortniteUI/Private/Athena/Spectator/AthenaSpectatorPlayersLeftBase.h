// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorPlayersLeftBase.generated.h"

class AFortBroadcastSpectatorInfo;
class AFortGameState;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorPlayersLeftBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMaxSquadSize(int32 MaxSquadSize);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdatePlayersLeft(int32 InPlayersLeft);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTeamsLeft(int32 InTeamsLeft);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTotalPlayers(int32 InTotalPlayers);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTotalTeams(int32 InTotalTeams);

private:
	UFUNCTION()
	void OnBroadcastSpectatorInfoReplicated(AFortBroadcastSpectatorInfo* BroadcastSpectatorInfo);

	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

};

