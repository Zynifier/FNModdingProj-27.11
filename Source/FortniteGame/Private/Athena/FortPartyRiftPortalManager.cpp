// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPartyRiftPortalManager.h"
#include "Net/UnrealNetwork.h"

bool AFortPartyRiftPortalManager::CanSpawnPortal(const AFortPlayerController* PlayerController, FGameplayTagContainer& OutResultTags) const
{
	return false;
}

bool AFortPartyRiftPortalManager::DeterminePortalSpawnLocation(AFortPlayerPawn* PlayerPawn, FVector& Location, FRotator& Rotation) const
{
	return false;
}

void AFortPartyRiftPortalManager::GetPartyRiftPortalManager(const UObject* WorldContextObject, AFortPartyRiftPortalManager*& OutPartyRiftPortalManager, EPartyRiftPortalManagerValidityResult& OutIsValid)
{
}

void AFortPartyRiftPortalManager::ReleasePortal(AFortAthenaPartyRiftPortal* PortalToRelease, const FString& Reason)
{
}

void AFortPartyRiftPortalManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPartyRiftPortalManager, AllPortals);
}
