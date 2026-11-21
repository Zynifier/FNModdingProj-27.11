// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/KeepItemContainer.h"
#include "Net/UnrealNetwork.h"

FName AKeepItemContainer::GetContainerNameAndLevelKey()
{
	return FName();
}

int32 AKeepItemContainer::GetLootTierOverride_Implementation() const
{
	return int32();
}

void AKeepItemContainer::InitializeContainer(int32 InitUpgradeLevel)
{
}

void AKeepItemContainer::OnRep_HostUpgradeLevel()
{
}

void AKeepItemContainer::OnRep_SearchedBy()
{
}

void AKeepItemContainer::ResetContainer(AFortPlayerController* FortPC)
{
}

void AKeepItemContainer::RestoreLoot()
{
}

void AKeepItemContainer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AKeepItemContainer, HostUpgradeLevel);
	DOREPLIFETIME(AKeepItemContainer, SearchedBy);
	DOREPLIFETIME(AKeepItemContainer, BestAvailableRarity);
	DOREPLIFETIME(AKeepItemContainer, MaxItems);
}
