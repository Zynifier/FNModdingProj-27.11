// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventMatchSquadWidgetBase.h"
#include "AthenaBroadcastSquadStatusWidget.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;
class UAthenaRemoteSquadViewData;
class UFortMinigameTeamIdentification;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaBroadcastSquadStatusWidget : public UAthenaEventMatchSquadWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorController, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFollowedPlayerChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameTeamIdChanged(const UFortMinigameTeamIdentification* MinigameTeamId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnPipModeChanged(bool bPipModeEnabled);

	UPROPERTY(BlueprintReadOnly, Category="AthenaBroadcastSquadStatusWidget")
	FUniqueNetIdRepl FollowedPlayerUID;

private:
	UFUNCTION()
	void HandleSquadIdChanged(UAthenaRemoteSquadViewData* InSquadData, uint8 SquadId);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaBroadcastSquadStatusWidget", meta=(AllowPrivateAccess))
	TSubclassOf<UFortMinigameTeamIdentification> DesignTime_MinigameTeamId;
#endif

};

