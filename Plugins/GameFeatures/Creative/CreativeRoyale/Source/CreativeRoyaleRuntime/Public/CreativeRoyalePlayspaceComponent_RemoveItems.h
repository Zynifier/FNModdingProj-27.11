// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "CreativeRoyalePlayspaceComponent_RemoveItems.generated.h"

class AFortMinigame;
enum class EFortMinigameState : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class CREATIVEROYALERUNTIME_API UCreativeRoyalePlayspaceComponent_RemoveItems : public UPlayspaceComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION()
	void OnPlotLoadComplete();

	UFUNCTION()
	void OnSpawningFromSaveFinish();

	UPROPERTY(Transient)
	bool bSpawnFromGameplay;

};

