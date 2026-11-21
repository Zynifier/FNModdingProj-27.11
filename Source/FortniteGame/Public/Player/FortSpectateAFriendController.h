// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Player/FortLiveSpectatorController.h"
#include "FortSpectateAFriendController.generated.h"

class AFortPlayerStateAthena;
class AFortTeamInfo;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortSpectateAFriendController : public AFortLiveSpectatorController
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_FollowAnyTeam();

	UFUNCTION()
	void OnRep_HasValidTarget();

	UFUNCTION()
	void OnRep_PlayerJoinedOn();

	UFUNCTION()
	void OnRep_TeamJoinedOnPlacement();

	UFUNCTION()
	void OnRep_TeamToFollow();

	UPROPERTY(ReplicatedUsing=OnRep_PlayerJoinedOn)
	TObjectPtr<AFortPlayerStateAthena> PlayerJoinedOn;

	UPROPERTY(ReplicatedUsing=OnRep_HasValidTarget)
	bool HasValidTarget;

	UPROPERTY(ReplicatedUsing=OnRep_TeamToFollow)
	uint8 TeamToFollow;

	UPROPERTY(ReplicatedUsing=OnRep_FollowAnyTeam)
	bool FollowAnyTeam;

	UPROPERTY(ReplicatedUsing=OnRep_TeamJoinedOnPlacement)
	int32 TeamJoinedOnPlacement;

	UPROPERTY()
	TObjectPtr<AFortTeamInfo> TeamJoinedOn;

	UPROPERTY(Config)
	FVector DefaultCameraLocation;

	UPROPERTY(Config)
	bool FollowAnyTeamAfterFirst;

	UPROPERTY(Config)
	float StartingDiconnectTimerLength;

	UPROPERTY(Config)
	float InvalidTargetDiconnectTimerLength;

};

