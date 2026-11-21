// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Rounds.generated.h"

class AFortAthenaMutator_MatchConditionManager;
class AFortAthenaMutator_Rounds;
enum class EAthenaRoundsMutatorPhase : uint8;
enum class EMatchConditionMutatorTimingType : uint8;

UENUM(BlueprintType)
enum class EAthenaRoundsMutatorPhase : uint8
{
	/** GamePhase is EAthenaGamePhase::Setup */
	GamePhase_Setup = 0,
	/** GamePhase is EAthenaGamePhase::Warmup */
	GamePhase_Warmup = 1,
	/** Fade transition between GamePhase_Warmup or RoundEndUI and the next round's RoundSetup */
	FadeOutToNextRound = 2,
	/** A new round is setting up */
	RoundSetup = 3,
	/** A round is in progress */
	RoundPlay = 4,
	/** Round or match condition has been satisfied.  Wait for a time before RoundEndUI/MatchEndUI. */
	RoundEnd = 5,
	/** Round end UI is displayed, before going back to FadeOutToNextRound */
	RoundEndUI = 6,
	/** Match end UI is displayed */
	MatchEndUI = 7,
	/** GamePhase jumped to EAthenaGamePhase::EndGame before we reached MatchEndUI.
	  * This probably means that low-level code ended the match automatically.
	  * The LTM may need to override a mutator function, alter playlist settings, etc. to prevent this. */
	MatchEndedPrematurely = 8,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRoundsMutatorPhaseChanged, const AFortAthenaMutator_Rounds*, Mutator, const EAthenaRoundsMutatorPhase, Phase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRoundsMutatorRoundAdvanced, const AFortAthenaMutator_Rounds*, Mutator, const int32, Round);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Actor", "Cooking", "FortAthenaMutator", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Rounds : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetLastCompletedRoundNum() const;

	UFUNCTION(BlueprintPure)
	EAthenaRoundsMutatorPhase GetPhase() const;

	UFUNCTION(BlueprintPure)
	int32 GetRoundNum() const;

	UPROPERTY(BlueprintAssignable)
	FRoundsMutatorPhaseChanged OnPhaseChanged;

	UPROPERTY(BlueprintAssignable)
	FRoundsMutatorRoundAdvanced OnRoundAdvanced;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Rounds")
	FText HUDLoadingReasonText;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Rounds")
	FScalableFloat NextRoundFadeOutDuration;

	UPROPERTY(EditDefaultsOnly, Category="RoundEnd")
	FScalableFloat RoundEndTimeDilationDuration;

	UPROPERTY(EditDefaultsOnly, Category="RoundEnd")
	FScalableFloat RoundEndDuration;

	UPROPERTY(EditDefaultsOnly, Category="RoundEnd")
	FScalableFloat TimeUntilRoundEndUICoversScreen;

	UPROPERTY(EditDefaultsOnly, Category="RoundEnd")
	FScalableFloat RoundEndUIDuration;

private:
	UFUNCTION()
	void OnMatchConditionTimingSatisfied(const EMatchConditionMutatorTimingType TimingType);

	UFUNCTION()
	void OnRep_CurrentRoundNum();

	UFUNCTION()
	void OnRep_RoundPhase(const EAthenaRoundsMutatorPhase OldRoundPhase);

	UPROPERTY(ReplicatedUsing=OnRep_RoundPhase)
	EAthenaRoundsMutatorPhase RoundPhase;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentRoundNum)
	int32 CurrentRoundNum;

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_MatchConditionManager> MatchConditionManager;

};

UCLASS()
class UFortCheatManager_RoundsMutator : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void RoundsMutatorDebug(const float TextScale = 1.000000f);

};

