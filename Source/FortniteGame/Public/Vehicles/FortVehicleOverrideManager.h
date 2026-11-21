// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortVehicleOverrideManager.generated.h"

class AActor;
class AController;
class AFortAthenaVehicle;

USTRUCT(BlueprintType)
struct FFortVehicleOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ForwardValue;

	UPROPERTY()
	float RightValue;

	UPROPERTY()
	bool bHonk;

	UPROPERTY()
	bool bBoost;

};

USTRUCT()
struct FFortReplicatedVehicleOverrideData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAthenaVehicle> Vehicle;

	UPROPERTY()
	FFortVehicleOverrideData OverrideData;

};

USTRUCT()
struct FFortReplicatedVehicleOverrideDataContainer : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortReplicatedVehicleOverrideData> Overrides;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortVehicleOverrideManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortVehicleOverrideManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleVehicleDeath(AFortAthenaVehicle* DeadVehicle, const FGameplayTagContainer& InTags, AController* EventInstigator, AActor* DamageCauser);

	UPROPERTY(Replicated)
	FFortReplicatedVehicleOverrideDataContainer ReplicatedVehicleOverrides;

};

