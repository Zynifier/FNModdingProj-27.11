// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "AmbientAudioTypes.h"
#include "AmbientAudioSubsystem.generated.h"

class AAmbientAudioParameterActor;
class UAmbientAudioComponent;
class UAmbientAudioDataAsset;
class UAudioParameterComponent;

/**
 * UAmbientAudioSubsystem
 */
UCLASS()
class AMBIENTAUDIO_API UAmbientAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Adds an Ambient Entry to the Ambient Subsystem
	 * @param AmbientName - Name of the ambient entry
	 * @param Asset - The ambient asset containing the ambient audio data
	 * @param Priority - priority of this entry if multiple entries are active
	 * @param CrossfadeTime - crossfade time when changing assets due to priority (in seconds)
	 *
	 * @note: Do not call this for Ambient volumes - volumes will add their ambient entry automatically
	 */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void AddAmbientEntry(FName AmbientName, UAmbientAudioDataAsset* Asset, int32 Priority = 0, float CrossfadeTime = 0.000000f);

	/**
	 * Adds a GameplayTag to the Subsystem's active tags
	 * @param GameplayTag - Gameplay Tag to add / activate
	 */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void AddGameplayTag(FGameplayTag GameplayTag);

	/**
	 * Returns the AudioParameterComponent from the ParameterActor that this subsystem manages
	 */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	UAudioParameterComponent* GetAudioParameterComponent();

	/**
	 * Remove an Ambient Entry from the Ambient Player
	 * @param AmbientName - Name of the Ambient Entry
	 * @param CrossfadeOverride - If non-negative, this value will be used for fading out (in seconds)
	 *
	 * @note: Do not call this for Ambient volumes - volumes will remove their ambient entry automatically
	 */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void RemoveAmbientEntry(FName AmbientName, float CrossfadeOverride = -1.000000f);

	/**
	 * Removes a GameplayTag from the Subsystem's active tags
	 * @param GameplayTag - Gameplay Tag to remove / deactivate
	 */
	UFUNCTION(BlueprintCallable, Category="AmbientAudio")
	void RemoveGameplayTag(FGameplayTag GameplayTag);

	UPROPERTY(BlueprintAssignable, Category="AmbientAudio")
	FAmbientAudioTagChangeSignature OnTagChanged;

	UPROPERTY(BlueprintAssignable, Category="AmbientAudio")
	FAmbientAudioEntryChangeSignature OnEntryChanged;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAmbientAudioComponent>> AmbientComponents;

	UPROPERTY(Transient)
	TObjectPtr<AAmbientAudioParameterActor> ParameterActor;

};

