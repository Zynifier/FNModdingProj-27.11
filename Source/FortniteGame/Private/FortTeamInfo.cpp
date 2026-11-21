// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTeamInfo.h"
#include "Net/UnrealNetwork.h"

int32 AFortTeamInfo::GetTeamExperience() const
{
	return int32();
}

int32 AFortTeamInfo::GetTeamLevel() const
{
	return int32();
}

void AFortTeamInfo::OnSpottedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortTeamInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTeamInfo, Team);
	DOREPLIFETIME(AFortTeamInfo, ChatRoomID);
	DOREPLIFETIME(AFortTeamInfo, TeamSpottedActors);
	DOREPLIFETIME(AFortTeamInfo, PrivateInfo);
}
