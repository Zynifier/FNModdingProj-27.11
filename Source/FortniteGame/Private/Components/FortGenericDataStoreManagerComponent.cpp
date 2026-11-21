// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGenericDataStoreManagerComponent.h"

UObject* UFortGenericDataStoreManagerComponent::AddNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType)
{
	return nullptr;
}

UObject* UFortGenericDataStoreManagerComponent::GetNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType) const
{
	return nullptr;
}

bool UFortGenericDataStoreManagerComponent::RemoveNamedStoreByType(const FName& StoreName, const TSubclassOf<UObject>& ClassType)
{
	return false;
}
