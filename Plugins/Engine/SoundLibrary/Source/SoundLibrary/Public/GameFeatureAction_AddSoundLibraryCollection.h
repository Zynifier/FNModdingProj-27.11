// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddSoundLibraryCollection.generated.h"

class USoundLibraryCollection;
class USoundLibrarySubsystem;

/**
 * GameFeatureAction responsible for adding sound library collections to the sound library subsystem
 */
UCLASS(MinimalAPI, meta=(DisplayName="Add SoundLibrary Collection"))
class UGameFeatureAction_AddSoundLibraryCollection : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	/** Our collection of sound library collections, to be added to the sound library subsystem */
	UPROPERTY(EditAnywhere, Category="SoundLibrary", meta=(AssetBundles="Client"))
	TArray<TSoftObjectPtr<USoundLibraryCollection>> CollectionList;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<USoundLibrarySubsystem>> TrackedSubsystems;

};

