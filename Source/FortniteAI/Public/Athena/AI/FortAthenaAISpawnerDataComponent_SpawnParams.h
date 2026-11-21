// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "Engine/DataTable.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_SpawnParamsBase.h"
#include "FortAthenaAISpawnerDataComponent_SpawnParams.generated.h"

class AAIController;
class APawn;
class UFortAthenaAISpawnerData;

UCLASS()
class UFortAthenaAISpawnerDataComponent_SpawnParams : public UFortAthenaAISpawnerDataComponent_SpawnParamsBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Pawn", meta=(AllowPrivateAccess="true"))
	TSubclassOf<APawn> PawnClass;

	UPROPERTY(EditDefaultsOnly, Category="Pawn", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category="Pawn", meta=(AllowPrivateAccess="true"))
	FDataTableRowHandle PawnStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="Pawn", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAISpawnerData>> SpawnerDataSpawnedAsChildren;

	UPROPERTY(EditDefaultsOnly, Category="Collision Check", meta=(AllowPrivateAccess="true", EditCondition="!bSpawnInAir && !bCheckForOverlaps"))
	FCollisionProfileName GroundTraceCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Category="Collision Check|In-Air Spawning", meta=(AllowPrivateAccess="true", EditCondition="bSpawnInAir && bCheckForOverlaps"))
	float InAirSpawnTraceStartHeight;

	UPROPERTY(EditDefaultsOnly, Category="Collision Check|In-Air Spawning", meta=(AllowPrivateAccess="true", EditCondition="bSpawnInAir && bCheckForOverlaps"))
	float InAirSpawnTraceEndHeight;

	UPROPERTY(EditDefaultsOnly, Category="Collision Check|In-Air Spawning", meta=(AllowPrivateAccess="true", EditCondition="bSpawnInAir && bCheckForOverlaps"))
	float InAirSpawnTraceSphereRadius;

	UPROPERTY(EditDefaultsOnly, Category="Collision Check", meta=(AllowPrivateAccess="true"))
	float SpawnTracePadding;

	UPROPERTY(EditAnywhere, Category="Collision Check", meta=(AllowPrivateAccess="true"))
	uint8 bCheckForOverlaps : 1;

	UPROPERTY(EditAnywhere, Category="POI Location", meta=(AllowPrivateAccess="true"))
	uint8 bAddPOILocationTagsOnSpawn : 1;

	UPROPERTY(EditDefaultsOnly, Category="In-Air Spawning", meta=(AllowPrivateAccess="true"))
	uint8 bSpawnInAir : 1;

	UPROPERTY(EditDefaultsOnly, Category="In-Air Spawning", meta=(AllowPrivateAccess="true", EditCondition="bSpawnInAir"))
	uint8 bSetSkyDivingFromBus : 1;

	UPROPERTY(EditAnywhere, Category="Pawn", meta=(AllowPrivateAccess="true"))
	uint8 bSetPlayerPawnAttributesWithThisStatHandle : 1;

};

