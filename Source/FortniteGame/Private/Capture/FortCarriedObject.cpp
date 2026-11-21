// Copyright Epic Games, Inc. All Rights Reserved.

#include "Capture/FortCarriedObject.h"
#include "Net/UnrealNetwork.h"

AActor* AFortCarriedObject::GetHoldingActor() const
{
	return nullptr;
}

void AFortCarriedObject::OnRep_HolderInfo(FCarriedObjectAttachmentInfo& PreviousInfo)
{
}

void AFortCarriedObject::ReturnToSpawnPoint()
{
}

void AFortCarriedObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCarriedObject, HolderInfo);
	DOREPLIFETIME(AFortCarriedObject, Team);
	DOREPLIFETIME(AFortCarriedObject, SpawnPointActor);
}
