// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "FortControllerComponent_AthenaQuestsPinner.generated.h"

class UAthenaChallengeIndicatorCache;
class UFortMiniMapChallengeIndicators;
class UUserWidget;

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_AthenaQuestsPinner : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Quests Pinner")
	TSubclassOf<UUserWidget> InWorldMarkerWidget;

	UPROPERTY(EditAnywhere, Category="Quests Pinner")
	TSubclassOf<UFortMiniMapChallengeIndicators> MinimapIndicatorClass;

	UPROPERTY(EditAnywhere, Config, Category="Quests Pinner")
	int32 MaximumInWorldPinsOnTheScreen;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Quests Pinner")
	float RevisitInWorldPinsRate;

private:
	UFUNCTION()
	void HandleOnSkydivedFromBusAndLanded(bool bLanded);

	UFUNCTION()
	void HandlePinnedQuestChanged(const FAthenaPinnedQuestData& PinnedQuestData);

	UFUNCTION()
	void HandlePlayerStateAcquired();

	UPROPERTY(Transient)
	TObjectPtr<UFortMiniMapChallengeIndicators> MinimapIndicators;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaChallengeIndicatorCache> ChallengeIndicatorCache;

};

