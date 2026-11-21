// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "UObject/NoExportTypes.h"
#include "McpProfileGroup.generated.h"

class UMcpProfile;

USTRUCT()
struct FProfileEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProfileId;

	UPROPERTY()
	TObjectPtr<UMcpProfile> ProfileObject;

	UPROPERTY()
	bool bWaitingForRefreshAllProfilesResponse;

	UPROPERTY()
	bool bForwardUpdatesToClient;

};

UCLASS(Config=Engine)
class MCPPROFILESYS_API UMcpProfileGroup : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	int32 DelayMcpResults;

	UPROPERTY(Config)
	int32 WeeklyIntervalStartDay;

	UPROPERTY()
	TArray<FProfileEntry> ProfileList;

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	bool bIsServer;

	UPROPERTY(Config)
	FString ProfileNotificationsStompTopic;

	UPROPERTY()
	FString LastMcpVersion;

	UPROPERTY()
	FString LastContentVersion;

	UPROPERTY()
	FString LastMinBuild;

	UPROPERTY()
	FTimespan LocalTimeOffset;

	UPROPERTY()
	FString LockCode;

	UPROPERTY()
	TArray<TObjectPtr<UMcpProfile>> LockedProfiles;

	UPROPERTY()
	FString LockedProfilesString;

	UPROPERTY(Config)
	int32 ProfileWriteLockTimeoutSecs;

	UPROPERTY()
	bool bSubscribedToNotifications;

	UPROPERTY(Config)
	FString ApplyStashEndPoint;

	UPROPERTY(Config)
	bool bSendProfileCommandRevisions;

	UPROPERTY(Config)
	bool bAsyncParseProfileUpdates;

	UPROPERTY(Config)
	int32 MaxChangesToForwardInUpdate;

	UPROPERTY(Config)
	int32 MaxChangeSizeInBytes;

	UPROPERTY(Config)
	TArray<FString> ForwardToClientExclusions;

};

