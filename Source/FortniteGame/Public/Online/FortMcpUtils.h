// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "FortMcpUtils.generated.h"

USTRUCT()
struct FFortCharacterRanges
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint32> Ranges;

	UPROPERTY()
	TArray<uint32> SinglePoints;

	UPROPERTY()
	TArray<uint32> ExcludedPoints;

};

USTRUCT()
struct FIssuedFriendCode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString CodeId;

	UPROPERTY()
	FString CodeType;

	UPROPERTY()
	FDateTime DateCreated;

};

USTRUCT()
struct FMcpMatchResults
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Placement;

	UPROPERTY()
	int32 Kills;

	UPROPERTY()
	int32 Deaths;

};

USTRUCT(BlueprintType)
struct FMcpPrivacySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="McpPrivacySettings")
	bool OptOutOfPublicLeaderboards;

	UPROPERTY(BlueprintReadWrite, Category="McpPrivacySettings")
	bool OptOutOfFriendsLeaderboards;

};

USTRUCT()
struct FPlayerToxicityReportRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Reason;

	UPROPERTY()
	FString Details;

	UPROPERTY()
	FString ReporterGameSessionId;

	UPROPERTY()
	FString ReportOrigin;

	UPROPERTY()
	FString ProfileOrigin;

	UPROPERTY()
	FString VoiceChatChannelStatus;

	UPROPERTY()
	FString GameSessionId;

	UPROPERTY()
	FString Token;

	UPROPERTY()
	FString EmeraldToken;

	UPROPERTY()
	FString CreativeIslandSharingLink;

	UPROPERTY()
	FString CreativeIslandGuid;

	UPROPERTY()
	FString CreativeIslandOwnerAccountId;

	UPROPERTY()
	FString UEFNProjectId;

	UPROPERTY()
	FString UEFNModuleId;

	UPROPERTY()
	FString SubGameName;

	UPROPERTY()
	FString PlaylistName;

	UPROPERTY()
	bool bIsCompetitiveEvent;

	UPROPERTY()
	FString ReporterPlatform;

	UPROPERTY()
	FString OffenderPlatform;

	UPROPERTY()
	bool bBlockUserRequested;

	UPROPERTY()
	bool bUserMarkedAsKnown;

};

USTRUCT()
struct FQueryXboxUserXUIDParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString UserXSTSToken;

};

USTRUCT()
struct FXboxDedicatedServerSessionCreationParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TitleId;

	UPROPERTY()
	FString SandboxId;

	UPROPERTY()
	TArray<FString> XboxUserIds;

};

UCLASS(Config=Game, MinimalAPI)
class UFortMcpUtils : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString CreateXboxDedicatedServerSessionUrl;

	UPROPERTY(Config)
	FString UnredeemedCodesUrl;

	UPROPERTY(Config)
	FString QueryUserXuidUrl;

	UPROPERTY(Config)
	FString InMatchTimePlayedUrl;

	UPROPERTY(Config)
	FString ProcessPendingRewardsUrl;

	UPROPERTY(Config)
	bool bShouldSendTimeTracking;

	UPROPERTY(Config)
	FString VoiceLoginUrl;

	UPROPERTY(Config)
	FString VoiceJoinUrl;

	UPROPERTY(Config)
	FString PrivacySettingsUrl;

	UPROPERTY(Config)
	FString ReplacePlayerTokensUrl;

	UPROPERTY(Config)
	FString AllowHomebaseCharactersUrl;

	UPROPERTY(Config)
	FString InventorySnapshotUrl;

	UPROPERTY(Config)
	FString QuerySwitchEntitlementsUrl;

	UPROPERTY(Config)
	FString ReportPlayerToxicityUrl;

	UPROPERTY(Config)
	FString EventCalendardTestUrl;

	UPROPERTY(Config)
	FString QueryCreativeDiscoverySurfacePanelsUrl;

	UPROPERTY(Config)
	FString QueryCreativeDiscoverySurfacePanelPageUrl;

	UPROPERTY(Config)
	FString ResolveWellKnownIslandMetricsUrl;

	UPROPERTY(Config)
	bool bSubmitLogsPreferDeviceId;

	UPROPERTY(Config)
	int32 DefaultLogHeadLengthKb;

	UPROPERTY(Config)
	int32 DefaultLogTailLengthKb;

	UPROPERTY(Config)
	bool bUseGameSessionV2Endpoint;

};

