// Copyright Epic Games, Inc. All Rights Reserved.

#include "StormCallerComponent.h"

void UStormCallerComponent::ApplyPOINamesToDataRegistry(const UPlaylistUserOptions* UserOptions, const FGameplayTag& GameplayTagForPOI, const FText& MapCenterText, const FText& RandomText, const FText& BeaconText)
{
}

void UStormCallerComponent::ApplySavedPoiOptions(const TArray<FString>& PoiSavedOptionKeys, const TArray<FText>& PoiSavedOptionName, UFortActorOptionsComponent* ToyOptionsComponent)
{
}

AFortPoiVolume* UStormCallerComponent::GetPoiVolumeFromOptionIndex(int32 OptionIndex)
{
	return nullptr;
}

AFortPoiVolume* UStormCallerComponent::GetRandomPoiVolume()
{
	return nullptr;
}

const TArray<FVector4>& UStormCallerComponent::GetSafeZoneLocationBlockList() const
{
	static TArray<FVector4> Dummy;
	return Dummy;
}

void UStormCallerComponent::SpawnInitialSafeZone()
{
}

void UStormCallerComponent::UpdatePoiSavedOptions(TArray<FString>& InOutPoiSavedOptionKeys, TArray<FText>& InOutPoiSavedOptionNames, const UPlaylistUserOptions* UserOptions, const FGameplayTag& GameplayTagForPOI)
{
}
