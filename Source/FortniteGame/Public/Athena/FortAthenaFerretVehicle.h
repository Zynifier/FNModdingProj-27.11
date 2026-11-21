// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaDoghouseVehicle.h"
#include "FortAthenaFerretVehicle.generated.h"

class ABuildingActor;
class AFortPlayerPawn;
class UFortFerretVehicleConfigs;
class UFortVehicleAudioVoice;
class UGameplayEffect;
class ULegacyCameraShake;
class UMaterialInstanceDynamic;
class UParticleSystem;
class UParticleSystemComponent;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaFerretVehicle : public AFortAthenaDoghouseVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void BoostEnd();

	UFUNCTION(BlueprintPure)
	float GetBoostCharge() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleBoostChargeAboveThreshold();

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerRiding() const;

	UFUNCTION(BlueprintPure)
	bool IsShooting() const;

	UFUNCTION(BlueprintPure)
	bool IsTryingToShoot() const;

	UFUNCTION(BlueprintImplementableEvent)
	void LandedWithNoFuel();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetGrantWeaponGE(TSubclassOf<UGameplayEffect> NewGE);

	UFUNCTION(BlueprintImplementableEvent)
	void SmashedThroughBuildingPiece(const FVector& ImpactPoint, const FVector& ImpactNormal, const ABuildingActor* BuildingHitActor);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float BoostParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float MovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Rumble")
	float RumbleIntensity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Rumble")
	bool bBoostCameraActive;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Rumble")
	bool bLocalPlayerADS;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> DriverCameraShake;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CameraShake")
	TObjectPtr<ULegacyCameraShake> PassengerCameraShake;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Vehicle")
	TObjectPtr<AFortPlayerPawn> LocalPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CurrentMaxSpringCompression;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringCompressionRefireTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SparksRightParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float MovementAmountParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortAthenaFerretVehicle")
	float MinPropSpeedWhenShooting;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> RightGunMuzzle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> LeftGunMuzzle;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortAthenaFerretVehicle")
	float MaxHealthToDestroyPropWhileBoosting;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortAthenaFerretVehicle")
	float MaxHealthToDestroyPropWithDirectHit;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortAthenaFerretVehicle")
	float MaxHealthToDestroyProp;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaFerretVehicle")
	bool bShowWingTrails;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCueBoost(AFortPlayerPawn* Pawn, float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCueFired(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortFerretVehicleConfigs> FortFerretVehicleConfigs;

private:
	UFUNCTION(BlueprintCallable)
	void CacheAudioVoicePointers(UFortVehicleAudioVoice* InAudioMovementClose, UFortVehicleAudioVoice* InAudioMovementDistant, UFortVehicleAudioVoice* InAudioWindFirstPerson, UFortVehicleAudioVoice* InAudioDive, UFortVehicleAudioVoice* InAudioTaxi, UFortVehicleAudioVoice* InAudioSpark);

	UFUNCTION(BlueprintCallable)
	void CachePlaneFX(UParticleSystemComponent* InPlaneSpeedFX);

	UFUNCTION(BlueprintCallable)
	void CachePropAndBoostMeterSM(UStaticMeshComponent* InPropSM, UStaticMeshComponent* InBoostSM);

	UFUNCTION(BlueprintCallable)
	void SetSkidActive(bool bActive);

	UFUNCTION(BlueprintCallable)
	void SpawnWingTrailParticles();

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaFerretVehicle")
	TObjectPtr<UParticleSystem> PS_TrailTop;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaFerretVehicle")
	TObjectPtr<UParticleSystem> PS_TrailBottom;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailTopLeft;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailTopRight;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailBottomLeft;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailBottomRight;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> BoostMeterSM;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PropellerSM;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BoostMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> FuelGaugeMID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PlaneSpeedFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioMovementClose;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioMovementDistant;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioWindFirstPerson;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioDive;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioTaxi;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> FortAudioSpark;

};

