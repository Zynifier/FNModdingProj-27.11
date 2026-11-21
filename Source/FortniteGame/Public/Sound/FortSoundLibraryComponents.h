// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/FortSoundLibraryContexts.h"
#include "SoundLibraryComponent.h"
#include "FortSoundLibraryComponents.generated.h"

UCLASS(BlueprintType, HideCategories=("Tags", "ComponentReplication", "Sockets", "Activation", "Cooking", "Collision", "ComponentTick", "AssetUserData", "Replication", "Variable", "Navigation"))
class UFortSoundLibraryComponent : public USoundLibraryComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlaybackSettings(const FFortSoundLibraryPlaybackSettings& InSettings);

	UPROPERTY(EditDefaultsOnly, Category="Sound Library")
	FFortSoundLibraryPlaybackSettings PlaybackSettings;

};

