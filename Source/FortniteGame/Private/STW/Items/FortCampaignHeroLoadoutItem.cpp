// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortCampaignHeroLoadoutItem.h"

UFortHero* UFortCampaignHeroLoadoutItem::GetCommanderHero() const
{
	return nullptr;
}

UFortGadgetItemDefinition* UFortCampaignHeroLoadoutItem::GetGadgetDefinitionBySlotIndex(const int32 SlotIndex) const
{
	return nullptr;
}

UFortHero* UFortCampaignHeroLoadoutItem::GetHeroBySlotName(const FName& SlotName) const
{
	return nullptr;
}

void UFortCampaignHeroLoadoutItem::GetHeroes(TArray<UFortHero*>& OutHeroes) const
{
}

void UFortCampaignHeroLoadoutItem::GetHeroesBySlotTag(const FGameplayTagQuery& TagQuery, TArray<UFortHero*>& OutHeroes) const
{
}

int32 UFortCampaignHeroLoadoutItem::GetLoadoutOrdinal() const
{
	return int32();
}

FName UFortCampaignHeroLoadoutItem::GetSlotNameByHero(const UFortHero* Hero) const
{
	return FName();
}

void UFortCampaignHeroLoadoutItem::GetSupportHeroes(TArray<UFortHero*>& OutHeroes) const
{
}

void UFortCampaignHeroLoadoutItem::GetSupportHeroesAndSupportSlotIndices(TArray<UFortHero*>& OutHeroes, TArray<int32>& OutSupportSlotIndices) const
{
}

UFortTeamPerkItem* UFortCampaignHeroLoadoutItem::GetTeamPerk() const
{
	return nullptr;
}

int32 UFortCampaignHeroLoadoutItem::GetTeamPerkActivationLevel() const
{
	return int32();
}

int32 UFortCampaignHeroLoadoutItem::GetTeamPerkActivationLevelAndSatisfyingSlotIndices(TArray<int32>& OutSatisfyingSlotIndices) const
{
	return int32();
}

UFortTeamPerkItemDefinition* UFortCampaignHeroLoadoutItem::GetTeamPerkItemDefinition() const
{
	return nullptr;
}

int32 UFortCampaignHeroLoadoutItem::GetTeamPerkMaxActivationLevel() const
{
	return int32();
}

bool UFortCampaignHeroLoadoutItem::IsTeamPerkActive() const
{
	return false;
}

bool UFortCampaignHeroLoadoutItem::IsTeamPerkProgressive() const
{
	return false;
}
