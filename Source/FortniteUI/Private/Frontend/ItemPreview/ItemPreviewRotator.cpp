// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/ItemPreview/ItemPreviewRotator.h"

void AItemPreviewRotator::CameraTransitionComplete()
{
}

FInterpolatedTransitionCamera AItemPreviewRotator::GetInterpolatedTransitionCameraPosition(const FTransform& TransitionCameraTransform, float TransitionCameraFieldOfView, float ProgressThroughTransitionSecs, float TransitionDurationSecs) const
{
	return FInterpolatedTransitionCamera();
}
