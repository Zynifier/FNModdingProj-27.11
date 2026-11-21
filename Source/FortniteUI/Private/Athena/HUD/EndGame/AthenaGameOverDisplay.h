// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ScalableFloat.h"
#include "FortCombatTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaGameOverDisplay.generated.h"

class ABattleMapPawnLive;
class UCommonButtonLegacy;
class UEliminatedOverlay;
class UFortMatchStatsScreen;
enum class EEndOfMatchReason : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGameOverDisplay : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnPawnDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION(BlueprintCallable)
	void OnPlayerLost(EEndOfMatchReason LostReason);

	UFUNCTION(BlueprintCallable)
	void OnPlayerOrTeamWon();

protected:
	UFUNCTION()
	void HandleToggledBattleMapLive(ABattleMapPawnLive* NewSpectatorPawn);

	UFUNCTION()
	void HighlightCountChanged(int32 HighlightCount);

	UFUNCTION()
	void InGameMatchmakingComplete(bool bSuccess);

	UFUNCTION()
	void OnKillFeedUpdated();

	UFUNCTION()
	void OnPlaceChanged();

	UFUNCTION()
	void OnRessurectingNowDelegate(bool bRessurectingNow);

	UFUNCTION()
	void OnSpecialActorListChanged();

	UFUNCTION()
	void OnSpectatorStreamingChanged(bool bSpectatorStreaming);

	UFUNCTION()
	void OnToggleFullscreenMap(bool bFullscreenMapVisible);

	UFUNCTION()
	void OnViewTargetChanged();

	UFUNCTION()
	void OnWinnerAnnounced(const FString& Winner);

	UFUNCTION()
	void OnWinningScoreDetermined(int32 Score);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaGameOverDisplay")
	TSubclassOf<UFortMatchStatsScreen> MatchStatsClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_ReturnToLobby;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_NextTeammate;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_PreviousTeammate;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_NextPlayer;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_PreviousPlayer;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_ReportPlayer;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_ToggleBattleMap;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FDataTableRowHandle Input_ForceStartPostGame;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEliminatedOverlay> EliminatedOverlay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Highlights;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameOverDisplay")
	FScalableFloat bAllowSpectateAllPlayers;

};

