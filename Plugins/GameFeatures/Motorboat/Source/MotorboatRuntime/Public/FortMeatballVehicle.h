// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortRechargingActionTimer.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortMeatballVehicle.generated.h"

class ABuildingActor;
class AFortPlayerPawn;
class APlayerController;
class UFortCameraMode;
class UFortMeatballVehicleConfigs;
class UFortVehicleAudioVoice;
class ULegacyCameraShake;
class UMaterialInstanceDynamic;
class UNiagaraComponent;

USTRUCT()
struct FMeatballInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortMeatballVehicleConfigs> FortMeatballVehicleConfigs;

	UPROPERTY()
	float PushForceCurrentMultiplier;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortMeatballVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CacheAudioPointers(UFortVehicleAudioVoice* InAudioEngineUp, UFortVehicleAudioVoice* InAudioEngineDown, UFortVehicleAudioVoice* InAudioWakeTurn, UFortVehicleAudioVoice* InAudioWakeSpeed, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioEngineOutOfFuel);

	UFUNCTION(BlueprintCallable)
	void CacheGroundFXComponent(UNiagaraComponent* InGroundFXComponent);

	UFUNCTION(BlueprintPure)
	float GetBoostCharge() const;

	UFUNCTION(BlueprintPure)
	FVector GetSeatOffset() const;

	UFUNCTION(BlueprintPure)
	FQuat GetSeatRotation() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void SmashedThroughBuildingPiece(const FVector& ImpactPoint, const FVector& ImpactNormal, const ABuildingActor* BuildingHitActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle")
	FFortRechargingActionTimer BoostAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Vehicle")
	float FxNormalizationMaxSpeedKmh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioEngineUp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioEngineDown;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWakeTurn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWakeSpeed;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioScrape;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioEngineOutOfFuel;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BoostMID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> CachedGroundFXComponent;

	UPROPERTY(Transient)
	TObjectPtr<APlayerController> DrivingPlayerController;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> LandCameraShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle")
	TSubclassOf<ULegacyCameraShake> LandCameraShakeClass;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> DriverCameraShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle")
	TSubclassOf<ULegacyCameraShake> DriverCameraShakeClass;

	UPROPERTY(Transient)
	float LandRumbleIntensity;

	UPROPERTY(Transient)
	uint64 LandForceFeedbackHandle;

	UPROPERTY(Transient)
	float TurnRumbleIntensity;

	UPROPERTY(Transient)
	uint64 TurnForceFeedbackHandle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMeatballVehicle")
	float CurrentSnowAltitude;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortMeatballVehicle")
	bool bHasSnow;

	UPROPERTY(Transient)
	bool bLargeRumble;

	UPROPERTY(Transient)
	bool bTurnRumbleActive;

	UPROPERTY(Transient)
	bool bWaterDropsOnScreen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag GCVehicleScreenDrips;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayCueParameters GCParamsEmpty;

protected:
	UFUNCTION(BlueprintCallable)
	void LandShakeEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostStarted();

	UFUNCTION(BlueprintCallable)
	void StopDriverCameraShake();

	UFUNCTION(BlueprintCallable)
	void StopLandRumble();

	UFUNCTION(BlueprintCallable)
	void StopTurnRumble();

	UFUNCTION(BlueprintCallable)
	void UpdateSnowAndDirtParams(float NormalizedForwardSpeed);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortMeatballVehicleConfigs> FortMeatballVehicleConfigs;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	int32 WaterLineStartPontoonIndex;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	int32 WaterLineEndPontoonIndex;

	UPROPERTY(Transient)
	bool bBoostFailed;

private:
	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> BoostingCamera;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> VehicleCameraNoWeaponOverride;

};

