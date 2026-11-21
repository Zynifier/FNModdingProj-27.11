// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortQuestIconComponent.h"

float UFortQuestIconComponent::GetViewDistanceRadius() const
{
	return float();
}

void UFortQuestIconComponent::HandlePinnedQuestChanged(const FAthenaPinnedQuestData& PinnedQuestData)
{
}

void UFortQuestIconComponent::OnOwnerCustomUpdateObjective(AFortPlayerController* PlayerController, int32 AchievedCount, int32 RequiredCount)
{
}

void UFortQuestIconComponent::OnOwnerObjectiveUpdated(const AFortPlayerController* PlayerController, const bool bQuestCompleted)
{
}

void UFortQuestIconComponent::OnOwnerQuestNotReady(AFortPlayerController* PlayerController)
{
}

void UFortQuestIconComponent::OnOwnerQuestReady(AFortPlayerController* PlayerController)
{
}

void UFortQuestIconComponent::OnQuestStageChanged(const AFortPlayerController* PlayerController, const int32 UpdatedQuestStage)
{
}

void UFortQuestIconComponent::PerformVisibilityDistanceCheck()
{
}

void UFortQuestIconComponent::SetIcon(UObject* MiniMapIcon)
{
}

void UFortQuestIconComponent::SetIconLocationOffset(const FVector& LocationOffset)
{
}

void UFortQuestIconComponent::SetIconPinned(UObject* PinnedIcon)
{
}

void UFortQuestIconComponent::SetIconScale(const FVector2D& IconScale)
{
}

void UFortQuestIconComponent::SetIconVisibilityInWorld(const bool bVisible)
{
}

void UFortQuestIconComponent::SetIconVisibilityOnMap(const bool bVisible)
{
}

void UFortQuestIconComponent::SetIconVisibilityOnMiniMap(const bool bVisible)
{
}

void UFortQuestIconComponent::SetViewDistanceRadius(const float ViewDistance)
{
}

void UFortQuestIconComponent::SetVisibility(const bool bVisible)
{
}
