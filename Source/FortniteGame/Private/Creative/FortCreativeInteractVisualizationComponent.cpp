// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeInteractVisualizationComponent.h"

UShapeComponent* UFortCreativeInteractVisualizationComponent::GetCollisionComponent() const
{
	return nullptr;
}

float UFortCreativeInteractVisualizationComponent::GetCurrentTime() const
{
	return float();
}

float UFortCreativeInteractVisualizationComponent::GetInteractRadius() const
{
	return float();
}

bool UFortCreativeInteractVisualizationComponent::GetPendingShow() const
{
	return false;
}

float UFortCreativeInteractVisualizationComponent::GetVisualizationDiameterDesired() const
{
	return float();
}

float UFortCreativeInteractVisualizationComponent::GetVisualizationDiameterStart() const
{
	return float();
}

UStaticMeshComponent* UFortCreativeInteractVisualizationComponent::GetVisualMeshComponent() const
{
	return nullptr;
}

bool UFortCreativeInteractVisualizationComponent::HasInteractRadius() const
{
	return false;
}

void UFortCreativeInteractVisualizationComponent::OnPlayModeChanged(AFortMinigame* InMinigame, bool bIsInPlayMode)
{
}

void UFortCreativeInteractVisualizationComponent::SetRadius(const float InInteractRadius)
{
}
