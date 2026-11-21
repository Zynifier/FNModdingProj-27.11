// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CreativeRegisteredPlayersInterface.generated.h"

class AFortPlayerState;

UINTERFACE(MinimalAPI)
class UCreativeRegisteredPlayersInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ICreativeRegisteredPlayersInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void OnAllPlayersUnregistered();

	UFUNCTION()
	virtual void OnMinigameEnded();

	UFUNCTION()
	virtual void OnMinigameStarted();

	UFUNCTION()
	virtual void OnPlayerAdded(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UFUNCTION()
	virtual void OnPlayerRegistered(const AFortPlayerState* PlayerState);

	UFUNCTION()
	virtual void OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UFUNCTION()
	virtual void OnPlayerUnregistered(const AFortPlayerState* PlayerState);

};

