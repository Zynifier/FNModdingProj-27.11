// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortUICameraManagerComponent.h"

EFrontEndCamera UFortUICameraManagerComponent::GetCamera() const
{
	return EFrontEndCamera();
}

AFortCameraBase* UFortUICameraManagerComponent::GetCameraActor() const
{
	return nullptr;
}

float UFortUICameraManagerComponent::GetZoomLevel() const
{
	return float();
}

void UFortUICameraManagerComponent::HandleCameraFrameTargetSettingsChanged(TScriptInterface<IFortUICameraFrameTargetInterface> FrameTarget)
{
}

void UFortUICameraManagerComponent::SetCamera(EFrontEndCamera NewCamera, FViewTargetTransitionParams TransitionParams)
{
}

void UFortUICameraManagerComponent::SetCameraFrame(const TScriptInterface<IFortUICameraFrameInterface> NewFrame)
{
}

void UFortUICameraManagerComponent::SetCustomCameraRotationOffset(const FRotator Offset)
{
}

void UFortUICameraManagerComponent::SetFrameTarget(const TScriptInterface<IFortUICameraFrameTargetInterface>& FrameTarget)
{
}

void UFortUICameraManagerComponent::SetZoomLevel(const float ZoomLevel)
{
}
