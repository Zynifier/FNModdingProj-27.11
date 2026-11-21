// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortItemQuantityPair.h"
#include "Quests/ManagerParticipantSubsetID.h"
#include "QuestTypes.generated.h"

class AActor;
class APlayerState;
class UFortQuestItemDefinition;

UENUM()
enum class EQuestObjectiveUpdateType : uint8
{
	Progressed = 0,
	ResetObjective = 1,
	ResetQuest = 2,
};

UENUM(BlueprintType)
enum class EQuestParticipationScope : uint8
{
	None = 0,
	/** Quest should be granted through the player's UControllerComponent_Quests */
	Personal = 1,
	/** Quest should be granted through the playspace's UPlayspaceComponent_Quests */
	Playspace = 2,
	/** Quest should be granted through the world's UGameStateComponent_Quests */
	World = 3,
	/** Quest should be granted through the world's UGameStateComponent_SquadQuests */
	Squad = 4,
	/** Quest should be granted through the world's UGameStateComponent_PartyQuests */
	Party = 5,
};

USTRUCT()
struct FQuestInstanceInitializationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FManagerParticipantSubsetID ManagerParticipantSubsetID;

	UPROPERTY()
	TWeakObjectPtr<AActor> QuestOwner;

};

USTRUCT()
struct FFortGrantedQuestData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> QuestDefinition;

	UPROPERTY()
	bool bQuestLoadedFromPersistence;

	UPROPERTY()
	TArray<int32> InitialQuestAchievedCounts;

	UPROPERTY()
	FQuestInstanceInitializationData QuestInstanceInitData;

	UPROPERTY()
	FDateTime QuestExpiration;

	UPROPERTY()
	TArray<FString> QuestPlaylists;

	UPROPERTY()
	FString QuestBucket;

};

USTRUCT()
struct FFortGrantedQuestDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortGrantedQuestData> GrantedQuestArray;

};

USTRUCT(BlueprintType)
struct FQuestCompletionNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestCompletionNode", meta=(GetOptions="Editor_GetValidObjectives"))
	FName Objective;

};

USTRUCT(BlueprintType)
struct FQuestCompletionSegment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestCompletionSegment")
	TArray<FQuestCompletionNode> CompletionNodes;

	UPROPERTY(EditAnywhere, Category="QuestCompletionSegment", meta=(ArrayClamp="CompletionNodes"))
	int32 RequiredNodeCompletions;

	UPROPERTY(EditAnywhere, Category="QuestCompletionSegment")
	bool bSegmentCommitment;

};

USTRUCT(BlueprintType)
struct FQuestCompletionPath
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestCompletionPath")
	TArray<FQuestCompletionSegment> CompletionSegments;

	UPROPERTY(EditAnywhere, Category="QuestCompletionPath")
	bool bPathCommitment;

};

USTRUCT(BlueprintType)
struct FQuestCompletionResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestCompletionResult")
	TArray<FFortItemQuantityPair> Rewards;

};

USTRUCT(BlueprintType)
struct FQuestInstanceParticipantConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="QuestInstanceParticipantConfiguration")
	uint8 bContributes : 1;

	UPROPERTY(EditAnywhere, Category="QuestInstanceParticipantConfiguration")
	uint8 bObserves : 1;

	UPROPERTY(EditAnywhere, Category="QuestInstanceParticipantConfiguration")
	uint8 bReceives : 1;

};

USTRUCT()
struct FUpdatedQuestObjectiveData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestID;

	UPROPERTY()
	FName BackendName;

	UPROPERTY()
	TWeakObjectPtr<APlayerState> OwningPlayer;

	UPROPERTY()
	FManagerParticipantSubsetID ManagerParticipantSubsetID;

private:
	UPROPERTY()
	int32 UpdatedCount;

	UPROPERTY()
	EQuestObjectiveUpdateType QuestObjectiveUpdateType;

	UPROPERTY(Transient)
	TWeakObjectPtr<APlayerState> ContributingPlayer;

};

USTRUCT()
struct FUpdatedQuestObjectiveDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FUpdatedQuestObjectiveData> Objectives;

};

