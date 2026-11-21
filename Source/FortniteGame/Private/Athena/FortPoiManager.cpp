// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPoiManager.h"
#include "Net/UnrealNetwork.h"

void AFortPoiManager::BindOnPoiEntered(FGameplayTag PoiTag, FPoiEventDelegateSingle Event)
{
}

void AFortPoiManager::BindOnPoiExited(FGameplayTag PoiTag, FPoiEventDelegateSingle Event)
{
}

const TArray<AFortPoiVolume*>& AFortPoiManager::GetAllPoiVolumes() const
{
	static TArray<AFortPoiVolume*> Dummy;
	return Dummy;
}

const TArray<AFortPoiVolume*>& AFortPoiManager::GetNamedOnMapPoiVolumes()
{
	static TArray<AFortPoiVolume*> Dummy;
	return Dummy;
}

const AFortPoiVolume* AFortPoiManager::GetVolumeWithTag(const FGameplayTag& TagToCheck)
{
	return nullptr;
}

bool AFortPoiManager::HasInitialized() const
{
	return false;
}

void AFortPoiManager::MinimalInitPostEventsReady(const TArray<FString>& NewEvents)
{
}

void AFortPoiManager::OnRep_FortPoiGridInfo()
{
}

void AFortPoiManager::OnRep_PoiGridForDebugDisplay()
{
}

void AFortPoiManager::OnRep_PoiTagContainerTable()
{
}

void AFortPoiManager::UnbindOnPoiEntered(FGameplayTag PoiTag, FPoiEventDelegateSingle Event)
{
}

void AFortPoiManager::UnbindOnPoiExited(FGameplayTag PoiTag, FPoiEventDelegateSingle Event)
{
}

void AFortPoiManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPoiManager, FortPoiGridInfo);
	DOREPLIFETIME(AFortPoiManager, PoiTagContainerTable);
	DOREPLIFETIME(AFortPoiManager, PoiTagContainerTableSize);
	DOREPLIFETIME(AFortPoiManager, PoiGridForDebugDisplay);
}
