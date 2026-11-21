// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "SoundLibrarySettings.generated.h"

class USoundLibrary;
class USoundLibraryCollection;

/**
 * FSoundLibrarySet - Set of SoundLibrary objects
 */
USTRUCT()
struct FSoundLibrarySet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Config")
	TSet<TObjectPtr<USoundLibrary>> LibrarySet;

};

/**
 * USoundLibraryCollection - A data asset representing a collection of SoundLibraries, indexed by GameplayTag
 */
UCLASS()
class USoundLibraryCollection : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound Library")
	TMap<FGameplayTag, FSoundLibrarySet> Libraries;

};

/**
 * USoundLibrarySettings - Configurable settings for the SoundLibrary plugin
 */
UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Sound Library"))
class USoundLibrarySettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** A collection of sound libraries associated with GameplayTags for convenience */
	UPROPERTY(EditAnywhere, Config, Category="Config")
	TSoftObjectPtr<USoundLibraryCollection> CommonLibraries;

};

