// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSpectatedPlayerSwitcher.h"

UFortSpectatedPlayerSwitcher::UFortSpectatedPlayerSwitcher(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortSpectatedPlayerSwitcher::ShouldBeVisible() const
{
	return false;
}
