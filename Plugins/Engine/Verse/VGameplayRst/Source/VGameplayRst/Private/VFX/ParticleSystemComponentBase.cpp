// Copyright Epic Games, Inc. All Rights Reserved.

#include "VFX/ParticleSystemComponentBase.h"
#include "Net/UnrealNetwork.h"

void UParticleSystemComponentBase::OnRep_bActive()
{
}

void UParticleSystemComponentBase::OnRep_ParticleSystemAsset()
{
}

void UParticleSystemComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UParticleSystemComponentBase, ParticleSystemAsset);
	DOREPLIFETIME(UParticleSystemComponentBase, bActive);
}
