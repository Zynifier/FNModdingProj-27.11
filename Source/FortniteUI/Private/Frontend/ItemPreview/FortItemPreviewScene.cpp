// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/ItemPreview/FortItemPreviewScene.h"

AItemPreviewScene* AFortItemPreviewSceneChanger::GetActiveScene()
{
	return nullptr;
}

AItemPreviewScene* AFortItemPreviewSceneChanger::GetPrimaryScene()
{
	return nullptr;
}

AItemPreviewScene* AFortItemPreviewSceneChanger::GetSceneTransitioningTo()
{
	return nullptr;
}

bool AFortItemPreviewSceneChanger::IsSoundEnabled() const
{
	return false;
}

void AFortItemPreviewSceneChanger::TickPedestalRotationOffset()
{
}

void AFortItemPreviewSceneChanger::TickZoomLevel()
{
}

void AItemPreviewScene::HandleItemShown(const UFortAccountItemDefinition* ItemViewed, AFortCameraTargetPedestal* Pedestal)
{
}
