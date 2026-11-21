// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "RespawnAndSpectateSelectPlayerComponent.generated.h"

class AFortAthenaMutator_RespawnAndSpectateSelect;

UENUM()
enum class ERespawnAndSpectatePlayerRespawningState : uint8
{
	/** This mutator is not currently handling this player's respawn. They could be alive or not far enough in the respawn process for this system to start managing it */
	None = 0,
	/** We are waiting on the player's respawn timer before they can respawn */
	WaitingOnTimer = 1,
	/** We are waiting on the player to select a respawn target before we respawn them
	*   If the player does NOT pick a target quickly enough we will attempt to force the default option upon them */
	WaitingOnPlayerSelection = 2,
	/** We shouldn't attempt to respawn until the normal respawn system has marked the client as ready.
	*	If we attempt to respawn before this flag has been marked, it can get marked again in the middle of the screen transition the respawn select screen triggers
	*	this will cause the player to respawn before the camera can be safely attached on the client. */
	WaitingOnClientReady = 3,
	/** The player's respawn has been triggered and will happen as soon as the client and server are ready
	*   It is ONLY during this state where we should attempt to manage the actual respawn and pass along needed respawn information (like the respawn location/rotation) */
	Respawning = 4,
	/** The player is almost finished respawning, but still needs to calculate data one more time */
	RespawnFinishing = 5,
};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class URespawnAndSpectatePlayerComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	float RespawnFailSafeTime;

	UPROPERTY(Replicated)
	TObjectPtr<AFortAthenaMutator_RespawnAndSpectateSelect> ManagingMutator;

protected:
	UFUNCTION()
	void OnRep_ReplicateClientScreenFade_FadeIn();

	UFUNCTION(Server, Reliable)
	void ServerFadeOutComplete();

	UPROPERTY(Replicated)
	ERespawnAndSpectatePlayerRespawningState RespawningState;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicateClientScreenFade_FadeIn)
	int32 ReplicateClientScreenFade_FadeIn;

};

