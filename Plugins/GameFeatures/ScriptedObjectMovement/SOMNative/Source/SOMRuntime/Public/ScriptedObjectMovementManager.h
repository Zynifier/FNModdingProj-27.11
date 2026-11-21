// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/FortGameStateComponent.h"
#include "ScriptedObjectMovementManager.generated.h"

class AFortGameStateAthena;
class AFortScriptedObjectMovement_WorldPhaseSite;
class AScriptedObjectMovement_StaticPath;
class UFortPlaylist;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_ScriptedObjectMovementManager : public UFortGameStateComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCurrentPlaylistReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortScriptedObjectMovement_WorldPhaseSite>> WorldPhaseSites;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AScriptedObjectMovement_StaticPath>> RegisteredStaticPaths;

	UPROPERTY(Transient)
	TObjectPtr<AScriptedObjectMovement_StaticPath> CurrentlyMovingStaticPath;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_ScriptedObjectMovementManager")
	FScalableFloat StaticPathCooldownBetweenMoves;

};

