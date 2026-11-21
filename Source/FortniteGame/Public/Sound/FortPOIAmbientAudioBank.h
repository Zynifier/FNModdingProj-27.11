// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AmbientAudioDataAsset.h"
#include "TimeOfDay/FortDayPhase.h"
#include "FortPOIAmbientAudioBank.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FFortPOIAmbientAudioLoop
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Loop Data")
	TSoftObjectPtr<USoundBase> LoopingSound;

	UPROPERTY(EditDefaultsOnly, Category="Loop Data")
	float CrossfadeTime;

};

USTRUCT(BlueprintType)
struct FFortPOIAmbientAudioOneShot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="One-shot Data")
	TSoftObjectPtr<USoundBase> OneShotSound;

	UPROPERTY(EditDefaultsOnly, Category="One-shot Data")
	FVector2D RetriggerTimeRange;

	UPROPERTY(EditDefaultsOnly, Category="One-shot Data")
	FVector2D TriggerDistanceRange;

	UPROPERTY(EditDefaultsOnly, Category="One-shot Data")
	TArray<EFortDayPhase> AllowedDayPhases;

};

UCLASS(NotPlaceable, Deprecated, BlueprintType, meta=(DeprecationMessage="FortPOIAmbientAudioBank has been replaced by AmbientAudioDataAsset"))
class UDEPRECATED_FortPOIAmbientAudioBank : public UAmbientAudioDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Loop Data", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDayPhase"))
	FFortPOIAmbientAudioLoop Loops[4];

	UPROPERTY(EditDefaultsOnly, Category="One-shot Data")
	TArray<FFortPOIAmbientAudioOneShot> OneShots;

};

