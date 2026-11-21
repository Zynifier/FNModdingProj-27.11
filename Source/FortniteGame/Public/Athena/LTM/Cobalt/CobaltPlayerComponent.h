// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Components/FortControllerComponent.h"
#include "CobaltPlayerComponent.generated.h"

class AFortAthenaMutator_Cobalt;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateAthena;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UCobaltPlayerComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ClientOnPawnKilled(AFortPlayerStateAthena* Victim);

	UFUNCTION()
	void OnPawnEnterWater(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnPawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void OnPlayerPawnLoaded(AFortPlayerController* PlayerController);

protected:
	UFUNCTION()
	void OnRep_CachedMutator();

	UPROPERTY(ReplicatedUsing=OnRep_CachedMutator)
	TWeakObjectPtr<AFortAthenaMutator_Cobalt> CachedMutator;

};

