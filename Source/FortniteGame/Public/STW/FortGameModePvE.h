// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "FortGameModeZone.h"
#include "FortGameModePvE.generated.h"

class AActor;
class ABuildingContainer;
class AFortAircraft;
enum class EFortIdleDetectionState : uint8;

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModePvE : public AFortGameModeZone
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddAllowIdlePlayerLocation(AActor* LocationActor, float Radius);

	UFUNCTION(BlueprintCallable)
	void RemoveAllowIdlePlayerLocation(AActor* LocationActor);

	UFUNCTION(BlueprintCallable)
	void SetIdleDetectionMaxIdleTime(EFortIdleDetectionState IdleState, float InMaxIdleTime);

	UFUNCTION(BlueprintCallable)
	void SetIdleDetectionMinIdleTime(EFortIdleDetectionState IdleState, float InMinIdleTime);

	UFUNCTION(BlueprintCallable)
	void SetIdleDetectionMovementDistance(EFortIdleDetectionState IdleState, float InMovementDistance);

	UFUNCTION(BlueprintCallable)
	void SetIdleDetectionPenaltyTime(float InPenaltyTime);

	UFUNCTION(BlueprintCallable)
	void SetIdleDetectionScoreThreshold(EFortIdleDetectionState IdleState, int32 InScoreThreshold);

	UFUNCTION(BlueprintCallable)
	void SetIdleKickEnabled(bool bEnabled);

	UPROPERTY(Config)
	bool bIdleKickEnabledByConfig;

	UPROPERTY()
	bool bIdleKickEnabledByBlueprint;

	UPROPERTY(Config)
	bool bOnlyIdleKickPublicMatches;

	UPROPERTY(Config)
	bool bResetDefaultIdleTimeWhenNoLongerSolo;

	UPROPERTY(Config)
	bool bAnyMovementNotIdleWhilePrivate;

	UPROPERTY(Config)
	bool bRestrictMaxIdleTime;

	UPROPERTY(Config)
	float RestrictedMaxIdleTime;

	UPROPERTY(Config)
	bool bSendIdleAnalytics;

	UPROPERTY(EditDefaultsOnly, Category="FortGameModePvE")
	bool bWaitForAircraft;

	UPROPERTY(EditDefaultsOnly, Category="FortGameModePvE")
	bool bBuildingContainersStartAlreadySearched;

	UPROPERTY(EditDefaultsOnly, Category="FortGameModePvE")
	bool bSpawnLootForBuildingContainersThatStartAlreadySearched;

	UPROPERTY(EditDefaultsOnly, Category="FortGameModePvE")
	TArray<TSubclassOf<ABuildingContainer>> BuildingContainersThatRequireSearching;

protected:
	UFUNCTION()
	void HandleOnAircraftRegistered(const AFortAircraft* InAircraft);

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bSpawnWeaponsWithMaxPerks : 1;

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bSpawnTrapsWithMaxPerks : 1;

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bUseHighPerkSlotValues : 1;

private:
	UPROPERTY(Config)
	bool bEnableBigBenPvE;

	UPROPERTY(Config)
	FDateTime BigBenPvE;

	UPROPERTY(Config)
	float BigBenPvEAdjust;

};

