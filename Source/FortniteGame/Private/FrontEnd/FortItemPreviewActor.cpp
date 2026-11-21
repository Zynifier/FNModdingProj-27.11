// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrontEnd/FortItemPreviewActor.h"

bool AFortItemPreviewActor::ArePreviewVisualsReady() const
{
	return false;
}

bool AFortItemPreviewActor::GetHideModifierFXUntilResInDissolveComplete() const
{
	return false;
}

const UFortAccountItemDefinition* AFortItemPreviewActor::GetItemDefinition() const
{
	return nullptr;
}

const UFortItem* AFortItemPreviewActor::GetSourceItemInstance() const
{
	return nullptr;
}

float AFortItemPreviewActor::GetStreamingSafetyDuration()
{
	return float();
}

bool AFortItemPreviewActor::GetUseCleanUpForIASItemPreviewFXDestruction() const
{
	return false;
}

bool AFortItemPreviewActor::GetUseIASItemPreviewLoadingEvents() const
{
	return false;
}

bool AFortItemPreviewActor::GetUseOutroForIASLoadingEffects() const
{
	return false;
}

bool AFortItemPreviewActor::IsSceneTransitioning() const
{
	return false;
}
