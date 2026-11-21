// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortOctopusVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortOctopusVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MinBuildingDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MaxBuildingDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MinBuildingDamageSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MaxBuildingDamageSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MinBuildingDamageWhileBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MaxBuildingDamageWhileBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MinBuildingDamageSpeedWhileBoostingKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float MaxBuildingDamageSpeedWhileBoostingKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Towhook")
	FName TowhookMuzzleSocketName;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float TowhookNetUpdateTime;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float WaterTraction;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float BoostBounceRechargeFalloff;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinSpeedToLaunchPlayersKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinYankLaunchForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxYankLaunchForce;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MinYankLaunchVelocityKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float MaxYankLaunchVelocityKmh;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	int32 MaxSignificanceBudgetForFX;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	int32 MaxSignificanceBudgetForAudio;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	uint8 bDisableFXWhenInsignificant : 1;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	uint8 bDisableAudioTickWhenInsignificant : 1;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	uint8 bGlassIsPenetrable : 1;

};

