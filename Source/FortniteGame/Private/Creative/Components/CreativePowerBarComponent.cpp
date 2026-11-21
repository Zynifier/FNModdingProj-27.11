// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativePowerBarComponent.h"
#include "Net/UnrealNetwork.h"

float UCreativePowerBarComponent::GetPowerPercentage() const
{
	return float();
}

void UCreativePowerBarComponent::InitializePowerBar(const bool bLoops, const float ChangeRate, const UCurveFloat* NewPowerCurve)
{
}

bool UCreativePowerBarComponent::IsInterpolationPaused() const
{
	return false;
}

void UCreativePowerBarComponent::ResumeInterpolation()
{
}

void UCreativePowerBarComponent::ServerSetStopTime_Implementation(const float ServerStopTime)
{
}
bool UCreativePowerBarComponent::ServerSetStopTime_Validate(const float ServerStopTime)
{
	return true;
}

void UCreativePowerBarComponent::SetLooping(const bool bLooping)
{
}

void UCreativePowerBarComponent::SetPowerCurve(const UCurveFloat* NewPowerCurve)
{
}

void UCreativePowerBarComponent::StopInterpolation()
{
}

void UCreativePowerBarComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativePowerBarComponent, StartTime);
	DOREPLIFETIME(UCreativePowerBarComponent, bLoop);
	DOREPLIFETIME(UCreativePowerBarComponent, PowerCurve);
}
