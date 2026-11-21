// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTouchLookStick.h"

bool UFortTouchLookStick::GetShowAllTimeTime() const
{
	return false;
}

float UFortTouchLookStick::GetSize() const
{
	return float();
}

bool UFortTouchLookStick::IsFireButtonUnderTouch_Implementation(FVector2D TouchPosition) const
{
	return false;
}

void UFortTouchLookStick::OnFireFromIndexStopped(const int32 StopFireIndex)
{
}

void UFortTouchLookStick::SetFiringState_Implementation(bool IsFiring)
{
}

void UFortTouchLookStick::SetSize(float NewSize)
{
}

void UFortTouchLookStick::SetTouchStickPositionAbsolute(FVector2D TouchPosition)
{
}

void UFortTouchLookStick::SetTouchStickPositionLocal(FVector2D TouchPosition)
{
}
