// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/LTMWidgetBase.h"

AFortPlayerStateAthena* ULTMWidgetBase::GetViewingPlayerState() const
{
	return nullptr;
}

uint8 ULTMWidgetBase::GetViewingTeam() const
{
	return uint8();
}

void ULTMWidgetBase::OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget)
{
}

void ULTMWidgetBase::SetPlayerPortrait(AFortPlayerStateAthena* Player, UFortLazyImage* PortraitImage) const
{
}
