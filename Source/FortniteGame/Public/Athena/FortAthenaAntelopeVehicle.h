// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKMotorVehicle.h"
#include "Athena/FortAthenaVehicleSubstates.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortAthenaAntelopeVehicle.generated.h"

class ABuildingActor;
class AFortPlayerPawn;
class UCurveFloat;
class UFortAntelopeVehicleConfigs;
class UFortVehicleAudioVoice;
class ULegacyCameraShake;
class UMaterialInstanceDynamic;
class UParticleSystem;
class UParticleSystemComponent;
class UStaticMeshComponent;

USTRUCT()
struct FAntelopeInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAntelopeVehicleConfigs> FortAntelopeVehicleConfigs;

	UPROPERTY(Transient)
	bool bIsBoosting;

	UPROPERTY(Transient)
	ENaturalSlideState NaturalSlideState;

	UPROPERTY(Transient)
	float PushForceCurrentMultiplier;

	UPROPERTY(Transient)
	FVector BackLeanSocketPosition;

	UPROPERTY()
	float LeanImpulseScaleBack;

	UPROPERTY(Transient)
	float BounceForceBack;

	UPROPERTY()
	FVector BounceOffsetBack;

};

USTRUCT()
struct FAntelopeOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LeanPositionBack;

	UPROPERTY(Transient)
	FVector LeanPositionTargetBack;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaAntelopeVehicle : public AFortAthenaSKMotorVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void BoostEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void BoostFailed();

	UFUNCTION(BlueprintCallable)
	void CacheAudioPointers(UFortVehicleAudioVoice* InAudioEngineRevUp, UFortVehicleAudioVoice* InAudioSkid, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioBoost, UFortVehicleAudioVoice* InAudioHandbrakeSkid, UFortVehicleAudioVoice* InAudioBoostCharge, UFortVehicleAudioVoice* InAudioEngineIdle);

	UFUNCTION(BlueprintCallable)
	void CacheBoostSM(UStaticMeshComponent* InBoost);

	UFUNCTION(BlueprintCallable)
	void ClearBoostAccumulated();

	UFUNCTION(BlueprintPure)
	float GetBoostAccumulated() const;

	UFUNCTION(BlueprintPure)
	bool IsAccumulatingBoost() const;

	UFUNCTION(BlueprintPure)
	bool IsInBoostSmashForgivenessPeriod() const;

	UFUNCTION(BlueprintPure)
	bool IsLeaningOrBouncingBack() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerRiding() const;

	UFUNCTION(BlueprintPure)
	bool IsNaturalSliding() const;

	UFUNCTION(BlueprintPure)
	bool IsPassivelyExpendingBoost() const;

	UFUNCTION(BlueprintPure)
	bool IsSmashing() const;

	UFUNCTION(BlueprintImplementableEvent)
	void NaturalSlideBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void NaturalSlideEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void SmashedThroughBuildingPiece(const FVector& ImpactPoint, const FVector& ImpactNormal, const ABuildingActor* BuildingHitActor);

	UPROPERTY(VisibleAnywhere, Category="FortAthenaAntelopeVehicle")
	FVector LeanPositionBack;

	UPROPERTY(VisibleAnywhere, Category="FortAthenaAntelopeVehicle")
	FVector LeanPositionTargetBack;

	UPROPERTY(VisibleAnywhere, Category="FortAthenaAntelopeVehicle")
	FVector LeanPositionFront;

	UPROPERTY(VisibleAnywhere, Category="FortAthenaAntelopeVehicle")
	float LeanPositionFrontMaxLag;

	UPROPERTY(VisibleAnywhere, Category="FortAthenaAntelopeVehicle")
	float LeanPositionFrontLagCoefficient;

	UPROPERTY(Transient)
	FVector BackLeanSocketPosition;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LeanImpulseScaleBack;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector BounceOffsetBack;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UCurveFloat> BounceCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WheelFX")
	TArray<FLinearColor> BoostSlideColors;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float HandBrakeSkidParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float BoostParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float MovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float BatteryParam;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_Boost_Flames;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	float CachedSkidValue;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioEngineRevUp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioSkid;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioScrape;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioWind;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioBoost;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioHandbrakeSkid;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioBoostCharge;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CachedAudioEngineIdle;

	UPROPERTY(Transient)
	bool bOutOfRangeAudioParamsSet;

	UPROPERTY(Transient)
	bool bBudgetBasedAudioParamsCleared;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	TObjectPtr<UMaterialInstanceDynamic> BoostMeterMID;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	TObjectPtr<UMaterialInstanceDynamic> BodyMID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_ATV_Engine_Ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	TObjectPtr<UParticleSystem> PS_Sputtering_Flames_Template;

	UPROPERTY(Transient)
	bool bHaveTriggeredBoostFX;

	UPROPERTY(Transient)
	bool bIsUsingSputteringFlamesTemplate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	bool bAreWheelsIced;

	UPROPERTY(Transient)
	int32 RenderingDetailMode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	float CacheWheelsBackOpacity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	float CacheWheelsFrontOpacity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	TObjectPtr<UMaterialInstanceDynamic> WheelBlursFront;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAthenaAntelopeVehicle")
	TObjectPtr<UMaterialInstanceDynamic> WheelBlursBack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> WheelBlur_BL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> WheelBlur_BR;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> WheelBlur_FL;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> WheelBlur_FR;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UPROPERTY(BlueprintReadWrite, Transient, Category="Vehicle")
	bool bPlayingBoostFX;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Vehicle")
	bool bPlayingBoostFXForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float BoostFXTime;

	UPROPERTY(BlueprintReadWrite, Category="Vehicle")
	float BoostFXFOVOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UCurveFloat> BoostFXStrengthCurve;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UCurveFloat> BoostFXRumbleStrengthCurve;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortAntelopeVehicleConfigs> FortAntelopeVehicleConfigs;

private:
	UFUNCTION(BlueprintCallable)
	void CacheParticleComponentPointers(UParticleSystemComponent* WheelDust, UParticleSystemComponent* WheelSlide, UParticleSystemComponent* TrailLeft, UParticleSystemComponent* TrailRight, UParticleSystemComponent* InEngineReady);

	UFUNCTION(BlueprintCallable)
	void CacheWheelBlurStaticMeshes(UStaticMeshComponent* InBL, UStaticMeshComponent* InBR, UStaticMeshComponent* InFL, UStaticMeshComponent* InFR);

	UFUNCTION(BlueprintCallable)
	void SetSkidActive(bool bActive);

	UPROPERTY(Transient)
	bool bIsBoosting;

	UPROPERTY(Transient)
	ENaturalSlideState NaturalSlideState;

	UPROPERTY(Transient)
	float BounceForceBack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_WheelDust;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_WheelSlide;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailLeft;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailRight;

};

