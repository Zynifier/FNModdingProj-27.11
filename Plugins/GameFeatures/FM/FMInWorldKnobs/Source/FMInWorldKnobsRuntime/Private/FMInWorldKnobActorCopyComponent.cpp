// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMInWorldKnobActorCopyComponent.h"

void UFMInWorldKnobActorCopyComponent::ClearCopiedInWorldKnob()
{
}

FString UFMInWorldKnobActorCopyComponent::GetCurrentKnobValueBP() const
{
	return FString();
}

void UFMInWorldKnobActorCopyComponent::OnInWorldKnobFloatProviderConnectionChanged(bool bConnected, UObject* ModulatorObject)
{
}

void UFMInWorldKnobActorCopyComponent::OnInWorldKnobModulatedPropertyValueChanged(const FString& Value, UObject* ModulatorObject)
{
}

void UFMInWorldKnobActorCopyComponent::OnInWorldKnobRuntimeValueChanged(const FString& Value, UPlaylistUserOptionBase* Option)
{
}

void UFMInWorldKnobActorCopyComponent::OnInWorldKnobSerializedValueChanged(const FString& Value, UPlaylistUserOptionBase* Option, APlayerController* PlayerController)
{
}

void UFMInWorldKnobActorCopyComponent::SetCopiedInWorldKnob(UObject* InWorldKnobObject)
{
}
