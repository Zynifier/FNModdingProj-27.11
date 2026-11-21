// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Weapons/FortWeapon.h"
#include "Weapons/FortWeaponRangedForVehicle.h"
#include "FortWeaponRanged_Ostrich.generated.h"

class AFortProjectileBase;
class UAnimMontage;
class UFortGameplayAbility;
class USceneComponent;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRanged_Ostrich : public AFortWeaponRangedForVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	float GetAimPointCacheRange() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	int32 GetAmmoPerCharge() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	float GetAutofireDelay() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	float GetFireRate() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	int32 GetMaxRockets() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	int32 GetMinRocketsForFiring() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	float GetRocketsCooldown() const;

	UFUNCTION(BlueprintPure, Category="Gameplay|HotfixableVariables")
	float GetTimeToLoadOneAmmoCharge() const;

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void LoadShotgunAmmo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadedRockets(int32 NumRocketsLoaded);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnServerActivateSecondaryFire(UFortGameplayAbility* SecondaryFire, const FVector& LaunchPosition);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnServerLoadSingleRocket();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void PlayReloadAnim();

protected:
	UFUNCTION()
	void OnRep_RocketsCooldown();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRocketFired(USceneComponent* AttachToMesh, FName AttachToSocket);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRocketFiringStarted(USceneComponent* AttachToMesh, FName AttachToSocket);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRocketLauncherSettle(USceneComponent* AttachToMesh, FName AttachToSocket);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetCharging(bool bNewCharging);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetFiringRockets(bool bNewFiring, int32 NumToFire);

	UPROPERTY(EditAnywhere, Category="Gameplay")
	TSubclassOf<AFortProjectileBase> ProjectileTemplate;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RocketsCooldown)
	bool bRocketsOnCooldown;

	UPROPERTY(Transient)
	bool bLocalChargingRockets;

	UPROPERTY(Transient)
	bool bRocketFireButtonDown;

	UPROPERTY(Transient)
	int32 RocketAmmoLocal;

	UPROPERTY(Transient)
	int32 ServerLoadedRockets;

	UPROPERTY(Transient)
	bool bFiringRockets;

	UPROPERTY(Transient)
	bool bUseShotgunSecondBarrel;

	UPROPERTY(Transient)
	float RocketFireTimer;

	UPROPERTY(Transient)
	float RocketChargeTimer;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat FireRate;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat AutofireDelay;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat RocketsCooldown;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat TimeToLoadOneAmmoCharge;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat AimPointCacheRange;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat MinRocketsForFiring;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat AmmoPerCharge;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FScalableFloat MaxRockets;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FName SecondaryFireMuzzleName;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FName SecondaryFireTraceSocket;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FName ShotgunSecondBarrelMuzzleName;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	FName StartLoadingSectionName;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketChargingLoop;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketFullyChargedLoop;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketFire;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketFireSettle;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketCooldownLoop;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> RocketCooldownReady;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> ShotgunFireSecondBarrel;

	UPROPERTY(EditDefaultsOnly, Category="Weapon HUD Data")
	TArray<FWeaponHudData> GamepadHudKeyActionData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTagContainer LoadRocketTag;

	UPROPERTY(Transient)
	FTimerHandle AutoFireTimer;

	UPROPERTY(Transient)
	FTimerHandle ReloadShotgunTimer;

	UPROPERTY(Transient)
	FTimerHandle ServerSideRocketCooldownTimer;

};

