// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricButtonComponentBase.h"

void UFabricButtonComponentBase::ConstructButton_Implementation()
{
}

UTimelineComponent* UFabricButtonComponentBase::GetCloseTimeline_Implementation()
{
	return nullptr;
}

UTimelineComponent* UFabricButtonComponentBase::GetOpenTimeline_Implementation()
{
	return nullptr;
}

void UFabricButtonComponentBase::HandleButtonClicked_Implementation()
{
}

void UFabricButtonComponentBase::HandleButtonDoubleClicked_Implementation()
{
}

void UFabricButtonComponentBase::HandleButtonHovered_Implementation()
{
}

void UFabricButtonComponentBase::HandleButtonPressed_Implementation()
{
}

void UFabricButtonComponentBase::HandleButtonReleased_Implementation()
{
}

void UFabricButtonComponentBase::HandleButtonUnhovered_Implementation()
{
}

bool UFabricButtonComponentBase::IsEnabled()
{
	return false;
}

bool UFabricButtonComponentBase::IsHovered()
{
	return false;
}

bool UFabricButtonComponentBase::IsPressed()
{
	return false;
}

bool UFabricButtonComponentBase::IsToggledOn()
{
	return false;
}

void UFabricButtonComponentBase::OnButtonClicked_Implementation()
{
}

void UFabricButtonComponentBase::OnButtonDoubleClicked_Implementation()
{
}

void UFabricButtonComponentBase::OnButtonPressed_Implementation()
{
}

void UFabricButtonComponentBase::OnButtonReleased_Implementation()
{
}

void UFabricButtonComponentBase::OnDisabled_Implementation()
{
}

void UFabricButtonComponentBase::OnEnabled_Implementation()
{
}

void UFabricButtonComponentBase::OnHovered_Implementation()
{
}

void UFabricButtonComponentBase::OnToggleStateChanged_Implementation(bool bIsToggled)
{
}

void UFabricButtonComponentBase::OnUnhovered_Implementation()
{
}

void UFabricButtonComponentBase::SetEnabled(bool bNewEnabled)
{
}

void UFabricButtonComponentBase::SetToggleState(bool bNewToggleState, bool bBroadcast, bool bForce)
{
}

void UFabricButtonComponentBase::SetWidgetViewModel(UFabricInteractableViewModel* ViewModel)
{
}

void UFabricButtonComponentBase::SwapToggle()
{
}
