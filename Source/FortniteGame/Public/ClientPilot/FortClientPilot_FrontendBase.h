// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilot/FortClientPilot_Base.h"
#include "FortClientPilot_FrontendBase.generated.h"

UCLASS()
class UFortClientPilot_FrontendBase : public UFortClientPilot_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bWaitingForSkillTreePurchase;

	UPROPERTY()
	bool bWaitingForWorkerSlot;

	UPROPERTY()
	int32 NumSkillPurchasesAttempted;

	UPROPERTY()
	int32 MaxSkillPurchaseAttempts;

	UPROPERTY()
	int32 NumWorkerSlotsAttempted;

	UPROPERTY()
	int32 MaxWorkerSlotAttempts;

	UPROPERTY()
	int32 LoopsSpentWaitingForFrontend;

	UPROPERTY()
	float LobbyActionTimer;

	UPROPERTY()
	float TimeBetweenLobbyActions;

	UPROPERTY()
	bool bHasAttemptedAbandon;

	UPROPERTY()
	float LastMatchmakeTime;

	UPROPERTY()
	float LastLoginCycleTime;

};

