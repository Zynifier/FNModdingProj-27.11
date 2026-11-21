// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "SoundLibraryContext.h"
#include "AnimNotify_SoundLibrary.generated.h"

class AActor;
class UAnimSequenceBase;
class UAudioComponent;
class USkeletalMeshComponent;
class USoundLibrary;
class USoundLibraryAnimNotifyHelper;
class USoundLibraryContext;

/**
 * ESoundLibraryNotifyTriggerType
 */
UENUM()
enum class ESoundLibraryNotifyTriggerType : uint8
{
	Play = 0,
	Stop = 1,
	None = 2,
};

/**
 *	FSoundLibraryAnimContextSettings
 */
USTRUCT(BlueprintType, meta=(DisplayName="Animation Notify Settings"))
struct FSoundLibraryAnimContextSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Preview", meta=(ClampMin="0.0"))
	float PreviewAnimationRate;
#endif

	/** The animation rate needs to be inside the Min and Max for playback.  This threshold will be ignored if both values are zero. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ClampMin="0.0"))
	FFloatInterval AnimRateThreshold;

	/** The name of the corresponding event in a SoundLibrary */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(Categories="SoundLibrary"))
	FGameplayTag EventName;

	/** NOTE! Please be aware attaching to an actor creates an audio component.  Use only if needed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bAttachToActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(AnimNotifyBoneName="true"))
	FName AttachName;

	/** NOTE! Please be aware fade out functionality creates an audio component.  Use only if needed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library")
	bool bFadeOutOnEnd;

	/** Looping sounds will always use FadeTime regardless of FadeOutOnEnd. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(EditCondition="bFadeOutOnEnd"))
	float FadeTime;

	/** Defines the chance of of this notify triggering, 0 = No Chance, 1 = Always triggers. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ClampMax="1.0", ClampMin="0.0"))
	float NotifyTriggerChance;

	/** Volume multiplier for sound playback. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(ClampMin="0.0"))
	float VolumeMultiplier;

};

/**
 * UAnimNotifyState_SoundLibrary
 */
UCLASS(HideCategories=("Object"))
class SOUNDLIBRARY_API UAnimNotifyState_SoundLibrary : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Sound", meta=(AnimNotifyExpand="true"))
	TObjectPtr<USoundLibraryContext> SoundContext;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Sound")
	TSoftObjectPtr<USoundLibrary> TestLibrary;
#endif

	UPROPERTY(Transient)
	TObjectPtr<USoundLibraryAnimNotifyHelper> NotifyHelper;

};

/**
 * UAnimNotify_SoundLibrary
 */
UCLASS(HideCategories=("Object"))
class SOUNDLIBRARY_API UAnimNotify_SoundLibrary : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Sound", meta=(AnimNotifyExpand="true"))
	TObjectPtr<USoundLibraryContext> SoundContext;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Sound")
	TSoftObjectPtr<USoundLibrary> TestLibrary;
#endif

	UPROPERTY(Transient)
	TObjectPtr<USoundLibraryAnimNotifyHelper> NotifyHelper;

};

/**
 *	USoundLibraryAnimContext - Context for sound playback via animation notify.
 */
UCLASS(BlueprintType, meta=(DisplayName="Animation Notify Context"))
class SOUNDLIBRARY_API USoundLibraryAnimContext : public USoundLibraryContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sound Library")
	void ConfigureContext(AActor* OwningActor, UAnimSequenceBase* InAnimation, const FSoundLibraryAnimContextSettings& InSettings);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound Library", meta=(AnimNotifyExpand="true", DisplayName="Settings", ExposeOnSpawn))
	FSoundLibraryAnimContextSettings AnimSettings;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Sound Library", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UAnimSequenceBase> Animation;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<USkeletalMeshComponent> MeshComponent;

	/** This will be true when normal burst SoundLibrary_AnimNotify's are used */
	UPROPERTY(Transient)
	bool bSupportsNotifyEnd;

	UPROPERTY(Transient)
	float AnimRate;

};

/**
 *	USoundLibraryAnimNotifyHelper - Shared functionality for sound playback via animation notify / notify state.
 */
UCLASS()
class USoundLibraryAnimNotifyHelper : public UObject
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<USoundLibrary> TestLibrary;
#endif

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UAudioComponent>> PlayingComps;

};

