// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AI/Components/FortAIComponent_Telemetry.h"
#include "RidingAnalytics.generated.h"

class URidableComponent;
class URiderComponent;

USTRUCT()
struct FRidingAnalyticsData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(Export)
	TSoftObjectPtr<URiderComponent> Rider;

	UPROPERTY(Export)
	TSoftObjectPtr<URidableComponent> Ridable;

};

USTRUCT()
struct FRidingAnalyticsData_Started : public FRidingAnalyticsData_Base
{
	GENERATED_BODY()

};

USTRUCT()
struct FRidingAnalyticsData_Stopped : public FRidingAnalyticsData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float TotalRidingTime;

	UPROPERTY()
	float RiderStartHealth;

	UPROPERTY()
	float RiderStartShield;

	UPROPERTY()
	float RiderEndHealth;

	UPROPERTY()
	float RiderEndShield;

	UPROPERTY()
	float TotalDistanceTraveled;

	UPROPERTY()
	int32 JumpUseCount;

	UPROPERTY()
	int32 AbilityUseCount;

	UPROPERTY()
	float RiderDamageDealt;

	UPROPERTY()
	float RiderDamageTaken;

	UPROPERTY()
	float RiderHealingReceived;

	UPROPERTY()
	float RiderShieldGained;

	UPROPERTY()
	uint8 bRidableEliminated : 1;

	UPROPERTY()
	uint8 bRidableExhausted : 1;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaPettingWildlifeTelemetryData : public UFortAthenaAITelemetryData
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnPetted();

private:
	UPROPERTY(Transient)
	int32 PetCount;

};

UCLASS()
class URidingAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

};

