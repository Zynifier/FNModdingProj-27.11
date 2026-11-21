// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "PlayspaceUsers.h"
#include "Playspaces/Components/PlayspaceComponent_LoadingScreen.h"
#include "CreativeRoyalePlayspaceComponent_LoadingScreen.generated.h"

class AFortMinigame;
enum class EFortMinigameState : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UCreativeRoyalePlayspaceComponent_LoadingScreen : public UPlayspaceComponent_LoadingScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="LoadingScreen")
	bool bShouldDisplayLoadingScreenDuringPostGame;

private:
	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void OnPlayspaceUserAdded(FPlayspaceUser& AddedUser);

	UFUNCTION()
	void OnPlotLoadComplete();

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FText PlotNotFinishedLoadingContext;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FText MinigameResetContext;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	FScalableFloat FailsafeTimeoutLength;

};

