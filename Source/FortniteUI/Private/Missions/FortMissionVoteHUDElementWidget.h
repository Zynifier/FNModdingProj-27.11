// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameStateZone.h"
#include "FortHUDElementWidget.h"
#include "FortMissionVoteHUDElementWidget.generated.h"

enum class EFortVoteArbitratorType : uint8;
enum class EFortVoteStatus : uint8;
enum class EFortVoteType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortMissionVoteHUDElementWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Mission Vote HUD Element")
	int32 GetVoteTimeRemaining(EFortVoteType VoteType);

	UFUNCTION(BlueprintCallable, Category="Mission Vote HUD Element")
	bool HasLocalPlayerVoted(EFortVoteType VoteType);

	UFUNCTION(BlueprintCallable, Category="Mission Vote HUD Element")
	bool IsMultiplayerVote(EFortVoteType VoteType);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Vote HUD Element")
	void OnVoteEnded(EFortVoteType VoteType, EFortVoteArbitratorType ArbitratorType, bool VoteSucceeded);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Vote HUD Element")
	void OnVoteStarted(EFortVoteType VoteType, EFortVoteArbitratorType ArbitratorType, int32 YesVoteCount, int32 NoVoteCount);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Vote HUD Element")
	void OnVoteUpdated(EFortVoteType VoteType, int32 YesVoteCount, int32 NoVoteCount);

	UFUNCTION(BlueprintCallable, Category="Mission Vote HUD Element")
	void RegisterFailsafeForVoteType(EFortVoteType VoteType);

private:
	UFUNCTION()
	void HandleDifficultyIncreaseVoteUpdate(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters);

	UFUNCTION()
	void HandleMissionActivationVoteUpdate(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters);

};

