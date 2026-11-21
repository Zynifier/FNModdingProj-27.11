// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Context/FortHomebaseUIContext.h"

void UFortDisableAutoSlottingPromptAction::CompleteExecution(const EFortDialogResult Result, const FName ResultName)
{
}

void UFortHomebaseUIContext::AutoSlotAllSurvivorSquads()
{
}

UFortCollectionBookData* UFortHomebaseUIContext::GetCollectionBookData() const
{
	return nullptr;
}

FName UFortHomebaseUIContext::GetCurrentlyFocusedHeroLoadoutSlotName() const
{
	return FName();
}

UFortCampaignHeroLoadoutItem* UFortHomebaseUIContext::GetCurrentlyViewedHeroLoadout() const
{
	return nullptr;
}

UFortItem* UFortHomebaseUIContext::GetItemInSquadSlot(FName SquadName, int32 SlotIndex) const
{
	return nullptr;
}

TArray<UFortItem*> UFortHomebaseUIContext::GetItemsInSquad(const FName SquadId, bool bRemoveEmptySquadSlots) const
{
	return TArray<UFortItem*>();
}

bool UFortHomebaseUIContext::GetShouldAutoSlotSurvivorSquads() const
{
	return false;
}

UFortHero* UFortHomebaseUIContext::GetSlottedPrimaryHero() const
{
	return nullptr;
}

FFortMultiSizeBrush UFortHomebaseUIContext::GetSquadIcon(const FName SquadId) const
{
	return FFortMultiSizeBrush();
}

bool UFortHomebaseUIContext::GetUnlockedGadgets(TArray<UFortItem*>& UnlockedGadgets) const
{
	return false;
}

UFortQuestItemDefinition* UFortHomebaseUIContext::GetUnlockingQuestDefinitionForHeroLoadoutSlot(const FName& SlotName, const UFortCampaignHeroLoadoutItem* Loadout) const
{
	return nullptr;
}

UFortQuestItemDefinition* UFortHomebaseUIContext::GetUnlockingQuestDefinitionForSquadSlot(const FName& SquadName, const int32 SlotIndex) const
{
	return nullptr;
}

void UFortHomebaseUIContext::GetWorkerSetBonusEffectModifiers(const FGameplayTag& SetBonusTag, TArray<FFortAttributeModifierDisplayData>& OutModifiers) const
{
}

void UFortHomebaseUIContext::HandleDifferentHeroLoadoutActivated(UFortMcpProfileCampaign* Profile)
{
}

bool UFortHomebaseUIContext::IsAnySquadSlotUnlocked(const FName SquadId) const
{
	return false;
}

bool UFortHomebaseUIContext::IsHeroLoadoutSlotUnlocked(const FName& SlotName, const UFortCampaignHeroLoadoutItem* Loadout) const
{
	return false;
}

void UFortHomebaseUIContext::SetCurrentlyFocusedHeroLoadoutSlotName(const FName& SlotName)
{
}

void UFortHomebaseUIContext::SetCurrentlyViewedHeroLoadout(const UFortCampaignHeroLoadoutItem* Loadout)
{
}

void UFortHomebaseUIContext::SetShouldAutoSlotSurvivorSquads(const bool Value)
{
}
