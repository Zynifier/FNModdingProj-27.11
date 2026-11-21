// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/DynamicBackgrounds/DynamicBackgroundDirector.h"

EBackgroundSource ADynamicBackgroundDirector::GetBackgroundSource() const
{
	return EBackgroundSource();
}

bool ADynamicBackgroundDirector::GetHasDonutShopSequenceBeenSeen()
{
	return false;
}

TSoftObjectPtr<UTexture> ADynamicBackgroundDirector::GetLoadedTexture()
{
	return TSoftObjectPtr<UTexture>();
}

void ADynamicBackgroundDirector::MarkDonutSequenceSeen()
{
}

void ADynamicBackgroundDirector::OnDonutSequenceInitiated()
{
}

void ADynamicBackgroundDirector::RequestDonutUIPlayAnim()
{
}

void ADynamicBackgroundDirector::ResetDonutShopSeen()
{
}

void ADynamicBackgroundDirector::SetIsInDonutSequence(bool bIsInSequence)
{
}

void ADynamicBackgroundDirector::TryForceSetupDonutStore()
{
}
