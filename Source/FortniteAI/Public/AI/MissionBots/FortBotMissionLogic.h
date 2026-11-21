// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortBotMissionLogic.generated.h"

class AActor;
class AFortAIController;
class AFortBotController;
class AFortBotStructureBuilder;
class AFortMission;
class UBehaviorTree;
class UFortBuildingInstructions;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortBotMissionLogic : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	void ClearAllLocated();

	UFUNCTION(BlueprintCallable, Category="AI")
	void MarkAllLocated();

	UFUNCTION(BlueprintCallable, Category="AI")
	void MarkSingleLocator(const AActor* LocatorActor);

	UFUNCTION(BlueprintImplementableEvent, Category="AI")
	void OnAssignedBehavior(AFortAIController* BotAI);

	UFUNCTION(BlueprintImplementableEvent, Category="AI")
	bool OnCanStartOtherMission(AFortAIController* BotAI, AFortMission* OtherMission);

	UFUNCTION(BlueprintImplementableEvent, Category="AI")
	bool OnInteractWithMissionGoal(AFortAIController* BotAI, AActor* MissionGoal);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission")
	void OnMissionActivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Mission")
	void OnMissionFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="Mission")
	void OnMissionStarted();

	UFUNCTION(BlueprintCallable, Category="AI")
	void ResetBehavior();

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetCurrentBehavior(UBehaviorTree* Behavior);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetGoalsInvulnerable(bool bGodMode);

	UFUNCTION(BlueprintCallable, Category="AI")
	AFortBotStructureBuilder* SpawnStructureBuilder(AActor* MissionGoal, UFortBuildingInstructions* BuildingInstructions);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AI")
	TObjectPtr<AFortMission> Mission;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AI")
	TArray<TObjectPtr<AActor>> Goals;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortBotStructureBuilder>> Builders;

	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTree> CurrentBehaviorAsset;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortBotController>> AssignedAI;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AI")
	TArray<uint8> GoalHasLocator;

};

