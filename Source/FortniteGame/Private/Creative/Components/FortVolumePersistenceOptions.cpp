// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortVolumePersistenceOptions.h"
#include "Net/UnrealNetwork.h"

const UFortCreativePersistenceComponent* UFortVolumePersistenceOptions::GetFirstOrderedPersistenceComponent() const
{
	return nullptr;
}

bool UFortVolumePersistenceOptions::IsPlayerClearDataOptionAllowed() const
{
	return false;
}

bool UFortVolumePersistenceOptions::IsTherePersistenceDevices() const
{
	return false;
}

void UFortVolumePersistenceOptions::RegistryFortCreativePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent, const FFortCreativePersistenceOptions& FortCreativePersistenceOptions)
{
}

void UFortVolumePersistenceOptions::UnregistryFortCreativePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent)
{
}

void UFortVolumePersistenceOptions::UpdatePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent, const FFortCreativePersistenceOptions& FortCreativePersistenceOptions)
{
}

void UFortVolumePersistenceOptions::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVolumePersistenceOptions, bAllowPlayerToClearData);
}
