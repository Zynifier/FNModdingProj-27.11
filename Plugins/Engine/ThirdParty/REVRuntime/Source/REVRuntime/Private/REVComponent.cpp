// Copyright Epic Games, Inc. All Rights Reserved.

#include "REVComponent.h"

UREVComponent::UREVComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UREVComponent::SetRevModel(UREVModel* InModel)
{
}

void UREVComponent::SetSettings(URevSettings* InSettings)
{
}

void UREVComponent::UpdateParameters(const float InPitch, const float InRPM, const float InThrottle, const float InVelocity, const int32 InGear, const bool bInEnableShifting)
{
}

void UREVComponent::UpdateSimSettings()
{
}

void UREVComponent::Update(FAudioMotorSimInputContext& Input, FAudioMotorSimRuntimeContext& RuntimeInfo)
{
}

void UREVComponent::StartOutput()
{
}

void UREVComponent::StopOutput()
{
}
