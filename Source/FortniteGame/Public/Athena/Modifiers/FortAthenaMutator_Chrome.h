// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_Chrome.generated.h"

class AAthenaChromeTraversePoint;
class AAthenaTraversePoint;
class AFortAthenaMutator_SynchronizedTeleport;
class AFortPlayerStateAthena;
class AFortSquadStart;
class UGameplayEffect;

USTRUCT()
struct FChromeRoute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ChromeRoute")
	FFortSquadStartSearchParamData SquadStartSearchParam;

	UPROPERTY(EditDefaultsOnly, Category="ChromeRoute")
	TArray<FGameplayTag> FinishPOITags;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Chrome : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FText TeleportingPlayersText;

	UPROPERTY(EditAnywhere, Category="Waypoints")
	TSubclassOf<AAthenaChromeTraversePoint> TraversePointClass;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	TArray<FPrimaryAssetId> ChromeVehicleAssetIds;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FFortSquadStartSearchParamData VehicleStartSearchParam;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	TSubclassOf<UGameplayEffect> FuelSettingGE;

	UPROPERTY(EditDefaultsOnly, Category="Score")
	FScalableFloat ScoreToWin;

	UPROPERTY(EditDefaultsOnly, Category="Routes")
	FScalableFloat bUseOverridingSpawnTransforms;

	UPROPERTY(EditDefaultsOnly, Category="Routes")
	TArray<FTransform> OverridingSpawnTransforms;

	UPROPERTY(EditDefaultsOnly, Category="Routes")
	TArray<FChromeRoute> Routes;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat CountdownDuration;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat NumOfTeamsToFinishBeforeFinalizeWinner;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_ChromeInfoMessage;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	TArray<FAthenaGameMessageData> GameMsg_RaceCountdownMessage;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_FinishPointReached;

private:
	UFUNCTION()
	void HandleTeleportComplete();

	UFUNCTION()
	void OnRep_FinishTraversePoint();

	UFUNCTION()
	void OnRep_RaceStarted();

	UFUNCTION()
	void OnTraversePointTouched(AAthenaTraversePoint* PointActor, AFortPlayerStateAthena* TouchingPlayer);

	UPROPERTY()
	TArray<TObjectPtr<AFortSquadStart>> ChromeSquadStarts;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> FinishedPlayerStates;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_SynchronizedTeleport> TeleportMutator;

	UPROPERTY(ReplicatedUsing=OnRep_FinishTraversePoint)
	TObjectPtr<AAthenaChromeTraversePoint> FinishTraversePoint;

	UPROPERTY(ReplicatedUsing=OnRep_RaceStarted)
	bool bRaceStarted;

};

