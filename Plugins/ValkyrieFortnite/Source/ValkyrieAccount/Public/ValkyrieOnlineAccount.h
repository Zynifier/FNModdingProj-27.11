// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGlobals.h"
#include "OnlineAccountCommon.h"
#include "ValkyrieOnlineAccount.generated.h"

class UFortClientSettingsRecord;
class UFortMcpProfileCommonCore;
class UFortMcpProfileCreative;
class UMcpProfileGroup;

UCLASS(MinimalAPI)
class UValkyrieOnlineAccount : public UOnlineAccountCommon
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	bool bEOSLoginEnabled;

	UPROPERTY(Config)
	bool bEOSPersistentLoginEnabled;

	UPROPERTY(Config)
	bool bUseExchangeCodeLogin;

	UPROPERTY(Config)
	bool bQueryCreativeAccessEnabled;

	UPROPERTY(Config)
	bool bQueryOwnershipEnabled;

	UPROPERTY(Config)
	bool bFetchCreativeProfileEnabled;

	UPROPERTY(Config)
	bool bFetchClientSettingsEnabled;

	UPROPERTY(Config)
	FLogoutLogSubmitOptions LogoutFailureOptions;

	UPROPERTY(Transient)
	TObjectPtr<UMcpProfileGroup> ProfileGroup;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCommonCore> CommonCoreProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortMcpProfileCreative> CreativeModeProfile;

	UPROPERTY(Transient)
	TObjectPtr<UFortClientSettingsRecord> ClientSettingsRecord;

};

