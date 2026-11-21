// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "McpCommandContexts.h"
#include "McpProfile.generated.h"

class UMcpProfileGroup;

UCLASS(Config=Engine)
class MCPPROFILESYS_API UMcpProfile : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString DebugName;

	UPROPERTY()
	bool bProfileLockOperationPending;

	UPROPERTY()
	bool bProfileUnlockOperationPending;

	UPROPERTY(Config)
	bool bEnableMocks;

private:
	UFUNCTION(ServiceRequest(MCP))
	void DeleteAllProfiles(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDeleteAllProfiles);

	UFUNCTION(ServiceRequest(MCP))
	void DeleteProfile(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDeleteProfile);

	UFUNCTION(ServiceRequest(MCP))
	void LockProfileForWrite(const FString& Code, int32 Timeout, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execLockProfileForWrite);

	UFUNCTION(ServiceRequest(MCP))
	void QueryProfile(const FBaseUrlContext& Context);
	DECLARE_FUNCTION(execQueryProfile);

	UFUNCTION(ServiceRequest(MCP))
	void QueryPublicProfile(const FBaseUrlContext& Context);
	DECLARE_FUNCTION(execQueryPublicProfile);

	UFUNCTION(ServiceRequest(MCP))
	void UnlockProfileForWrite(const FString& Code, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUnlockProfileForWrite);

	UPROPERTY(Config)
	bool AllowSubscriptionToNotificationsService;

	UPROPERTY()
	TObjectPtr<UMcpProfileGroup> ProfileGroup;

	UPROPERTY()
	FString ProfileId;

	UPROPERTY()
	int64 ProfileRevision;

	UPROPERTY()
	int32 FullProfileQueryQueued;

	UPROPERTY()
	bool bProfileWriteLocked;

	UPROPERTY()
	FDateTime ProfileWriteLockExpireTime;

	UPROPERTY(Config)
	bool QueuedProfileUpdatingEnabled;

};

