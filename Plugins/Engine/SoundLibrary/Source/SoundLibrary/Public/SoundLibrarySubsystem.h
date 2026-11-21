// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "SoundLibraryContext.h"
#include "SoundLibrarySimpleContext.h"
#include "SoundLibrarySubsystem.generated.h"

class AActor;
class USoundLibrary;
class USoundLibraryCollection;
class USoundLibraryContext;
class USoundLibrarySimpleContext;

/**
 *	FSoundLibraryActorData - runtime data for an actor participating in the SoundLibrarySubsystem
 */
USTRUCT()
struct FSoundLibraryActorData
{
	GENERATED_BODY()

public:
	/** Our collection of SoundLibraries */
	UPROPERTY(Transient)
	TSet<TObjectPtr<USoundLibrary>> SoundLibraries;

	/** Our collection of SoundLibraryContexts */
	UPROPERTY(Transient)
	TArray<TObjectPtr<USoundLibraryContext>> SoundLibraryContexts;

};

/**
 * USoundLibrarySubsystem - Per world subsystem used to manage registration and playback of Sound Libraries 
 */
UCLASS()
class SOUNDLIBRARY_API USoundLibrarySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Adds a specific SoundLibraryContext to a given actor
	 * @param Actor - The actor we're retrieving the context from
	 * @param ContextClass - Specific class type of the context we're trying to add
	 * 
	 * @return The context that was added (or found, if one of this type was already present)
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	USoundLibraryContext* AddContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass);

	/**
	 * Adds multiple Sound Libraries to an Actor
	 * @param Actor - The actor using the libraries
	 * @param Libraries - The sound libraries to add
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void AddLibraries(AActor* Actor, TArray<USoundLibrary*> Libraries);

	/**
	 * Adds multiple Sound Libraries to an Actor
	 * @param Actor - The actor using the libraries
	 * @param CollectionTags - The collection of tags that index into our LibraryCollections (see USoundLibraryCollection)
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void AddLibrariesFromCollections(AActor* Actor, const FGameplayTagContainer& CollectionTags);

	/**
	 * Adds a Sound Library to an Actor
	 * @param Actor - The actor using the library
	 * @param Library - The sound library to add
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void AddLibrary(AActor* Actor, USoundLibrary* Library);

	/**
	 * Pauses event response within the Sound Library system.
	 * NOTE: Libraries can still be added and removed as normal.  Call ::EnableEventsForActor to resume
	 * @param Actor - The actor using the library
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void DisableEventsForActor(const AActor* Actor);

	/**
	 * Resumes event response within the Sound Library system. 
	 * NOTE: See also ::DisableEventsForActor
	 * @param Actor - The actor using the library
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void EnableEventsForActor(const AActor* Actor);

	/**
	 * Returns a specific SoundLibraryContext on a given actor, if it exists
	 * @param Actor - The actor we're retrieving the context from
	 * @param ContextClass - Specific class type of the context we're trying to retrieve
	 *
	 * @return The context that was found, null if it was not already on the specified actor
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	USoundLibraryContext* GetContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass);

	/**
	 * Plays sound(s) using the given context
	 * NOTE: The context is intentionally reset after successful use!
	 * @param Context - Information needed for locating the correct sounds
	 * @param OutResults - extra data related to the results of function call
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library", meta=(DisplayName="Play Sound with Context"))
	void PlaySound(USoundLibraryContext* Context, FSoundLibraryPlayResult& OutResults);

	/**
	 * Plays sound(s) using SimpleSoundLibraryContext
	 * @param InSettings - Information needed for determining playback behavior
	 * @param OutResults - extra data related to the results of function call
	 * 
	 * @return True if the actor was valid and had at least one successful sound library event matching the tag
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library", meta=(DisplayName="Play Sound Simple"))
	FSoundLibraryPlayResult PlaySoundSimple(AActor* OwningActor, const FSoundLibrarySimpleContextSettings& InSettings);

	/**
	 * Removes a SoundLibraryContext from an Actor if it exists
	 * @param Actor - The actor we're retrieving the context from
	 * @param ContextClass - Specific class type of the context we're trying to retrieve
	 *
	 * @return Whether or not a context was actually found and removed from the specified actor
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	bool RemoveContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass);

	/**
	 * Removes multiple Sound Libraries from an Actor
	 * @param Actor - The actor using the libraries
	 * @param Libraries - The sound libraries to remove
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void RemoveLibraries(const AActor* Actor, TArray<USoundLibrary*> Libraries);

	/**
	 * Removes multiple Sound Libraries from an Actor
	 * @param Actor - The actor using the libraries
	 * @param CollectionTags - The collection of tags that index into our LibraryCollections (see USoundLibraryCollection)
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void RemoveLibrariesFromCollections(const AActor* Actor, const FGameplayTagContainer& CollectionTags);

	/**
	 * Removes a Sound Library from an Actor
	 * @param Actor - The actor using the library
	 * @param Library - The sound library to remove
	 */
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void RemoveLibrary(const AActor* Actor, USoundLibrary* Library);

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<USoundLibraryCollection>> LibraryCollections;

	UPROPERTY(Transient)
	TObjectPtr<USoundLibrarySimpleContext> SimpleContext;

	UPROPERTY(Transient)
	TMap<uint32, FSoundLibraryActorData> ActorDataMap;

};

