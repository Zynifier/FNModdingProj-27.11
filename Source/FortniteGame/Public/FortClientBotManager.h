// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortClientBotManager.generated.h"

class ABuildingActor;
class AFortPawn;
class AFortPickup;
class AFortPlayerPawn;
class UFortWorldItem;

USTRUCT()
struct FClientBotBuildStep
{
	GENERATED_BODY()

};

UCLASS(Config=Game)
class UFortClientBotManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTimerHandle MissionEndTimerHandle;

	UPROPERTY()
	bool bHasAttemptedAbandon;

	UPROPERTY()
	bool bIsMatchmaking;

	UPROPERTY()
	bool bShouldPickRandomMap;

	UPROPERTY()
	bool bShouldRecordFPSCharts;

	UPROPERTY()
	bool bShouldRecordMemoryReports;

	UPROPERTY()
	bool bFPSRecordingStarted;

	UPROPERTY()
	bool bWatchingForCallStack;

	UPROPERTY()
	int32 iSelectedTheater;

	UPROPERTY()
	int32 iSelectedTile;

	UPROPERTY()
	TArray<int32> SelectedTileList;

	UPROPERTY()
	float RandomZoneDifficultyMinimum;

	UPROPERTY()
	float RandomZoneDifficultyMaximum;

	UPROPERTY()
	int32 NumSkillPurchasesAttempted;

	UPROPERTY()
	int32 MaxSkillPurchaseAttempts;

	UPROPERTY()
	int32 NumWorkerSlotsAttempted;

	UPROPERTY()
	int32 MaxWorkerSlotAttempts;

	UPROPERTY()
	float LobbyActionTimer;

	UPROPERTY()
	float TimeBetweenLobbyActions;

	UPROPERTY()
	bool bWaitingForSkillTreePurchase;

	UPROPERTY()
	bool bWaitingForWorkerSlot;

	UPROPERTY()
	int32 LoopsSpentWaitingForFrontend;

	UPROPERTY()
	float TimeBetweenStartButtonClicks;

	UPROPERTY()
	float TimeSinceFriendInvitesSent;

	UPROPERTY()
	float LastMatchmakeTime;

	UPROPERTY()
	float LastLoginCycleTime;

	UPROPERTY()
	float MatchmakingStartTime;

	UPROPERTY()
	float LastChangedStateTime;

	UPROPERTY()
	float LastRandomTurnTime;

	UPROPERTY()
	float LastPickLootTime;

	UPROPERTY()
	float LastPickEnemyTime;

	UPROPERTY()
	float LastEnemyKilledTime;

	UPROPERTY()
	float LastBuildingKilledTime;

	UPROPERTY()
	float LastGoodInteraction;

	UPROPERTY()
	float LastCheckGoodTarget;

	UPROPERTY()
	TWeakObjectPtr<AFortPawn> WeakEnemyTarget;

	UPROPERTY()
	AFortPickup* PickupTarget;

	UPROPERTY()
	ABuildingActor* BuildingTarget;

	UPROPERTY()
	ABuildingActor* MissionTarget;

	UPROPERTY()
	ABuildingActor* PrimaryMissionTarget;

	UPROPERTY()
	TArray<ABuildingActor*> AllMissionTargets;

	UPROPERTY()
	TArray<ABuildingActor*> ActiveMissionTargets;

	UPROPERTY()
	FVector ViewLocation;

	UPROPERTY()
	AFortPlayerPawn* MyPawn;

	UPROPERTY()
	TArray<UFortWorldItem*> ItemsToCheckForMaxStackSize;

};

