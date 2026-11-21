// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortSoundIndicatorComponent.h"

void UFortSoundIndicatorComponent::AddSoundIndicatorIconOverride(const FSoundIndicatorIconPicker& IconOverride)
{
}

UTexture* UFortSoundIndicatorComponent::GetPreferredSoundIndicatorIcon_Implementation() const
{
	return nullptr;
}

EFortSoundIndicatorTypes UFortSoundIndicatorComponent::GetPreferredSoundIndicatorType_Implementation() const
{
	return EFortSoundIndicatorTypes();
}

void UFortSoundIndicatorComponent::InitializeDefaultValues(const float InUpdateFrequency, const bool bInStartLoopingOnBeginPlay, const EFortSoundIndicatorTypes InDefaultSoundIndicatorType, const float InDefaultMaxVisibilityDistance, UTexture* InDefaultIcon, const FLinearColor InDefaultTint, USoundBase* InDefaultSoundLinkedToIndicator)
{
}

void UFortSoundIndicatorComponent::RemoveSoundIndicatorIconOverride(const FSoundIndicatorIconPicker& IconOverride)
{
}

void UFortSoundIndicatorComponent::ShowSoundIndicator(const FVector& InSoundLocation, const USoundBase* InSoundBeingPlayed, const float InVolumeMultiplier, APlayerState* InRequestingPlayerState)
{
}

void UFortSoundIndicatorComponent::ShowSoundIndicatorForDuration(const FVector& InSoundLocation, USoundBase* InSoundBeingPlayed, const float InVolumeMultiplier, const float InDuration, APlayerState* InRequestingPlayerState)
{
}

void UFortSoundIndicatorComponent::StartSoundIndicatorLooping(const FVector& InSoundLocation, USoundBase* InSoundBeingPlayed, const float InVolumeMultiplier, APlayerState* InRequestingPlayerState)
{
}

void UFortSoundIndicatorComponent::StartTargetedSoundIndicatorLooping(AActor* InTargetedActor, USoundBase* InSoundBeingPlayed, const float InVolumeMultiplier, APlayerState* InRequestingPlayerState)
{
}

void UFortSoundIndicatorComponent::StopSoundIndicatorLooping()
{
}
