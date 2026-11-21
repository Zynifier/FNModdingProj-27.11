// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/FortFrontendLevelScriptActor.h"

TSoftObjectPtr<AFortItemPreviewPedestal> AFortFrontendLevelScriptActor::GetCommanderPreviewPedestalActor() const
{
	return TSoftObjectPtr<AFortItemPreviewPedestal>();
}

AFortFrontendLevelScriptActor* AFortFrontendLevelScriptActor::GetFrontendLevelScript(UObject* WorldContextObject)
{
	return nullptr;
}

TSoftObjectPtr<AFortItemPreviewPedestal> AFortFrontendLevelScriptActor::GetHeroLoadoutPreviewPedestalActor() const
{
	return TSoftObjectPtr<AFortItemPreviewPedestal>();
}
