// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "Subsystems/WorldSubsystem.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "FortWeaponModManager.generated.h"

class AActor;
class AFortPickup;
class AFortWeapon;
class AWeaponModManagerMeshActor;
class UFortWeaponModHISMComp;
class UFortWeaponModISMComp;
class UFortWeaponModItemDefinition;
class UFortWeaponPickupSpawnModData;
class UStaticMesh;
class UStaticMeshComponent;

USTRUCT()
struct FFortWeaponModManagerPickupInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPickup> Pickup;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponModItemDefinition> ModDefinition;

	UPROPERTY(Transient)
	FWeaponModStaticMeshData MeshData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponModHISMComp> HISMComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponModISMComp> ISMComp;

};

USTRUCT()
struct FFortWeaponModManagerWeaponInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> Weapon;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponModItemDefinition> ModDefinition;

	UPROPERTY(Transient)
	FWeaponModStaticMeshData MeshData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponModHISMComp> HISMComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponModISMComp> ISMComp;

};

USTRUCT()
struct FFortWeaponModTrackedPickupSMCompData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> PickupModMeshes;

};

UCLASS()
class AWeaponModManagerMeshActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<UStaticMesh*, UFortWeaponModHISMComp*> HISMComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<UStaticMesh*, UFortWeaponModISMComp*> ISMComponents;

};

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UFortWeaponModHISMComp : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UFortWeaponModISMComp : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortWeaponModManager : public UTickableWorldSubsystem
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleFortPickupEndPlay(AActor* Pickup, EEndPlayReason::Type Reason);

	UPROPERTY(Transient)
	TObjectPtr<AWeaponModManagerMeshActor> WorldMeshActor;

	UPROPERTY(Transient)
	TArray<FFortWeaponModManagerWeaponInstanceData> WeaponInstanceData;

	UPROPERTY(Transient)
	TArray<FFortWeaponModManagerPickupInstanceData> PickupInstanceData;

	UPROPERTY(Transient)
	TMap<AFortPickup*, FFortWeaponModTrackedPickupSMCompData> TrackedPickupSMComps;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponPickupSpawnModData> AutoApplyModDataAsset;

};

