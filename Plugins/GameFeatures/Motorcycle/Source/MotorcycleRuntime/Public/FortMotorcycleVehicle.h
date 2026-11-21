// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaSKMotorVehicle.h"
#include "Vehicles/Components/FortVehicleSeatComponent.h"
#include "FortMotorcycleVehicle.generated.h"

class AFortWeapon;
class UFortCameraMode;
class UFortCameraMode_AthenaVehicle;
class UFortMotorcycleVehicleConfigs;
class ULegacyCameraShake;
class UNiagaraComponent;
enum class EFortMotorcycleAirTrickType : uint8;

UENUM(BlueprintType)
enum class EFortMotorcycleAirTrickType : uint8
{
	None = 0,
	Default = 1,
	Left = 2,
	Right = 3,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class MOTORCYCLERUNTIME_API AFortMotorcycleVehicle : public AFortAthenaSKMotorVehicle
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMotorcycleAirTrick);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMotorcycleChargingJump);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMotorcycleInventoryMode, const bool, IsInInventoryMode);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMotorcycleJump, const float, JumpChargeFactor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMotorcycleStartAirTrick, const EFortMotorcycleAirTrickType, TrickType);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMotorcycleStoppie);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMotorcycleSuperSlidingChanged, const bool, bIsSuperSliding);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMotorcycleWheelie);

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Cancel Charging Jump"))
	void BP_OnCancelChargingJump();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Charging Jump"))
	void BP_OnChargingJump(const float JumpChargeFactor);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Wheelie Failed"))
	void BP_OnFailWheelie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Finish Air Trick"))
	void BP_OnFinishAirTrick();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Jump"))
	void BP_OnJump(const float JumpChargeFactor);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Stoppie Landed"))
	void BP_OnLandStoppie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Wheelie Landed"))
	void BP_OnLandWheelie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Stoppie Released"))
	void BP_OnReleaseStoppie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Wheelie Released"))
	void BP_OnReleaseWheelie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Start Air Trick"))
	void BP_OnStartAirTrick(const EFortMotorcycleAirTrickType TrickType);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Start Charging Jump"))
	void BP_OnStartChargingJump();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Stoppie Started"))
	void BP_OnStartStoppie();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Wheelie Started"))
	void BP_OnStartWheelie();

	UFUNCTION(BlueprintCallable)
	void ChangeBoostAttackState(const bool bNewIsBoostAttacking);

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	FVector GetAverageSpringNormal() const;

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	float GetLeanAngleDegrees() const;

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	EPhysicalSurface GetSurfaceTypeVehicleOn() const;

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	bool IsInInventoryMode() const;

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	bool IsPowerSliding() const;

	UFUNCTION(BlueprintPure, Category="Motorcycle")
	bool IsSuperSliding() const;

	UFUNCTION()
	void OnPlayerWeaponChanged(AFortWeapon* InNewWeapon, AFortWeapon* InPrevWeapon);

	UFUNCTION(Server, Reliable)
	void ServerEjectAllPlayers();

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleChargingJump OnStartChargingJumpDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleChargingJump OnCancelChargingJumpDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleJump OnJumpDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleJump OnChargingJumpDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleStartAirTrick OnStartAirTrickDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleAirTrick OnFinishAirTrickDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleWheelie OnStartWheelieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleWheelie OnReleaseWheelieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleWheelie OnLandWheelieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleWheelie OnFailWheelieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleStoppie OnStartStoppieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleStoppie OnReleaseStoppieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleStoppie OnLandStoppieDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleInventoryMode OnInventoryModeChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Motorcycle")
	FMotorcycleSuperSlidingChanged OnSuperSlidingChangedDelegate;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> InventoryCameraModeClass;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> InventoryCameraModeClassADS;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> PassengerCameraModeClass;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TSubclassOf<UFortCameraMode> PassengerCameraModeClassADS;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	TObjectPtr<UFortMotorcycleVehicleConfigs> FortMotorcycleVehicleConfigs;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	FName RearAxleSocket;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle")
	TArray<FActionDefForUI> ActionDefForUI;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float SwingArmRotation;

protected:
	UFUNCTION()
	void OnRep_IsBoostAttacking();

	UPROPERTY(Transient, Replicated)
	TArray<int32> BoostShapeIndices;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsBoostAttacking)
	bool bIsBoostAttacking;

	UPROPERTY(Transient)
	EFortMotorcycleAirTrickType CachedTrickType;

	UPROPERTY(Transient)
	bool bHadPassengerAtTrickStart;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TArray<FName> PassengerADSSockets;

	UPROPERTY(EditAnywhere, Category="Motorcycle")
	TArray<FVector> PassengerADSRelativeOffsets;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> CachedNiagaraComponentRoadAndExhaust;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FString RoadAndExhaustNiagaraComponentName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustVehicleSpeedName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustSlideDirectionName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	float RoadAndExhaustMinSpeedForDust;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustDustRearName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustDustColorLerpName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	float RoadAndExhaustDustColorLerp;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustDustAlphaMultiplierName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	float RoadAndExhaustDustAlphaMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustPeelOutColorIndexName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustPeelOutRearName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustIsPeelOutOnRoadName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustIsPeelOutOnRoadRewindName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FName RoadAndExhaustIsInAirName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FGameplayTag RoadAndExhaustCameraDirtGameplayCueTag;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	FGameplayTag RoadAndExhaustCameraWaterGameplayCueTag;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Niagara")
	TArray<TEnumAsByte<EPhysicalSurface>> RoadAndExhaustSurfaceTypeArrayForFX;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> DriverCameraShakeInstance;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> AcceleratingCameraShakeInstance;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Materials")
	FName RoadAndExhaustHeadlightsName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Road And Exhaust|Materials")
	FName RoadAndExhaustBrakelightsName;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashMinSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashForwardDistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashForwardDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FGameplayTag DoorBashGameplayCueTag;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	TArray<TEnumAsByte<EObjectTypeQuery>> DoorBashCollisionTypesForDoor;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	TArray<TEnumAsByte<EObjectTypeQuery>> DoorBashCollisionTypesForPawn;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashSphereRadiusForPawnLaunch;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FScalableFloat DoorBashScalarForPawnLaunch;

	UPROPERTY(EditDefaultsOnly, Category="Motorcycle|Door Bash")
	FGameplayTag DoorBashPawnLaunchGameplayCueTag;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Motorcycle|Inventory Mode")
	FGameplayTagQuery InventoryModeTagQuery;

	UPROPERTY(EditDefaultsOnly, Transient, Category="FortMotorcycleVehicle")
	FGameplayTagContainer InputContextBlockedTags;

private:
	UPROPERTY(EditAnywhere, Category="Mobile HUD")
	FGameplayTag MobileHUDTag;

};

