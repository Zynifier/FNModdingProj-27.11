// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_MatchCondition.generated.h"

class AFortAthenaMutator_MatchCondition;
class AFortAthenaMutator_MatchConditionManager;
enum class EAthenaGamePhase : uint8;

UENUM()
enum class EMatchConditionMutatorTeamStatus : uint8
{
	/** Not yet designated as winner or loser in the current segment of the match */
	None = 0,
	/** Won the current segment of the match */
	Won = 1,
	/** Lost the current segment of the match */
	Lost = 2,
	/** Already placed or disconnected in a previous segment of the match.  Never counted again as winning or losing. */
	Placed = 3,
};

UENUM()
enum class EMatchConditionMutatorTimingType : uint8
{
	/** End round immediately when condition is satisfied */
	Round = 0,
	/** End match when the end of round is reached */
	MatchAtEndOfRound = 1,
	/** End match immediately when condition is satisfied */
	MatchImmediate = 2,
	COUNT = 3 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMatchConditionMutatorSatisfied, const AFortAthenaMutator_MatchCondition*, MatchConditionMutator, const bool, bSatisfied);

USTRUCT()
struct FMatchConditionMutatorTeamData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamNum;

	UPROPERTY()
	EMatchConditionMutatorTeamStatus TeamStatus;

};

UCLASS(Abstract, HideCategories=("Actor", "Cooking", "FortAthenaMutator", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MatchCondition : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnGamePhaseChanged(const EAthenaGamePhase NewPhase, const EAthenaGamePhase PreviousHighestGamePhaseProcessed);

	UFUNCTION()
	void OnRep_bSatisfied();

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_MatchCondition")
	FScalableFloat bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_MatchCondition")
	EMatchConditionMutatorTimingType TimingType;

	UPROPERTY(Replicated)
	TObjectPtr<AFortAthenaMutator_MatchConditionManager> MatchConditionManager;

private:
	UPROPERTY(ReplicatedUsing=OnRep_bSatisfied)
	uint8 bSatisfied : 1;

	UPROPERTY(Replicated)
	uint8 bLocked : 1;

	UPROPERTY(Replicated)
	uint8 bLockedPermanently : 1;

	UPROPERTY(Replicated)
	TArray<FMatchConditionMutatorTeamData> TeamDataArray;

};

