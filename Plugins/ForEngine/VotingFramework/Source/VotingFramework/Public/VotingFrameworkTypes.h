// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "VotingFrameworkTypes.generated.h"

class UWorld;
enum class EVoteSessionNetworkType : uint8;
enum class EVoteSessionState : uint8;
enum class EVoteState : uint8;

UENUM(BlueprintType)
enum class EVoteSessionNetworkType : uint8
{
	// We have not determined the network type yet

	NotDetermined = 0,
	// Uses a dedicated server, but not a mesh network of servers

	DedicatedServer = 1,
	// A mesh network of servers

	MeshNetwork = 2,
};

UENUM(BlueprintType)
enum class EVoteSessionState : uint8
{
	None = 0,
	Setup = 1,
	Voting = 2,
	Complete = 3,
	Shutdown = 4,
};

UENUM(BlueprintType)
enum class EVoteState : uint8
{
	None = 0,
	Setup = 1,
	Active = 2,
	Completed = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnVoteCasted, const FUniqueNetIdRepl&, UserNetId, const FGameplayTag&, VoteSessionId, const FGameplayTag&, VoteId, const FGameplayTag&, VoteSelectionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnVoteChange, const FGameplayTag&, VoteSessionId, const FGameplayTag&, VoteId, const FGameplayTag&, VoteSelectionId, int32, ServerVoteTotal, int32, AllServersVoteTotal);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnVoteEnd, const FGameplayTag&, VoteSessionId, const FGameplayTag&, VoteId, const FGameplayTag&, WinningVoteSelectionId, EVoteState, VoteState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVoteSessionComplete, const FGameplayTag&, VoteSessionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnVoteSessionSetup, const FGameplayTag&, VoteSessionId, const FGameplayTag&, StartingVoteId, const EVoteSessionNetworkType, NetworkType, EVoteSessionState, SessionState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVoteSessionShutdown, const FGameplayTag&, VoteSessionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVoteSessionVoting, const FGameplayTag&, VoteSessionId, const FGameplayTag&, StartingVoteId, EVoteSessionState, SessionState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVoteSetup, const FGameplayTag&, VoteSessionId, const FGameplayTag&, VoteId, EVoteState, VoteState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVoteStart, const FGameplayTag&, VoteSessionId, const FGameplayTag&, VoteId, EVoteState, VoteState);

USTRUCT()
struct FCastedVote
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FName VoteSessionId;

	UPROPERTY(Transient)
	FName VoteId;

	UPROPERTY(Transient)
	FName VoteSelectionId;

};

USTRUCT()
struct FVoteRuntime : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

protected:
	UPROPERTY(Transient)
	FName VoteSessionId;

	UPROPERTY(Transient)
	FName VoteId;

	UPROPERTY(Transient)
	TArray<FName> VoteSelectionIds;

	UPROPERTY(Transient)
	EVoteState VoteState;

	UPROPERTY(Transient)
	FName VoteSelectionWinningResult;

	UPROPERTY(Transient, NotReplicated)
	FName Shadow_VoteSelectionWinningResult;

	UPROPERTY(Transient, NotReplicated)
	EVoteState Shadow_VoteState;

};

USTRUCT()
struct FVoteRuntimeArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

protected:
	UPROPERTY(Transient)
	TArray<FVoteRuntime> VotingResults;

};

USTRUCT(BlueprintType)
struct FVoteSelection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTag VoteSessionId;

	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTag VoteId;

	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTag VoteSelectionId;

};

USTRUCT(BlueprintType)
struct FVoteSelectionResults : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

protected:
	UPROPERTY(Transient)
	FName VoteSessionId;

	UPROPERTY(Transient)
	FName VoteId;

	UPROPERTY(Transient)
	FName VoteSelectionId;

	UPROPERTY(Transient)
	int32 ServerVoteTotal;

	UPROPERTY(Transient)
	int32 AllServersVoteTotal;

	UPROPERTY(Transient, NotReplicated)
	int32 Shadow_ServerVoteTotal;

	UPROPERTY(Transient, NotReplicated)
	int32 Shadow_AllServersVoteTotal;

};

USTRUCT()
struct FVoteSelectionResultsArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

protected:
	UPROPERTY(Transient)
	TArray<FVoteSelectionResults> VoteSelectionResults;

};

USTRUCT(BlueprintType)
struct FVoteSelectionSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FGameplayTag VoteSelectionId;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FText VoteSelectionText;

};

USTRUCT()
struct FVoteSessionRuntime : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FName VoteSessionId;

	UPROPERTY(Transient)
	EVoteSessionNetworkType NetworkType;

	UPROPERTY(Transient)
	EVoteSessionState VoteSessionState;

	UPROPERTY(Transient)
	FName CurrentVoteId;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

	UPROPERTY(Transient, NotReplicated)
	EVoteSessionState Shadow_VoteSessionState;

};

USTRUCT()
struct FVoteSessionRuntimeArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> WorldRef;

protected:
	UPROPERTY(Transient)
	TArray<FVoteSessionRuntime> VotingSessions;

};

USTRUCT(BlueprintType)
struct FVoteSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FGameplayTag VoteId;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	bool bLocksSelection;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FText VoteText;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	TArray<FVoteSelectionSettings> VoteSelections;

};

USTRUCT(BlueprintType)
struct FVoteSessionSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FGameplayTag VoteSessionId;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	FText VoteSessionText;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	TArray<FVoteSettings> VoteSettingsList;

	UPROPERTY(EditDefaultsOnly, Category="VotingFramework")
	EVoteSessionNetworkType NetworkType;

};

