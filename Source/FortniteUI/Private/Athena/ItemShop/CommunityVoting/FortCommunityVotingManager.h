// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCommunityVotingManager.generated.h"

class UFortMtxOfferData;

UCLASS()
class UFortCommunityVotingManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void RefreshVotes(const bool IsIncrementing);

private:
	UFUNCTION()
	void OnNewVoteTimerEnd();

	UFUNCTION()
	void OnRevealTimerEnd();

	UFUNCTION()
	void OnVotingStateChanged();

	UFUNCTION()
	void OnVotingTimerEnd();

	UFUNCTION()
	void RefreshNewVoteTimer();

	UFUNCTION()
	void RefreshRevealTimer();

	UFUNCTION()
	void RefreshVotingTimer();

	UPROPERTY()
	TArray<TObjectPtr<UFortMtxOfferData>> CachedDisplayAssets;

};

