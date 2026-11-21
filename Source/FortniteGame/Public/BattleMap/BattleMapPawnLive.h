// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Replay/FortReplaySpectatorPawnBase.h"
#include "BattleMapPawnLive.generated.h"

class ABattleMapEdge;
class ABattleMapNode;
class ABattleMapTimeIndicator;
class USoundBase;

UCLASS(MinimalAPI, HideCategories=("Navigation"))
class ABattleMapPawnLive : public AFortReplaySpectatorPawnBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool BP_IsOnTimelineMode() const;

	UFUNCTION(BlueprintCallable)
	bool BP_SetTimelineMode(bool bEnabled);

	UFUNCTION(BlueprintCallable)
	bool HandleClickPressed(FKey ButtonPressed);

	UFUNCTION(BlueprintCallable)
	bool HandleClickReleased(FKey ButtonReleased);

	UFUNCTION(Exec)
	void ZoomIn(const float Val);

protected:
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

};

