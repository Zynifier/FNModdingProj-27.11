// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/RespawnAndSpectateSelectWidgetBase.h"

int32 URespawnAndSpectateSelectWidgetBase::GetCurrentlyHoveredButtonIndex() const
{
	return int32();
}

UWidget* URespawnAndSpectateSelectWidgetBase::NativeGetDesiredFocusTarget() const
{
	return nullptr;
}

void URespawnAndSpectateSelectWidgetBase::OnAvailableOptionsChanged()
{
}

void URespawnAndSpectateSelectWidgetBase::OnLocalPlayerRespawned()
{
}

void URespawnAndSpectateSelectWidgetBase::OnRespawnBecameAvailable()
{
}

void URespawnAndSpectateSelectWidgetBase::OnSelectionConfirmed()
{
}

void URespawnAndSpectateSelectWidgetBase::OnSelectionHovered(URespawnAndSpectateSelectButtonWidgetBase* Widget)
{
}

void URespawnAndSpectateSelectWidgetBase::OnSelectionMade(URespawnAndSpectateSelectButtonWidgetBase* Widget)
{
}

void URespawnAndSpectateSelectWidgetBase::OnSelectionMadeMobile(URespawnAndSpectateSelectButtonWidgetBase* Widget)
{
}
