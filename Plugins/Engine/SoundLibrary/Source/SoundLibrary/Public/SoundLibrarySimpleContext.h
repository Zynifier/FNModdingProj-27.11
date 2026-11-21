// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "SoundLibraryContext.h"
#include "SoundLibrarySimpleContext.generated.h"

class AActor;
class USceneComponent;
class USoundAttenuation;
class USoundConcurrency;

/**
 *	FSoundLibrarySimpleContextSettings - Context settings for a USoundLibrarySimpleContext.
 *   A context is intended to be reset after each use, but the associated settings object is not reset.  
 *   This allows our settings object to hold the (typically tool-time) data needed to invoke the correct event.
 */
USTRUCT(BlueprintType, meta=(DisplayName="Simple Sound Settings"))
struct FSoundLibrarySimpleContextSettings
{
	GENERATED_BODY()

public:
	/** The name of the corresponding event in a SoundLibrary */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(Categories="SoundLibrary"))
	FGameplayTag EventName;

	/** If true, an audio component is created and attached to the scene component specified in the USoundLibrarySimpleContext. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attach")
	bool bAttachedSound;

	/** Should we stop playing when the owner of the attach component is destroyed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	bool bStopWhenAttachedDestroyed;

	/** Should we cleanup the audio component when the sound completes or is stopped */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	bool bAutoDestroy;

	/** force creation of an audio component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bForceComponentCreation;

	/** A linear scalar multiplied with the volume, in order to make the sound louder or softer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float VolumeMultiplier;

	/** A linear scalar multiplied with the pitch */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float PitchMultiplier;

	/** Length (in seconds) in which to begin playback */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float StartTime;

	/** Override Concurrency settings package */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	TObjectPtr<USoundConcurrency> ConcurrencySettings;

	/** Override Attenuation settings package */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	TObjectPtr<USoundAttenuation> AttenuationSettings;

	/** Socket or bone name used for attachment */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attach", meta=(AnimNotifyBoneName="true"))
	FName AttachName;

	/** Component used for spawning attached sounds.  If not specified, will fall back to the actor's default attach component. */
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Attach", meta=(EditInline="true", ExposeOnSpawn))
	TObjectPtr<USceneComponent> AttachToComponent;

	/** Specifies whether Location is a relative offset or an absolute world position */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Attach")
	TEnumAsByte<EAttachLocation::Type> LocationType;

	/** Either a relative offset from attach component or an absolute world position translated to a relative offset. (Depends on the value of Location Type) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Attach")
	FVector Location;

};

/**
 *	USoundLibrarySimpleContext - Minimal context for basic sound playback using the SoundLibrarySubsystem.
 *   The Settings object can be modified directly if used as part of an animation notify, or set with 
 *   ConfigureContext if called natively or through blueprint.
 */
UCLASS(BlueprintType, meta=(DisplayName="Simple Sound Context"))
class SOUNDLIBRARY_API USoundLibrarySimpleContext : public USoundLibraryContext
{
	GENERATED_BODY()

public:
	//~ End USoundLibraryContext interface

	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void ConfigureContext(AActor* OwningActor, const FSoundLibrarySimpleContextSettings& InSettings);

	/** Parameters used to customize this context */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(AnimNotifyExpand="true", ExposeOnSpawn))
	FSoundLibrarySimpleContextSettings Settings;

};

