// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorPlayerListScreenBase.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;
class UAthenaSpectatorPlayerListRowData;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpectatorPlayerListScreenBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Player List")
	void UpdateListUI();

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpectatorPlayerListScreenBase")
	TArray<TObjectPtr<UAthenaSpectatorPlayerListRowData>> RowDataArray;

private:
	UFUNCTION()
	void ClearPlayers();

	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void OnPlayerBecameIrrelevant(AFortPlayerState* NewlyIrrelevantPlayer);

	UFUNCTION()
	void OnPlayerBecameRelevant(AFortPlayerState* NewlyRelevantPlayer);

	UFUNCTION()
	void OnPlayerDied(AFortPlayerState* NewlyDeadPlayer);

};

