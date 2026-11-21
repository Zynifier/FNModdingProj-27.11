// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapFloor_Turret.generated.h"

class AActor;
class ABuildingSMActor;
class AFortPawn;
class AFortPlayerPawn;
class UFortMinigameLogicComponent;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapFloor_Turret : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ActivateTurret();

	UFUNCTION(BlueprintCallable)
	void AddOverlapComponent(UPrimitiveComponent* OverlapComponent);

	UFUNCTION()
	void BindTimers();

	UFUNCTION(BlueprintCallable)
	void ConsumeAmmo();

	UFUNCTION()
	void DeactivateTurret();

	UFUNCTION(BlueprintCallable)
	void FinishReload();

	UFUNCTION(BlueprintCallable)
	AFortPlayerPawn* GetClosestTarget();

	UFUNCTION()
	AFortPawn* GetTarget();

	UFUNCTION(BlueprintCallable)
	void SetTarget(AFortPawn* NewTarget);

	UFUNCTION()
	void UnbindTimers();

	UPROPERTY(BlueprintReadWrite, Export, Category="BuildingTrapFloor_Turret", meta=(EditInline="true"))
	TObjectPtr<UFortMinigameLogicComponent> MinigameLogic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="TurretTrap", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> RotateComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="TurretTrap", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> FiringPoint;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> OverlapCollisionComponent;

	UPROPERTY(EditDefaultsOnly, Category="TurretTrap")
	float RotateInterval;

	UPROPERTY(BlueprintReadWrite, Category="BuildingTrapFloor_Turret")
	TArray<TObjectPtr<AFortPlayerPawn>> PlayerArray;

	UPROPERTY(BlueprintReadWrite, Category="BuildingTrapFloor_Turret")
	TObjectPtr<ABuildingSMActor> BlockingActor;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="BuildingTrapFloor_Turret")
	TObjectPtr<AFortPawn> Target;

	UPROPERTY(EditDefaultsOnly, Category="TargetSystem")
	float MinRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Category="TargetSystem")
	float MaxRotationSpeed;

	UPROPERTY(Transient, Replicated)
	float CurrentRotationalSpeed;

	UPROPERTY(EditDefaultsOnly, Category="TargetSystem")
	float UpdateIntervalTime;

	UPROPERTY(Transient)
	float CachedUpdateTime;

	UPROPERTY(EditDefaultsOnly, Category="TargetSystem")
	float IncreaseIntervalRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Category="TargetSystem")
	float DecreaseIntervalRotationSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentlyActive, Category="BuildingTrapFloor_Turret")
	uint8 bCurrentlyActive : 1;

	UPROPERTY(BlueprintReadWrite, Category="BuildingTrapFloor_Turret")
	uint8 bInSlowdownMode : 1;

	UPROPERTY(BlueprintReadWrite, Category="BuildingTrapFloor_Turret")
	uint8 bUseOwnerTeam : 1;

	UPROPERTY(EditDefaultsOnly, Category="Configurables")
	uint8 bCanTakeDamage : 1;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="BuildingTrapFloor_Turret")
	FVector ShootLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tags")
	FGameplayTag GTShoot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tags")
	FGameplayTag GTReload;

	UPROPERTY(EditDefaultsOnly, Category="Configurables")
	float Lifetime;

	UPROPERTY(EditDefaultsOnly, Category="Configurables")
	float FireRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Configurables")
	float ReloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Configurables")
	FVector BoxExtents;

protected:
	UPROPERTY(BlueprintReadWrite, Replicated, Category="BuildingTrapFloor_Turret")
	uint8 bIsSearching : 1;

private:
	UFUNCTION()
	void FireTurret();

	UFUNCTION()
	void MinigameEnded();

	UFUNCTION()
	void MinigameStarted();

	UFUNCTION()
	void OnEnterTurretRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaveTurretRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnRep_CurrentlyActive();

	UFUNCTION()
	void PerformGunRotation(const AFortPawn* TargetActor, const FVector& AimLocation, const FRotator& CurrentRotation, USceneComponent* RotateComponent);

	UFUNCTION()
	void RotateTurretClient();

	UFUNCTION()
	void RotateTurretServer();

	UPROPERTY(Transient)
	int32 CurrentAmmoCount;

	UPROPERTY(EditDefaultsOnly, Category="Configurables")
	int32 MaxAmmo;

};

