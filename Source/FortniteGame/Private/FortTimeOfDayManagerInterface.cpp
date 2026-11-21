// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTimeOfDayManagerInterface.h"

void IFortTimeOfDayManagerInterface::FastForwardToTime(float FastForwardTimeOfDay, float FastForwardSpeed, float RestoreSpeed)
{
}

void IFortTimeOfDayManagerInterface::FastForwardToTime_ByDuration(float FastForwardTimeOfDay, float FastForwardDuration, float RestoreSpeed)
{
}

EFortDayPhase IFortTimeOfDayManagerInterface::GetCurrentDayPhase() const
{
	return EFortDayPhase();
}

float IFortTimeOfDayManagerInterface::GetDefaultTimeOfDaySpeed() const
{
	return float();
}

UDirectionalLightComponent* IFortTimeOfDayManagerInterface::GetDirectionalLightComponent() const
{
	return nullptr;
}

UExponentialHeightFogComponent* IFortTimeOfDayManagerInterface::GetHeightFogComponent() const
{
	return nullptr;
}

EFortDayPhase IFortTimeOfDayManagerInterface::GetPreviousDayPhase() const
{
	return EFortDayPhase();
}

float IFortTimeOfDayManagerInterface::GetTimeOfDay() const
{
	return float();
}

float IFortTimeOfDayManagerInterface::GetTimeOfDaySpeed() const
{
	return float();
}

float IFortTimeOfDayManagerInterface::GetTimePerCycle() const
{
	return float();
}

UFortTimeOfDayWeatherComponent* IFortTimeOfDayManagerInterface::GetWeatherComponent() const
{
	return nullptr;
}

bool IFortTimeOfDayManagerInterface::IsVisible() const
{
	return false;
}

void IFortTimeOfDayManagerInterface::RegisterForDayPhaseChangedEvent(FDayNightPhaseChangeBlueprintEventSignature DelegateSignature, const bool bMakeInitialCall)
{
}

void IFortTimeOfDayManagerInterface::RegisterForWeatherComponentSetEvent(FOnWeatherComponentSetBlueprintEventSignature DelegateSignature)
{
}

bool IFortTimeOfDayManagerInterface::SetTimeOfDay(const float InTimeOfDay)
{
	return false;
}

void IFortTimeOfDayManagerInterface::SetTimeOfDayManagerVisibility(const bool bVisible)
{
}

bool IFortTimeOfDayManagerInterface::SetTimeOfDaySpeed(const float InTimeOfDaySpeed)
{
	return false;
}

bool IFortTimeOfDayManagerInterface::SetTimeOfDaySpeedFactor(const float NewTimeOfDaySpeedFactor, const bool bForceSet)
{
	return false;
}

void IFortTimeOfDayManagerInterface::UnregisterForDayPhaseChangedEvent(UObject* EventReceiver)
{
}

void IFortTimeOfDayManagerInterface::UnregisterForWeatherComponentSetEvent(FOnWeatherComponentSetBlueprintEventSignature DelegateSignature)
{
}
