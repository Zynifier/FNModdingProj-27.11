// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortLauncherAthena.h"
#include "Net/UnrealNetwork.h"

void AFortLauncherAthena::OnRep_ReplayLaunchInfo()
{
}

void AFortLauncherAthena::OnRep_ServerLaunchInfo()
{
}

void AFortLauncherAthena::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AFortLauncherAthena::ReTriggerForPawn(AFortPlayerPawnAthena* AthenaPawn)
{
}

void AFortLauncherAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLauncherAthena, ReplayLaunchInfo);
	DOREPLIFETIME(AFortLauncherAthena, ServerLaunchInfo);
}
