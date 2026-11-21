// Copyright Epic Games, Inc. All Rights Reserved.

#include "CosmeticLoadoutSlotTemplate.h"

FPrimaryAssetId UCosmeticLoadoutSlotTemplate::GetDefaultCosmeticItemId() const
{
	return FPrimaryAssetId();
}

const FGameplayTagContainer& UCosmeticLoadoutSlotTemplate::GetMetaTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

const FCosmeticLoadoutSlotRequirements& UCosmeticLoadoutSlotTemplate::GetRequirements() const
{
	static FCosmeticLoadoutSlotRequirements Dummy;
	return Dummy;
}

FGameplayTag UCosmeticLoadoutSlotTemplate::GetSlotTag() const
{
	return FGameplayTag();
}
