// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTimeOfDayManager.h"
#include "Net/UnrealNetwork.h"

void AFortTimeOfDayManager::AddLightAndFogPhaseSettingOverride(EFortDayPhase DayPhase, TSubclassOf<UFortDayPhaseInfoOverride> DayPhaseInfoOverride, float BlendInLength)
{
}

void AFortTimeOfDayManager::AddLightAndFogPhaseSettingOverrideMulticast_Implementation(EFortDayPhase DayPhase, TSubclassOf<UFortDayPhaseInfoOverride> DayPhaseInfoOverride, float BlendInLength)
{
}

void AFortTimeOfDayManager::ApplyInhibitorFogOverrides(float FogDensity, FLinearColor FogColor, float FogStartDistance)
{
}

void AFortTimeOfDayManager::BlendLightAndFogPhaseSettingOverride(float Alpha)
{
}

void AFortTimeOfDayManager::BreakExponentialHeightFogValues(FExponentialHeightFogValues HeightFogValues, float& FogDensity, float& FogHeightFalloff, float& FogMaxOpacity, float& StartDistance, float& DirectionalInscatteringExponent, float& DirectionalInscatteringStartDistance, FLinearColor& DirectionalInscatteringColor, FLinearColor& FogInscatteringColor, float& VolumetricFogScatteringDistribution, float& VolumetricFogExtinctionScale, float& VolumetricFogDistance)
{
}

void AFortTimeOfDayManager::DisableGlobalInhibitor(const FInhibitorData& InhibitorData)
{
}

void AFortTimeOfDayManager::DisableVolumeInhibitor(const FInhibitorData& InhibitorData)
{
}

void AFortTimeOfDayManager::EnableGlobalInhibitor(const FInhibitorData& InhibitorData)
{
}

void AFortTimeOfDayManager::EnableVolumeInhibitor(const FInhibitorData& InhibitorData)
{
}

void AFortTimeOfDayManager::EndBlendLightAndFogPhaseSettingOverride()
{
}

FLinearColor AFortTimeOfDayManager::GetDirectOverrideFogColor() const
{
	return FLinearColor();
}

float AFortTimeOfDayManager::GetDirectOverrideFogDensity() const
{
	return float();
}

float AFortTimeOfDayManager::GetDirectOverrideFogStartDistance() const
{
	return float();
}

AActor* AFortTimeOfDayManager::GetLastEnabledInhibitor() const
{
	return nullptr;
}

float AFortTimeOfDayManager::GetSafeZoneGamePhaseTimeRemaining() const
{
	return float();
}

float AFortTimeOfDayManager::GetStormStrength() const
{
	return float();
}

TArray<FThreatLocationInfo> AFortTimeOfDayManager::GetThreatClouds() const
{
	return TArray<FThreatLocationInfo>();
}

bool AFortTimeOfDayManager::HasInhibitors() const
{
	return false;
}

void AFortTimeOfDayManager::Inhibitor_SetDefaultSettings()
{
}

FExponentialHeightFogValues AFortTimeOfDayManager::MakeExponentialHeightFogValues(float FogDensity, float FogHeightFalloff, float FogMaxOpacity, float StartDistance, float DirectionalInscatteringExponent, float DirectionalInscatteringStartDistance, FLinearColor DirectionalInscatteringColor, FLinearColor FogInscatteringColor, float VolumetricFogScatteringDistribution, float VolumetricFogExtinctionScale, float VolumetricFogDistance)
{
	return FExponentialHeightFogValues();
}

void AFortTimeOfDayManager::OnRep_DirectOverrides()
{
}

void AFortTimeOfDayManager::OnRep_HeightFogEnabled()
{
}

void AFortTimeOfDayManager::OnRep_ServerTODIsVisible()
{
}

void AFortTimeOfDayManager::OnRep_TimeOfDay()
{
}

void AFortTimeOfDayManager::OnRep_TimeOfDayInit(const float OldTimeOfDay)
{
}

void AFortTimeOfDayManager::OnRep_TimeOfDaySpeed(const float OldTimeOfDaySpeed)
{
}

void AFortTimeOfDayManager::OnRep_WeatherComponent()
{
}

void AFortTimeOfDayManager::RemoveLightAndFogPhaseSettingOverride(EFortDayPhase DayPhase, float BlendOutLength)
{
}

void AFortTimeOfDayManager::RemoveLightAndFogPhaseSettingOverrideMulticast_Implementation(EFortDayPhase DayPhase, float BlendOutLength)
{
}

void AFortTimeOfDayManager::SetDirectionalLightColorMultiplier(float NewDirectionalLightColorMultiplier)
{
}

void AFortTimeOfDayManager::SetDirectionalLightComponentRotation(const FQuat& NewQuat, bool bInEditor, float DeltaTime)
{
}

void AFortTimeOfDayManager::SetFogDirectionalInscatteringMultiplier(float NewFogDirectionalInscatteringMultiplier)
{
}

void AFortTimeOfDayManager::SetRealTimeCaptureAndUpdateSkyCapture(bool bIsRealCaptureActive)
{
}

void AFortTimeOfDayManager::SetSpecificTimeOfDayInEditor(float NewTimeOfDayInEditor)
{
}

void AFortTimeOfDayManager::SetStormStrength(float NewStormStrength)
{
}

void AFortTimeOfDayManager::SetUseSpecificTimeOfDayEditing(bool bShouldUseSpecificTimeOfDay)
{
}

void AFortTimeOfDayManager::ToggleDebugForceStormEffects()
{
}

void AFortTimeOfDayManager::TryToUpdateFogForInhibitors()
{
}

void AFortTimeOfDayManager::UpdateInhibitorLastModificationDate(const FInhibitorData& InhibitorData)
{
}

void AFortTimeOfDayManager::UpdatePostProcessVolumes(EFortDayPhase InCurrentTimeOfDayEditing)
{
}

void AFortTimeOfDayManager::UpdatePostProcessVolumesV2(EFortTODMPostProcess::Type InCurrentTimeOfDayEditing)
{
}

void AFortTimeOfDayManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTimeOfDayManager, TimeOfDay);
	DOREPLIFETIME(AFortTimeOfDayManager, TimeOfDayReplicated);
	DOREPLIFETIME(AFortTimeOfDayManager, TimeOfDaySpeed);
	DOREPLIFETIME(AFortTimeOfDayManager, bTimeStarted);
	DOREPLIFETIME(AFortTimeOfDayManager, bHeightFogEnabled);
	DOREPLIFETIME(AFortTimeOfDayManager, DirectOverrides);
	DOREPLIFETIME(AFortTimeOfDayManager, bServerTODIsVisible);
	DOREPLIFETIME(AFortTimeOfDayManager, WeatherComponent);
}
