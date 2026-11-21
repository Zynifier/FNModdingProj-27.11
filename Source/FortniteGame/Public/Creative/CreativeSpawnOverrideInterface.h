// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CreativeSpawnOverrideInterface.generated.h"

class AFortAthenaAircraft;
class AFortPlayerController;
class AFortPlayerStateAthena;
enum class ECreativePlayerSpawnMethod : uint8;

UENUM(BlueprintType)
enum class ECreativePlayerSpawnMethod : uint8
{
	Spawner = 0,
	Rift = 1,
	Aircraft = 2,
};

UINTERFACE(MinimalAPI, BlueprintType)
class UCreativeSpawnOverrideInterface : public UInterface
{
	GENERATED_BODY()
};

class ICreativeSpawnOverrideInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AFortAthenaAircraft* GetAircraftForPlayer(const AFortPlayerController* InController) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetInitialStormRadius() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	ECreativePlayerSpawnMethod GetPlayerSpawnMethod() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsSpawningViaAircraft() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly)
	bool OverridePlayerSpawnLocationAndRotation(AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool ShouldSpawnAtFirstSafeZonePhaseLocation() const;

};

