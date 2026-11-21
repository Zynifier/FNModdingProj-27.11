// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/FortOctopusVehicle.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortSphericalDriveModel.h"
#include "Athena/Vehicle/FortTowhookModel.h"
#include "FortSpaghettiVehicle.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortSpaghettiTowhookAttachableProjectile;
class UFortSpaghettiVehicleConfigs;
class UFortVehicleAudioVoice;
class ULegacyCameraShake;
class UParticleSystemComponent;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortSpaghettiVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AimTraceHitsTarget() const;

	UFUNCTION(BlueprintCallable)
	void BreakTowhook();

	UFUNCTION(BlueprintPure)
	float GetAccelerationPercent() const;

	UFUNCTION(BlueprintCallable)
	bool GetIsExtendToggled();

	UFUNCTION(BlueprintPure)
	void GetPrimaryContact(bool& bIstouching, FVector& ContactPoint, FVector& ContactNormal) const;

	UFUNCTION(BlueprintPure)
	FVector GetSeatForwardDir() const;

	UFUNCTION(BlueprintPure)
	FRotator GetSeatRotation() const;

	UFUNCTION(BlueprintPure)
	FVector GetSeatRotationTorque() const;

	UFUNCTION(BlueprintPure)
	FVector GetSeatRotationVelocity() const;

	UFUNCTION(BlueprintCallable)
	void GetSeatSteerDeltas(float& SeatSteerYawDelta, float& SeatSteerPitchDelta, float& SeatSteerRollDelta);

	UFUNCTION(BlueprintPure)
	float GetSeatSteerStrength() const;

	UFUNCTION(BlueprintPure)
	FVector GetSeatUpDir() const;

	UFUNCTION(BlueprintPure)
	FRotator GetShellRotation() const;

	UFUNCTION(BlueprintPure)
	FVector GetTargetHeading() const;

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetTowhookAttachedComponent() const;

	UFUNCTION(BlueprintPure)
	FVector GetTowhookCableAttachLocation() const;

	UFUNCTION(BlueprintPure)
	void GetTowhookCableEndpoints(FVector& OutCableStart, FVector& OutCableEnd) const;

	UFUNCTION(BlueprintPure)
	FVector GetTowhookMuzzlePosition() const;

	UFUNCTION(BlueprintPure)
	FVector GetTowhookMuzzlePositionInterp() const;

	UFUNCTION(BlueprintPure)
	FVector GetTowhookPosition() const;

	UFUNCTION(BlueprintPure)
	FRotator GetTowhookRotation(const bool bInterp = true) const;

	UFUNCTION(BlueprintPure)
	bool IsTowhookAttached() const;

	UFUNCTION(BlueprintPure)
	bool IsTowhookContracting() const;

	UFUNCTION(BlueprintPure)
	bool IsTowhookExtending() const;

	UFUNCTION(BlueprintPure)
	bool IsTowhookHolstered() const;

	UFUNCTION(BlueprintPure)
	bool IsTowhookInAirExtending() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostBounce(const FVector& Location, const FVector& Normal, const float Force, AActor* HitActor, int32 BounceCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHit(const FVector& Location, const FVector& Normal, const float Force, AActor* HitActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHitPawn(const FVector& Normal, const float Force, AFortPlayerPawn* HitPawn);

	UFUNCTION()
	void OnRep_ReplicatedAttachState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTargetPoint(const bool bAimAssistHitsTarget, const FVector& TargetPoint);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetTowhookAttachState(FNetTowhookAttachState InTowhookAttachState);

	UFUNCTION(BlueprintCallable)
	void SetTowhookAttachState(UPrimitiveComponent* Component, const FVector& WorldLocation, const FVector& WorldNormal);

	UFUNCTION(BlueprintCallable)
	void SetTowhookProjectile(AFortSpaghettiTowhookAttachableProjectile* ProjectileActor);

	UPROPERTY(BlueprintReadWrite, Category="FortSpaghettiVehicle")
	TObjectPtr<ULegacyCameraShake> CacheDriverCameraShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="SphericalDriveModel")
	float BounceContactRepulsionForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="SphericalDriveModel")
	float BoostForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="SphericalDriveModel")
	float MaxVerticalBoostForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="SphericalDriveModel")
	float BoostSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="SphericalDriveModel")
	FSphericalDriveParams BaseSphericalDriveParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="TowhookModel")
	FTowhookParams BaseTowhookParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	float TowhookSpringDeformationRateOnGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	bool bAutoRetractGrapple;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	bool bCanHoldGrapple;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	float TowhookInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	float TowhookInterpMaxPercentPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="TowhookModel")
	float TowhookMaxInvalidateTargetAngleDeg;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TowhookModel")
	float TowhookMaxInvalidateTargetDot;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FName InternalBlockerCollisionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boost")
	FFortRechargingActionTimer BoostBounceAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	TEnumAsByte<ECollisionChannel> ProjectileTraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	float ProjectileSpeedKmh;

	UPROPERTY(BlueprintAssignable)
	FTowhookActionDelegate OnTowhookShot;

	UPROPERTY(BlueprintAssignable)
	FTowhookActionDelegate OnTowhookAttached;

	UPROPERTY(BlueprintAssignable)
	FTowhookActionDelegate OnTowhookDetached;

	UPROPERTY(BlueprintAssignable)
	FTowhookActionDelegate OnTowhookMissed;

	UPROPERTY(BlueprintAssignable)
	FTowhookActionDelegate OnTowhookHolstered;

	UPROPERTY(BlueprintAssignable)
	FTowhookYankDelegate OnTowhookYanked;

	UPROPERTY(BlueprintAssignable)
	FExtendToggledDelegate OnExtendToggled;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedAttachState)
	FNetTowhookAttachState ReplicatedAttachState;

protected:
	UFUNCTION()
	void OnBoostBounceInternal(const FVector& Location, const FVector& Normal, const float Force, UPrimitiveComponent* HitComponent);

	UFUNCTION()
	void OnTowhookYankedInternal(const FVector& YankForce, UPrimitiveComponent* YankedComponent);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerUpdateTowhook(FVector_NetQuantizeNormal InNetTowhookAimDir);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortSpaghettiVehicleConfigs> FortSpaghettiVehicleConfigs;

private:
	UFUNCTION(BlueprintCallable)
	void CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioTowCable);

	UFUNCTION(BlueprintCallable)
	void CacheParticleFX(UParticleSystemComponent* InCoilTopR, UParticleSystemComponent* InCoilTopL, UParticleSystemComponent* InCoilBottomR, UParticleSystemComponent* InCoilBottomL, UParticleSystemComponent* InBoost, UParticleSystemComponent* InDust);

	UFUNCTION()
	void OnRep_NetTowhookAimDir();

	UPROPERTY(ReplicatedUsing=OnRep_NetTowhookAimDir)
	FVector_NetQuantizeNormal NetTowhookAimDir;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheCoilIdleTopR;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheCoilIdleTopL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheCoilIdleBottomR;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheCoilIdleBottomL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheBoostFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheDustFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioMovement;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWind;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioTowCable;

};

