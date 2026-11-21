// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "Engine/DataAsset.h"
#include "ScalableFloat.h"
#include "FortSpawnActorInfo.generated.h"

class AFortLevelSpawnActor;

UENUM(BlueprintType)
enum class EFortSpawnActorTime : uint8
{
	// immediately after the playlist is loaded

	PostPlaylistLoad = 0,
	// at the start of the hold time of the storm

	StartOfStormHoldTime = 1,
};

UCLASS()
class UFortSpawnActorInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FName SpawnActorID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	TSubclassOf<AFortLevelSpawnActor> SpawnActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FCollisionProfileName CollisionProfile;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	EFortSpawnActorTime SpawnTiming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat SafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat SpawnAtSafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat DelayBetweenSpawns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat MinActorsToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat MaxActorsToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat MinSpawnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSpawnActorInfo")
	FScalableFloat MaxSpawnHeight;

};

