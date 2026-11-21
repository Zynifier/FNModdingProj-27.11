// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "DestroyOnSafeZonePhaseComponent.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBeforeDestroyDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestroyDelayStartedDelegate, float, Delay);

UCLASS(HideCategories=("Cooking", "Collision", "ComponentTick", "ComponentReplication"), meta=(BlueprintSpawnableComponent))
class UDestroyOnSafeZonePhaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DestroyOnSafeZonePhaseComponent")
	FScalableFloat DestroyInPhase;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DestroyOnSafeZonePhaseComponent")
	FScalableFloat MinDestroyDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DestroyOnSafeZonePhaseComponent")
	FScalableFloat MaxDestroyDelay;

	UPROPERTY(BlueprintAssignable)
	FOnDestroyDelayStartedDelegate OnDestroyDelayStarted;

	UPROPERTY(BlueprintAssignable)
	FOnBeforeDestroyDelegate OnBeforeDestroy;

protected:
	UFUNCTION()
	void HandlePlaylistReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};

