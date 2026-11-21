// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpecialEventAudioAnalysisBaseComponent.h"
#include "SpecialEventAudioHapticsComponent.generated.h"

USTRUCT(BlueprintType)
struct FSpecialEventAudioHapticsAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	float LoudnessFloor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	float LoudnessCeiling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	float HapticsIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	int32 ChannelIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	uint8 bAffectsLeftLarge : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	uint8 bAffectsLeftSmall : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	uint8 bAffectsRightLarge : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpecialEventAudioHapticsAction")
	uint8 bAffectsRightSmall : 1;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class USpecialEventAudioHapticsComponent : public USpecialEventAudioAnalysisBaseComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="EventAudioHaptics")
	bool AreHapticsActive() const;

	UFUNCTION(BlueprintCallable, Category="EventAudioHaptics")
	void StartHaptics();

	UFUNCTION(BlueprintCallable, Category="EventAudioHaptics")
	void StopHaptics();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EventAudioHaptics")
	TArray<FSpecialEventAudioHapticsAction> HapticsActions;

	UPROPERTY(EditAnywhere, Category="EventAudioHaptics")
	bool bStartHapticsOnBeginPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="EventAudioHaptics")
	float IntensityMultiplier;

};

