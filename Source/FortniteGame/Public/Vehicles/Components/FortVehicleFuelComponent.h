// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortVehicleTypes.h"
#include "FortVehicleFuelComponent.generated.h"

class AFortAthenaVehicle;
class USoundBase;
class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFortAthenaVehicleFuelChanged, float, NewFuelPercent, float, OldFuelPercent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFortAthenaVehicleLowFuel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFortAthenaVehicleOutOfFuel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFortAthenaVehicleRefueledFromEmpty);

USTRUCT(BlueprintType)
struct FRuntimeFuelUsageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="RuntimeFuelUsageInfo")
	float FuelPerSecondIdle;

	UPROPERTY(BlueprintReadWrite, Category="RuntimeFuelUsageInfo")
	float FuelPerSecondDriving;

	UPROPERTY(BlueprintReadWrite, Category="RuntimeFuelUsageInfo")
	float FuelPerSecondBoosting;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent, DisplayName="Fuel Component"))
class UFortVehicleFuelComponent : public UActorComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetFuelCapacity() const;

	UFUNCTION(BlueprintPure)
	const FRuntimeFuelUsageInfo& GetFuelUsageInfo();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ReinitializeFuelUsageInfo();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFuel(const float NewFuel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFuelUsageInfo(const FRuntimeFuelUsageInfo& NewFuelUsageInfo);

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Fuel")
	FOnFortAthenaVehicleFuelChanged OnFuelChanged;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Fuel")
	FOnFortAthenaVehicleRefueledFromEmpty OnRefueledFromEmpty;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Fuel")
	FOnFortAthenaVehicleOutOfFuel OnOutOfFuel;

	UPROPERTY(BlueprintAssignable, Category="Vehicle|Fuel")
	FOnFortAthenaVehicleLowFuel OnLowFuel;

protected:
	UPROPERTY()
	TObjectPtr<AFortAthenaVehicle> OwnerVehicle;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerFuel)
	float ServerFuel;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Audio")
	TObjectPtr<USoundBase> OutOfFuelSound;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Audio")
	TObjectPtr<USoundBase> LowFuelSound;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Audio")
	TObjectPtr<USoundBase> LowFuelRepeatingPing;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat UsesFuelSystem;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat InitializeWithStartingFuel;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat FuelTankCapacity;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat FuelPerSecondIdle;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat FuelPerSecondDriving;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat FuelPerSecondBoosting;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat MinFuelAtSpawn;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat MaxFuelAtSpawn;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat InfiniteFuel;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat LowFuelRepeatingPingDelay;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|Settings")
	FScalableFloat LowFuelPercent;

	UPROPERTY(EditAnywhere, Category="Fuel|UI")
	TArray<FVehicleSpecificUIDetails> CustomFuelUI;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|UI")
	FText FuelSubText;

	UPROPERTY(EditDefaultsOnly, Category="Fuel|UI")
	TSoftObjectPtr<UTexture2D> FuelSubTextImage;

private:
	UFUNCTION()
	void OnRep_ServerFuel(float PreviousFuel);

};

