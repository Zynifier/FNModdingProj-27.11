// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_FF2.generated.h"

class AAthenaBuildingFoundationObjective;
class UCustomCharacterPart;

USTRUCT(BlueprintType)
struct FTargetDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AAthenaBuildingFoundationObjective>> Targets;

	UPROPERTY(EditAnywhere, Category="TargetDataEntry")
	FGameplayTag FoundationTag;

	UPROPERTY(EditAnywhere, Category="TargetDataEntry")
	FScalableFloat HealthPercentRequiredToMoveOn;

	UPROPERTY(EditAnywhere, Category="TargetDataEntry")
	bool bFindInStormCircle;

	UPROPERTY(EditAnywhere, Category="TargetDataEntry")
	TArray<int32> StormCircleIndices;

protected:
	UPROPERTY(EditAnywhere, Category="TargetDataEntry")
	FScalableFloat NumberOfFoundationsToFind;

};

USTRUCT()
struct FTeamSetupDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TeamSetupDataEntry")
	uint8 TeamNum;

	UPROPERTY(EditAnywhere, Category="TeamSetupDataEntry")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_FF2 : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_CurrentRound();

	UFUNCTION()
	void OnRep_EndOfLastRoundServerTime();

	UFUNCTION()
	void UpdateHealth();

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AAthenaBuildingFoundationObjective>> FoundationsToWatch;

	UPROPERTY()
	TArray<TObjectPtr<AAthenaBuildingFoundationObjective>> AllObjectiveFoundations;

	UPROPERTY(EditAnywhere, Category="Target Data")
	TArray<FTargetDataEntry> TargetData;

	UPROPERTY(EditAnywhere, Category="Head Data")
	TArray<FTeamSetupDataEntry> TeamSetupData;

	UPROPERTY(EditAnywhere, Category="Misc Data")
	FScalableFloat LastRoundLength;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentRound)
	int32 CurrentRound;

	UPROPERTY(Replicated)
	float CurrentHealth;

	UPROPERTY(Replicated)
	float MaxHealth;

	UPROPERTY(ReplicatedUsing=OnRep_EndOfLastRoundServerTime)
	float EndOfLastRoundServerTime;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_1x1_LowHealth;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_3x3_LowHealth;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_5x5_LowHealth;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_Round_1_Done;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_Round_2_Done;

};

