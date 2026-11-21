// Copyright Epic Games, Inc. All Rights Reserved.

#include "Datastore/DatastoreComponentBase.h"
#include "Net/UnrealNetwork.h"

void UDatastoreComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDatastoreComponentBase, ReplicatedDatastoreState);
}
