// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortCampaignHeroLoadoutItemDefinition.h"

const FFortCrewSlotInformation& UFortCampaignHeroLoadoutItemDefinition::GetCommanderSlot() const
{
	static FFortCrewSlotInformation Dummy;
	return Dummy;
}

int32 UFortCampaignHeroLoadoutItemDefinition::GetSlotIndexByName(const FName& SlotName) const
{
	return int32();
}

const TArray<FFortCrewSlotInformation>& UFortCampaignHeroLoadoutItemDefinition::GetSlots() const
{
	static TArray<FFortCrewSlotInformation> Dummy;
	return Dummy;
}
