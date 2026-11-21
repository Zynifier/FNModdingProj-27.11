// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Player/FortPlayerControllerSpectating.h"
#include "FortLiveSpectatorController.generated.h"

class AFortBroadcastRemoteClientInfo;
class AFortPlayerState;
class APlayerController;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortLiveSpectatorController : public AFortPlayerControllerSpectating
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void HandlePlayerAdded(APlayerController* AddedPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetFollowedPlayer(AFortPlayerState* NewPlayerToFollow, const FVector& SpectatorLocation, bool bValidPos);

	UPROPERTY()
	TObjectPtr<AFortPlayerState> FollowedPlayerState;

	UPROPERTY()
	TArray<TObjectPtr<AFortBroadcastRemoteClientInfo>> RemoteClientInfos;

};

