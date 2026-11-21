// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortActivityModeSetSelection.h"

UFortActivityModeSetSelection::UFortActivityModeSetSelection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FOnlineLinkId UFortActivityModeSetSelection::GetSelectedLinkId() const
{
	return FOnlineLinkId();
}

void UFortActivityModeSetSelection::SetActivity(UFortGameActivity* GameActivity)
{
}

UFortGameActivity* UFortActivityModeSetSelection::SetSelectedMnemonic(const FString& Mnemonic)
{
	return nullptr;
}
