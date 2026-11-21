// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayComponent.h"
#include "Interfaces/IAudioGameplayVolumeInteraction.h"
#include "Misc/Guid.h"
#include "AmbientAudioComponent.generated.h"

class UAmbientAudioDataAsset;

/**
 *  UAmbientAudioComponent - Audio Gameplay component for ambient audio
 */
UCLASS(BlueprintType, Blueprintable, HideCategories=("AssetUserData", "Activation", "Collision", "Tags"), ClassGroup=("AudioGameplay"), meta=(BlueprintSpawnableComponent))
class AMBIENTAUDIO_API UAmbientAudioComponent : public UAudioGameplayComponent, public IAudioGameplayVolumeInteraction
{
	GENERATED_BODY()

public:
	/** Accessor and Mutator for AmbientAsset */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void SetAmbientAsset(UAmbientAudioDataAsset* InAmbientAsset);

	/** Accessor and Mutator for CrossfadeTime */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void SetCrossfadeTime(float InCrossfadeTime);

	/** Accessor and Mutator for Priority */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void SetPriority(int32 InPriority);

private:
	// Ambient asset to be added when component is activated

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AmbientAudio", meta=(AllowPrivateAccess))
	TObjectPtr<UAmbientAudioDataAsset> AmbientAsset;

	// Priority of this ambient asset.  When multiple assets are active the highest priority assets are played.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AmbientAudio", meta=(AllowPrivateAccess))
	int32 Priority;

	// Crossfade time (in seconds) for this asset. This value is used to determine the appropriate time 
// to fade in and out audio when adding and removing ambient assets to the subsystem

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AmbientAudio", meta=(AllowPrivateAccess))
	float CrossfadeTime;

	// Unique identifier for use with the ambient audio subsystem

	UPROPERTY(Transient)
	FGuid AmbientGuid;

	UPROPERTY(Transient)
	FName DisplayName;

};

