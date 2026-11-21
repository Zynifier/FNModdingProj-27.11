// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeTags.h"

FText UFortCreativeTagsManager::GetCreativeTagTextForID(const FName& TagID)
{
	return FText();
}

TArray<FName> UFortCreativeTagsManager::GetUserVisibleTagIDsForItem(const UFortItemDefinition* ItemDefinition)
{
	return TArray<FName>();
}

TArray<FText> UFortCreativeTagsManager::GetUserVisibleTagsForItem(const UFortItemDefinition* ItemDefinition)
{
	return TArray<FText>();
}
