// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LobbyBeaconState.h"
#include "FortLobbyBeaconState.generated.h"

class UFortMissionGenerator;

UENUM()
enum class ELobbyMissionGeneratorDetailsRequirement : uint8
{
	Unknown = 0,
	NotRequired = 1,
	Required = 2,
};

UCLASS(Abstract, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLobbyBeaconState : public ALobbyBeaconState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bIsLobbyTimerPaused;

protected:
	UFUNCTION()
	void OnRep_MissionGeneratorClassPath();

	UFUNCTION()
	void OnRep_MissionGeneratorDetailsRequirement();

	UPROPERTY(Replicated)
	int32 MatchmakingLevel;

	UPROPERTY(ReplicatedUsing=OnRep_MissionGeneratorClassPath)
	FString MissionGeneratorClassPath;

	UPROPERTY(Transient)
	TObjectPtr<UFortMissionGenerator> CachedMissionGeneratorCDO;

	UPROPERTY(ReplicatedUsing=OnRep_MissionGeneratorDetailsRequirement)
	ELobbyMissionGeneratorDetailsRequirement MissionGeneratorDetailsRequirement;

	UPROPERTY(Transient)
	bool bWorldRecordLoaded;

};

