// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricTimelinePreviewComponent.h"

bool UFabricTimelinePreviewComponent::GetShouldPreview() const
{
	return false;
}

void UFabricTimelinePreviewComponent::PreviewTimeline(UTimelineComponent* Timeline, float SecondsToPlay, bool bReverseAnimation)
{
}
