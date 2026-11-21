// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeploymentConsoleComponent.h"

FVector UDeploymentConsoleComponent::AdjustLocationToValidHeight(const FVector& RespawnLocation) const
{
	return FVector();
}

FRotator UDeploymentConsoleComponent::CalculateSpawnRotationFromLocation(const FVector& InSpawnLocation) const
{
	return FRotator();
}

void UDeploymentConsoleComponent::ClearFlightInfos() const
{
}

void UDeploymentConsoleComponent::ConstructInventoryOnController(AFortPlayerControllerAthena* InController)
{
}

void UDeploymentConsoleComponent::ForcePlayerEnterAircraft(AFortPlayerControllerAthena* InController, AFortAthenaAircraft* InAircraft)
{
}

const FBox2D& UDeploymentConsoleComponent::GetCachedAircraftSpawnZone() const
{
	static FBox2D Dummy;
	return Dummy;
}

FAircraftFlightConstructionInfo UDeploymentConsoleComponent::GetDefaultFlightPathConstructionInfo(const AFortGameStateAthena* GameStateAthena, const EAirCraftBehavior AircraftBehavior) const
{
	return FAircraftFlightConstructionInfo();
}

AFortAthenaMapInfo* UDeploymentConsoleComponent::GetMapInfo() const
{
	return nullptr;
}

TArray<uint8> UDeploymentConsoleComponent::GetMinigameTeamsWithPlayers(const AFortMinigame* InMinigame)
{
	return TArray<uint8>();
}

const TArray<FVector2D>& UDeploymentConsoleComponent::GetSpawnPoints() const
{
	static TArray<FVector2D> Dummy;
	return Dummy;
}

const TArray<FDeploymentConsoleTeamData>& UDeploymentConsoleComponent::GetTeamSpawnData() const
{
	static TArray<FDeploymentConsoleTeamData> Dummy;
	return Dummy;
}

void UDeploymentConsoleComponent::InitializeFlightPath(AFortGameStateAthena* GSA, const FAircraftFlightConstructionInfo& FlightPathConstructionInfo)
{
}

FBox2D UDeploymentConsoleComponent::MoveBoxTo(const FBox2D& InBox, const FVector2D& VectorToMoveTo)
{
	return FBox2D();
}

void UDeploymentConsoleComponent::ResetSpawnPoints()
{
}

FVector2D UDeploymentConsoleComponent::RetrievePlayerSpawnLocation(const bool bIsGameInProgress, const bool bGroupTeams, const uint8 InTeam)
{
	return FVector2D();
}

void UDeploymentConsoleComponent::SetAircraftDropZone(const FBox2D& InDropZone)
{
}

void UDeploymentConsoleComponent::SetAircraftLock(const bool bIsLocked)
{
}

void UDeploymentConsoleComponent::SetPlayerIsWaiting(AController* InController, const bool bInPlayerIsWaiting)
{
}

void UDeploymentConsoleComponent::SetupTeamSpawnPoints(const bool bGroupTeams)
{
}

AFortAthenaAircraft* UDeploymentConsoleComponent::SpawnAircraft(const int32 FlightIndex)
{
	return nullptr;
}

TArray<FDeploymentConsoleAircraftData> UDeploymentConsoleComponent::SpawnAircrafts(const bool bSpawnAircraftForEachTeam)
{
	return TArray<FDeploymentConsoleAircraftData>();
}
