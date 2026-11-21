// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortControllerComponent_CreativeDebugger.generated.h"

class AFortMinigame;
class AFortPlayerController;
class UFortControllerComponent_AIDebugger;
enum class EFortMinigameState : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CreativeDebugger : public UFortControllerComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void OnMutatorUpdated();

	UFUNCTION()
	void OnPlayerSpawned(AFortPlayerController* PC);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat DebuggerEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat VerseDebugDrawEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat NavigationMeshEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat NavigationPathsEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat GhostModeEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat InvincibilityEnabledByDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Data Registry")
	FScalableFloat FastIterationEnabledByDataRegistry;

	UPROPERTY(EditAnywhere, Category="Debugger")
	TSubclassOf<UFortControllerComponent_AIDebugger> AIDebuggerClass;

};

