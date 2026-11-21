// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMInWorldKnobActorBase.h"

void AFMInWorldKnobActorBase::CopyAttributesFromOtherKnob(AFMInWorldKnobActorBase* OtherKnob)
{
}

void AFMInWorldKnobActorBase::CopyAttributesFromOtherKnobInternal_Implementation(AFMInWorldKnobActorBase* OtherKnob)
{
}

bool AFMInWorldKnobActorBase::GetConsumeInteractionFromChildInteractable(APlayerController* PlayerController) const
{
	return false;
}

UClass* AFMInWorldKnobActorBase::GetCopyClassInternal_Implementation() const
{
	return nullptr;
}

TSubclassOf<UUserWidget> AFMInWorldKnobActorBase::GetCopyWidgetClassInternal_Implementation() const
{
	return TSubclassOf<UUserWidget>();
}

int32 AFMInWorldKnobActorBase::GetCurrentOptionIndex() const
{
	return int32();
}

bool AFMInWorldKnobActorBase::GetCurrentValueAsBool() const
{
	return false;
}

uint8 AFMInWorldKnobActorBase::GetCurrentValueAsEnum() const
{
	return uint8();
}

float AFMInWorldKnobActorBase::GetCurrentValueAsFloat() const
{
	return float();
}

int32 AFMInWorldKnobActorBase::GetCurrentValueAsInt() const
{
	return int32();
}

FName AFMInWorldKnobActorBase::GetCurrentValueAsName() const
{
	return FName();
}

FString AFMInWorldKnobActorBase::GetCurrentValueAsString() const
{
	return FString();
}

FText AFMInWorldKnobActorBase::GetCurrentValueLabel()
{
	return FText();
}

USceneComponent* AFMInWorldKnobActorBase::GetHitComponent() const
{
	return nullptr;
}

APlayerController* AFMInWorldKnobActorBase::GetInteractingController() const
{
	return nullptr;
}

int32 AFMInWorldKnobActorBase::GetNumberOptions() const
{
	return int32();
}

UFabricInteractableViewModel* AFMInWorldKnobActorBase::GetWidgetViewModel() const
{
	return nullptr;
}

bool AFMInWorldKnobActorBase::HasActiveFloatProvider() const
{
	return false;
}

bool AFMInWorldKnobActorBase::IsOverriddenByPort() const
{
	return false;
}

void AFMInWorldKnobActorBase::KnobValueChanged(int32 NewIndex, bool SnapToSelection, APlayerController* PlayerController)
{
}

void AFMInWorldKnobActorBase::OnFloatProviderFloatUpdated(float NewFloat)
{
}

void AFMInWorldKnobActorBase::OnKnobIsVisible(bool bInIsVisible)
{
}

void AFMInWorldKnobActorBase::OnReceiveFloatProvidersFromPort(const TArray<UFabricFloatProviderBase*>& FloatProvider)
{
}

void AFMInWorldKnobActorBase::ResetToDefaultValue(APlayerController* PlayerController)
{
}

void AFMInWorldKnobActorBase::SetCurrentKnobPosition_Implementation(float KnobPosition)
{
}

void AFMInWorldKnobActorBase::SetKnobDisplayOnly(bool bDisplayOnly)
{
}

void AFMInWorldKnobActorBase::SetKnobEnabled(bool bEnabled)
{
}

void AFMInWorldKnobActorBase::SetNumberOptions_Implementation(int32 NumberOptions)
{
}

void AFMInWorldKnobActorBase::SetSelectedIndex_Implementation(int32 Index, bool SnapToSelection)
{
}

void AFMInWorldKnobActorBase::SetTitle_Implementation(const FText& Title)
{
}

void AFMInWorldKnobActorBase::SetWidgetViewModel(UFabricInteractableViewModel* ViewModel)
{
}

void AFMInWorldKnobActorBase::UpdateDisplayOnlyVisuals_Implementation(bool bDisplayOnly)
{
}

void AFMInWorldKnobActorBase::UpdateEnabledVisuals_Implementation(bool bEnabled)
{
}

void AFMInWorldKnobActorBase::UpdateFocusVisuals_Implementation(bool bFocused)
{
}

void AFMInWorldKnobActorBase::UpdateInteractableVisuals_Implementation(bool bInteractable)
{
}
