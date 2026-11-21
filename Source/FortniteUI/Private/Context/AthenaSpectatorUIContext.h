// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "BlueprintContextBase.h"
#include "AthenaSpectatorUIContext.generated.h"

class AFortGameState;
class AFortPawn;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AFortPlayerStateAthena;
class UAthenaRemotePlayerViewData;
class UAthenaRemoteSquadViewData;

USTRUCT()
struct FAthenaSpectatorUITeamEntry
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UAthenaSpectatorUIContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UAthenaRemotePlayerViewData* GetFollowedPlayerData() const;

	UFUNCTION(BlueprintPure)
	bool GetPipMode() const;

	UFUNCTION(BlueprintPure)
	UAthenaRemotePlayerViewData* GetPlayerData(const FUniqueNetIdRepl PlayerUID) const;

private:
	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

	UFUNCTION()
	void OnPawnForReplayRelevancyChanged(AFortPawn* InPawnForReplayRelevancy);

	UFUNCTION()
	void OnPlayerBecameIrrelevant(AFortPlayerState* FPS);

	UFUNCTION()
	void OnPlayerBecameRelevant(AFortPlayerState* FPS);

	UFUNCTION()
	void OnPlayerControllerSet();

	UFUNCTION()
	void OnPlayerStateAdded(AFortPlayerStateAthena* FPSA);

	UPROPERTY()
	TMap<FUniqueNetIdRepl, TObjectPtr<UAthenaRemotePlayerViewData>> PlayerDataMap;

	UPROPERTY()
	TMap<uint8, TObjectPtr<UAthenaRemoteSquadViewData>> InSessionSquadDataMap;

	UPROPERTY()
	TObjectPtr<AFortPlayerControllerSpectating> SpectatingPC;

	UPROPERTY()
	FUniqueNetIdRepl FollowedPlayerUID;

	UPROPERTY()
	FUniqueNetIdRepl ReplayRelevancyPlayerUID;

};

