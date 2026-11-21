// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Heroes/FortHeroGameplayDefinition.h"

bool UFortHeroGameplayDefinition::DoesHeroPerkApplyToCommander(UFortHero* FortHero, UFortHero* CommanderHero)
{
	return false;
}

bool UFortHeroGameplayDefinition::DoesHeroSatisfyTeamPerkCondition(const UFortTeamPerkItemDefinition* TeamPerk, UFortHero* SupportHero)
{
	return false;
}

bool UFortHeroGameplayDefinition::DoesTeamPerkApplyToCommander(const UFortTeamPerkItem* TeamPerk, const UFortHero* CommanderHero)
{
	return false;
}

UFortAbilityKit* UFortHeroGameplayDefinition::GetAbilityKitForCommanderPerk(const UFortHeroType* HeroDefinition)
{
	return nullptr;
}

UFortAbilityKit* UFortHeroGameplayDefinition::GetAbilityKitForHeroPerk(const UFortHeroType* HeroDefinition)
{
	return nullptr;
}

TArray<UFortAbilityKit*> UFortHeroGameplayDefinition::GetAbilityKitsForActiveAbilityPerks(const UFortHeroType* HeroDefinition)
{
	return TArray<UFortAbilityKit*>();
}

EFortItemTier UFortHeroGameplayDefinition::GetAbilityKitUnlockTierForHero(const UFortHero* FortHero, UFortAbilityKit* AbilityKit)
{
	return EFortItemTier();
}

EFortItemTier UFortHeroGameplayDefinition::GetCommanderTierRequiredForHeroPerkToApplyToCommander(UFortHero* FortHero, UFortHero* CommanderHero)
{
	return EFortItemTier();
}

EFortItemTier UFortHeroGameplayDefinition::GetCommanderTierRequiredForTeamPerkToApplyToCommander(const UFortTeamPerkItem* TeamPerk, const UFortHero* CommanderHero)
{
	return EFortItemTier();
}

TArray<FText> UFortHeroGameplayDefinition::GetKeywordDisplayNames(UFortHeroType* HeroType)
{
	return TArray<FText>();
}

bool UFortHeroGameplayDefinition::IsAbilityKitUnlockedForHero(const UFortHero* FortHero, UFortAbilityKit* AbilityKit)
{
	return false;
}

bool UFortHeroGameplayDefinition::IsCommanderPerkUnlockedForHero(UFortHero* FortHero)
{
	return false;
}

bool UFortHeroGameplayDefinition::IsHeroPerkUnlockedForHero(UFortHero* FortHero)
{
	return false;
}

bool UFortHeroGameplayDefinition::IsHeroPerkValidForCommander(const UFortHero* SlottedHero, const UFortCampaignHeroLoadoutItem* HeroLoadout, const FName& SupportHeroSlotName, bool bIsSlotting, FText& OutReason)
{
	return false;
}

bool UFortHeroGameplayDefinition::IsSlottedHeroAbilityDuplicated(const UFortHero* PotentiallySlottedHero, const UFortCampaignHeroLoadoutItem* HeroLoadout, const FName& SupportHeroSlotName, bool bIsSlotting)
{
	return false;
}

bool UFortHeroGameplayDefinition::IsTeamPerkValidForCommander(const UFortTeamPerkItem* TeamPerk, const UFortCampaignHeroLoadoutItem* HeroLoadout, FText& OutReason)
{
	return false;
}
