// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortGameplayDataTrackerComponent.generated.h"

class AActor;
class ABuildingActor;
class AFortGameStateAthena;
class AFortPawn;
class UFortGameplayDataTrackerComponent;

UENUM()
enum class EFortGameplayDataTrackerEventContributionType : uint8
{
	Accumulate = 0,
	Set = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortGameplayDataTrackerChangedHasAnyEventValue, UFortGameplayDataTrackerComponent*, DataTrackerComponent, bool, bHasEventValues);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortTrackedGameplayDataRangeChangedInternal, bool, bIsInRange, const FGameplayTag&, AccumulationTag, const FGameplayTag&, RangeTag);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FFortTrackedGameplayDataRangeChanged, bool, bIsInRange, const FGameplayTag&, AccumulationTag, const FGameplayTag&, RangeTag);

USTRUCT(BlueprintType)
struct FFortGameplayDataTrackerThreshold
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerThreshold")
	FScalableFloat EnterValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerThreshold")
	FScalableFloat ExitValue;

};

USTRUCT(BlueprintType)
struct FFortGameplayDataTrackedRange
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackedRange")
	FGameplayTag RangeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackedRange")
	FFortGameplayDataTrackerThreshold LowerThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackedRange")
	FFortGameplayDataTrackerThreshold UpperThreshold;

	UPROPERTY(Transient)
	FFortTrackedGameplayDataRangeChangedInternal RangeChangedInternalDelegate;

	UPROPERTY(Transient)
	bool bIsCurrentlyInRange;

};

USTRUCT(BlueprintType)
struct FFortGameplayDataTrackerAccumulationContributor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerAccumulationContributor")
	FGameplayTag EventTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerAccumulationContributor")
	FScalableFloat EventValueMultiplier;

	UPROPERTY(Transient)
	float CurrentValue;

};

USTRUCT(BlueprintType)
struct FFortGameplayDataTrackerAccumulation
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerAccumulation")
	FGameplayTag AccumulationTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerAccumulation", meta=(TitleProperty="EventTag"))
	TArray<FFortGameplayDataTrackerAccumulationContributor> Contributions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameplayDataTrackerAccumulation", meta=(TitleProperty="RangeTag"))
	TArray<FFortGameplayDataTrackedRange> TrackedRanges;

	UPROPERTY(Transient)
	float CurrentValue;

};

USTRUCT()
struct FFortGameplayDataTrackerActorStateConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FGameplayTag StateTag;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FGameplayTag EventTag;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat ShouldUseDistanceCheck;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat ShouldInterpolateValueOverDistance;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat DistanceNear;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat DistanceFar;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat DistancePercentLerpExponent;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat ShouldUseDotProductTest;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat DotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat DotProductFalureMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat ShouldHaveFirstEntryEvent;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FGameplayTag FirstEntryEvent;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventGuaranteedRange;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventNearComparisonRange;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventTrackedActorFacingNearDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventTrackedActorFacingFarDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventAvatarActorFacingNearDotProductComparisonValue;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateConfig")
	FScalableFloat FirstEntryEventAvatarActorFacingFarDotProductComparisonValue;

};

USTRUCT()
struct FFortGameplayDataTrackerTrackedActorState
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AActor> TrackedActor;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> TrackedActorAsPawn;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> TrackedActorAsBuilding;

	UPROPERTY(Transient)
	FGameplayTag CurrentState;

	UPROPERTY(Transient)
	bool bHasUnprocessedStateEntry;

};

USTRUCT()
struct FFortGameplayDataTrackerActorStateGroupConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateGroupConfig")
	TArray<TSoftClassPtr<AActor>> RelevantActorClasses;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateGroupConfig")
	bool bAllowDBNOPawns;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerActorStateGroupConfig", meta=(TitleProperty="StateTag"))
	TArray<FFortGameplayDataTrackerActorStateConfig> StateConfigs;

	UPROPERTY(Transient)
	TArray<FFortGameplayDataTrackerTrackedActorState> ActorStates;

};

USTRUCT()
struct FFortGameplayDataTrackerEventConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerEventConfiguration")
	FGameplayTag EventTag;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerEventConfiguration")
	FScalableFloat CoolDownRate;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerEventConfiguration")
	EFortGameplayDataTrackerEventContributionType ContributionType;

};

USTRUCT()
struct FFortGameplayDataTrackerEventValue
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTag EventTag;

	UPROPERTY(Transient)
	float Value;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameplayDataTrackerComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortGameplayDataTrackerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	bool AddDataAccumulation(FFortGameplayDataTrackerAccumulation Accumulation);

	UFUNCTION(BlueprintPure)
	float GetAccumulationValue(const FGameplayTag& AccumulationTag) const;

	UFUNCTION(BlueprintPure)
	float GetEventValue(const FGameplayTag& EventTag) const;

	UFUNCTION(BlueprintCallable)
	bool RegisterForAccumulationRangeEvents(const FGameplayTag& AccumulationTag, const FGameplayTag& RangeTag, UPARAM(DisplayName="Event") FFortTrackedGameplayDataRangeChanged Delegate);

	UFUNCTION(BlueprintCallable)
	bool RegisterForEventValueRange(const FGameplayTag& Event, FFortGameplayDataTrackedRange Range, UPARAM(DisplayName="Event") FFortTrackedGameplayDataRangeChanged Delegate);

	UFUNCTION(BlueprintCallable)
	virtual void TriggerEvent(const FGameplayTag& EventTag, float Value = 1.000000f);

protected:
	UFUNCTION()
	void OnRep_EventValues();

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent")
	bool bShouldReplicateEvents;

	UPROPERTY(BlueprintAssignable)
	FFortGameplayDataTrackerChangedHasAnyEventValue OnChangedHasAnyEventValue;

private:
	UFUNCTION()
	void HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent")
	FScalableFloat TrackerEnabled;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent")
	bool bUseFirstPlayerControllerViewTargetAsAvatarActor;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent", meta=(TitleProperty="EventTag"))
	TArray<FFortGameplayDataTrackerEventConfiguration> EventsToTrack;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent", meta=(TitleProperty="RelevantActorClasses"))
	TArray<FFortGameplayDataTrackerActorStateGroupConfig> ActorStateGroupsToTrack;

	UPROPERTY(EditAnywhere, Category="FortGameplayDataTrackerComponent", meta=(TitleProperty="AccumulationTag"))
	TArray<FFortGameplayDataTrackerAccumulation> AccumulationsToTrack;

	UPROPERTY(Transient)
	TArray<FFortGameplayDataTrackerEventConfiguration> FullEventsToTrackList;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EventValues)
	TArray<FFortGameplayDataTrackerEventValue> ReplicatedEventValues;

	UPROPERTY(Transient)
	TArray<FFortGameplayDataTrackerEventValue> EventValues;

	UPROPERTY(Transient)
	TArray<FFortGameplayDataTrackerAccumulation> DataAccumulations;

	UPROPERTY(Transient)
	TArray<FFortGameplayDataTrackerAccumulation> PendingDataAccumulationRegistrations;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

	UPROPERTY()
	float VislogFrequencySeconds;

	UPROPERTY()
	float LastVislogTime;

};

