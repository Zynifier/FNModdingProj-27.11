// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortEncounterSettings.h"
#include "Missions/FortMission.h"
#include "FortMission_ActiveThreat.generated.h"

class AFortPlayerController;
class UFortAIEncounterInfo;

USTRUCT()
struct FFortActiveThreatPlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerController> PlayerController;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> Encounter;

};

UCLASS(Abstract, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMission_ActiveThreat : public AFortMission
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortMission_ActiveThreat")
	bool bStartBasedOnAthenaGamePhases;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_ActiveThreat", meta=(EditCondition="bStartBasedOnAthenaGamePhases"))
	EAthenaGamePhase StartingGamePhase;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_ActiveThreat")
	float StartingDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_ActiveThreat")
	int32 StartingActiveThreatEncounterIndex;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_ActiveThreat")
	FFortEncounterSettings EncounterSettings;

	UPROPERTY(Transient)
	TArray<FFortActiveThreatPlayerData> PlayerData;

	UPROPERTY(Transient)
	float SyncedEncounterStartingTime;

	UPROPERTY(Transient)
	int32 CurrentActiveThreatEncounterIndex;

};

