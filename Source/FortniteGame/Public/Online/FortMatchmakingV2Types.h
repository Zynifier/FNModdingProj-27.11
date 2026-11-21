// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingV2Types.generated.h"

UENUM()
enum class EMatchmakingErrorV2 : int32
{
	Success = 0,
	Canceled = 1,
	NeedUpdate = 2,
	VersionMismatch = 3,
	UpdateFailed = 4,
	NotLoggedIn = 5,
	NoIdentityInterface = 6,
	NoSessionInterface = 7,
	AlreadyInSession = 8,
	FindSessionFailure = 9,
	InvalidSessionId = 10,
	FailedToQueryEncryptionKey = 11,
	FailedToRefreshAuthToken = 12,
	FailedToCleanupSession = 13,
	FailedToJoinSession = 14,
	FailedToTravelToSession = 15,
	Unauthorized = 16,
	BannedFromAthena = 17,
	BannedFromAthenaForExploit = 18,
	BannedFromAthenaForTeaming = 19,
	BannedFromAthenaForTeamKilling = 20,
	InvalidCustomMatchKey = 21,
	FailedToContactGameServices = 22,
	FailedToConnectToMMS = 23,
	MMSCommunicationIssue = 24,
	ServiceReturnedError = 25,
	PlaylistNoLongerAvailable = 26,
	CrossplayUnsetWithInputDevicePoolShift = 27,
	CrossplayNeededForTournamentMatch = 28,
	MatchmakingDisabled = 29,
	AccountLevelTooLow = 30,
	JoinInProgressError = 31,
	SpectateInProgressError = 32,
	MatchmakingInProgress = 33,
	TooFrequentRequests = 34,
	HostFailedToGenerateDownloadableContent = 35,
	FailedToAcquireContent = 36,
	CancelledDownloadContent = 37,
	DataAssetDirectoryUpdateFailed = 38,
	InvalidPlaylistRevision = 39,
	FailedToConnectToContentBeacon = 40,
	FailedToAcquireServerInitializationState = 41,
	CancelledDuringPreTravelSetup = 42,
	QueryUserSessionIdTokensFailed = 43,
	UnknownError = 44,
};

UENUM()
enum class EMatchmakingSourceV2 : uint8
{
	None = 0,
	AthenaMatchmakingWidget = 1,
	// normal lobby

	ActivityMatchmakingWidget = 2,
	// new "activity browser"

	ReadyUpScreenWidget = 3,
	// in-game (post-match)

	ForcedIntro = 4,
	// used for in game events like Apollo and Yogurt

	KeepPlayingTogetherWidget = 5,
	// in-game (post-match) alertnative to using Ready Up Screen

	Unknown = 6,
};

UENUM()
enum class EMatchmakingV2Fork_ContentBeacon : uint8
{
	Begin = 0,
	Idle = 1,
	Completed = 2,
	Failed = 3,
	INVALID = 4,
	V2_DisconnectedBegin = 5,
	V2_ReadinessChangedBegin = 6,
	V2_OnContentBeaconErrorFailed = 7,
	V2_OnContentBeaconErrorSuccess = 8,
	V2_OnClientReadinessChangedFailed = 9,
	V2_OnClientReadinessChangedSuccess = 10,
	V2_CancelRequested = 11,
	V1_Begin = 12,
	V1_WaitingForContent = 13,
	V1_Disconnected = 14,
	V1_Failed = 15,
	V1_ReadinessCallback = 16,
	V1_JoinAnyways = 17,
	V1_TravelToSession = 18,
	V1_TravelToSessionLambda = 19,
	V1_TravelToSessionTimeout = 20,
	V1_ReadinessCallbackFailed = 21,
	V1_CancelRequested = 22,
};

UENUM()
enum class EMatchmakingV2Fork_ServerInit : uint8
{
	Begin = 0,
	Idle = 1,
	Completed = 2,
	Failed = 3,
	INVALID = 4,
	ReadyToTravel = 5,
	WaitForInit = 6,
	WaitForSubGameContent = 7,
	WaitForSubGameContent_Callback = 8,
	WaitForSubGameContent_Callback_Ready = 9,
	WaitForSubGameContent_Callback_NotReady = 10,
	WaitBeforeTravel = 11,
	FailedToConnect = 12,
	MissingParty = 13,
	FailedCallback = 14,
	ServerInitStateChange_Callback = 15,
	ServerInitStateChange_Callback_Ready = 16,
	ServerInitStateChange_Callback_NotReady = 17,
	CancelRequested = 18,
};

UENUM()
enum class EMatchmakingV2State : uint8
{
	Begin = 0,
	Idle = 1,
	Completed = 2,
	Failed = 3,
	INVALID = 4,
	RunningMainBranch = 5,
	Main_RunningChecks = 6,
	Main_DADUpdate = 7,
	Main_CheckPlaylistValid = 8,
	Main_ModifyOptions = 9,
	Main_Begin_JoinInProgress = 10,
	Main_JoinInProgress_PartyLeader_Begin = 11,
	Main_JoinInProgress_PartyLeader_Success = 12,
	Main_JoinInProgress_PartyLeader_Failed = 13,
	Main_JoinInProgress_PartyMember = 14,
	Main_Begin_NormalFlow = 15,
	Main_NormalFlow_SetValues = 16,
	Main_NormalFlow_CheckPartyValidity = 17,
	Main_NormalFlow_CheckInputValidity = 18,
	Main_NormalFlow_CheckTournamentValidity = 19,
	Main_NormalFlow_Complete = 20,
	RunningFollowerBranch = 21,
	Follower_CheckIsNotMatchmaking = 22,
	Follower_SettingMemberVariables = 23,
	Follower_ValidatingLeaderMatchmakingInfo = 24,
	Follower_ValidatingRegion = 25,
	Follower_ValidatingHotfixVersion = 26,
	Follower_ValidatingTournamentQualifications = 27,
	Follower_ValidatingPlaylist = 28,
	Follower_RunDADUpdate = 29,
	Follower_AfterDADUpdate_SetValues = 30,
	Follower_AfterDADUpdate_CheckPartyValidity = 31,
	FollowerBranch_Complete = 32,
	/////////////////////////////////

	CallingMatchmakingService = 33,
	/////////////////////////////////

	WaitingForMatchmakingServiceCallback = 34,
	/////////////////////////////////

	FindingSessionId = 35,
	/////////////////////////////////

	WaitingForFindSessionIdCallback = 36,
	/////////////////////////////////
/////////////////////////////////

	QueryUserSessionIdTokens = 37,
	/////////////////////////////////
/////////////////////////////////

	AfterFindSession = 38,
	/////////////////////////////////
/////////////////////////////////

	Fork_JoinFoundSession = 39,
	/////////////////////////////////
/////////////////////////////////

	RefreshPlatformAuthToken = 40,
	/////////////////////////////////
/////////////////////////////////

	DestroySession = 41,
	/////////////////////////////////
/////////////////////////////////

	DestroyConsoleSession = 42,
	/////////////////////////////////
/////////////////////////////////

	CheckConsoleSessionDestruction = 43,
	/////////////////////////////////
/////////////////////////////////

	JoinSession = 44,
	/////////////////////////////////
/////////////////////////////////

	PassedJoinSession = 45,
	/////////////////////////////////
/////////////////////////////////

	PreTravelSetupStartTime = 46,
	/////////////////////////////////
/////////////////////////////////

	ClearJoinSessionDelegate = 47,
	/////////////////////////////////
/////////////////////////////////

	Fork_ServerInitAndContent = 48,
	/////////////////////////////////
/////////////////////////////////

	OnReadyForTravel = 49,
	/////////////////////////////////
/////////////////////////////////

	WaitingForReadyToTravelToSession = 50,
	/////////////////////////////////
/////////////////////////////////

	AttemptToTravel = 51,
};

UENUM()
enum class EMatchmakingV2_Temp_JoinInProgressState : uint8
{
	Begin = 0,
	Idle = 1,
	Completed = 2,
	Failed = 3,
	INVALID = 4,
	Branch_JoinHost = 5,
	Branch_JoinParty = 6,
	Branch_JoinBroadcaster = 7,
	Branch_JoinPartyMember = 8,
	ConnectToReservationBeacon = 9,
	ConnectToReservationBeaconForPersistentParty = 10,
	CheckConnectToReservationBeaconForPersistentPartyData = 11,
	DelayingCallToJoin = 12,
	CheckNotMatchmaking = 13,
	CallToJoin = 14,
};

UENUM()
enum class EMatchmakingV2_Temp_PreloadingAthenaForJoinInProgress : uint8
{
	Begin = 0,
	Idle = 1,
	Completed = 2,
	Failed = 3,
	INVALID = 4,
	PreloadingAthena = 5,
	BeginningServerTransfer_UnfinishedRefactor = 6,
};

UENUM()
enum class EUseInputWithPartyResult : uint8
{
	Success = 0,
	LocalPlayerNeedsToAllowCrossplay = 1,
	LocalPlayerRestricted = 2,
	RemotePlayerRestricted = 3,
	UnknownFailure = 4,
};

USTRUCT()
struct FFortMatchmakingErrorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EMatchmakingErrorV2 Error;

	UPROPERTY()
	FString ErrorCode;

	UPROPERTY()
	FString ResponseStr;

};

USTRUCT()
struct FMMSAltDomainRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString OriginalDomain;

	UPROPERTY()
	FString AltDomain;

};

