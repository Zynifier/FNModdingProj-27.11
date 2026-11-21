// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Athena/Modifiers/SpecialRelevancyNode.h"
#include "Components/FortControllerComponent.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_FakeKillRelevancy.generated.h"

class AFortPlayerStateAthena;
class UFortControllerComponent_FakeKillRelevancy;

UENUM()
enum class EFakeKillRelevancyPlayerKillStep : uint8
{
	/** UFortControllerComponent_FakeKillRelevancy has been told the player should die, but blueprint has not yet been informed */
	Initiated = 0,
	/** Blueprint has been informed, but has not yet visually killed the player */
	BlueprintNotified = 1,
	/** Blueprint has called OnKillEffectsPlayed() to inform us that the player has been visually killed, and should now be considered "dead" by UI, etc. */
	VisualsPerformed = 2,
};

USTRUCT()
struct FFakeKillRelevancyBucket
{
	GENERATED_BODY()

};

USTRUCT()
struct FFakeKillRelevancyPhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag Reason;

	UPROPERTY()
	int32 NumWavesExpected;

	UPROPERTY()
	int32 WaveNum;

	UPROPERTY()
	float RelevancyDelay;

};

USTRUCT(BlueprintType)
struct FFakeKillRelevancyVictim
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FakeKillRelevancyVictim")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadWrite, Category="FakeKillRelevancyVictim")
	FVector DeathLocation;

};

USTRUCT(BlueprintType)
struct FFakeKillRelevancyPlayerDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FakeKillRelevancyPlayerDataEntry")
	TArray<FFakeKillRelevancyVictim> Victims;

	UPROPERTY(BlueprintReadOnly, Category="FakeKillRelevancyPlayerDataEntry")
	FGameplayTag Reason;

	UPROPERTY(BlueprintReadOnly, Category="FakeKillRelevancyPlayerDataEntry")
	int32 PhaseNum;

	UPROPERTY(BlueprintReadOnly, Category="FakeKillRelevancyPlayerDataEntry")
	int32 WaveNum;

	UPROPERTY()
	float RelevancyDelay;

	UPROPERTY()
	float RelevancyChangeServerWorldTime;

};

USTRUCT()
struct FFakeKillRelevancyPlayerDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFakeKillRelevancyPlayerDataEntry> Entries;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_FakeKillRelevancy> ControllerComponent;

};

USTRUCT()
struct FFakeKillRelevancySupergroup
{
	GENERATED_BODY()

};

USTRUCT()
struct FFakeKillRelevancyTestParameters
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_FakeKillRelevancy : public AFortAthenaMutator_SpecialRelevancy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetRelevancy();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetUpKillPhase(const int32 MaxPlayersRemaining, const FGameplayTag& Reason, const int32 NumWaves, const float RelevancyDelay);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartNextKillWave();

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_FakeKillRelevancy")
	TSubclassOf<UFortControllerComponent_FakeKillRelevancy> FakeKillControllerComponentClass;

private:
	UFUNCTION()
	void EndWave(const int32 EndPhaseNum, const int32 WaveNum);

	UPROPERTY(Replicated)
	TArray<FFakeKillRelevancyPhaseData> RelevancyPhaseDataArray;

	UPROPERTY(Replicated)
	int32 PhaseNum;

};

UCLASS()
class UFortCheatManager_FakeKillRelevancy : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void FakeKillRelevancyDebug(const float TextScale = 1.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void FakeKillRelevancyReset();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void FakeKillRelevancySetUpPhase(const int32 MaxPlayersRemaining, const FString& ReasonGameplayTagString, const int32 NumWaves, const float RelevancyDelay);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void FakeKillRelevancyStartNextWave();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void FakeKillRelevancyTestAlgorithm(const int32 NumPlayers, const FString& MaxPlayersRemainingAfterPhases, const int32 MinSquadSize = 0, const int32 MaxSquadSize = 0, const int32 Iterations = 1, const int32 LogVerbosity = 5);

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_FakeKillRelevancy : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="FakeKillRelevancy")
	void CancelKillEffectsOnClient(const TArray<AFortPlayerStateAthena*>& PlayerStates);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="FakeKillRelevancy")
	void CancelKillEffectsOnServer();

	UFUNCTION(BlueprintPure)
	FVector GetDeathLocation(const AFortPlayerStateAthena* PlayerState) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void OnKillEffectsPlayed(const AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintImplementableEvent, Category="FakeKillRelevancy")
	void PlayKillEffects(const FFakeKillRelevancyPlayerDataEntry& FakeKillData, const float RelevancyDelay);

	UFUNCTION(BlueprintAuthorityOnly, Category="FakeKillRelevancy")
	void ResetRelevancy();

private:
	UFUNCTION()
	void OnRep_ResetCounter();

	UPROPERTY(Replicated)
	FFakeKillRelevancyPlayerDataArray PlayerDataArray;

	UPROPERTY()
	TMap<TObjectPtr<AFortPlayerStateAthena>, EFakeKillRelevancyPlayerKillStep> ClientPlayerStateKillStepMap;

	UPROPERTY(ReplicatedUsing=OnRep_ResetCounter)
	uint8 ResetCounter;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AFortPlayerStateAthena>> DebugSupergroupPlayerStates;

};

