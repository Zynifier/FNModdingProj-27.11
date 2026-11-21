// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortDeployableBaseManager.h"
#include "Net/UnrealNetwork.h"

void AFortDeployableBaseManager::BroadcastHordeWaveStinger(EHordeWaveStingerType StingerType) const
{
}

void AFortDeployableBaseManager::GetAllDeployableBasePlots(TArray<ADeployableBasePlot*>& OutDeployableBasePlots) const
{
}

void AFortDeployableBaseManager::GetAvailableTiers(TArray<FAvailableTierLayout>& OutAvailableTiers) const
{
}

AFortDeployableBaseManager* AFortDeployableBaseManager::GetCurrent(UObject* WorldContextObject)
{
	return nullptr;
}

ADeployableBasePlot* AFortDeployableBaseManager::GetDeployableBasePlotFromLocation(const FVector& Location) const
{
	return nullptr;
}

EDeployableBaseUseType AFortDeployableBaseManager::GetDeployableBaseUseType() const
{
	return EDeployableBaseUseType();
}

int32 AFortDeployableBaseManager::GetHighestDefeatedTierForPlayerAndLayout(FUniqueNetIdRepl PlayerId, const UFortTieredCollectionLayout* Layout) const
{
	return int32();
}

bool AFortDeployableBaseManager::GetTierOutputForSelectedTier(int32 Tier, const UFortTieredCollectionLayout* Layout, FFortTierCollectionLayoutOutput& Output) const
{
	return false;
}

void AFortDeployableBaseManager::ReloadAllPlots()
{
}

void AFortDeployableBaseManager::SetKeepDeployableBasesOnLogout(bool bInKeepBasesOnLogout)
{
}

void AFortDeployableBaseManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortDeployableBaseManager, bRestrictedBuildingActive);
	DOREPLIFETIME(AFortDeployableBaseManager, bBusyWithPlotActions);
	DOREPLIFETIME(AFortDeployableBaseManager, DeployableBaseUseType);
	DOREPLIFETIME(AFortDeployableBaseManager, ActiveTieredCollectionLayouts);
	DOREPLIFETIME(AFortDeployableBaseManager, DeployableBaseArray);
}
