// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Navigation/FortNavPathRendererComponent.h"
#include "Net/UnrealNetwork.h"

void UFortNavPathRendererComponent::DeactivateFX()
{
}

void UFortNavPathRendererComponent::OnRep_ColorIndexUpdated()
{
}

void UFortNavPathRendererComponent::OnRep_PathModeUpdated()
{
}

void UFortNavPathRendererComponent::OnRep_PathPointsUpdated()
{
}

void UFortNavPathRendererComponent::UpdatePathsVisualOnClient()
{
}

void UFortNavPathRendererComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortNavPathRendererComponent, AllPathsPoints);
	DOREPLIFETIME(UFortNavPathRendererComponent, PathMode);
	DOREPLIFETIME(UFortNavPathRendererComponent, CurrentPathColorIndex);
}
