// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorCloneMachine.generated.h"

class AFortPlayerPawn;
class AFortPlayerStart;
class USoundCue;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorCloneMachine : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Clone Machine")
	void OnCloneMachineActivationBegins();

	UFUNCTION(BlueprintNativeEvent, Category="Clone Machine")
	void OnCloneMachineRespawningBegins();

	UFUNCTION(BlueprintNativeEvent, Category="Clone Machine")
	void OnCloneMachineSpawnsPlayer(AFortPlayerPawn* PlayerPawn);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStart> CloneLocation;

	UPROPERTY(Transient)
	uint8 bRespawnCompleteAndSelfDestructing : 1;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	FScalableFloat DelayBeforeActivation;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	FScalableFloat DelayBeforeRespawn;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	FScalableFloat DelayBeforeSelfDestruct;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	FScalableFloat DelayBeforeSelfDestructWithStorm;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	TObjectPtr<USoundCue> OnDamagedNotifyPlayerSound;

	UPROPERTY(EditDefaultsOnly, Category="Clone Machine")
	TObjectPtr<USoundCue> OnDestroyedNotifyPlayerSound;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ActivationServerEndTime, Category="BuildingGameplayActorCloneMachine")
	float ActivationServerEndTime;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_RespawnServerEndTime, Category="BuildingGameplayActorCloneMachine")
	float RespawnServerEndTime;

private:
	UFUNCTION()
	void OnRep_ActivationServerEndTime();

	UFUNCTION()
	void OnRep_RespawnServerEndTime();

};

