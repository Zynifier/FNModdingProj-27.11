// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaMapInfo.h"
#include "DeploymentConsoleComponent.generated.h"

class AController;
class AFortAthenaAircraft;
class AFortAthenaMapInfo;
class AFortGameStateAthena;
class AFortMinigame;
class AFortPlayerControllerAthena;
enum class EAirCraftBehavior : uint8;

USTRUCT(BlueprintType)
struct FDeploymentConsoleAircraftData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DeploymentConsoleAircraftData")
	uint8 Team;

	UPROPERTY(BlueprintReadWrite, Category="DeploymentConsoleAircraftData")
	TObjectPtr<AFortAthenaAircraft> Aircraft;

};

USTRUCT(BlueprintType)
struct FDeploymentConsoleTeamData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DeploymentConsoleTeamData")
	uint8 Team;

	UPROPERTY(BlueprintReadWrite, Category="DeploymentConsoleTeamData")
	TArray<FVector2D> SpawnLocations;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class DEPLOYMENTCONSOLE_API UDeploymentConsoleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FVector AdjustLocationToValidHeight(const FVector& RespawnLocation) const;

	UFUNCTION(BlueprintPure)
	FRotator CalculateSpawnRotationFromLocation(const FVector& InSpawnLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	void ClearFlightInfos() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ConstructInventoryOnController(AFortPlayerControllerAthena* InController);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static void ForcePlayerEnterAircraft(AFortPlayerControllerAthena* InController, AFortAthenaAircraft* InAircraft);

	UFUNCTION(BlueprintPure)
	const FBox2D& GetCachedAircraftSpawnZone() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FAircraftFlightConstructionInfo GetDefaultFlightPathConstructionInfo(const AFortGameStateAthena* GameStateAthena, const EAirCraftBehavior AircraftBehavior) const;

	UFUNCTION(BlueprintPure)
	AFortAthenaMapInfo* GetMapInfo() const;

	UFUNCTION(BlueprintPure)
	static TArray<uint8> GetMinigameTeamsWithPlayers(const AFortMinigame* InMinigame);

	UFUNCTION(BlueprintPure)
	const TArray<FVector2D>& GetSpawnPoints() const;

	UFUNCTION(BlueprintPure)
	const TArray<FDeploymentConsoleTeamData>& GetTeamSpawnData() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void InitializeFlightPath(AFortGameStateAthena* GSA, const FAircraftFlightConstructionInfo& FlightPathConstructionInfo);

	UFUNCTION(BlueprintPure)
	static FBox2D MoveBoxTo(const FBox2D& InBox, const FVector2D& VectorToMoveTo);

	UFUNCTION(BlueprintCallable)
	void ResetSpawnPoints();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FVector2D RetrievePlayerSpawnLocation(const bool bIsGameInProgress, const bool bGroupTeams, const uint8 InTeam);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetAircraftDropZone(const FBox2D& InDropZone);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetAircraftLock(const bool bIsLocked);

	UFUNCTION(BlueprintCallable)
	void SetPlayerIsWaiting(AController* InController, const bool bInPlayerIsWaiting);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetupTeamSpawnPoints(const bool bGroupTeams);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AFortAthenaAircraft* SpawnAircraft(const int32 FlightIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	TArray<FDeploymentConsoleAircraftData> SpawnAircrafts(const bool bSpawnAircraftForEachTeam);

protected:
	UPROPERTY(BlueprintReadWrite, Category="DeploymentConsoleComponent")
	TArray<FDeploymentConsoleAircraftData> Aircrafts;

	UPROPERTY(EditDefaultsOnly, Category="SpawnParams")
	FScalableFloat RadiusPercentForRespawnMin;

	UPROPERTY(EditDefaultsOnly, Category="SpawnParams")
	FScalableFloat RadiusPercentForRespawnMax;

	UPROPERTY(EditDefaultsOnly, Category="SpawnParams")
	FScalableFloat MaxRespawnRadius;

	UPROPERTY(EditDefaultsOnly, Category="SpawnParams")
	FScalableFloat TeamMemberSpread;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GroundCheck")
	FScalableFloat TraceForGroundStart;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GroundCheck")
	FScalableFloat TraceForGroundEnd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GroundCheck")
	FScalableFloat MinHeightFromGround;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GroundCheck")
	FScalableFloat MinHeightFromZero;

	UPROPERTY(Transient)
	TArray<FVector2D> SpawnPoints;

	UPROPERTY(Transient)
	TArray<FDeploymentConsoleTeamData> TeamSpawnData;

};

