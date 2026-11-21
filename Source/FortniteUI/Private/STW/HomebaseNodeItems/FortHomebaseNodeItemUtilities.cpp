// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/HomebaseNodeItems/FortHomebaseNodeItemUtilities.h"

bool UFortHomebaseNodeItemUtilities::AreAnyHomebaseNodeItemsUnseenForSquadId(AFortPlayerController* FortPC, const FName& SquadId)
{
	return false;
}

bool UFortHomebaseNodeItemUtilities::AreAnyHomebaseNodeItemsUnseenForSquadType(AFortPlayerController* FortPC, const EFortHomebaseSquadType SquadType)
{
	return false;
}

UFortHomebaseNodeItem* UFortHomebaseNodeItemUtilities::GetHomebaseNodeItemForSquadSlot(AFortPlayerController* FortPC, const FName& SquadId, const int32 SquadSlot)
{
	return nullptr;
}

UFortHomebaseNodeItem* UFortHomebaseNodeItemUtilities::GetHomebaseNodeItemForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags)
{
	return nullptr;
}

FString UFortHomebaseNodeItemUtilities::GetHomebaseNodeItemNameForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags)
{
	return FString();
}

bool UFortHomebaseNodeItemUtilities::IsHomebaseNodeItemUnseenForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags)
{
	return false;
}

bool UFortHomebaseNodeItemUtilities::IsSquadSlotUnseen(AFortPlayerController* FortPC, const FName& SquadId, const int32 SquadSlot)
{
	return false;
}
