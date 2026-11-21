// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortTeamEnum.h"
#include "FortAthenaMutator_TeamPerformanceMessage.generated.h"

UENUM(BlueprintType)
enum class ETeamPerformanceMessageReplicationType : uint8
{
	/** Variable replication. Low cost, mostly reliable. If several messages are sent near the same time only the last message will get sent.*/
	VariableReplication = 0,
	/** Unreliable function replication. Low cost, some messages will get lost. Losses are less predictable than with variable replication.
	*	Sometimes many messages sent one after another will get through, sometimes a message sent by itself will be lost.*/
	MulticastFunction_Unreliable = 1,
	/** Reliable function replication. High cost, and there is a limit to how many reliable functions can run at once. But messages should ALWAYS get through.
	*	ONLY use this setting if the message canNOT be called frequently and there is a safe limit for how many of these messages will get run near the same time. (If you aren't sure what that is, ask an engineer.)*/
	MulticastFunction_Reliable = 2,
};

UENUM(BlueprintType)
enum class ETeamPerformanceMessageTrackingStat : uint8
{
	/** How many points a team has scored. Threshold values should be integers. */
	TeamScore = 0,
	/** How many points a team has relative to the goal score. Threshold values should be 0 < x <= 1 */
	TeamScorePercent = 1,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTeamPerformanceMessageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	FName NameIdentifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	FScalableFloat bEnabledHotfix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	TMap<TEnumAsByte<EFortTeamAffiliation::Type>, FAthenaGameMessageData> TeamAffiliationMessagesMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	ETeamPerformanceMessageTrackingStat TrackingStat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	FScalableFloat StatThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	ETeamPerformanceMessageReplicationType ReplicationType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TeamPerformanceMessageData")
	int32 NumberOfTeamsToTriggerFor;

	UPROPERTY(Transient)
	TArray<uint8> TeamsThatTriggeredMessage;

	UPROPERTY(Transient)
	uint8 bEnabledInternal : 1;

	UPROPERTY(Transient)
	uint8 bCanStillBeTriggered : 1;

	UPROPERTY(Transient)
	int32 MessageIndex;

};

USTRUCT()
struct FTeamPerformanceMessageReplication
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MessageIndex;

	UPROPERTY()
	uint8 TeamId;

	UPROPERTY()
	uint8 ReplicationTriggerIndex;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TeamPerformanceMessage : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetMessageEnabled(const FName NameIdentifier, const bool bEnabled);

protected:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastTriggerMessage_Reliable(const FTeamPerformanceMessageReplication& InMessageTrigger);

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastTriggerMessage_Unreliable(const FTeamPerformanceMessageReplication& InMessageTrigger);

	UFUNCTION()
	void OnGoalScoreChanged();

	UFUNCTION()
	void OnRep_MessageTriggerReplicated();

	UFUNCTION()
	void OnTeamScoreChanged(const uint8 TeamId, const int32 NewScore);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_TeamPerformanceMessage")
	TArray<FTeamPerformanceMessageData> MessageDatas;

	UPROPERTY(ReplicatedUsing=OnRep_MessageTriggerReplicated)
	FTeamPerformanceMessageReplication MessageTriggerReplicated;

};

