// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortVolumeTimeOfDayComponent.h"
#include "Net/UnrealNetwork.h"

void UFortVolumeTimeOfDayComponent::ApplyInhibitorFogOverrides(float FogDensity, FLinearColor FogColor)
{
}

void UFortVolumeTimeOfDayComponent::ApplyTimeOfDayComponentSettings(bool bShouldSwitch)
{
}

void UFortVolumeTimeOfDayComponent::CreateLocalTimeOfDayManager()
{
}

TScriptInterface<IFortTimeOfDayManagerInterface> UFortVolumeTimeOfDayComponent::GetTimeOfDayManager(AActor* TimeOfDayComponentOwner)
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

TScriptInterface<IFortTimeOfDayManagerInterface> UFortVolumeTimeOfDayComponent::GetVolumeTimeOfDayManager() const
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

void UFortVolumeTimeOfDayComponent::HandleViewTargetChanged()
{
}

void UFortVolumeTimeOfDayComponent::MutatorSettingsChanged(const FPropertyOverrideData& OverrideData)
{
}

void UFortVolumeTimeOfDayComponent::OnRep_DaySequenceModifierData()
{
}

void UFortVolumeTimeOfDayComponent::OnRep_TimeOfDayConfig()
{
}

void UFortVolumeTimeOfDayComponent::OnRep_TimeOfDayManager()
{
}

void UFortVolumeTimeOfDayComponent::SpectatorFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer)
{
}

void UFortVolumeTimeOfDayComponent::SwitchToGlobalTODManager()
{
}

void UFortVolumeTimeOfDayComponent::SwitchToLocalTODManager()
{
}

TScriptInterface<IFortTimeOfDayManagerInterface> UFortVolumeTimeOfDayComponent::TryGetTimeOfDayManager(AActor* TimeOfDayComponentOwner)
{
	return TScriptInterface<IFortTimeOfDayManagerInterface>();
}

void UFortVolumeTimeOfDayComponent::UpdateLocalTracking()
{
}

void UFortVolumeTimeOfDayComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVolumeTimeOfDayComponent, TimeOfDayManager);
	DOREPLIFETIME(UFortVolumeTimeOfDayComponent, TimeOfDayConfig);
	DOREPLIFETIME(UFortVolumeTimeOfDayComponent, DaySequenceModifierData);
}
