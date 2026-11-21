// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/UI/FortMiniMapComponent_Discoverable.h"
#include "Net/UnrealNetwork.h"

void UFortMiniMapComponent_Discoverable::DisableDefaultVisibilityCanChangeAtRuntime()
{
}

EMiniMapComponentDiscoverableVisibility UFortMiniMapComponent_Discoverable::GetDefaultVisibility()
{
	return EMiniMapComponentDiscoverableVisibility();
}

bool UFortMiniMapComponent_Discoverable::GetDefaultVisibilityCanChangeAtRuntime() const
{
	return false;
}

EMiniMapComponentDiscoverableVisibility UFortMiniMapComponent_Discoverable::GetPlayersSetVisibility(const AFortPlayerController* PlayerController) const
{
	return EMiniMapComponentDiscoverableVisibility();
}

EMiniMapComponentDiscoverableVisibility UFortMiniMapComponent_Discoverable::GetVisibilityForPlayer(const AFortPlayerController* PlayerController) const
{
	return EMiniMapComponentDiscoverableVisibility();
}

void UFortMiniMapComponent_Discoverable::OnRep_NotDiscoveredIcon()
{
}

void UFortMiniMapComponent_Discoverable::OnRep_NotDiscoveredIconScale()
{
}

void UFortMiniMapComponent_Discoverable::SetDefaultVisibility(const EMiniMapComponentDiscoverableVisibility InVisibility, const bool bClearAllPlayerVisibilityOverrides)
{
}

void UFortMiniMapComponent_Discoverable::SetMiniMapDiscoveredIcon(UObject* MiniMapIcon)
{
}

void UFortMiniMapComponent_Discoverable::SetMiniMapDiscoveredIconScale(const FVector2D& IconScale)
{
}

void UFortMiniMapComponent_Discoverable::SetMiniMapNotDiscoveredIconScale(const FVector2D& IconScale)
{
}

void UFortMiniMapComponent_Discoverable::SetVisibilityForPlayer(AFortPlayerController* PlayerController, EMiniMapComponentDiscoverableVisibility Visibility)
{
}

void UFortMiniMapComponent_Discoverable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMiniMapComponent_Discoverable, DefaultVisibility);
	DOREPLIFETIME(UFortMiniMapComponent_Discoverable, NotDiscoveredIconScale);
	DOREPLIFETIME(UFortMiniMapComponent_Discoverable, NotDiscoveredIcon);
}
