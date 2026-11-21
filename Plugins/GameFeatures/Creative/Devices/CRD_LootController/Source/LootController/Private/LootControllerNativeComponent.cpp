// Copyright Epic Games, Inc. All Rights Reserved.

#include "LootControllerNativeComponent.h"

void ULootControllerNativeComponent::AddToArray(TArray<FBuildingContainersFoundEntry>& InOutBuildingContainersFoundArray, const int32 InBuildingContainerFoundIndex, const FBuildingContainersArrayEntry& InBuildingContainerToAdd)
{
}

void ULootControllerNativeComponent::AsyncGetActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass)
{
}

bool ULootControllerNativeComponent::IsRemoveLootEnabled() const
{
	return false;
}

bool ULootControllerNativeComponent::IsThrottleEnabled() const
{
	return false;
}

void ULootControllerNativeComponent::PrintDebugString(const FString& DebugString, const bool LogWarning)
{
}
