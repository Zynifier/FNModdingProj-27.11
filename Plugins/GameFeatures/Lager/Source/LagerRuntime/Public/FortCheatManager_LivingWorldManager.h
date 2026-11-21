// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_LivingWorldManager.generated.h"

UCLASS()
class UFortCheatManager_LivingWorldManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void LivingWorldManagerDisplaySpawnPoints(float MaxDisplayDistance = 50000.000000f);

	UFUNCTION(Exec)
	void LivingWorldManagerGDTNextDensityGrid();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerSpawn(const FString& EventDataName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerSpawnAtLocation(const FString& EventDataName = TEXT(""), FVector Location = FVector(0.000000, 0.000000, 0.000000), FRotator Rotation = FRotator(0.000000, 0.000000, 0.000000));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerSpawnEvent(const FString& EventDataName = TEXT(""), const FString& SpawnerDataNames = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerSpawnEventAtLocation(const FString& EventDataName = TEXT(""), FVector Location = FVector(0.000000, 0.000000, 0.000000), FRotator Rotation = FRotator(0.000000, 0.000000, 0.000000), const FString& SpawnerDataNames = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerTeleportTo(const FString& EventDataName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerTeleportToSpawnPosition(const FString& EventDataName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerTriggerEvent(const FString& EventDataName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LWMS(const FString& EventDataName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LWMSE(const FString& EventDataName = TEXT(""), const FString& SpawnerDataNames = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LWMTE(const FString& EventDataName = TEXT(""));

private:
	UPROPERTY(Transient)
	int32 CheatTeleportToCount;

	UPROPERTY(Transient)
	FString CheatTeleportLastEventDataName;

	UPROPERTY(Transient)
	int32 CheatSpawnEventCount;

	UPROPERTY(Transient)
	FString CheatSpawnEventName;

	UPROPERTY(Transient)
	int32 CheatTriggerEventCount;

	UPROPERTY(Transient)
	FString CheatTriggerEventName;

};

