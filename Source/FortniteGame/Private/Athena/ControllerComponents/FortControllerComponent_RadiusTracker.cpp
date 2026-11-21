// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_RadiusTracker.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_RadiusTracker::OnRep_TrackingDisplayInfos()
{
}

void UFortControllerComponent_RadiusTracker::UpdateTrackingDisplayIndicators()
{
}

void UFortControllerComponent_RadiusTracker::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_RadiusTracker, TrackingDisplayInfos);
}
