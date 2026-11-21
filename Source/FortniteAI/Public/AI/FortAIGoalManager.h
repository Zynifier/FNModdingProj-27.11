// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "AI/FortAITypes.h"
#include "AI/Goals/FortAIGoal.h"
#include "AI/Goals/FortAIGoalSelectionCriteria.h"
#include "FortInitializationInterface.h"
#include "FortAIGoalManager.generated.h"

class AActor;
class AFortAIController;
class UEnvQuery;
class UFortAIAssignment;
class UFortAIAssignmentSettings;
class UFortAIGoalProvider;
class UObject;
enum class EAssignmentCreationResult : uint8;

UENUM(BlueprintType)
enum class EAssignmentCreationResult : uint8
{
	AssignmentNotFoundOrCreated = 0,
	AssignmentCreated = 1,
	AssignmentFound = 2,
};

USTRUCT()
struct FAIAssignmentInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TWeakObjectPtr<UFortAIAssignment> CurrentAssignment;

	UPROPERTY()
	FFortAIGoalInfo CurrentGoal;

	UPROPERTY()
	float TimeCurrentGoalWasChosen;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteAI.EAssignmentType"))
	float TimeExitedLastAssignmentOfType[4];

	UPROPERTY()
	TWeakObjectPtr<UFortAIAssignment> PreviousAssignment;

	UPROPERTY()
	FFortAIGoalInfo PreviousGoal;

	UPROPERTY()
	bool bWaitingForQueryResponse;

	UPROPERTY()
	bool bSuppressGoalUpdates;

	UPROPERTY()
	bool bReportEnemyGoalSelection;

};

USTRUCT()
struct FAIDiscouragedGoalTimer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortAIGoalInfo DiscouragedGoalInfo;

	UPROPERTY()
	double ExpirationTime;

	UPROPERTY()
	uint32 NumberOfTimesMarkedForDiscouragement;

};

UCLASS(MinimalAPI)
class AFortAIGoalManager : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction))
	void AddGoal(AActor* GoalActor, UFortAIAssignmentSettings* GoalSettings);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction))
	void AddGoalActorToAssignment(UFortAIAssignment* Assignment, AActor* GoalActor);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void AddGoalsToWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const TArray<FFortAIGoalInfo>& GoalInfos);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void AddGoalToWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const FFortAIGoalInfo& GoalInfo);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction))
	UFortAIAssignment* AddWorldAssignment(UFortAIAssignmentSettings* AssignmentSettings, AActor* GoalActor);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContext"))
	void ClearGoalDiscouragementFromActor(AFortAIController* AI, const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void CreateWorldAssignment(UObject* WorldContextObject, FFortAIAssignmentIdentifier WorldAssignmentIdentifier, UFortAIAssignmentSettings* AssignmentSettings, TSubclassOf<UFortAIGoalProvider> GoalProvider, FFortAIAssignmentIdentifier& AssignmentIdentifier, EAssignmentCreationResult& CreationResult);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContext"))
	bool IsDiscouragedFromActor(AFortAIController* AI, const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void MakeGoalFromActor(FFortAIGoalInfo& Goal, const UObject* WorldContextObject, AActor* GoalActor, bool bActorAlwaysPerceived = true, bool bGoalActorAllowsUndermining = true);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void MakeGoalFromLocation(FFortAIGoalInfo& Goal, const UObject* WorldContextObject, const FVector& GoalLocation);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void MakeGoalsFromActors(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<AActor*>& GoalActors, bool bActorsAlwaysPerceived = true, bool bGoalActorsAllowUndermining = true);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void MakeGoalsFromLocations(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<FVector>& GoalLocations);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void MakeGoalsFromLocationsAndActor(TArray<FFortAIGoalInfo>& Goals, const UObject* WorldContextObject, const TArray<FVector>& GoalLocations, const AActor* GoalActor = nullptr);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void RemoveGoalFromWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const FFortAIGoalInfo& GoalInfo);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void RemoveGoalsFromWorldAssignment(UObject* WorldContextObject, const FFortAIAssignmentIdentifier& AssignmentIdentifier, const TArray<FFortAIGoalInfo>& GoalInfos);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection", meta=(WorldContext="WorldContextObject"))
	static void RemoveWorldAssignment(const UObject* WorldContextObject, FFortAIAssignmentIdentifier AssignmentIdentifier);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContext"))
	static void SetCurrentGoalDiscouragement(UObject* WorldContext, AFortAIController* AI);

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortAIAssignment>> WorldAssignments;

	UPROPERTY()
	TArray<TObjectPtr<UFortAIAssignment>> WorldEnemyAssignments;

	UPROPERTY()
	TObjectPtr<UFortAIAssignment> DefaultAttackPlayersAssignment;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UEnvQuery>> CombinedQueries;

	UPROPERTY(EditAnywhere, Category="GoalManager")
	TObjectPtr<UFortAIAssignmentSettings> DefaultEncounterAssignmentSettings;

	UPROPERTY(EditAnywhere, Category="GoalManager")
	TObjectPtr<UFortAIAssignmentSettings> DefaultEnemyAssignmentSettings;

	UPROPERTY(EditAnywhere, Category="GoalManager")
	TArray<FPawnGoalSelectionTableEntry> PawnGoalSelectionTable;

};

