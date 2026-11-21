// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Building/BuildingGameplayActorSpawnMachine.h"
#include "Building/SpawnMachineEnabledConfig.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_Reboot.generated.h"

class ABuildingGameplayActorSpawnMachine;
class AFortPlayerPawn;
class UFortGameStateComponent_Reboot;

USTRUCT()
struct FSpawnMachineRepData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	ESpawnMachineState SpawnMachineState;

	UPROPERTY()
	float SpawnMachineCooldownStartTime;

	UPROPERTY()
	float SpawnMachineCooldownEndTime;

	UPROPERTY()
	int32 SpawnMachineRepDataHandle;

	UPROPERTY()
	FSpawnMachineEnabledConfig EnabledConfig;

};

USTRUCT()
struct FSpawnMachineRepDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FSpawnMachineRepData> SpawnMachineRepDataArray;

	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_Reboot> OwningComponent;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortGameStateComponent_Reboot : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Resurrection")
	virtual bool IsResurrectionEnabled(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetSpawnMachineEnabledConfig(const ABuildingGameplayActorSpawnMachine* RebootVan, const FSpawnMachineEnabledConfig& EnabledConfig);

private:
	UPROPERTY(Transient, Replicated)
	FSpawnMachineRepDataArray SpawnMachineRepData;

};

