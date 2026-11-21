// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortHUDTargetUnderReticleInterface.h"

float IFortHUDTargetUnderReticleInterface::GetHUDTargetDifficultyRating() const
{
	return float();
}

TArray<FText> IFortHUDTargetUnderReticleInterface::GetHUDTargetDisplayModifiers() const
{
	return TArray<FText>();
}

FText IFortHUDTargetUnderReticleInterface::GetHUDTargetDisplayName() const
{
	return FText();
}

float IFortHUDTargetUnderReticleInterface::GetHUDTargetHealthPercentage() const
{
	return float();
}

FText IFortHUDTargetUnderReticleInterface::GetHUDTargetUpgradeDisplayName() const
{
	return FText();
}
