// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayRequirements.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AmbientAudioTypes.generated.h"

class UAudioParameterComponent;
class USoundBase;
enum class EAmbientAudioEntryActionType : uint8;
enum class EAmbientAudioTagActionType : uint8;

/**
 *	EAmbientAudioEntryActionType - The type of change associated with an ambient audio entry change event
 */
UENUM(BlueprintType)
enum class EAmbientAudioEntryActionType : uint8
{
	Added = 0,
	Updated = 1,
	Removed = 2,
	Count = 3 UMETA(Hidden),
};

/**
 *	EAmbientAudioTagActionType - The type of change associated with an ambient audio tag change event
 */
UENUM(BlueprintType)
enum class EAmbientAudioTagActionType : uint8
{
	Added = 0,
	Removed = 1,
	Count = 2 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAmbientAudioEntryChangeSignature, FName, AmbientName, EAmbientAudioEntryActionType, ActionType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAmbientAudioTagChangeSignature, const FGameplayTag&, GameplayTag, EAmbientAudioTagActionType, ActionType);

/**
 *	FAmbientAudioBase - Base audio data used for ambiance
 */
USTRUCT(BlueprintType)
struct AMBIENTAUDIO_API FAmbientAudioBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(AllowedClasses="/Script/Engine.SoundBase", DisplayPriority="1"))
	TSoftObjectPtr<USoundBase> Sound;

	///** DEPRECATED - Use "Custom" inside Requirements details view instead */
//UE_DEPRECATED(5.1, "Use PlaybackRequirements.Custom instead")

	UPROPERTY()
	FGameplayTagQuery Requirements;

	/** Requirements that need to be met for sound playback */
	UPROPERTY(EditAnywhere, Category="Requirements", meta=(ShowOnlyInnerProperties))
	FAudioGameplayRequirements PlaybackRequirements;

};

/**
 *	FAmbientAudioLoop - Looping audio used for an ambient bed
 */
USTRUCT(BlueprintType)
struct AMBIENTAUDIO_API FAmbientAudioLoop : public FAmbientAudioBase
{
	GENERATED_BODY()

};

/**
 *	FAmbientAudioOneShot - Periodic ambient one shot audio
 */
USTRUCT(BlueprintType)
struct AMBIENTAUDIO_API FAmbientAudioOneShot : public FAmbientAudioBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Settings", meta=(DisplayPriority="2"))
	FVector2D RetriggerTimeRange;

	UPROPERTY(EditAnywhere, Config, Category="Settings", meta=(DisplayPriority="2"))
	FVector2D TriggerDistanceRange;

};

/*
 *   AAmbientAudioSubsystemActor - Spawned and owned by AmbientAudioSubsystem, used for parameter sharing between all playing sounds
 */
UCLASS(BlueprintType, Blueprintable)
class AAmbientAudioParameterActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioParameterComponent> Parameters;

};

