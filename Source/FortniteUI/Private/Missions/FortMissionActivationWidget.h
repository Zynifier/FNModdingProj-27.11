// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "Context/FortHUDContext.h"
#include "FortGameStateZone.h"
#include "Online/FortUITeamInfo.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortMissionActivationWidget.generated.h"

class AFortGameStateZone;
class AFortMission;
class AFortPlayerController;
class UCurveFloat;
class UFortMissionActivationInfo;
class UFortMissionInfo;
enum class EFortMissionActivationWidgetState : uint8;
enum class EFortVoteArbitratorType : uint8;
enum class EFortVoteStatus : uint8;
enum class EFortVoteType : uint8;

UENUM(BlueprintType)
enum class EFortMissionActivationWidgetState : uint8
{
	Default = 0,
	StartObjective = 1,
	IncreaseDifficulty = 2,
	Invalid = 3,
};

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UFortMissionActivationInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool CanRequestVote(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool DoesPrimaryMissionContainTags(const FGameplayTagContainer& Tags) const;

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	EFortVoteArbitratorType GetArbitratorType(EFortVoteType VoteType);

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	int32 GetAvailableBluGloCount() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	void GetDeltaRewards(int32 BaseDifficultyIncreaseTier, int32 ComparedDifficultyIncreaseTier, TArray<FFortItemDelta>& DeltaRewards) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	int32 GetIncreaseDifficultyBluGloRequirement() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	FUniqueNetIdRepl GetInstigatorId(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	FText GetLockoutTimeRemaining(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	float GetMissionObjectiveTimeRemaining() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	EFortVoteType GetMissionVoteType() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	AFortMission* GetPrimaryMission() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	UFortMissionInfo* GetPrimaryMissionInfo() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	int32 GetStartObjectiveBluGloRequirement() const;

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	void GetVoteCounts(EFortVoteType VoteType, int32& OutYesVoteCount, int32& OutNoVoteCount);

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	TArray<FVoter> GetVoters(EFortVoteType VoteType);

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	float GetVoteTimeRemaining(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	bool HasPlayerVoted(EFortVoteType VoteType);

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool IsAnyVoteActive() const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool IsPlayerVoteInstigator(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool IsVoteActive(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	bool IsVoteLocked(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	void RequestVote(EFortVoteType VoteType, float VoteDuration, float FailedVoteLockoutDuration, EFortVoteArbitratorType ArbitratorType);

	UFUNCTION(BlueprintCallable, Category="Mission Activation Info")
	void SubmitVote(EFortVoteType VoteType, bool bApprove);

	UFUNCTION(BlueprintPure, Category="Mission Activation Info")
	FText TimeSecondsToText(float InSeconds) const;

	UPROPERTY(BlueprintReadOnly, Category="Mission Activation Info")
	bool bIsMultiplayer;

private:
	UFUNCTION()
	void HandleGameplayVoteUpdated(EFortVoteType VoteType, EFortVoteStatus VoteStatus, int32 VoteResult, const TArray<FVoter>& Voters);

	UFUNCTION()
	void HandleTeamMemberAdded(FFortTeamMemberInfo NewInfo);

	UFUNCTION()
	void HandleTeamMemberRemoved(int32 RemovedIndex);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FortPC;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateZone> GameStateZone;

	UPROPERTY(Transient)
	TObjectPtr<UCurveFloat> DifficultyIncreaseBluGloCurve;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortMissionActivationWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mission Activation Widget")
	void RequestDefaultState();

	UFUNCTION(BlueprintCallable, Category="Mission Activation Widget")
	void RequestDifficultyIncreaseState();

	UFUNCTION(BlueprintCallable, Category="Mission Activation Widget")
	void RequestStartObjectiveState();

protected:
	UFUNCTION(BlueprintPure, Category="Mission Activation Widget")
	EFortMissionActivationWidgetState GetCurrentState() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnActiveVoteChangedBP(EFortVoteType VoteType, bool bIsVoteActive, int32 VoteResult);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnMultiplayerChangedBP(bool bIsMultiplayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnStateUpdated(EFortMissionActivationWidgetState ActiveState, EFortMissionActivationWidgetState PreviousState);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnVoteLockoutChangedBP(EFortVoteType VoteType, bool bIsLocked);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Mission Activation Widget")
	TObjectPtr<UFortMissionActivationInfo> InfoObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Activation Widget")
	FGameplayTagContainer ReadyUpObjectiveHandle;

private:
	UPROPERTY(EditDefaultsOnly, Category="Mission Activation Widget")
	TObjectPtr<UCurveFloat> DifficultyIncreaseBluGloCurve;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortMissionActivationWidgetPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mission Activation Widget")
	void SetInfoObject(UFortMissionActivationInfo* NewInfoObject);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void InfoObjectUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnActiveVoteChangedBP(EFortVoteType VoteType, bool bIsVoteActive, int32 VoteResult);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnMultiplayerChangedBP(bool bIsMultiplayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnVoteLockoutChangedBP(EFortVoteType VoteType, bool bIsLocked);

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Activation Widget")
	void OnVoteUpdatedBP(EFortVoteType VoteType);

	UPROPERTY(BlueprintReadOnly, Category="Mission Activation Widget")
	TObjectPtr<UFortMissionActivationInfo> InfoObject;

};

