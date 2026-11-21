// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_SpecialEventTODM.generated.h"

class AActor;
class ASpecialEventPhase;
class ASpecialEventScript;
class IFortTimeOfDayManagerInterface;

UENUM(BlueprintType)
enum class ESpecialEventTODMModifyType : uint8
{
	/** Keep the GameState's TODM.  Don't modify visibility. */
	Keep = 0,
	/** Hide the GameState's TODM, but don't remove it from the GameState */
	Hide = 1,
	/** Show the GameState's TODM */
	Show = 2,
	/** Spawn a new TODM and provide it to the GameState.  Hide the GameState's old TODM. */
	Spawn = 3,
	/** Provide the GameState with the persistent level's TODM, or null if there isn't one.  Show the persistent TODM.  Hide the GameState's old TODM. */
	Persistent = 4,
	/** Destroy the GameState's TODM */
	Destroy = 5,
	/** Destroy all TODMs */
	DestroyAll = 6,
	/** Destroy all TODMs except the GameState's TODM */
	DestroyAllButGameState = 7,
};

USTRUCT(BlueprintType)
struct FSpecialEventTODMSubphaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMSubphaseData", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float PhaseTime;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMSubphaseData")
	ESpecialEventTODMModifyType ModifyType;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMSubphaseData", meta=(EditCondition="ModifyType == ESpecialEventTODMModifyType::Spawn"))
	TSubclassOf<AActor> SpawnClass;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMSubphaseData")
	float TimeOfDay;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMSubphaseData")
	float SpeedFactor;

};

USTRUCT(BlueprintType)
struct FSpecialEventTODMPhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMPhaseData")
	FGameplayTag PhaseTag;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventTODMPhaseData")
	TArray<FSpecialEventTODMSubphaseData> SubphaseDataArray;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Actor", "Cooking", "Events", "FortAthenaMutator", "HLOD", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpecialEventTODM : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="TimeOfDayManager")
	TArray<FSpecialEventTODMPhaseData> PhaseDataArray;

private:
	UFUNCTION()
	void OnPhaseActivated(ASpecialEventScript* InSpecialEventScript, ASpecialEventPhase* InSpecialEventPhase);

	UPROPERTY()
	TObjectPtr<ASpecialEventScript> SpecialEventScript;

	UPROPERTY(Replicated)
	int32 PhaseIndexInProgress;

	UPROPERTY(Replicated)
	int32 SubphaseIndexInProgress;

	UPROPERTY(Replicated)
	TScriptInterface<IFortTimeOfDayManagerInterface> SpawnedTODM;

	UPROPERTY(Replicated)
	bool bDebug;

};

UCLASS()
class UFortCheatManager_SpecialEventTODM : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpecialEventTODM_ToggleDebug();

};

