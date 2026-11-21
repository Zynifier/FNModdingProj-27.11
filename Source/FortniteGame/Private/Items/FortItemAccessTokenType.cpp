// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortItemAccessTokenType.h"

UFortItemDefinition* UFortItemAccessTokenType::GetAccessItem() const
{
	return nullptr;
}

const FText& UFortItemAccessTokenType::GetUnlockDescription() const
{
	static FText Dummy;
	return Dummy;
}
