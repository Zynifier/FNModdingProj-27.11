// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/FortCheatManagerMissionsInterface.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManagerMissions.generated.h"

UCLASS()
class UFortCheatManagerMissions : public UChildCheatManager, public IFortCheatManagerMissionsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void DumpActorsWithAssetTags(const FString& TagList);

	UFUNCTION(Exec)
	void DumpAllActiveMissions();

	UFUNCTION(Exec)
	void DumpAllActorsWithAssetTags();

	UFUNCTION(Exec)
	void DumpAllDisplayedMissions();

	UFUNCTION(Exec)
	void EndDeimosSpawning();

	UFUNCTION(Exec)
	void ExecuteNewMissionGeneration(float DifficultyLevel, const FString& GeneratorName = TEXT(""));

	UFUNCTION(Exec)
	void ForceCompleteDisplayedObjective(const int32 ObjectiveIndex);

	UFUNCTION(Exec)
	void ForceCompleteDumpedObjective(const FString& MissionName, const int32 ObjectiveIndex);

	UFUNCTION(Exec)
	void ForceSaveMissionStateAndWorld(const FString& SaveFilename);

	UFUNCTION(Exec)
	void ListMissionGenerators();

	UFUNCTION(Exec)
	void ListMissions();

	UFUNCTION(Exec)
	void LoadMission(const FString& MissionName = TEXT(""));

	UFUNCTION(Exec)
	void LoadMissionGenerator(const FString& GeneratorName = TEXT(""));

	UFUNCTION(Exec)
	void MissionForceFailure(const FString& MissionName);

	UFUNCTION(Exec)
	void MissionForcePrimaryFailure();

	UFUNCTION(Exec)
	void MissionForcePrimarySuccess(float FractionCompleted = 1.000000f);

	UFUNCTION(Exec)
	void MissionForceSuccess(const FString& MissionName, float FractionCompleted = 1.000000f);

	UFUNCTION(Exec)
	void RegenerateZoneMissions();

	UFUNCTION(Exec)
	void RegenerateZoneMissionsWithDifficultyLevel(float DifficultyLevelOverride);

	UFUNCTION(Exec)
	void SendMissionEvent(const FString& MissionEventName = TEXT(""));

	UFUNCTION(Exec)
	void TeleportToMissionActor();

	UFUNCTION(Exec)
	void ToggleAIIgnoreMissionActors();

	UFUNCTION(Exec)
	void ToggleSecondaryMissionHeaders();

};

