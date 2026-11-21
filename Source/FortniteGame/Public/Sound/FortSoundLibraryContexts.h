// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Components/FortFootstepComponent.h"
#include "SoundLibraryContext.h"
#include "FortSoundLibraryContexts.generated.h"

class AActor;
class UAudioComponent;
class UFortSoundIndicatorComponent;
class UInitialActiveSoundParams;
class USceneComponent;
class USoundAttenuation;
class USoundBase;
class USoundConcurrency;

USTRUCT(BlueprintType)
struct FFortPlayerFoleyContextSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound Library", meta=(Categories="SoundLibrary"))
	FGameplayTag EventName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound Library")
	EFortFootstepPlayerRelation RelationToPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound Library")
	EFortFootstepStanceType Stance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound Library")
	EFortFootstepSurface Surface;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	FGameplayTagContainer ContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ClampMin="0.0"))
	float VolumeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ClampMin="0.0"))
	float PitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bUseSurfaceType;

};

USTRUCT(BlueprintType)
struct FFortSoundLibraryPlaybackSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attach")
	bool bAttachedSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	bool bStopWhenAttachedDestroyed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	bool bAutoDestroy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bForceComponentCreation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float VolumeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float PitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	float StartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	TObjectPtr<USoundConcurrency> ConcurrencySettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Playback")
	TObjectPtr<USoundAttenuation> AttenuationSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attach", meta=(AnimNotifyBoneName="true"))
	FName AttachName;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Attach", meta=(EditInline="true", ExposeOnSpawn))
	TObjectPtr<USceneComponent> AttachToComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Attach")
	TEnumAsByte<EAttachLocation::Type> LocationType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Attach")
	FVector Location;

};

UCLASS(BlueprintType)
class FORTNITEGAME_API UFortPlayerFoleyContext : public USoundLibraryContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void ConfigureContext(AActor* OwningActor, const FFortPlayerFoleyContextSettings& InSettings);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(AnimNotifyExpand="true", DisplayName="Settings", ExposeOnSpawn))
	FFortPlayerFoleyContextSettings PlayerFoleySettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bPlaySoundFromNative;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerFoleyContext")
	TObjectPtr<UInitialActiveSoundParams> AudioParams;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortSoundIndicatorComponent> SoundIndicator;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerFoleyContext")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerFoleyContext")
	bool bContextValid;

};

UCLASS(BlueprintType)
class UFortSoundLibraryContext : public USoundLibraryContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(AnimNotifyExpand="true", ExposeOnSpawn))
	FFortSoundLibraryPlaybackSettings PlaybackSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ExposeOnSpawn))
	bool bAppendPerspectiveTag;

protected:
	UFUNCTION(BlueprintPure, Category="Sound Library")
	bool PlaySoundAttached(AActor* InActor, USoundBase* InSound, TArray<UAudioComponent*>& OutComponents) const;

	UFUNCTION(BlueprintPure, Category="Sound Library")
	bool PlaySoundSimple(AActor* InActor, USoundBase* InSound, TArray<UAudioComponent*>& OutComponents) const;

};

