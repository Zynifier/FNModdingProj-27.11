// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "RejoinCheck.h"
#include "FortBlueprintContext.h"
#include "Online/FortOnlineSessionTypes.h"
#include "FortMatchmakingContext.generated.h"

class AFortLobbyBeaconClient;
enum class EFortSTWMatchmakingPrivacyType : uint8;
enum class EMatchmakingCompleteResult : uint8;
enum class EMatchmakingUtilityState : uint8;

UENUM()
enum class EFortSTWMatchmakingPrivacyType : uint8
{
	Public = 0,
	FriendsOnly = 1,
	Private = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyConnectingToGame);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyConnectionAttemptFailedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyConnectionStartedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyDisconnected);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyStartedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyTimeExpiredDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLobbyTimeUpdatedDelegate, int32, CurrentTime);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyWaitingForPlayersDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLobbyWaitingForPlayersTimeUpdateDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchmakingCompletedDelegate, EMatchmakingCompleteResult, Result);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMatchmakingFlowChangeDelegate, bool, bIsActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMatchmakingStartedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchmakingStateChangeDelegate, TEnumAsByte<EMatchmakingState::Type>, OldState, TEnumAsByte<EMatchmakingState::Type>, NewState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMatchmakingUtilityChangedStateDelegate, EMatchmakingUtilityState, OldState, EMatchmakingUtilityState, NewState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOutpostDiscoveryFailure);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReadyUpStatusChangedDelegate, bool, bReadyStatus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRejoinCheckCompletedDelegate, ERejoinStatus, RejoinStatus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWorldRecordLoadedChangedDelegate, bool, NewWorldRecordLoaded);

USTRUCT()
struct FFortMatchmakingConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ChanceToHostOverride;

	UPROPERTY()
	float ChanceToHostIncrease;

	UPROPERTY()
	int32 MaxSearchResultsOverride;

	UPROPERTY()
	int32 MaxProcessedSearchResults;

};

UCLASS(Config=Game, MinimalAPI)
class UFortMatchmakingContext : public UFortBlueprintContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void CancelMatchmaking();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void CheckRejoinStatus();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void DisconnectFromLobby();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void DisplayAntiTaxiError();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void EnterOutpost();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ForceTeamFill(const bool bForcedTeamFillValue) const;

	UFUNCTION(BlueprintPure)
	EFortSTWMatchmakingPrivacyType GetCurrentStwMatchmakingPrivacy() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	FString GetCustomMatchmakingKey() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	ECommonInputType GetInputBasedMatchmakingPool(bool& bIsDefaultPool, bool& bEntirePartyUsingTargetPoolInput) const;

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	FText GetLegacyNonInputBasedPlayAgainstText();

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	AFortLobbyBeaconClient* GetLobbyBeaconClient() const;

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	float GetLobbyWaitForPlayersTimeRemaining();

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	FText GetMatchmakingFillText(bool bDesiredFill) const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool HasBroadcasterToken() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsConnectedToGame() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsCustomMatchmakingKeyEnabled() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsInLobby() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsInputBasedMatchmakingEnabled() const;

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool IsJoinableGameAvailable();

	UFUNCTION(BlueprintPure, Category="Matchmaking")
	bool IsMatchmakingFlowActive() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsMatchmakingLocal() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsMatchmakingRegionEnabled() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingContext")
	bool IsOutpostPermitted() const;

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool IsWaitingOnUpdateManager();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool IsWorldRecordLoaded();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool JoinFromLobby();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool NeedToCheckRejoinStatus();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void ReadyUp();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void RequestUtilityToCancelMatchmaking();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void RequestUtilityToMatchmake();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void RequestUtilityToToggleMatchmaking();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void SetCustomMatchmakingKey(const FString& Key);

	UFUNCTION(BlueprintCallable, Category="Matchmaking")
	void SetMatchmakingFlowActive(bool InFlow);

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void StartCriticalMission(float MinMissionDifficulty = 0.000000f, float MaxMissionDifficulty = 100000.000000f);

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void StartMatchmaking();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	bool StartOnboardingMission();

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void StartQuickPlay(float MinMissionDifficulty = 0.000000f, float MaxMissionDifficulty = 100000.000000f);

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void StartStormShieldExpansionAssist(float MinMissionDifficulty = 0.000000f, float MaxMissionDifficulty = 100000.000000f);

	UFUNCTION(BlueprintCallable, Category="MatchmakingContext")
	void StartWargameSimulationAssist(float MinMissionDifficulty = 0.000000f, float MaxMissionDifficulty = 100000.000000f);

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingStartedDelegate OnMatchmakingStarted;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingCompletedDelegate OnMatchmakingComplete;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingStateChangeDelegate OnMatchmakingStateChange;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingFlowChangeDelegate OnMatchmakingFlowChanged;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyConnectionStartedDelegate OnLobbyConnectionAttemptStarted;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyConnectionAttemptFailedDelegate OnLobbyConnectionAttemptFailed;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyConnectionAttemptFailedDelegate OnLobbyConnectionAttemptProceedToLobby;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyWaitingForPlayersDelegate OnLobbyWaitingForPlayers;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyWaitingForPlayersTimeUpdateDelegate OnLobbyWaitingForPlayersTimeUpdate;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyStartedDelegate OnLobbyStarted;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyDisconnected OnLobbyDisconnected;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyConnectingToGame OnLobbyConnectingToGame;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyTimeUpdatedDelegate OnLobbyTimeUpdated;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnLobbyTimeExpiredDelegate OnLobbyTimeExpired;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnReadyUpStatusChangedDelegate OnLocalReadyUpStatusChange;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnWorldRecordLoadedChangedDelegate OnWorldRecordLoadedChanged;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnRejoinCheckCompletedDelegate OnRejoinCheckCompleted;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingUtilityChangedStateDelegate OnUtilityPreStateChanged;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext")
	FOnMatchmakingUtilityChangedStateDelegate OnUtilityStateChanged;

private:
	UPROPERTY(Config)
	FFortMatchmakingConfig NormalConfig;

	UPROPERTY(Config)
	FFortMatchmakingConfig CriticalConfig;

	UPROPERTY(Config)
	FFortMatchmakingConfig QuickPlayConfig;

	UPROPERTY(Config)
	FFortMatchmakingConfig OnboardingConfig;

	UPROPERTY(Config)
	FFortMatchmakingConfig OutpostConfig;

	UPROPERTY(Transient)
	bool bMatchmakingFlowActive;

	UPROPERTY(BlueprintAssignable, Category="MatchmakingContext", meta=(AllowPrivateAccess="true"))
	FOnOutpostDiscoveryFailure OnOutpostDiscoveryFailure;

};

