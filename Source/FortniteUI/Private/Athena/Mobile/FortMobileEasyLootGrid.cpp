// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Mobile/FortMobileEasyLootGrid.h"

void UFortMobileEasyLootGrid::HandleAutoPickUpPressed()
{
}

void UFortMobileEasyLootGrid::HandleCollapsedListPressed()
{
}

bool UFortMobileEasyLootGrid::IsEasyLootGridEnabled(const AFortPlayerController* FortPC)
{
	return false;
}

bool UFortMobileEasyLootGrid::IsEasyLootGridEnabledForActor(const AFortPlayerController* FortPC, const AActor* PickUpItem)
{
	return false;
}

void UFortMobileEasyLootGrid::UpdateListPostAnimation()
{
}
