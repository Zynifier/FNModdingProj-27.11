// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/MusicEventSubsystem/MusicEventSubsystem.h"

UAudioComponent* UMusicEventSubsystem::AddEvent(USoundBase* Asset, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags)
{
	return nullptr;
}

void UMusicEventSubsystem::AddEventByComponent(UAudioComponent* Component, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags)
{
}

void UMusicEventSubsystem::AddEventBySynthComponent(USynthComponent* Component, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags)
{
}

void UMusicEventSubsystem::ChangeEventCategory(UAudioComponent* Component, FGameplayTag EventTag)
{
}

void UMusicEventSubsystem::ChangeEventCategorySynthComponent(USynthComponent* Component, FGameplayTag EventTag)
{
}

void UMusicEventSubsystem::ChangeEventGroup(UAudioComponent* Component, FName GroupName)
{
}

void UMusicEventSubsystem::ChangeEventGroupSynthComponent(USynthComponent* Component, FName GroupName)
{
}

UMusicEventInstance* UMusicEventSubsystem::GetEventInstance(UAudioComponent* Component)
{
	return nullptr;
}

bool UMusicEventSubsystem::IsEnabled() const
{
	return false;
}

void UMusicEventSubsystem::OnEventInstancePlaybackCompleted(UMusicEventInstance* Instance)
{
}

void UMusicEventSubsystem::OnLoadingScreenComplete()
{
}

void UMusicEventSubsystem::RemoveAllEvents(bool bPreviousWorldsOnly)
{
}

void UMusicEventSubsystem::RemoveEvent(UAudioComponent* Component)
{
}

void UMusicEventSubsystem::RemoveEventBySynthComponent(USynthComponent* Component)
{
}

void UMusicEventSubsystem::RemoveEventCategory(FGameplayTag EventTag)
{
}

UMusicEventSubsystemDebugWidget::UMusicEventSubsystemDebugWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
