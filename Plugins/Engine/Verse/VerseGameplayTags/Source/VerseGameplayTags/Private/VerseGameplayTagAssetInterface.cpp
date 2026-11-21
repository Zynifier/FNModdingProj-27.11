// Copyright Epic Games, Inc. All Rights Reserved.

#include "VerseGameplayTagAssetInterface.h"

void IVerseGameplayTagAssetInterface::GetOwnedGameplayTags(FVerseGameplayTagContainer& TagContainer) const
{
}

bool IVerseGameplayTagAssetInterface::HasAllMatchingGameplayTags(const FVerseGameplayTagContainer& TagContainer) const
{
	return false;
}

bool IVerseGameplayTagAssetInterface::HasAnyMatchingGameplayTags(const FVerseGameplayTagContainer& TagContainer) const
{
	return false;
}

bool IVerseGameplayTagAssetInterface::HasMatchingGameplayTag(FVerseGameplayTag TagToCheck) const
{
	return false;
}
