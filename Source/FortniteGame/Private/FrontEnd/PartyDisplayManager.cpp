// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrontEnd/PartyDisplayManager.h"

void APartyDisplayManager::BeginLoadingAssetsForItem(UFortItem* ItemToView, const TArray<TSoftObjectPtr<UObject>>& AssetsToLoad, const FGuid& RequestId)
{
}

FFortAthenaLoadout APartyDisplayManager::GetCosmeticLoadoutForCurrentDisplayedItem() const
{
	return FFortAthenaLoadout();
}

AFortPlayerPawn* APartyDisplayManager::GetHeroPlayerPawnForCurrentDisplayedItem()
{
	return nullptr;
}

bool APartyDisplayManager::GetPartyMemberIndexByPlayerPawn(const AFortPlayerPawn* PlayerPawn, int32& OutPlayerIndex) const
{
	return false;
}

FUniqueNetIdRepl APartyDisplayManager::GetPlayerIdFromPartyMemberIndex(int32 PartyMemberIndex) const
{
	return FUniqueNetIdRepl();
}

void APartyDisplayManager::HandleCharacterCustomizationFinished(AFortPlayerPawn* Pawn)
{
}

void APartyDisplayManager::HandleItemsShown(const TArray<UFortItem*>& ItemShown, const FGuid& RequestId)
{
}

void APartyDisplayManager::NotifyPrefabChanged(AActor* PrefabActor, UFortItem* CurrentItem)
{
}

void APartyDisplayManager::OnPawnBeginCursorOver(AActor* TouchedActor)
{
}

void APartyDisplayManager::OnPawnClicked(AActor* TouchedActor, FKey ButtonPressed)
{
}

void APartyDisplayManager::OnPawnEndCursorOver(AActor* TouchedActor)
{
}

void APartyDisplayManager::OnPawnTouchReleased(ETouchIndex::Type FingerIndex, AActor* TouchedActor)
{
}

void UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals::OnItemDisplayReady(AFortPlayerPawn* Pawn)
{
}

void UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals::OnPreviousCustomizationComplete(AFortPlayerPawn* Pawn)
{
}

void UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals::OnRequestedCustomizationComplete(AFortPlayerPawn* Pawn)
{
}

UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals* UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals::SetupPrefabVisuals(const APartyDisplayManager* Target, const UFortItem* Item, const FGuid& RequestId)
{
	return nullptr;
}
