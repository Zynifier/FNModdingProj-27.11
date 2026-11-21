// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "CreativeGameStreamDeviceCoordinatorComponent.generated.h"

class AFortMinigame;
class UCreativeGameStreamDeviceComponent;
enum class EFortMinigameState : uint8;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UCreativeGameStreamDeviceCoordinatorComponent : public UPlayspaceComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* InMinigame, const EFortMinigameState NewMinigameState);

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UCreativeGameStreamDeviceComponent>> EndGameCreativeGameStreamDeviceComponentQueue;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortMinigame> Minigame;

};

