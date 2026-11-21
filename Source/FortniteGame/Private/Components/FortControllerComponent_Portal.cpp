// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_Portal.h"

bool UFortControllerComponent_Portal::CanCancelPortalMatchmaking() const
{
	return false;
}

bool UFortControllerComponent_Portal::CanInitiateMatchmakingToPortalOrigin() const
{
	return false;
}

bool UFortControllerComponent_Portal::CanInitiatePortalMatchmkaing(UFortPortalComponent* PortalComponent) const
{
	return false;
}

bool UFortControllerComponent_Portal::CanInitiatePrivateMatchmaking()
{
	return false;
}

void UFortControllerComponent_Portal::ClientInitiateMatchmakingToPortalOrigin_Implementation()
{
}

void UFortControllerComponent_Portal::InitiateMatchmakingToPortalOrigin()
{
}

bool UFortControllerComponent_Portal::IsGameDetailPreviewScreenEnabled()
{
	return false;
}

bool UFortControllerComponent_Portal::IsOnPortalHudEnabled()
{
	return false;
}

void UFortControllerComponent_Portal::OnPortalMatchmakingComplete(const bool bSuccess)
{
}

void UFortControllerComponent_Portal::ServerSetPortalLinkCode_Implementation(UFortPortalComponent* PortalComponent, const FOnlineLinkId& LinkId)
{
}
bool UFortControllerComponent_Portal::ServerSetPortalLinkCode_Validate(UFortPortalComponent* PortalComponent, const FOnlineLinkId& LinkId)
{
	return true;
}
