// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "FortFallTeleportSpawnerComponent.generated.h"

class AActor;
class UFortFallTeleportComponentBase;

UCLASS(BlueprintType, Blueprintable)
class FALLTELEPORTATIONRUNTIME_API UFortFallTeleportSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event);

	UFUNCTION()
	void HandleWarmupCountdownEndTimeUpdated(float NewEndTime);

	UPROPERTY(EditDefaultsOnly, Category="Fall Teleportation")
	TSoftClassPtr<AActor> PlayerPawnReceiverClass;

	UPROPERTY(EditDefaultsOnly, Category="Fall Teleportation")
	TSubclassOf<UFortFallTeleportComponentBase> ComponentToAddClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Fall Teleportation")
	FScalableFloat TeleportEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="Fall Teleportation")
	FScalableFloat RemoveComponentRequestTimeOffset;

};

