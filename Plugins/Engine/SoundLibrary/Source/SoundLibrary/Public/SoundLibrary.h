// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayRequirements.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "SoundLibrary.generated.h"

class USoundBase;
class USoundLibrary;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSoundLibraryEditorEvent);

/**
 *	USoundLibrary - A collection of sounds, indexed by EventName as a GameplayTag
 */
UCLASS(BlueprintType, Blueprintable)
class SOUNDLIBRARY_API USoundLibrary : public UObject
{
	GENERATED_BODY()

public:
	/** Adds a Sound to this Library at runtime.  NOTE: Sounds added in this fashion will not be saved with the library! */
	UFUNCTION(BlueprintCallable, Category="Scripting", meta=(DisplayName="Add Sound (Transient)"))
	void AddSound(FGameplayTag InTag, USoundBase* InSound);

	/** Finds a sound. Returns a sound base object */
	UFUNCTION(BlueprintPure, Category="Scripting")
	USoundBase* FindSound(FGameplayTag InTag) const;

	/** Allows for runtime setting of this Library's channel */
	UFUNCTION(BlueprintCallable, Category="Scripting")
	void SetChannel(FGameplayTag InTag);

	/** Allows for runtime setting of this Library's priority */
	UFUNCTION(BlueprintCallable, Category="Scripting")
	void SetPriority(int32 InPriority);

#if WITH_EDITOR
	/** Sorts this SoundLibrary alphabetically by each GameplayTag Key entry */
	UFUNCTION(BlueprintCallable, Category="Editor")
	void Sort();
#endif

#if WITH_EDITORONLY_DATA
	/** Editor only description of this SoundLibrary asset (optional) */
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="Sound Library", meta=(MultiLine="true"))
	FString Description;
#endif

	/** The collection of sound objects, indexed by GameplayTag */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound Library", meta=(Categories="SoundLibrary"))
	TMap<FGameplayTag, TSoftObjectPtr<USoundBase>> Sounds;

	/** Requirements that need to be met for this library to be considered */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Requirements", meta=(ShowOnlyInnerProperties))
	FAudioGameplayRequirements LibraryRequirements;

	/**
	 * If specified, this Library is sorted against other Library assets that have the same Channel.
	 * By default, results will contain the entries with the highest priority, per channel.  
	 * This behavior can be customized with a custom context (See also USoundLibraryContext::FilterResultsForPlayback)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config", meta=(Categories="SoundLibrary", EditCondition="bCanActAsParent", EditConditionHides))
	FGameplayTag Channel;

	/** Used in conjunction with the Channel to determine matching entries per event call.  Ignored if Channel is unused. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config", meta=(EditCondition="bCanActAsParent || Parent != nullptr", EditConditionHides))
	int32 Priority;

	/** Metadata in the form of gameplay tags that can be actioned in the sound library context on event playback */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	FGameplayTagContainer Metadata;

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintAssignable, Category="Editor")
	FSoundLibraryEditorEvent OnRebuildMap;
#endif

#if WITH_EDITORONLY_DATA
	/** The parent library. Sounds in the parent library are included unless overridden in the current library. See 'FullLibrary' member for more info */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	TObjectPtr<USoundLibrary> Parent;
#endif

#if WITH_EDITORONLY_DATA
	/** If true, other libraries can choose this library as a valid parent */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config", meta=(DisplayPriority="5"))
	bool bCanActAsParent;
#endif

	/** Complete listing of this library's contents at runtime, including library entries inherited from parents */
	UPROPERTY(VisibleDefaultsOnly, Category="GameData")
	TMap<FGameplayTag, TSoftObjectPtr<USoundBase>> FullLibrary;

	/** Sound entries dynamically added at runtime, indexed by GameplayTag */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<USoundBase>> RuntimeSounds;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USoundBase>> LoadedSoundObjects;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<USoundBase>> Assets;

};

