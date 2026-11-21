// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKMotorVehicle.h"
#include "Athena/FortAthenaVehicleSubstates.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortAthenaGoatVehicle.generated.h"

class AFortPlayerPawn;
class UCurveFloat;
class UFortGoatVehicleConfigs;
class ULegacyCameraShake;
class UParticleSystemComponent;

USTRUCT()
struct FGoaFInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortGoatVehicleConfigs> FortGoatVehicleConfigs;

	UPROPERTY(Transient)
	EPowerSlideState PowerSlideState;

	UPROPERTY(Transient)
	float AccumulatedPowerSlideBoostDiscrete;

	UPROPERTY(Transient)
	float PushForceCurrentMultiplier;

	UPROPERTY(Transient)
	float AngularSpeedEnterPowerSlide;

	UPROPERTY(Transient)
	FVector LeanSocketPositionFR;

	UPROPERTY(Transient)
	float LeanImpulseScaleFR;

	UPROPERTY(Transient)
	FVector LeanSocketPositionBR;

	UPROPERTY(Transient)
	float LeanImpulseScaleBR;

	UPROPERTY(Transient)
	FVector LeanSocketPositionBL;

	UPROPERTY(Transient)
	float LeanImpulseScaleBL;

	UPROPERTY(Transient)
	float BounceForceFR;

	UPROPERTY()
	FVector BounceOffsetFR;

	UPROPERTY(Transient)
	float BounceForceBR;

	UPROPERTY()
	FVector BounceOffsetBR;

	UPROPERTY(Transient)
	float BounceForceBL;

	UPROPERTY()
	FVector BounceOffsetBL;

};

USTRUCT()
struct FGoatOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LeanPositionFR;

	UPROPERTY(Transient)
	FVector LeanPositionTargetFR;

	UPROPERTY(Transient)
	FVector LeanPositionBR;

	UPROPERTY(Transient)
	FVector LeanPositionTargetBR;

	UPROPERTY(Transient)
	FVector LeanPositionBL;

	UPROPERTY(Transient)
	FVector LeanPositionTargetBL;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaGoatVehicle : public AFortAthenaSKMotorVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BoostBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void BoostEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void BoostIncrease(int32 AccumulationStepIndex);

	UFUNCTION(BlueprintCallable)
	void ClearBoostAccumulated();

	UFUNCTION(BlueprintImplementableEvent)
	void EBrakeBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void EBrakeEnd();

	UFUNCTION(BlueprintPure)
	float GetBoostAccumulated() const;

	UFUNCTION(BlueprintPure)
	FName GetGolfCartEBrakeActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintPure)
	FName GetGolfCartForwardActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintPure)
	FName GetGolfCartHonkActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintPure)
	FName GetGolfCartReverseActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintPure)
	bool IsEBraking() const;

	UFUNCTION(BlueprintPure)
	bool IsLeaningOrBouncingBL() const;

	UFUNCTION(BlueprintPure)
	bool IsLeaningOrBouncingBR() const;

	UFUNCTION(BlueprintPure)
	bool IsLeaningOrBouncingFR() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerRiding() const;

	UFUNCTION(BlueprintPure)
	bool IsPowerSliding() const;

	UFUNCTION(BlueprintImplementableEvent)
	void PowerSlideBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void PowerSlideEnd();

	UPROPERTY(VisibleAnywhere, Transient, Category="FortAthenaGoatVehicle")
	FVector LeanPositionFR;

	UPROPERTY(Transient)
	FVector LeanPositionTargetFR;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LeanImpulseScaleFR;

	UPROPERTY(VisibleAnywhere, Transient, Category="FortAthenaGoatVehicle")
	FVector LeanPositionBR;

	UPROPERTY(Transient)
	FVector LeanPositionTargetBR;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LeanImpulseScaleBR;

	UPROPERTY(VisibleAnywhere, Transient, Category="FortAthenaGoatVehicle")
	FVector LeanPositionBL;

	UPROPERTY(Transient)
	FVector LeanPositionTargetBL;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LeanImpulseScaleBL;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector BounceOffsetFR;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector BounceOffsetBR;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector BounceOffsetBL;

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

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortGoatVehicleConfigs> FortGoatVehicleConfigs;

private:
	UFUNCTION(BlueprintCallable)
	void CacheParticleComponentPointers(UParticleSystemComponent* WheelDust, UParticleSystemComponent* WheelSlide, UParticleSystemComponent* TrailLeft, UParticleSystemComponent* TrailRight);

	UFUNCTION(BlueprintCallable)
	void SetSkidActive(bool bActive);

	UPROPERTY(Transient)
	float AccumulatedPowerSlideBoostDiscrete;

	UPROPERTY(Transient)
	FVector LeanSocketPositionFR;

	UPROPERTY(Transient)
	FVector LeanSocketPositionBR;

	UPROPERTY(Transient)
	FVector LeanSocketPositionBL;

	UPROPERTY(Transient)
	EPowerSlideState PowerSlideState;

	UPROPERTY(Transient)
	float BounceForceFR;

	UPROPERTY(Transient)
	float BounceForceBR;

	UPROPERTY(Transient)
	float BounceForceBL;

	UPROPERTY(Transient)
	float AngularSpeedEnterPowerSlide;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_WheelDust;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_WheelSlide;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailLeft;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_TrailRight;

};

