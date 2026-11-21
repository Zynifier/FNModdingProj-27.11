// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "SoundLibraryContext.generated.h"

class AActor;
class UAudioComponent;
class USoundBase;

/**
 *	FSoundLibraryContextEventInput - Struct to hold input for a single SoundLibraryContext Play event
 */
USTRUCT(BlueprintType)
struct SOUNDLIBRARY_API FSoundLibraryContextEventInput
{
	GENERATED_BODY()

public:
	/** The actor owner of the sound to be played */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Sound Library")
	TObjectPtr<USoundBase> Sound;

	/** The actor owner of the sound to be played */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Sound Library")
	TObjectPtr<AActor> Owner;

	/** The name of the event associated with this PlaySound call */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Sound Library")
	FGameplayTag EventTag;

	/** Metadata about the SoundLibrary entry */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Sound Library")
	FGameplayTagContainer LibraryTags;

};

/**
 *	FSoundLibraryPlayResult - results of a Play call from a SoundLibraryContext
 */
USTRUCT(BlueprintType)
struct SOUNDLIBRARY_API FSoundLibraryPlayResult
{
	GENERATED_BODY()

public:
	/** The name of the event associated with this PlaySound call */
	UPROPERTY(BlueprintReadOnly, Category="Sound Library")
	FGameplayTag EventName;

	/** Set to true if the event was blocked from playback */
	UPROPERTY(BlueprintReadOnly, Category="Sound Library")
	bool bWasBlocked;

	/** Set to true the event had successful playback */
	UPROPERTY(BlueprintReadOnly, Category="Sound Library")
	bool bSuccess;

	/** 
	 * Resulting audio components from playback 
	 * Care should be taken with storing FSoundLibraryPlaySoundResult because these are strong references.
	 */
	UPROPERTY(BlueprintReadWrite, Export, Category="Sound Library", meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> AudioComponents;

};

/**
 *	USoundLibraryContext - Runtime data for sound playback. Derive from this for custom types of contexts.
 */
UCLASS(Abstract, EditInlineNew, HideDropdown, BlueprintType, Blueprintable)
class SOUNDLIBRARY_API USoundLibraryContext : public UObject
{
	GENERATED_BODY()

public:
	/** Creates a valid event name based on our context's data */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	bool CreateEventName(UPARAM(ref) FGameplayTag& OutEventName) const;

	/** Gathers a list of actors that will receive the PlaySound event.  Useful for forwarding events to other actors */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	bool GatherActorTargets(UPARAM(ref) TArray<AActor*>& OutActors) const;

	/** Called when added to an actor via USoundLibrarySubsystem::AddContext */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	void OnAddedToActor(const AActor* InActor);

	/** Called when removed from an actor via USoundLibrarySubsystem::RemoveContext */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	void OnRemovedFromActor(const AActor* InActor);

	/** Handles the play call for the provided sound */
	UFUNCTION(BlueprintNativeEvent, Category="Sound Library")
	bool Play(const FSoundLibraryContextEventInput& InEventData, TArray<UAudioComponent*>& OutComponents);

	UPROPERTY(BlueprintReadWrite, Transient, Category="Sound Library", meta=(ExposeOnSpawn))
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY(BlueprintReadWrite, Category="Sound Library", meta=(Categories="SoundLibrary", ExposeOnSpawn))
	FGameplayTag BaseEventName;

	/** Allows contexts to specify whether or not they should forward events to their Actor's Owner (if one exists) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Sound Library", meta=(ExposeOnSpawn))
	bool bForwardToActorOwner;

	/** Allows contexts to specify whether or not they should forward events to the actors attached to this actor (if they exist) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Sound Library", meta=(ExposeOnSpawn))
	bool bForwardToAttachedActors;

	/** If true, resets the context after use. See SoundLibrarySubsystem::PlaySound for additional details */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Sound Library", meta=(ExposeOnSpawn))
	bool bAutoResetContext;

	/** Game state needed for library playback (optional) */
	UPROPERTY(Transient)
	FGameplayTagContainer PlaybackTags;

};

