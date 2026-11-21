// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Math/MathFwd.h"
#include "ClientPilot/FortClientPilot_Base.h"
#include "FortClientPilot_GameplayBase.generated.h"

class AFortPlayerPawn;
class UFortWorldItem;

USTRUCT()
struct FClientPilotBuildStep
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortClientPilot_GameplayBase : public UFortClientPilot_Base
{
	GENERATED_BODY()

public:
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
	float LastPickEditTime;

	UPROPERTY()
	FVector ViewLocation;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> MyPawn;

	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItem>> ItemsToCheckForMaxStackSize;

	UPROPERTY()
	FTimerHandle MissionEndTimerHandle;

};

UCLASS()
class UFortClientPilot_GameplayNone : public UFortClientPilot_GameplayBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortClientPilot_GameplayRpcTest : public UFortClientPilot_GameplayBase
{
	GENERATED_BODY()

};

