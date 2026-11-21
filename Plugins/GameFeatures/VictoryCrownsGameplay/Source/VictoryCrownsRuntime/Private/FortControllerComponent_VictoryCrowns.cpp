// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortControllerComponent_VictoryCrowns.h"
#include "Net/UnrealNetwork.h"

bool UFortControllerComponent_VictoryCrowns::AuthorityHasDroppedCrownItem(const UFortItem* CrownItem) const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::AuthorityHasHeldCrownItem(const UFortItem* CrownItem) const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::AuthorityHasSquadDroppedCrownItem(const UFortItem* CrownItem) const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::AuthorityHasSquadHeldCrownItem(const UFortItem* CrownItem) const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::AuthoritySquadHasSeenCrownItem(const UFortItem* CrownItem, const bool bDropped) const
{
	return false;
}

void UFortControllerComponent_VictoryCrowns::CacheAccountItemData()
{
}

void UFortControllerComponent_VictoryCrowns::DebugForceSetRoyalRoyaleAchievedCount(int32 NewRoyalRoyaleCount)
{
}

const UFortWorldItem* UFortControllerComponent_VictoryCrowns::GetCrownInPlayerInventory() const
{
	return nullptr;
}

const int32 UFortControllerComponent_VictoryCrowns::GetRoyalRoyaleAchievedCount() const
{
	return int32();
}

const int32 UFortControllerComponent_VictoryCrowns::GetVictoryCrownsBestowedCount() const
{
	return int32();
}

void UFortControllerComponent_VictoryCrowns::HandleEnterAircraft()
{
}

void UFortControllerComponent_VictoryCrowns::HandleExitAircraft(AController* ExitingController)
{
}

void UFortControllerComponent_VictoryCrowns::HandlePawnChanged(APawn* OldPawn, APawn* NewPawn)
{
}

bool UFortControllerComponent_VictoryCrowns::HasWonCrownInMatch() const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::HasWonRoyalRoyale() const
{
	return false;
}

bool UFortControllerComponent_VictoryCrowns::IsCrownInPlayerInventory() const
{
	return false;
}

void UFortControllerComponent_VictoryCrowns::OnAthenaProfileInitialized()
{
}

void UFortControllerComponent_VictoryCrowns::OnEnterAircraft(AController* EnteringController)
{
}

void UFortControllerComponent_VictoryCrowns::OnRep_VictoryCrownAccountData()
{
}

void UFortControllerComponent_VictoryCrowns::OnRep_WonCrownInMatch()
{
}

void UFortControllerComponent_VictoryCrowns::OnRep_WonRoyalRoyale()
{
}

void UFortControllerComponent_VictoryCrowns::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_VictoryCrowns, bWonCrownInMatch);
	DOREPLIFETIME(UFortControllerComponent_VictoryCrowns, bWonRoyalRoyale);
	DOREPLIFETIME(UFortControllerComponent_VictoryCrowns, VictoryCrownAccountData);
}
