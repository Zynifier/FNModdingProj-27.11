// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortVehicleManager.generated.h"

class AActor;
class AFortAthenaVehicle;
class AFortVehicleManager;
class UFortVehicleItemDefinition;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleCountByTagChanged, FGameplayTag, VehicleTag, int32, NewVehicleCount);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVehicleSpawnsUpdated, UFortVehicleItemDefinition*, VehicleItemDef, TArray<AActor*>&, SpawnedVehicles, int32, NewVehicleCount);

UCLASS()
class AFortVehicleManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="VehicleManager")
	int32 GetVehicleCountByTag(FGameplayTag VehicleTag) const;

	UFUNCTION(BlueprintCallable, Category="VehicleManager", meta=(ExpandBoolAsExecs="ReturnValue", WorldContext="WorldContextObject"))
	static bool GetVehicleManager(const UObject* WorldContextObject, AFortVehicleManager*& VehicleManager);

	UPROPERTY(BlueprintAssignable)
	FOnVehicleCountByTagChanged OnVehicleCountByTagChanged;

private:
	UFUNCTION()
	void OnNavSystemLockReleased();

	UPROPERTY()
	TArray<TObjectPtr<AFortAthenaVehicle>> Vehicles;

	UPROPERTY()
	TMap<FGameplayTag, int32> VehicleCountByTagMap;

};

