// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortEventLevelNavigationActor.h"

bool AFortEventLevelNavigationActor::CanCommitNavigationRequest_Implementation() const
{
	return false;
}

FFortEventLevelNavigationDisplayDetails AFortEventLevelNavigationActor::GetDisplayDetails() const
{
	return FFortEventLevelNavigationDisplayDetails();
}

UFortGameStateComponent_EventLevel* AFortEventLevelNavigationActor::GetOwningGameStateComp() const
{
	return nullptr;
}

void AFortEventLevelNavigationActor::HandleDisplayMeshBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
}

void AFortEventLevelNavigationActor::HandleDisplayMeshClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
}

void AFortEventLevelNavigationActor::HandleDisplayMeshEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
}

void AFortEventLevelNavigationActor::HandleDisplayMeshInputTouchEnd(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
}

void AFortEventLevelNavigationActor::HandleMCPInventoryChanged(const TSet<FString>& TypesChanged, int64 ProfileRvn)
{
}

bool AFortEventLevelNavigationActor::HasPurchasedSeasonBook() const
{
	return false;
}

void AFortEventLevelNavigationActor::UpdateBangState(FGameplayTag BangTacker, bool bShowBang)
{
}
