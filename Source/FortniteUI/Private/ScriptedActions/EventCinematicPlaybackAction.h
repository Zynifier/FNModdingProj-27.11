// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortScriptedAction.h"
#include "EventCinematicPlaybackAction.generated.h"

class AFortPlayerController;
class UFortQuestItem;

UCLASS(BlueprintType, HideCategories=("Actor", "Navigation", "Replication", "Actor", "Navigation", "Replication"))
class AEventCinematicPlaybackAction : public AFortScriptedAction
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleVideoEnded();

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItem> Quest;

	UPROPERTY(Transient)
	FName ObjectiveName;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> Player;

	UPROPERTY(Transient)
	FDataTableRowHandle ObjectiveStat;

};

