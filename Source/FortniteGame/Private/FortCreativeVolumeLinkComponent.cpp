// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeVolumeLinkComponent.h"
#include "Net/UnrealNetwork.h"

AFortVolume* UFortCreativeVolumeLinkComponent::GetLinkedVolume()
{
	return nullptr;
}

void UFortCreativeVolumeLinkComponent::OnLinkedVolumeSettingsChanged(const FPropertyOverrideData& OverrideData)
{
}

void UFortCreativeVolumeLinkComponent::OnRep_LinkedVolume()
{
}

void UFortCreativeVolumeLinkComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeVolumeLinkComponent, LinkedVolume);
}
