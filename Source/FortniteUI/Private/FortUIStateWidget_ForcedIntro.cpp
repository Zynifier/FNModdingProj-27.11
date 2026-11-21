// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUIStateWidget_ForcedIntro.h"

TSoftClassPtr<UUserWidget> UFortUIStateWidget_ForcedIntro::GetPlaylistLoadingScreenWidget() const
{
	return TSoftClassPtr<UUserWidget>();
}

void UFortUIStateWidget_ForcedIntro::OnNewForcedIntroTextDisplayState_Implementation(EForcedIntroTextDisplayState NewState)
{
}

void UFortUIStateWidget_ForcedIntro::StartMatch()
{
}
