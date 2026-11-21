// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_OverrideLockerConfigInPlaylist.generated.h"

class UFortLockerConfig;

UCLASS(MinimalAPI, meta=(DisplayName="Add Locker Config Playlists Override"))
class UFortUIGameFeatureAction_OverrideLockerConfigInPlaylist : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config Override")
	FGameplayTagQuery PlaylistQuery;

	UPROPERTY(EditAnywhere, Category="Config Override")
	TObjectPtr<UFortLockerConfig> LockerConfig;

};

