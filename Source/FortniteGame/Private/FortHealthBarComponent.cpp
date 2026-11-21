// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortHealthBarComponent.h"
#include "Net/UnrealNetwork.h"

FText UFortHealthBarComponent::GetHealthBarDisplayText() const
{
	return FText();
}

void UFortHealthBarComponent::OnRep_DisplayText()
{
}

void UFortHealthBarComponent::OnRep_IsVisible()
{
}

void UFortHealthBarComponent::SetHealthBarDisplayText(FText NewDisplayText)
{
}

void UFortHealthBarComponent::SetHealthBarVisibility(bool bNewVisibleState)
{
}

void UFortHealthBarComponent::SetHealthBarWidgetVisibility(bool bIsVisible)
{
}

void UFortHealthBarComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortHealthBarComponent, DisplayText);
	DOREPLIFETIME(UFortHealthBarComponent, bIsHealthBarVisible);
}
