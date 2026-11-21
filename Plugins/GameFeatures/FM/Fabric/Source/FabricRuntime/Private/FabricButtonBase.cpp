// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricButtonBase.h"

UTimelineComponent* AFabricButtonBase::GetCloseTimeline_Implementation()
{
	return nullptr;
}

UTimelineComponent* AFabricButtonBase::GetOpenTimeline_Implementation()
{
	return nullptr;
}

void AFabricButtonBase::HandleButtonClicked_Implementation()
{
}

void AFabricButtonBase::HandleButtonDoubleClicked_Implementation()
{
}

void AFabricButtonBase::HandleButtonHovered_Implementation()
{
}

void AFabricButtonBase::HandleButtonPressed_Implementation()
{
}

void AFabricButtonBase::HandleButtonReleased_Implementation()
{
}

void AFabricButtonBase::HandleButtonUnhovered_Implementation()
{
}

bool AFabricButtonBase::IsEnabled()
{
	return false;
}

bool AFabricButtonBase::IsHovered()
{
	return false;
}

bool AFabricButtonBase::IsPressed()
{
	return false;
}

bool AFabricButtonBase::IsToggledOn()
{
	return false;
}

void AFabricButtonBase::OnButtonClicked_Implementation()
{
}

void AFabricButtonBase::OnButtonDoubleClicked_Implementation()
{
}

void AFabricButtonBase::OnButtonPressed_Implementation()
{
}

void AFabricButtonBase::OnButtonReleased_Implementation()
{
}

void AFabricButtonBase::OnDisabled_Implementation()
{
}

void AFabricButtonBase::OnEnabled_Implementation()
{
}

void AFabricButtonBase::OnHovered_Implementation()
{
}

void AFabricButtonBase::OnToggleStateChanged_Implementation(bool bIsToggled)
{
}

void AFabricButtonBase::OnUnhovered_Implementation()
{
}

void AFabricButtonBase::SetEnabled(bool bNewEnabled)
{
}

void AFabricButtonBase::SetToggleState(bool bNewToggleState, bool bBroadcast, bool bForce)
{
}

void AFabricButtonBase::SetWidgetViewModel(UFabricInteractableViewModel* ViewModel)
{
}

void AFabricButtonBase::SwapToggle()
{
}
