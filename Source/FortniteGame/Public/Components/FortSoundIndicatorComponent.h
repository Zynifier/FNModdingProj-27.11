// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortSoundCameraLensEffect.h"
#include "FortSoundIndicatorComponent.generated.h"

class AActor;
class APlayerState;
class USoundAttenuation;
class USoundBase;
class UTexture;
enum class EFortSoundIndicatorTypes : uint8;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSoundIndicatorIconPicker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SoundIndicatorIconPicker")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="SoundIndicatorIconPicker")
	TObjectPtr<UTexture> IconOverride;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSoundIndicatorTypePicker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SoundIndicatorTypePicker")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="SoundIndicatorTypePicker")
	EFortSoundIndicatorTypes SoundIndicatorType;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Variable", "ComponentTick", "ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"), meta=(BlueprintSpawnableComponent))
class UFortSoundIndicatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Sound Indicator")
	void InitializeDefaultValues(const float InUpdateFrequency, const bool bInStartLoopingOnBeginPlay, const EFortSoundIndicatorTypes InDefaultSoundIndicatorType, const float InDefaultMaxVisibilityDistance = 0.000000f, UTexture* InDefaultIcon = nullptr, const FLinearColor InDefaultTint = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000), USoundBase* InDefaultSoundLinkedToIndicator = nullptr);

	UFUNCTION(BlueprintCallable, Category="Sound Indicator", meta=(CPP_Default_InSoundLocation))
	void ShowSoundIndicator(const FVector& InSoundLocation, const USoundBase* InSoundBeingPlayed = nullptr, const float InVolumeMultiplier = 1.000000f, APlayerState* InRequestingPlayerState = nullptr);

	UFUNCTION(BlueprintCallable, Category="Sound Indicator", meta=(CPP_Default_InSoundLocation))
	void ShowSoundIndicatorForDuration(const FVector& InSoundLocation, USoundBase* InSoundBeingPlayed = nullptr, const float InVolumeMultiplier = 1.000000f, const float InDuration = 1.000000f, APlayerState* InRequestingPlayerState = nullptr);

	UFUNCTION(BlueprintCallable, Category="Sound Indicator", meta=(CPP_Default_InSoundLocation))
	void StartSoundIndicatorLooping(const FVector& InSoundLocation, USoundBase* InSoundBeingPlayed = nullptr, const float InVolumeMultiplier = 1.000000f, APlayerState* InRequestingPlayerState = nullptr);

	UFUNCTION(BlueprintCallable, Category="Sound Indicator")
	void StartTargetedSoundIndicatorLooping(AActor* InTargetedActor = nullptr, USoundBase* InSoundBeingPlayed = nullptr, const float InVolumeMultiplier = 1.000000f, APlayerState* InRequestingPlayerState = nullptr);

	UFUNCTION(BlueprintCallable, Category="Sound Indicator")
	void StopSoundIndicatorLooping();

protected:
	UFUNCTION(BlueprintCallable, Category="Sound Indicator")
	void AddSoundIndicatorIconOverride(const FSoundIndicatorIconPicker& IconOverride);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Sound Indicator")
	UTexture* GetPreferredSoundIndicatorIcon() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Sound Indicator")
	EFortSoundIndicatorTypes GetPreferredSoundIndicatorType() const;

	UFUNCTION(BlueprintCallable, Category="Sound Indicator")
	void RemoveSoundIndicatorIconOverride(const FSoundIndicatorIconPicker& IconOverride);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	bool bStartLoopingOnBeginPlay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	float UpdateFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	EFortSoundIndicatorTypes DefaultSoundIndicatorType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	TArray<FSoundIndicatorTypePicker> SoundIndicatorTypeOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	TObjectPtr<UTexture> DefaultIconOverride;

	UPROPERTY(EditDefaultsOnly, Category="Sound Indicator")
	TArray<FSoundIndicatorIconPicker> IconOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	FLinearColor DefaultTintOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	TObjectPtr<USoundBase> DefaultSoundLinkedToIndicator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator", meta=(InlineEditConditionToggle="AttenuationSettingsLinkedToIndicator"))
	bool bUseAttenuationSettingsForMaxDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator", meta=(EditCondition="bUseAttenuationSettingsForMaxDistance"))
	TObjectPtr<USoundAttenuation> AttenuationSettingsLinkedToIndicator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Sound Indicator")
	float DefaultMaxVisibilityDistance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sound Indicator")
	TWeakObjectPtr<APlayerState> RequestingPlayerState;

private:
	UPROPERTY(Transient)
	TObjectPtr<USoundBase> SoundBeingPlayed;

};

