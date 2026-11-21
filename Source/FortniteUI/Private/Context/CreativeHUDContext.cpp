// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/CreativeHUDContext.h"

void UCreativeHUDLContext::ForwardOnCreativeGhostChanged(bool bIsGhostEnabled)
{
}

void UCreativeHUDLContext::ForwardOnCreativeHeatmapTogged(bool bIsHeatmapToggled)
{
}

void UCreativeHUDLContext::ForwardOnCreativeInvulnerableChanged(bool bIsInvulnerable)
{
}

void UCreativeHUDLContext::ForwardOnCreativeQuickbarActiveChanged(bool bIsActive)
{
}

void UCreativeHUDLContext::ForwardOnCreativeQuickbarEnabledChanged(bool bIsEnabled)
{
}

void UCreativeHUDLContext::ForwardOnCreativeQuickbarEquippedChanged(bool bIsEquipped)
{
}

void UCreativeHUDLContext::ForwardOnCreativeQuickMenuDisplayedChanged(bool bIsDisplayed)
{
}

void UCreativeHUDLContext::ForwardOnDropToFloorChanged(bool bDropToFloorOn)
{
}

void UCreativeHUDLContext::ForwardOnLOSChanged(EHitTraceRule HitTraceRule)
{
}

void UCreativeHUDLContext::ForwardOnMoveToolRotationModified(FQuat currentRotationOffset)
{
}

void UCreativeHUDLContext::ForwardOnMoveToolScaleModified(FVector currentVector)
{
}

void UCreativeHUDLContext::ForwardOnPrecisionChanged(bool bPrecisionOn, uint8 GridSnapIndex)
{
}

void UCreativeHUDLContext::ForwardOnPropLockedInPlacedChanged(bool bLockedInPlace)
{
}

void UCreativeHUDLContext::ForwardOnRotationAxisChanged(uint8 AxisIndex)
{
}

void UCreativeHUDLContext::ForwardOnScaleAxisChanged(EScaleAxis Axis)
{
}

UDataTable* UCreativeHUDLContext::GetCreativeItemListSourceFromPlaylist() const
{
	return nullptr;
}

EHitTraceRule UCreativeHUDLContext::GetCurrentHitTraceRule() const
{
	return EHitTraceRule();
}

bool UCreativeHUDLContext::GetDropToFloorEnabled() const
{
	return false;
}

AFortPlayerPawn* UCreativeHUDLContext::GetOwningPlayerPawn() const
{
	return nullptr;
}

AFortPlayerState* UCreativeHUDLContext::GetOwningPlayerState() const
{
	return nullptr;
}

void UCreativeHUDLContext::GetPrecisionLevel(bool& SnappingEnabled, uint8& GridSnappingIndex) const
{
}

FRotator UCreativeHUDLContext::GetRotationAxis() const
{
	return FRotator();
}

EScaleAxis UCreativeHUDLContext::GetScaleAxis() const
{
	return EScaleAxis();
}

void UCreativeHUDLContext::HandleOnCreativeModeEnabledChanged(bool bIsEnabled)
{
}

bool UCreativeHUDLContext::IsPropLockedInPlace() const
{
	return false;
}

void UCreativeHUDLContext::OnCreativeQuickbarComponentLoaded()
{
}

void UCreativeHUDLContext::OnPlayerControllerSet()
{
}

void UCreativeHUDLContext::OnPlayerPawnSet()
{
}

void UCreativeHUDLContext::OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}
