// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/PersistenceComponent/FortCreativePersistenceComponentBase.h"

void UFortCreativePersistenceComponentBase::ClearData(const FUniqueNetIdRepl& PlayerId, const FString& SavePath)
{
}

void UFortCreativePersistenceComponentBase::GenerateNewPersistenceIDAndResaveActor()
{
}

FString UFortCreativePersistenceComponentBase::GetPersistenceID() const
{
	return FString();
}

void UFortCreativePersistenceComponentBase::GetPersistencePlayersIds(TArray<FUniqueNetIdRepl>& PersistencePlayers) const
{
}

void UFortCreativePersistenceComponentBase::InitializePersistenceComponent(UFortMinigameLogicComponent* InLogicComponent, bool bInUniqueForOwner)
{
}

bool UFortCreativePersistenceComponentBase::IsPersistenceIDValid(const FString& PersistenceID)
{
	return false;
}

bool UFortCreativePersistenceComponentBase::IsPersistenceRequired()
{
	return false;
}

void UFortCreativePersistenceComponentBase::LoadData(const FUniqueNetIdRepl& PlayerId, const FString& SavePath, UObject* OutData)
{
}

void UFortCreativePersistenceComponentBase::OnAddedToMinigame(AFortMinigame* FortMinigame)
{
}

void UFortCreativePersistenceComponentBase::OnPostDuplicate(bool bDuplicateForPie)
{
}

void UFortCreativePersistenceComponentBase::OnRemovedFromMinigame(AFortMinigame* FortMinigame)
{
}

void UFortCreativePersistenceComponentBase::SaveData(const UObject* Data, const FUniqueNetIdRepl& PlayerId, const FString& SavePath, bool bIsAutoSave)
{
}

void UFortCreativePersistenceComponentBase::SetAutoSaveEnabled(bool bAutoSaveEnabled)
{
}

void UFortCreativePersistenceComponentBase::SetUniqueForOwner(bool bInUniqueForOwner)
{
}

bool UFortCreativePersistenceComponentBase::TryOverridePersistenceIDAndResaveActor(const FString& NewPersistenceID)
{
	return false;
}

void UFortCreativePersistenceComponentBase::UpdateIsPersistencePosible()
{
}
