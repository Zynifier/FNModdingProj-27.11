// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_RegisterCustomInGameState.generated.h"

class UFortPlaylist;
class UFortUIStateWidgetBase;

UCLASS(MinimalAPI, meta=(DisplayName="Register Custom InGame State"))
class UFortUIGameFeatureAction_RegisterCustomInGameState : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_RegisterCustomInGameState")
	TSoftObjectPtr<UFortPlaylist> Playlist;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylist> CachedPlaylist;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_RegisterCustomInGameState")
	TSoftClassPtr<UFortUIStateWidgetBase> CustomInGameStateWidget;

};

