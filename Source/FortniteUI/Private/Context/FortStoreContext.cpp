// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortStoreContext.h"

bool UFortStoreContext::CardAddedToSummaryComplete()
{
	return false;
}

bool UFortStoreContext::CardBackRevealComplete()
{
	return false;
}

bool UFortStoreContext::CardEntryComplete()
{
	return false;
}

bool UFortStoreContext::CardExitComplete()
{
	return false;
}

bool UFortStoreContext::CardFlipComplete()
{
	return false;
}

bool UFortStoreContext::CardFrontRevealComplete()
{
	return false;
}

bool UFortStoreContext::CardPackDestroyComplete()
{
	return false;
}

bool UFortStoreContext::CardPackOpeningComplete()
{
	return false;
}

bool UFortStoreContext::ChoiceResultComplete()
{
	return false;
}

bool UFortStoreContext::DoesItemSlotExistInCollectionBook(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

bool UFortStoreContext::EnterCurrencyStore()
{
	return false;
}

bool UFortStoreContext::ExitCurrencyStore()
{
	return false;
}

bool UFortStoreContext::ExitSummary()
{
	return false;
}

void UFortStoreContext::FireInteractionAnalyticsEvent(const FString& Interaction, const FString& Details) const
{
}

bool UFortStoreContext::GetCard(int32 CardIdx, FCard& ResultOut) const
{
	return false;
}

TArray<FCard> UFortStoreContext::GetChoiceCards(int32 CardIdx) const
{
	return TArray<FCard>();
}

int32 UFortStoreContext::GetNumUnopenedCardPacksRemaining(const UFortCardPackItemDefinition* PackType, bool bCountChoicePacks) const
{
	return int32();
}

int32 UFortStoreContext::GetOwnedItemCount(const UFortItemDefinition* ItemDefinition) const
{
	return int32();
}

int32 UFortStoreContext::GetOwnedSurvivorCount(const UFortItem* SurvivorItem) const
{
	return int32();
}

int32 UFortStoreContext::GetPackOpeningLimit() const
{
	return int32();
}

bool UFortStoreContext::GetSkipOpening() const
{
	return false;
}

EFortStoreState UFortStoreContext::GetStoreState() const
{
	return EFortStoreState();
}

bool UFortStoreContext::IsItemMissingFromCollectionBook(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

bool UFortStoreContext::IsOpeningDirectPack() const
{
	return false;
}

bool UFortStoreContext::IsWaitingForMcp() const
{
	return false;
}

bool UFortStoreContext::MakeChoice(int32 ChoiceIdx, UFortAccountItemDefinition* ChoiceItemDefinition)
{
	return false;
}

void UFortStoreContext::SetSkipOpening(const bool bSkipOpen)
{
}
