// Copyright Epic Games, Inc. All Rights Reserved.

#include "PIPBlockManager/LiveStreamPiPBlockManager.h"

ULiveStreamPiPBlockManager* ULiveStreamPiPBlockManager::GetPiPBlockManager()
{
	return nullptr;
}

bool ULiveStreamPiPBlockManager::IsOutSideBlocked() const
{
	return false;
}

bool ULiveStreamPiPBlockManager::IsPlayerBlocked() const
{
	return false;
}

void ULiveStreamPiPBlockManager::SetPlayerBlocked(bool bInBlocked, bool bInOutsideBlocked)
{
}
