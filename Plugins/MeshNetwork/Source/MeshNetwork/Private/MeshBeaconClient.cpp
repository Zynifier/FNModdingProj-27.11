// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshBeaconClient.h"
#include "Net/UnrealNetwork.h"

void AMeshBeaconClient::OnRep_ConnectedToRoot()
{
}

void AMeshBeaconClient::OnRep_MeshPingTime()
{
}

void AMeshBeaconClient::OnRep_ParentIds()
{
}

void AMeshBeaconClient::ServerSetClientId_Implementation(const FString& NewClientId)
{
}
bool AMeshBeaconClient::ServerSetClientId_Validate(const FString& NewClientId)
{
	return true;
}

void AMeshBeaconClient::ServerUpdateLevelVisibility_Implementation(const FUpdateLevelVisibilityLevelInfo& LevelVisibility)
{
}
bool AMeshBeaconClient::ServerUpdateLevelVisibility_Validate(const FUpdateLevelVisibilityLevelInfo& LevelVisibility)
{
	return true;
}

void AMeshBeaconClient::ServerUpdateMultipleLevelsVisibility_Implementation(const TArray<FUpdateLevelVisibilityLevelInfo>& LevelVisibilities)
{
}
bool AMeshBeaconClient::ServerUpdateMultipleLevelsVisibility_Validate(const TArray<FUpdateLevelVisibilityLevelInfo>& LevelVisibilities)
{
	return true;
}

void AMeshBeaconClient::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMeshBeaconClient, bConnectedToRoot);
	DOREPLIFETIME(AMeshBeaconClient, MeshPingTime);
	DOREPLIFETIME(AMeshBeaconClient, ParentIds);
}
