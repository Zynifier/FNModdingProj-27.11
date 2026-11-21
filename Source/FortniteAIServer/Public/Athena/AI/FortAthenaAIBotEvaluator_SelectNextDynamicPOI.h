// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "FortAthenaAIBotEvaluator_SelectNextDynamicPOI.generated.h"

class AFortTeamInfoAthena;
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic;

USTRUCT()
struct FFailedToReachPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 BotPOIID;

	UPROPERTY(Transient)
	int32 FailCount;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_SelectNextDynamicPOI : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnGamePhaseLogicReady(const FFortBattleRoyaleGamePhaseLogicComponentReadyEvent& Event);

	UFUNCTION()
	void OnSafezonePhaseChanged(const FFortSafeZonePhaseUpdatedEvent& Event);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DynamicPOIExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DynamicPOILocationKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfoAthena> CachedTeamInfo;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_BattleRoyaleGamePhaseLogic> CachedGamePhaseLogic;

	UPROPERTY(Transient)
	FTimerHandle NextSearchTimerHandle;

	UPROPERTY(Transient)
	TArray<FFailedToReachPOI> FailedBotPOIList;

	UPROPERTY(Transient)
	int32 CachedSelectedBotPOIID;

};

