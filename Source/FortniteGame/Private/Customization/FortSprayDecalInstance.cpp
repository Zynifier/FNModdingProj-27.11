// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/FortSprayDecalInstance.h"
#include "Net/UnrealNetwork.h"

int32 AFortSprayDecalInstance::GetSpraySortOrder() const
{
	return int32();
}

void AFortSprayDecalInstance::OnRep_SprayInfo()
{
}

void AFortSprayDecalInstance::SetSprayParameters(AFortPlayerController* SpawningPC, UAthenaSprayItemDefinition* InSprayAsset)
{
}

void AFortSprayDecalInstance::StartSprayFadeOutDueToNewPlacement_Implementation()
{
}

void AFortSprayDecalInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSprayDecalInstance, SprayInfo);
}
