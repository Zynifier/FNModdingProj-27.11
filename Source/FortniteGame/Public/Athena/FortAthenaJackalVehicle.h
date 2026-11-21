// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortAthenaJackalVehicle.generated.h"

class AActor;
class AFortPlayerPawn;
class UAnimInstance;
class UAudioComponent;
class UFortAthenaJackalVehicleConfigs;
class UFortCameraMode_AthenaVehicle;
class UFortVehicleAudioVoice;
class UMaterialInstanceDynamic;
class UParticleSystemComponent;

USTRUCT()
struct FJackalInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAthenaJackalVehicleConfigs> FortJackalVehicleConfigs;

	UPROPERTY(Transient)
	bool bBoosting;

	UPROPERTY(Transient)
	float PendingJumpCharge;

	UPROPERTY(Transient)
	float FrontLateralFrictionRuntimeMultiplier;

	UPROPERTY(Transient)
	float PushForceCurrentMultiplier;

};

USTRUCT()
struct FJackalOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FJackalOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bShouldCorrectYaw;

	UPROPERTY(Transient)
	bool bShouldOverrideWaterSpringParams;

	UPROPERTY(Transient)
	float SpringLength;

	UPROPERTY(Transient)
	float SpringStiff;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaJackalVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioBoost, UFortVehicleAudioVoice* InAudioWind);

	UFUNCTION(BlueprintCallable)
	void CacheFX(UParticleSystemComponent* InBoostFX, UParticleSystemComponent* InLoopingFX);

	UFUNCTION(BlueprintPure)
	bool CanActivateBoost() const;

	UFUNCTION(BlueprintPure)
	bool CanBoost() const;

	UFUNCTION(BlueprintPure)
	bool CanChargeJump() const;

	UFUNCTION(BlueprintPure)
	bool CanJump() const;

	UFUNCTION(BlueprintPure)
	int32 GetBoostCandidateIndex() const;

	UFUNCTION(BlueprintCallable)
	FFortRechargingActionTimer GetCurrentBoostTimer();

	UFUNCTION(BlueprintPure)
	bool GetSpringHitLocation(int32 SpringIndex, FVector& HitLocation) const;

	UFUNCTION(BlueprintPure)
	bool IsDriveModeOnly() const;

	UFUNCTION()
	void NativeOnBoostBegin();

	UFUNCTION()
	void NativeOnBoostEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostEnd();

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnDriveModeChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnJumpChargeBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnJumpChargeEnd(float Charge);

	UFUNCTION(BlueprintImplementableEvent)
	void OnJumped(float Charge);

	UFUNCTION()
	void OnWeaponUnholstered();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortAthenaJackalVehicleConfigs> FortJackalVehicleConfigs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle")
	int32 NumBoostTimers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	TArray<FFortRechargingActionTimer> BoostTimers;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FGameplayTagContainer AbortSprintPlayerTags;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FGameplayTagContainer PreventBoostPlayerTags;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> SprintCameraModeClass;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> BoostCameraModeClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float JumpCharge;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Vehicle")
	float JumpCooldownRemaining;

	UPROPERTY(Transient)
	float PendingJumpCharge;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheBoostFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheLoopingFX;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BoostMID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioMovement;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioBoost;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWind;

	UPROPERTY(Transient)
	FVector FrontSpringFXOffset;

	UPROPERTY(Transient)
	FVector RearSpringFXOffset;

	UPROPERTY(Transient)
	FVector FXBoostEnd;

	UPROPERTY(Transient)
	bool bEmoteRequiresWeapon;

protected:
	UPROPERTY(Transient)
	bool bShouldCorrectYaw;

private:
	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void CheckWater(float WaterLocationZ, UParticleSystemComponent* WaterFX, UAudioComponent* WaterAudio);

	UFUNCTION()
	void OnHeldObjectDropped(AActor* HeldObject);

	UFUNCTION()
	void OnHeldObjectPickedUp(AActor* HeldObject);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UAnimInstance> BoostingAnimClass;

};

