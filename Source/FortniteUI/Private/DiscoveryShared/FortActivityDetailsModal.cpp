// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortActivityDetailsModal.h"

EFortInvalidActivityReason UFortActivityDetailsModal::GetInvalidActivityReason() const
{
	return EFortInvalidActivityReason();
}

const UFortGameActivity* UFortActivityDetailsModal::GetSelectedGameActivity() const
{
	return nullptr;
}

bool UFortActivityDetailsModal::IsCreativeModeSetActivity() const
{
	return false;
}

const bool UFortActivityDetailsModal::IsLocalPlayerPartyLeader() const
{
	return bool();
}

bool UFortActivityDetailsModal::IsModeSetActivity() const
{
	return false;
}
