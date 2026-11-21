// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortThreatVisualsManager.h"
#include "Net/UnrealNetwork.h"

void AFortThreatVisualsManager::BeginThreatVisualsPrecursor_Implementation(AActor* SourceActor, FVector ThreatLocation)
{
}

bool AFortThreatVisualsManager::GetCloudsAreHidden() const
{
	return false;
}

AThreatCloud* AFortThreatVisualsManager::GetThreatCloud(const FThreatLocationInfo& ThreatLocInfo) const
{
	return nullptr;
}

const TArray<FThreatLocationInfo> AFortThreatVisualsManager::GetThreatClouds() const
{
	return TArray<FThreatLocationInfo>();
}

void AFortThreatVisualsManager::OnRep_GoalActorLocations()
{
}

void AFortThreatVisualsManager::OnRep_HideClouds()
{
}

void AFortThreatVisualsManager::OnRep_StormWinds()
{
}

void AFortThreatVisualsManager::OnRep_ThreatLocations()
{
}

void AFortThreatVisualsManager::ResetMinimumCloudAltitude()
{
}

void AFortThreatVisualsManager::SetCloudsAreHidden(bool bHide)
{
}

void AFortThreatVisualsManager::SetMinimumCloudAltitude(float NewMinimumAltitude)
{
}

bool AFortThreatVisualsManager::StormsExist() const
{
	return false;
}

void AFortThreatVisualsManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortThreatVisualsManager, bHideClouds);
	DOREPLIFETIME(AFortThreatVisualsManager, ThreatLocations);
	DOREPLIFETIME(AFortThreatVisualsManager, StormWindArray);
	DOREPLIFETIME(AFortThreatVisualsManager, GoalActorLocations);
}
