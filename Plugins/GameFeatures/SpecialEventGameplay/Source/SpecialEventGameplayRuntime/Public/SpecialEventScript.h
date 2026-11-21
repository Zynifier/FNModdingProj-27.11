// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Modifiers/SpecialRelevancyNode.h"
#include "SpecialEventScript.generated.h"

class ASpecialEventPhase;
class ASpecialEventScript;
class UDataLayerAsset;
class ULevelStreamingDynamic;
class UMeshNetworkComponent;
class UWorld;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpecialEventScript_OnSpecialEventPhaseActivated, ASpecialEventScript*, SpecialEventScript, ASpecialEventPhase*, SpecialEventPhase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpecialEventScript_OnSpecialEventPhaseDeactivated, ASpecialEventScript*, SpecialEventScript, ASpecialEventPhase*, SpecialEventPhase);

USTRUCT(BlueprintType)
struct FPhaseLevelEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase")
	bool bLoadLevelOnScriptStart;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase", meta=(DisplayName="Level Starts Visible When Loaded"))
	bool bLevelStartsVisible;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase")
	bool bUnloadLevelOnPhaseEnd;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase")
	bool bMakeVisibleOnPhaseStart;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase", meta=(DisplayName="Make Visible At Phases"))
	FGameplayTagContainer MakeVisibleAtPhaseTags;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntryBase", meta=(DisplayName="Unload At Phases"))
	FGameplayTagContainer UnloadLevelAtPhaseTags;

};

USTRUCT(BlueprintType)
struct FPhaseDataLayerEntry : public FPhaseLevelEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseDataLayerEntry")
	TObjectPtr<UDataLayerAsset> DataLayerAsset;

protected:
	UPROPERTY(EditDefaultsOnly, Category="PhaseDataLayerEntry")
	bool bIsRecursive;

};

USTRUCT(BlueprintType)
struct FPhaseLevelEntry : public FPhaseLevelEntryBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseLevelEntry")
	TSoftObjectPtr<UWorld> LevelToLoad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseLevelEntry")
	FString LevelName;

	UPROPERTY(EditDefaultsOnly, Category="PhaseLevelEntry")
	bool bExcludeFromServerPreload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseLevelEntry")
	FVector Location;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseLevelEntry")
	FRotator Rotation;

private:
	UPROPERTY()
	TObjectPtr<ULevelStreamingDynamic> LevelInstance;

};

USTRUCT(BlueprintType)
struct FPhaseInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseInfo")
	FGameplayTag PhaseTag;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo")
	float PhaseDuration;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo")
	bool bSetRelevancyMode;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo", meta=(EditCondition="bSetRelevancyMode"))
	ESpecialRelevancyMode RelevancyMode;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo", meta=(EditCondition="RelevancyMode == ESpecialRelevancyMode::MultiSquad"))
	int32 NumOfSquadsInRelevancyGroup;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo", meta=(DisplayName="Requires Levels From Phases"))
	FGameplayTagContainer RequireLevelsFromPhaseTags;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo")
	bool bStartNextPhaseOnPhaseFinished;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo")
	bool bGarbageCollectAtPhaseStartOnServer;

	UPROPERTY(EditDefaultsOnly, Category="PhaseInfo")
	bool bGarbageCollectAtPhaseStartOnClient;

	UPROPERTY()
	TObjectPtr<ASpecialEventPhase> PhaseActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseInfo")
	TArray<FPhaseLevelEntry> Levels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PhaseInfo")
	TArray<FPhaseDataLayerEntry> DataLayers;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Actor", "Replication", "Tick", "ActorTick", "LOD", "Cooking", "Transform", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ASpecialEventScript : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AttemptFinishPhase(FGameplayTag PhaseTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AttemptStartNextPhase(FGameplayTag CurrentPhaseTag);

	UFUNCTION(BlueprintPure)
	int32 GetActivePhaseIndex() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void SetLocalPlayersSignificantForSpecialEventSequence(const bool bIsSignificant) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartEventAtIndex(const int32 InStartingIndex = 0, const float SequenceTimeOffset = 0.000000f);

	UPROPERTY(BlueprintAssignable)
	FSpecialEventScript_OnSpecialEventPhaseActivated OnSpecialEventPhaseActivated;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventScript_OnSpecialEventPhaseDeactivated OnSpecialEventPhaseDeactivated;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Script Finished"))
	void BP_OnScriptFinished();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Script Ready"))
	void BP_OnScriptReady();

	UFUNCTION()
	void OnRep_ReplicatedActivePhaseIndex();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	TArray<FPhaseInfo> PhaseInfoArray;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float DropDeadWindowSizeInSeconds;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float DelayAfterConentLoad;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float DelayAfterWarmup;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float ForceReturnToMainMenuTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float ForceReturnToMainMenuTimeRandomness;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float MinDelayReturnToMainMenu;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	float MaxDelayReturnToMainMenu;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	bool bPreloadAllLevelsOnServer;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	bool bAllowGarbageCollectionAfterUnload;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScript")
	bool bFullPurgeGC;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedActivePhaseIndex)
	int32 ReplicatedActivePhaseIndex;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMeshNetworkComponent> MeshNetworkComponent;

};

