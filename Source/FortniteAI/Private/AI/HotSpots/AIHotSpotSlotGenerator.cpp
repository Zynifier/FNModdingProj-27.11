// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/HotSpots/AIHotSpotSlotGenerator.h"

UAIHotSpotSlot* UAIHotSpotSlotGenerator::AddSlot(const FVector& RelativeLocation, const FRotator& RelativeRotation, TSubclassOf<UAIHotSpotSlot> CustomSlotClass, bool bEnabled) const
{
	return nullptr;
}

void UAIHotSpotSlotGenerator::GenerateSlots_Implementation()
{
}

AAIHotSpot* UAIHotSpotSlotGenerator::GetHotSpot() const
{
	return nullptr;
}
