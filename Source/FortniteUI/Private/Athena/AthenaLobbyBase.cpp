// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaLobbyBase.h"

bool UAthenaLobbyBase::ExitDiscover()
{
	return false;
}

TSoftClassPtr<UUserWidget> UAthenaLobbyBase::GetMotdTeaserClass()
{
	return TSoftClassPtr<UUserWidget>();
}

bool UAthenaLobbyBase::GetSurvivorTierWidgetAllowed() const
{
	return false;
}

void UAthenaLobbyBase::HandleActiveWidgetChanged(UWidget* NewActiveWidget, int32 WidgetIndex)
{
}

void UAthenaLobbyBase::HandleHideLobbySeasonResources(bool bShouldHide)
{
}

void UAthenaLobbyBase::HandlePickerOpenRequest(EFortPickerMode Mode, int32 InitialOption, bool bIgnoreFirstAccept)
{
}

void UAthenaLobbyBase::HandlePlayerTouchInput(ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex, bool& bOutHandled)
{
}

void UAthenaLobbyBase::HandleToggleFullscreenMap(bool bVisible)
{
}

bool UAthenaLobbyBase::HasUnseenQuests() const
{
	return false;
}

bool UAthenaLobbyBase::NavigateToDiscover()
{
	return false;
}

void UAthenaLobbyBase::SetHomeBarShownOnActivated()
{
}

bool UAthenaLobbyBase::ShouldShowHomeBarOnActivated()
{
	return false;
}
