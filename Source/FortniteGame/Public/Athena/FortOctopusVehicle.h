// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortSphericalDriveModel.h"
#include "Athena/Vehicle/FortTowhookModel.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortOctopusVehicle.generated.h"

class AActor;
class AFortOctopusTowhookAttachableProjectile;
class AFortPlayerPawn;
class UFXSystemComponent;
class UFortOctopusVehicleConfigs;
class UFortVehicleAudioVoice;
class ULegacyCameraShake;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExtendToggledDelegate, bool, bIsToggled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTowhookActionDelegate);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortOctopusVehicle : public AFortAthenaSKVehicle, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool AimTraceHitsTarget() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void BreakTowhook();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void DestroyTowhookProjectile();

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API float GetAccelerationPercent() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FRotator GetInterpedShellRotation() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API bool GetIsExtendToggled();

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API void GetPrimaryContact(bool& bIstouching, FVector& ContactPoint, FVector& ContactNormal) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetSeatForwardDir() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FRotator GetSeatRotation() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetSeatRotationTorque() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetSeatRotationVelocity() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void GetSeatSteerDeltas(float& SeatSteerYawDelta, float& SeatSteerPitchDelta, float& SeatSteerRollDelta);

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API float GetSeatSteerStrength() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetSeatUpDir() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FRotator GetShellRotation() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetTargetHeading() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API UPrimitiveComponent* GetTowhookAttachedComponent() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetTowhookCableAttachLocation() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API void GetTowhookCableEndpoints(FVector& OutCableStart, FVector& OutCableEnd) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetTowhookMuzzlePosition() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetTowhookMuzzlePositionInterp() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FVector GetTowhookPosition() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API FRotator GetTowhookRotation(const bool bInterp = true) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsTowhookAttached() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsTowhookContracting() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsTowhookExtending() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsTowhookHolstered() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsTowhookInAirExtending() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnBoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnBoostBounce(const FVector& Location, const FVector& Normal, const float Force, AActor* HitActor, int32 BounceCount);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnBoostEnd();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHit(const FVector& Location, const FVector& Normal, const float Force, AActor* HitActor);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHitPawn(const FVector& Normal, const float Force, AFortPlayerPawn* HitPawn);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ReplicatedAttachState();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnUpdateTargetPoint(const bool bAimAssistHitsTarget, const FVector& TargetPoint);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerBreakTowhook();

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerSetTowhookAttachState(FNetTowhookAttachState InTowhookAttachState);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetTowhookAttachState(UPrimitiveComponent* Component, const FVector& WorldLocation, const FVector& WorldNormal);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetTowhookProjectile(AFortOctopusTowhookAttachableProjectile* ProjectileActor);

	UPROPERTY(BlueprintReadWrite, Category="FortOctopusVehicle")
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Replicated, Category="TowhookModel")
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

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	float ShellRotationInterpSpeed;

	UPROPERTY(BlueprintReadWrite, Config, Category="Vehicle")
	FName OwningSpawnerName;

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
	FORTNITEGAME_API void OnBoostBounceInternal(const FVector& Location, const FVector& Normal, const float Force, UPrimitiveComponent* HitComponent);

	UFUNCTION()
	FORTNITEGAME_API void OnTowhookYankedInternal(const FVector& YankForce, UPrimitiveComponent* YankedComponent);

	UFUNCTION(Server, Unreliable)
	FORTNITEGAME_API void ServerUpdateTowhook(FVector_NetQuantizeNormal InNetTowhookAimDir);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortOctopusVehicleConfigs> FortOctopusVehicleConfigs;

private:
	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioTowCable);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void CacheParticleFX(UFXSystemComponent* InCoilTopR, UFXSystemComponent* InCoilTopL, UFXSystemComponent* InCoilBottomR, UFXSystemComponent* InCoilBottomL, UFXSystemComponent* InBoost, UFXSystemComponent* InDust);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_NetTowhookAimDir();

	UPROPERTY()
	FQuat ShellRotation;

	UPROPERTY()
	FVector CachedCameraDir;

	UPROPERTY()
	FFortTowhookModel TowhookModel;

	UPROPERTY()
	FVector TowhookAimDir;

	UPROPERTY(ReplicatedUsing=OnRep_NetTowhookAimDir)
	FVector_NetQuantizeNormal NetTowhookAimDir;

	UPROPERTY()
	TArray<FSphericalDriveContact> CachedContactPoints;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheCoilIdleTopR;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheCoilIdleTopL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheCoilIdleBottomR;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheCoilIdleBottomL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheBoostFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> CacheDustFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioMovement;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWind;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioTowCable;

};

