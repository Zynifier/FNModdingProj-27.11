// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_TDM.generated.h"

class AFortPlayerStateAthena;
class APlayerState;

USTRUCT(BlueprintType)
struct FTDMPlayerStandingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	bool bIsLocalPlayer;

	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	int32 PlayerScore;

	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	uint8 PlayerTeamId;

	UPROPERTY(BlueprintReadOnly, Category="TDMPlayerStandingInfo")
	int32 PlayerRanking;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTDMPlayerStandingsChanged, const TArray<FTDMPlayerStandingInfo>&, OrderedPlayerScores);

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TDM : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnTDMPlayerStandingsChanged OnPlayerStandingsChanged;

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FTDMPlayerStandingInfo> GetPlayerStandings() const;

	UFUNCTION()
	void OnMutatorGenericIntegerUpdated(int32 GenericIntegerIndex, int32 NewIntegerValue);

	UFUNCTION()
	virtual void OnPlayerKillScoreChanged(AFortPlayerStateAthena* PlayerState, const int32 NewKillScore);

	UFUNCTION()
	void OnPlayerStateAdded(APlayerState* AddedPlayerState);

	UFUNCTION()
	void OnPlayerStateRemoved(APlayerState* RemovedPlayerState);

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat NumKillsForVictory;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat EnableGoalScoreScaling;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat MinGoalScore;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat GoalScoreBucketSize;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat GoalScoreGridSnapValue;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat GoalScoreMinToWin;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat AllowSpectatingAfterDeath;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	bool bIsTwoTeamTDM;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_TDM")
	bool bShouldGrantInventoryToNewPlayers;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_TDM")
	FScalableFloat bShouldCalculateRespawnLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_TDM")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_Intro;

};

