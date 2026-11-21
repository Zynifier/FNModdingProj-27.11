// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "VoteListenerComponent.h"
#include "VotingFrameworkTypes.h"
#include "VoteResponderComponent.generated.h"

class APlayerState;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Voting"), meta=(BlueprintSpawnableComponent))
class UVoteResponderComponent : public UVoteListenerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="VotingFramework | Responder")
	void CastDefaultVoteSelection(const APlayerState* InPlayerState);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Responder")
	void CastManualVoteSelection(const APlayerState* InPlayerState, const FGameplayTag& VoteSelection);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Responder")
	void CastManualVoteSelectionAtIndex(const APlayerState* InPlayerState, const int32 SelectionIndex);

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCastVoteSelection(const FUniqueNetIdRepl& InUserId, const FCastedVote& CastedVote);

	UPROPERTY(EditAnywhere, Replicated, Category="VotingFramework")
	TArray<FVoteSelection> SupportedVoteSelections;

	UPROPERTY(EditAnywhere, Replicated, Category="VotingFramework")
	bool bShouldLockVotingAfterCasted;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, FCastedVote> PlayerCastedVotesMap;

	UPROPERTY(Transient)
	FName ActiveVoteSessionId;

	UPROPERTY(Transient)
	FName ActiveVoteId;

};

