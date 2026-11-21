// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingUtilityTypes.generated.h"

UENUM(meta=(Bitflags))
enum class EActivePreTravelSetupStepsMask : uint8
{
	None = 0,
	// The pre-travel setup is complete

	WaitingForSubGameContent = 1,
	// Waiting for sub game content to be ready

	WaitingForDownloadableContent = 2,
	// Waiting for content being downloaded by the content beacon

	WaitingForServerInitialization = 4,
	// Waiting until the server is ready to receive players (When the playlist is initialized)

	WaitingForContentBeaconDisconnect = 8,
	// Waiting until the contentbeacon has confirmed disconnected state, this is required so we
// don't have a stale connection laying around when we reconnect after travel

	WaitingForSecondContentBeacon = 16,
	// test mode for creating a second content beacon

	CancelingPreTravelSetup = 32,
};

UENUM(BlueprintType)
enum class EMatchmakingUtilityState : uint8
{
	Idle = 0,
	//

	MatchmakingUtilityBegin = 1,
	//

	MatchmakingUtilityCompleted = 2,
	//

	Completed = 3,
	//

	Failed = 4,
	//
//

	CheckSittingOutState = 5,
	//
//

	InitializePlaylistSelection = 6,
	//
//

	JoinMatchInProgress = 7,
	//
//

	CheckingIfBanned = 8,
	//
//

	PrivateMatchMinPartySize = 9,
	//
//

	GameFeaturePluginDownloadModal = 10,
	//
//

	CreativeContentDownloadModal = 11,
	//
//

	CheckModeratorModePermissions = 12,
	//
//

	CrossplayOptIn_GameMode = 13,
	//
//

	CrossplayOptIn_Fill = 14,
	//
//

	CrossplayDevices = 15,
	//
//

	FactionChoice = 16,
	//
//

	SetPartyReadiness = 17,
	//
//

	WaitingForPartyReadinessConfirmed = 18,
	//
//

	TournamentEligibility = 19,
	//
//

	TournamentRegionLock = 20,
	//
//

	TournamentMFA = 21,
	//
//

	TournamentEULA = 22,
	//
//

	AppEnvSecurity = 23,
	//
//

	WaitingForInitialPlaylistSelection = 24,
	//
//

	ServerBrowsers = 25,
	//
//

	WaitingForServerBrowserPlaylistSwap = 26,
	//
//

	DelayReadyUp = 27,
	//
//

	QoSSettings_UpdateManager = 28,
	//
//

	QoSSettings_UpdateManager_Success = 29,
	//
//

	SetAthenaReady = 30,
	//
//

	WaitingForAthenaReadinessConfirmed = 31,
	//
//

	PreloadAthena = 32,
	//
//

	UpdateHiddenMatchmakingDelay = 33,
	//
//

	WaitingForUpdateHiddenMatchmakingDelay = 34,
	//
//

	HiddenMatchmakingDelay = 35,
	//
//

	FindExistingEditSession = 36,
	//
//

	SelectingFlow = 37,
	//
//

	ReadyingUpforFlow = 38,
	//
//

	PartyMemberSameLocationCheck = 39,
	//
//

	CallingMatchmakingForFlow = 40,
	//
//

	WaitingForJoinMatchInProgressResponse = 41,
	//
//

	WaitingForMatchmakingResponse = 42,
	//
//

	WaitingForMatchmakingToCompleteAsPartyMember = 43,
	//
//

	WaitingForEntirePartyReady = 44,
	//
//

	WaitingForPartyToBeInSameLocation = 45,
	//
//

	WaitingForPartyToSwitchSubgames = 46,
	//
//

	WaitingToRestartMatchmaking_TooFrequentRequest = 47,
	//
//

	RequestingSpectateMatch = 48,
	//
//

	ProcessingMatchmakingResults_Success = 49,
	//
//

	ProcessingMatchmakingResults_Fail = 50,
	//
//
//

	PreloadingForJoiningMatchInProgress = 51,
	//
//
//

	ProcessingJoinMatchInProgressResults_Success = 52,
	//
//
//

	ProcessingJoinMatchInProgressResults_Fail = 53,
	//
//
//
// Restarts the ready checks if some party member un-readies after the ready checks completed successfully,
// but before matchmaking started (see CallingMatchmakingForFlow), this is intended as a temporary workaround
// for FORT-624349 which causes the entire party to unready at this stage
// TODO: Romualdo.Villalobos remove when NewReadiness flow is finished

	RestartingReadyChecksForLegacyFlow = 54,
	// Restarts the ready checks and matchmaking step if UFortMatchmakingV2 gets cancelled somehow 

	RestartingMatchmaking = 55,
	QueryingForLiveSpectatorEula = 56,
	//

	PreTravelToSessionSetup = 57,
	//
// Doing setup required before we can travel to the server. See: EActivePreTravelSetupStepsMask

	RunningPlaylistChecks = 58,
	// New Readiness flow ends up with the player just ready up in a social party OR calling to do a server transfer.
// Utility should not try to run the 3-phase commit ready check logic.

	NewReadiness_Begin = 59,
	NewReadiness_Ready_WaitingForConfirmation = 60,
	NewReadiness_Unready_WaitingForConfirmation = 61,
	NewReadiness_End = 62,
	QueryingKeychain = 63,
	INVALID = 64,
};

UENUM()
enum class EPlaylistUpdateReason : uint8
{
	LocalPlayerJoinedParty = 0,
	LocalPlayerLocationChangedToFrontend = 1,
	LocalPlayerSubgameSelected = 2,
	//////////////

	LocalPlayerLeftParty = 3,
	//////////////

	LocalPlayerDeclinedCrossplayPermission = 4,
	//////////////

	PartyGameSessionKeyChanged = 5,
	//////////////

	PartySquadFillChanged = 6,
	//////////////

	PartyMemberJoined = 7,
	//////////////

	PartyMemberLeft = 8,
	//////////////

	PartyMemberReadinessChanged = 9,
	//////////////

	PartyMemberInGameReadyCheckChanged = 10,
	//////////////

	PartyMemberLocationChanged = 11,
	//////////////

	PartyMemberSpectateAvailabilityChanged = 12,
	//////////////

	PartyMemberSessionJoinInfoChanged = 13,
	//////////////
//////////////

	ValidatePlaylist_QoSCheckFailed = 14,
	//////////////
//////////////

	ValidatePlaylist_TournamentEventOver = 15,
	//////////////
//////////////

	ValidatePlaylist_BlackoutChanged = 16,
	//////////////
//////////////

	ValidatePlaylist_MatchmakingEventsChanged = 17,
	//////////////
//////////////

	ValidatePlaylist_TournamentNewEventStarted = 18,
	//////////////
//////////////

	ValidatePlaylist_TournamentNewEventCountdown = 19,
	//////////////
//////////////

	ValidatePlaylist_TournamentsChanged = 20,
	//////////////
//////////////

	ValidatePlaylist_PlayerTournamentDataRefreshed = 21,
	//////////////
//////////////
//////////////

	Initialization = 22,
};

