// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "FortGameFeatureAction_AddToPlaylists.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Plugin To Playlists"))
class UFortGameFeatureAction_AddToPlaylists : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FName PluginName_DEPRECATED;

	UPROPERTY(EditAnywhere, Category="Playlist")
	bool bActivateSelf;

	UPROPERTY(EditAnywhere, DuplicateTransient, Category="Playlist")
	TArray<FName> OptionalAdditionalPluginsToActivate;

	UPROPERTY(EditAnywhere, Category="Playlist")
	FGameplayTagQuery PlaylistQuery;

	UPROPERTY(EditAnywhere, Category="Playlist")
	FName RequiredCVar;

};

