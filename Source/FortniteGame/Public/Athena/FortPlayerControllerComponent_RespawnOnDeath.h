// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortPlayerControllerComponent_RespawnOnDeath.generated.h"

class AFortPlayerPawnAthena;
class AFortRespawnDroneManager;
class APawn;

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerControllerComponent_RespawnOnDeath : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="BeginRespawnSequence"))
	void BP_BeginRespawnSequence(AFortPlayerPawnAthena* Pawn);

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="CalculateRespawnLocation"))
	FVector BP_CalculateRespawnLocation(const FVector& InRespawnLocation) const;

protected:
	UFUNCTION()
	void OnDroneManagerFinished(AFortRespawnDroneManager* DroneManager);

	UFUNCTION()
	void OnRep_DroneManager();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnRespawningPawnPossessed"))
	void OnRespawningPawnPossessed_BP(APawn* InPawn);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerClientIsReadyToRespawn();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerComponent_RespawnOnDeath")
	TSubclassOf<AFortRespawnDroneManager> RespawnDroneManagerClass;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_DroneManager, Category="FortPlayerControllerComponent_RespawnOnDeath")
	TObjectPtr<AFortRespawnDroneManager> DroneManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerControllerComponent_RespawnOnDeath")
	FScalableFloat RespawnDelay;

	UPROPERTY(EditDefaultsOnly, Category="Respawn")
	FScalableFloat DroneViewTargetBlendDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerComponent_RespawnOnDeath")
	FName ItemsToGiveOnRespawnLootTier;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerComponent_RespawnOnDeath")
	FGameplayTag RespawnEventTag;

	UPROPERTY(Transient, Replicated)
	FVector RespawnLocation;

	UPROPERTY(Transient)
	bool bIsPerformingRespawn;

};

