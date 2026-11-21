// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/AIHotSpotSlot.h"

void UAIHotSpotSlot::ClearSlot()
{
}

AAIHotSpot* UAIHotSpotSlot::GetHotSpot() const
{
	return nullptr;
}

FBox UAIHotSpotSlot::GetSlotBounds() const
{
	return FBox();
}

float UAIHotSpotSlot::GetSlotHeight() const
{
	return float();
}

int32 UAIHotSpotSlot::GetSlotIndex() const
{
	return int32();
}

FVector UAIHotSpotSlot::GetSlotLocation() const
{
	return FVector();
}

AAIController* UAIHotSpotSlot::GetSlotOwner() const
{
	return nullptr;
}

float UAIHotSpotSlot::GetSlotRadius() const
{
	return float();
}

FRotator UAIHotSpotSlot::GetSlotRotation() const
{
	return FRotator();
}

EAIHotSpotSlot UAIHotSpotSlot::GetSlotState() const
{
	return EAIHotSpotSlot();
}

int32 UAIHotSpotSlot::GetSlotUserId() const
{
	return int32();
}

bool UAIHotSpotSlot::HasUserId() const
{
	return false;
}

bool UAIHotSpotSlot::IsAIAllowed_Implementation(const AAIController* AI) const
{
	return false;
}

bool UAIHotSpotSlot::IsEnabled() const
{
	return false;
}

void UAIHotSpotSlot::SetSlotEnabled(bool bNewEnabled)
{
}

void UAIHotSpotSlot::SetSlotOwnerAndState(AAIController* NewOwner, EAIHotSpotSlot NewState)
{
}

void UAIHotSpotSlot::SetSlotState(EAIHotSpotSlot NewState)
{
}
