// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKPushVehicleCoastState.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortAthenaSKPushVehicle.generated.h"

class AFortPlayerPawn;
class UFortSKPushVehicleConfigs;
class UFortVehicleAudioVoice;
class UParticleSystemComponent;
enum class ECoastState : uint8;

USTRUCT()
struct FSKPushVehicleInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortSKPushVehicleConfigs> SKPushVehicleConfigs;

	UPROPERTY()
	uint8 bIsDriverTargetting : 1;

	UPROPERTY()
	uint8 bPedalForceCooldown : 1;

	UPROPERTY()
	uint8 bConstrainedRotation : 1;

	UPROPERTY()
	uint8 bIsCoastingOrDismounting : 1;

	UPROPERTY()
	ECoastState CurrentPhysicsCoastState;

	UPROPERTY()
	ECoastState CurrentAnimCoastState;

	UPROPERTY()
	float BrakeAboveTopSpeedDelta;

	UPROPERTY()
	FVector PushForceRelativeLocation;

};

USTRUCT()
struct FSKPushVehicleInternalPersistent : public FFortVehicleInternalPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FSKPushVehicleOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float StandingInPlaceSteerAngle;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortAthenaSKPushVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Vehicle")
	ECoastState GetCoastState(bool bGetPhysicsState = false) const;

	UFUNCTION(BlueprintPure)
	FName GetShoppingCartCoastActionName(AFortPlayerPawn* FortPlayerPawn) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetStandingInPlaceSteeringAngle() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsApplyingPedalForce() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsCoasting() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsDismountingFromCoast() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsEndCoasting() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsMounting() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsReadyToPedalFromCoast() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsStandingInPlace() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	virtual bool PlayerWantsToCoast(bool bCheckAnimOnlyCoast = false) const;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AntiGravityScalerWhenEmpty;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AntiGravityScalerWhenCoasting;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void OnIsCoastingChanged();

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float SpringCompressionRefireTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float MovementAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CurrentMaxSpringCompression;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SparksLeftParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SparksRightParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float LeftSlowDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float RightSlowDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float LeftFastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float RightFastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float FastDustParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float CoastingMovementParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float SkiddingAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float InAirParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float ScrapingAmountParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	float AudioWindParam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortSKPushVehicleConfigs> SKPushVehicleConfigs;

	UPROPERTY()
	ECoastState CurrentPhysicsCoastState;

	UPROPERTY()
	ECoastState CurrentAnimCoastState;

	UPROPERTY()
	bool bIsDriverTargetting;

private:
	UFUNCTION(BlueprintCallable)
	void CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioCoast, UFortVehicleAudioVoice* InAudioSkid, UFortVehicleAudioVoice* InAudioInAir, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioWind);

	UFUNCTION(BlueprintCallable)
	void CacheFX(UParticleSystemComponent* InWheelDustFX);

	UPROPERTY()
	bool bConstrainedRotation;

	UPROPERTY(Transient)
	bool bIsCoastingOrDismounting;

	UPROPERTY()
	float ForwardForceTractionScale;

	UPROPERTY()
	float StandingInPlaceSteerAngle;

	UPROPERTY()
	bool bPedalForceCooldown;

	UPROPERTY()
	FVector PushForceRelativeLocation;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioMovement;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioCoast;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioSkid;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioInAir;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioScrape;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> CacheAudioWind;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> CacheWheelDustFX;

};

