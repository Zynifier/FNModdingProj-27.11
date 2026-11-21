// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "VotingFrameworkTypes.h"
#include "VoteListenerComponent.generated.h"

enum class EVoteSessionNetworkType : uint8;
enum class EVoteSessionState : uint8;
enum class EVoteState : uint8;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Voting"), meta=(BlueprintSpawnableComponent))
class UVoteListenerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteSessionSetup OnVoteSessionSetupEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteSessionVoting OnVoteSessionVotingEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteSetup OnVoteSetupEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteStart OnVoteStartEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteChange OnVoteChangeEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteEnd OnVoteEndEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteSessionComplete OnVoteSessionCompleteEvent;

	UPROPERTY(BlueprintAssignable, Category="VotingFramework")
	FOnVoteSessionShutdown OnVoteSessionShutdownEvent;

protected:
	UFUNCTION()
	virtual void OnVoteChange(const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, const FGameplayTag& VoteSelectionId, int32 ServerVoteTotal, int32 AllServersVoteTotal);

	UFUNCTION()
	virtual void OnVoteEnd(const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, const FGameplayTag& WinningVoteSelectionId, EVoteState VoteState);

	UFUNCTION()
	virtual void OnVoteSessionComplete(const FGameplayTag& VoteSessionId);

	UFUNCTION()
	virtual void OnVoteSessionSetup(const FGameplayTag& VoteSessionId, const FGameplayTag& StartingVoteId, EVoteSessionNetworkType NetworkType, EVoteSessionState SessionState);

	UFUNCTION()
	virtual void OnVoteSessionShutdown(const FGameplayTag& VoteSessionId);

	UFUNCTION()
	virtual void OnVoteSessionVoting(const FGameplayTag& VoteSessionId, const FGameplayTag& StartingVoteId, EVoteSessionState SessionState);

	UFUNCTION()
	virtual void OnVoteSetup(const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, EVoteState VoteState);

	UFUNCTION()
	virtual void OnVoteStart(const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, EVoteState VoteState);

	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTagContainer RequestedVoteSessionIds;

	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTagContainer RequestedVoteIds;

	UPROPERTY(EditAnywhere, Category="VotingFramework")
	FGameplayTagContainer RequestedVoteSelectionIds;

};

