// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTouchControlRegion.h"

float UFortTouchControlRegion::GetTouchStickRange() const
{
	return float();
}

void UFortTouchControlRegion::MovePlayerRegionTick_Implementation(const FGeometry& InGeometry, const float DeltaTime)
{
}

void UFortTouchControlRegion::OnAdditionalTouchEnded_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnAdditionalTouchLost_Implementation(int32 PointerIndex)
{
}

void UFortTouchControlRegion::OnAdditionalTouchStarted_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnBuildModeChanged(bool bBuildModeEnabled)
{
}

void UFortTouchControlRegion::OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget)
{
}

void UFortTouchControlRegion::OnMovePlayerRegionTouchEnded_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnMovePlayerRegionTouchLost_Implementation(int32 PointerIndex)
{
}

void UFortTouchControlRegion::OnMovePlayerRegionTouchMoved_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnMovePlayerRegionTouchStarted_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnRotatePlayerRegionTouchEnded_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::OnRotatePlayerRegionTouchLost_Implementation(int32 PointerIndex)
{
}

void UFortTouchControlRegion::OnRotatePlayerRegionTouchMoved_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent, const FVector2D& MoveDelta)
{
}

void UFortTouchControlRegion::OnRotatePlayerRegionTouchStarted_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::ResetTouchState()
{
}

void UFortTouchControlRegion::RotatePlayerRegionTick_Implementation(const FGeometry& InGeometry, const float DeltaTime)
{
}

void UFortTouchControlRegion::SetFeedbackPosition_Implementation(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent)
{
}

void UFortTouchControlRegion::SetLockOnStickPosition(FVector2D LocalPos)
{
}

void UFortTouchControlRegion::SetMoveStickPos(FVector2D NewMoveStickPos)
{
}

void UFortTouchControlRegion::UpdateLockOnStickOrigin(FVector2D LocalPos, bool IsTouchStartEvent)
{
}

void UFortTouchControlRegion::UpdateLockOnStickPosition(FVector2D LocalPos)
{
}
