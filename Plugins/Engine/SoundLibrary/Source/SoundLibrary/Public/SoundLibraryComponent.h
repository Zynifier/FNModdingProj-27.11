// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayComponent.h"
#include "GameplayTagContainer.h"
#include "SoundLibraryContext.h"
#include "SoundLibraryProviderInterface.h"
#include "SoundLibraryComponent.generated.h"

class UAudioComponent;
class USoundLibrary;
class USoundLibraryContext;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoundLibraryEvent, FGameplayTag, EventName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSoundLibraryPlayEvent, const FSoundLibraryPlayResult&, Results, const USoundLibraryContext*, Context);

/**
 * USoundLibraryComponent
 */
UCLASS(HideCategories=("Tags", "ComponentReplication", "Sockets", "Activation", "Cooking", "Collision", "ComponentTick", "AssetUserData", "Replication", "Variable", "Navigation"), ClassGroup=("Audio"), meta=(BlueprintSpawnableComponent, DisplayName="SoundLibraryComponent"))
class SOUNDLIBRARY_API USoundLibraryComponent : public UAudioGameplayComponent, public ISoundLibraryProviderInterface
{
	GENERATED_BODY()

public:
	/** Adds an array of SoundLibraries to this component's owner */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void AddLibraries(const TArray<USoundLibrary*>& InLibraries);

	/** Adds SoundLibrary to this component's owner */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void AddLibrary(USoundLibrary* InLibrary);

	/** Returns the SoundLibraryContext that this component internally manages */
	UFUNCTION(BlueprintPure, Category="Sound Library")
	USoundLibraryContext* GetContext() const;

	/** Returns true if provided SoundLibrary tag has active audio components */
	UFUNCTION(BlueprintPure, Category="Sound Library")
	bool IsEventActive(FGameplayTag InEventName);

	UFUNCTION(BlueprintImplementableEvent, Category="Sound Library", meta=(ForceAsFunction))
	void OnEventPlayed(FGameplayTag InEventName);

	UFUNCTION(BlueprintImplementableEvent, Category="Sound Library", meta=(ForceAsFunction))
	void OnEventStopped(FGameplayTag InEventName);

	/** Allows user of this component to override functionality directly after a sound is played from this component's SoundLibraryContext */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library", meta=(ForceAsFunction))
	void OnSoundPlayed(FGameplayTag InEventName, UAudioComponent* InComponent);

	/** Allows user of this component to override functionality when this component is told to Stop an actively playing Event */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	void OnSoundStopped(FGameplayTag InEventName, UAudioComponent* InComponent, bool& bStopped);

	/** 
	  *  Plays an event on the SoundLibraryContext that this component internally manages
	  *  
	  *  Note: if left empty (optional) the context is expected to generate the event name based on runtime data
	  */
	UFUNCTION(BlueprintCallable, Category="Sound Library", meta=(CPP_Default_InEventName="()"))
	virtual FSoundLibraryPlayResult PlayEvent(FGameplayTag InEventName);

	/** Removes an array of SoundLibraries from this component's owner */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void RemoveLibraries(const TArray<USoundLibrary*>& InLibraries);

	/** Removes a SoundLibrary from this component's owner */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void RemoveLibrary(USoundLibrary* InLibrary);

	/**
	  *  Stops a currently-active event. By default will call Stop on any AudioComponent(s) that were created from the PlayEvent w/ the corresponding EventName
	  *  
	  *  Note: implement OnSoundStopped if you want to customize this behavior
	  */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	virtual bool StopEvent(FGameplayTag InEventName);

	/** Optional GameplayTag that gets converted to a ComponentTag that can be used to find this component on an actor specifically */
	UPROPERTY(EditDefaultsOnly, Category="Sound Library", meta=(Categories="SoundLibrary"))
	FGameplayTag ComponentTag;

	/** SoundLibraryContext class to create when this component is initialized */
	UPROPERTY(EditAnywhere, Category="Sound Library")
	TSubclassOf<USoundLibraryContext> ContextClass;

	/** SoundLibraries to add to the actor that owns this Component */
	UPROPERTY(EditAnywhere, Category="Sound Library")
	TArray<TObjectPtr<USoundLibrary>> Libraries;

	UPROPERTY(BlueprintAssignable)
	FOnSoundLibraryPlayEvent OnSoundLibraryPlayEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSoundLibraryEvent OnEventPlayedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnSoundLibraryEvent OnEventStoppedDelegate;

protected:
	UPROPERTY(Transient)
	TObjectPtr<USoundLibraryContext> Context;

};

