// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Vehicles/Components/FortVehicleSeatComponent.h"
#include "Weapons/FortCachedWeaponOverheatData.h"
#include "FortVehicleSeatWeaponComponent.generated.h"

class AActor;
class AFortPawn;
class AFortWeaponRanged;
class UFortVehicleDynamicReticleWidgetComponent;
class UFortWeaponItemDefinition;
class UFortWeaponRangedItemDefinition;
class USkeletalMeshComponent;
enum class EFortWeaponOverheatState : uint8;

USTRUCT()
struct FVehicleWeapon_RetainedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 AmmoInClip;

	UPROPERTY()
	float LastFireTime;

	UPROPERTY()
	bool bHasPrevious;

};

USTRUCT(BlueprintType)
struct FWeaponSeatDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeaponSeatDefinition")
	int32 SeatIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponSeatDefinition")
	TObjectPtr<UFortWeaponItemDefinition> VehicleWeapon;

	UPROPERTY(EditAnywhere, Category="Input")
	TArray<FActionDefForUI> WeaponActionDefForUI;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponItemDefinition> VehicleWeaponOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponItemDefinition> LastEquippedVehicleWeapon;

	UPROPERTY(EditDefaultsOnly, Category="WeaponSeatDefinition")
	bool bSendReplicatedTargetingEvent;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortVehicleSeatWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquipMountedWeapon, AFortWeaponRanged*, EquippedMountedWeapon);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOverheatStateChanged, EFortWeaponOverheatState, OverheatState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeatedPlayerTargetingChangedDelegate, const bool, bIsTargeting);

public:
	UFUNCTION(BlueprintCallable, Category="VehicleWeapon")
	void EquipVehicleWeapon(AFortPawn* FortPawn, FWeaponSeatDefinition& WeaponSeatDefinition, int32 ItemLevel = 0);

	UFUNCTION(BlueprintPure, Category="Overheat")
	float GetCurrentOverheatValue() const;

	UFUNCTION(BlueprintPure)
	const FVector GetDynamicReticleLocation() const;

	UFUNCTION(BlueprintPure, Category="Overheat")
	float GetOverheatingMaxValue() const;

	UFUNCTION(BlueprintPure, Category="MountedWeapon")
	AActor* GetVehicle() const;

	UFUNCTION(BlueprintImplementableEvent, Category="MountedWeapon")
	void OnMountedWeaponFired(const int32 SeatIdx, int32 ShotsRemaining);

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	TArray<FName> MuzzleSocketNames;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	TArray<FWeaponSeatDefinition> WeaponSeatDefinitions;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	int32 ActiveSeatIdx;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleSeatWeaponComponent")
	TObjectPtr<UFortWeaponRangedItemDefinition> CachedWeaponDef;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleSeatWeaponComponent")
	float CachedOverheatMax;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleSeatWeaponComponent")
	float CachedOverheatValue;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_OverheatValueRepped, Category="FortVehicleSeatWeaponComponent")
	float OverheatValueRepped;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortVehicleSeatWeaponComponent")
	bool bWeaponEquipped;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortVehicleSeatWeaponComponent")
	bool bUseVehicleOrientationForShootingCone;

	UPROPERTY(EditAnywhere, Category="AimingAndCamera")
	bool bControlledByMultipleSeats;

	UPROPERTY(EditAnywhere, Category="AimingAndCamera")
	bool bUseWeaponCameraMode;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortVehicleSeatWeaponComponent")
	TObjectPtr<AActor> ActorBase;

	UPROPERTY(Transient)
	bool bReadyToSleep;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MountedWeapon")
	FScalableFloat TotalShotsAllowedThenShutdown;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ShotsFired, Category="MountedWeapon")
	int32 ShotsFired;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnSeatedPlayerTargetingChangedDelegate OnSeatedPlayerTargetingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnOverheatStateChanged OnOverheatStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnEquipMountedWeapon OnEquipMountedWeapon;

protected:
	UFUNCTION(BlueprintPure)
	float GetOverheatScaler() const;

	UFUNCTION(BlueprintPure)
	float GetOverheatTime() const;

	UFUNCTION()
	void OnRep_OverheatValueRepped();

	UFUNCTION()
	void OnRep_ShotsFired();

	UPROPERTY(EditDefaultsOnly, Category="Replicaton")
	bool bSeatUsesFastSharedReplication;

	UPROPERTY(Transient, Replicated)
	bool bWeaponOverheatDataHasBeenCached;

	UPROPERTY(Replicated)
	FFortCachedWeaponOverheatData CachedWeaponOverheatData;

	UPROPERTY(Replicated)
	FVehicleWeapon_RetainedData CachedWeaponState;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	bool bSaveAndRestoreWeaponData;

	UPROPERTY(BlueprintReadOnly, Export, Category="MountedWeapon", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> WeaponSklMeshComponent;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	FName VehicleSocketName;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	FName VehiclePawnAttachSocketName;

	UPROPERTY(EditAnywhere, Category="MountedWeapon")
	float AttachmentAngleOffsetYaw;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleDynamicReticleWidgetComponent> DynamicReticleWidgetComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleSeatWeaponComponent")
	TWeakObjectPtr<AFortWeaponRanged> CachedWeapon;

};

