// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieOnlineInstance.generated.h"

class UMcpProfileManager;
class UValkyrieEosConfigSync;
class UValkyrieLocalPlayer;
class UValkyrieMatchmaking;
class UValkyrieUpdateManager;
class UWorld;

UCLASS(Config=Game)
class VALKYRIEACCOUNT_API UValkyrieOnlineInstance : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UValkyrieEosConfigSync> EosConfigSync;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieLocalPlayer> LocalPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieMatchmaking> Matchmaking;

	UPROPERTY(Transient)
	TObjectPtr<UWorld> OnlineWorld;

	UPROPERTY(Transient)
	TObjectPtr<UMcpProfileManager> ProfileManager;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieUpdateManager> UpdateManager;

};

