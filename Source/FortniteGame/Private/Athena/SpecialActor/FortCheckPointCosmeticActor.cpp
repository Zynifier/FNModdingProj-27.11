// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortCheckPointCosmeticActor.h"
#include "Net/UnrealNetwork.h"

void AFortCheckPointCosmeticActor::OnRep_bIsEndPoint()
{
}

void AFortCheckPointCosmeticActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCheckPointCosmeticActor, CheckPointIndex);
	DOREPLIFETIME(AFortCheckPointCosmeticActor, bIsEndPoint);
}
