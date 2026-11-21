// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/HoverDronePawn.h"
#include "BattleMapPawnReplay.generated.h"

class ABattleMapEdge;
class ABattleMapNode;
class ABattleMapTimeIndicator;
class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Navigation"))
class ABattleMapPawnReplay : public AHoverDronePawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool BP_IsOnTimelineMode() const;

	UFUNCTION(BlueprintCallable)
	bool BP_SetTimelineMode(bool bEnabled);

protected:
	UFUNCTION()
	void HandleBattleMapAutomaticCameraPlacementChanged(bool bEnabled);

	UFUNCTION()
	void HandleBattleMapShowAllSquadMembersChanged(bool bEnabled);

	UFUNCTION()
	void HandleBattleMapShowNearbyChestsChanged(bool bEnabled);

	UFUNCTION()
	void HandleBattleMapShowTimeIndicatorChanged(bool bEnabled);

	UFUNCTION()
	void HandleCameraOutsideSafeZoneChanged(bool bCameraOutsideSafeZone);

	UFUNCTION()
	void HandleCompletedAllRequested();

	UFUNCTION()
	void HandleGotoTimeComplete(bool bWasSuccessful);

	UFUNCTION()
	void HandleLeftMouseDown();

	UFUNCTION()
	void HandleLeftMouseUp();

	UFUNCTION()
	void HandlePlaybackTimeChanged(float NowTime);

	UFUNCTION()
	void HandleRefreshingReplayEvents();

	UFUNCTION()
	void HandleReplayEventRemoving(int32 Index);

	UFUNCTION()
	void HandleRightMouseDown();

	UFUNCTION()
	void HandleRightMouseUp();

	UFUNCTION()
	void HandleTimeIndicatorUpdatedSegment(const ABattleMapNode* StartNode, const ABattleMapEdge* Edge, const ABattleMapNode* EndNode);

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> GroundMoveNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> AirMoveNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> GotKillNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> ZoneNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapNode> TeamFlightNodeClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TSubclassOf<ABattleMapTimeIndicator> TimeIndicatorClass;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TObjectPtr<USoundBase> SelectedNodeSound;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TObjectPtr<USoundBase> HoveredNodeSound;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	TObjectPtr<USoundBase> ScrubbingToSound;

};

