// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTouchMoveStick.h"

bool UFortTouchMoveStick::AllowMobileImprovedAutorun()
{
	return false;
}

float UFortTouchMoveStick::GetHalfHeight() const
{
	return float();
}

FVector2D UFortTouchMoveStick::GetStickPosition() const
{
	return FVector2D();
}

void UFortTouchMoveStick::HandleTouchEnded_Implementation()
{
}

void UFortTouchMoveStick::HandleTouchStarted_Implementation()
{
}

bool UFortTouchMoveStick::IsLocked() const
{
	return false;
}

bool UFortTouchMoveStick::IsTouched() const
{
	return false;
}

void UFortTouchMoveStick::SetMovementLockStatus_Implementation(bool MovementIsLocked)
{
}

void UFortTouchMoveStick::SetStickPosition(FVector2D NewPosition)
{
}
