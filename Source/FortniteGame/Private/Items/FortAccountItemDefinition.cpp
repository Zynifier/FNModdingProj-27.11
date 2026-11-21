// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortAccountItemDefinition.h"

FPrimaryAssetId UFortAccountItemDefinition::GetPrimaryAssetId() const
{
	if (CachedPrimaryAssetId.IsValid())
	{
		return CachedPrimaryAssetId;
	}

	return Super::GetPrimaryAssetId();
}
