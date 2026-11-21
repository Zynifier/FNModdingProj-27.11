// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/ActorInstanceHandle.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortHeliFlightModel.h"
#include "FortVehicleInterface.h"
#include "FortHoagieVehicle.generated.h"

class AActor;
class AController;
class AFortPawn;
class AFortPlayerPawn;
class UAnimMontage;
class UCurveFloat;
class UFortHoagieVehicleAnimInstance;
class UFortHoagieVehicleConfigs;
class UNiagaraComponent;
enum class EHoagieBoostState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHoagieAltimeterTraceUpdatedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoagieBoostStateDelegate, EHoagieBoostState, State);

USTRUCT()
struct FCachedSeatCollision
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 SeatIndex;

	UPROPERTY(Transient)
	bool bOccupied;

};

USTRUCT()
struct FHoagieCmd
{
	GENERATED_BODY()

};

USTRUCT()
struct FHoagieDeathEffectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Damage;

	UPROPERTY()
	FGameplayTagContainer DamageTags;

	UPROPERTY()
	FVector Momentum;

	UPROPERTY()
	FHitResult HitInfo;

	UPROPERTY()
	TObjectPtr<AFortPawn> InstigatedBy;

	UPROPERTY()
	TObjectPtr<AActor> DamageCauser;

	UPROPERTY()
	FGameplayEffectContextHandle EffectContext;

};

USTRUCT()
struct FHoagieInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortHoagieVehicleConfigs> FortHoagieVehicleConfigs;

	UPROPERTY()
	EHoagieState CurrentHoagieState;

	UPROPERTY()
	float LastRotorImpulseTime;

	UPROPERTY()
	FVector RotorHitLinearImpulse;

	UPROPERTY()
	FVector RotorHitAngularImpulse;

};

USTRUCT()
struct FHoagieInternal : public FFortVehicleInternalPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortHeliFlightModel FlightModel;

};

USTRUCT()
struct FHoagieOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FHoagieOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FReplicatedHeliControlState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantizeNormal Up;

	UPROPERTY()
	FVector_NetQuantizeNormal Forward;

};

USTRUCT()
struct FRotorHit
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FActorInstanceHandle HitObjectHandle;

	UPROPERTY(Transient)
	float LastHitTimer;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortHoagieVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetAltitude() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetBoostCooldown() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FVector GetBoostDirection() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetBoostDuration() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetBoostTimeLeft() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetDistanceToGround() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetForwardAlpha() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool GetIsEngineOn() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetLiftAlpha() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetMaxAltitude() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetMaxBoostCooldown() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetRotorAngleDegrees() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FVector GetRotorCenterPosition() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetRotorSpeed() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetRotorSpeedPercent() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetShutdownTimeLeft() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetSteerAlpha() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetStrafeAlpha() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	FVector GetThrustDirection(bool bWorldSpace) const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	float GetVerticalSpeedKmh() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsScrapingBottom() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsShuttingDown() const;

	UFUNCTION(BlueprintPure, Category="Vehicle")
	bool IsStartingUp() const;

	UPROPERTY(EditAnywhere, Config, Category="Vehicle")
	FName PassengerCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float CameraBoomDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	float CameraBoomHeight;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FHoagieBoostStateDelegate OnBoostStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FHoagieAltimeterTraceUpdatedDelegate OnAltimeterTraceUpdated;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FHoagieAltimeterTraceUpdatedDelegate OnCrashingStateEntered;

	UPROPERTY(Transient)
	bool bEngineAudioDisabled;

protected:
	UFUNCTION()
	void HoagieOnDisabledChanged(bool bDisabled);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void MulticastRotorImpulse(const FHitResult& RotorHit);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCritRotor(float Damage, const FVector& ImpactLocation, AController* DamageInstigator, AActor* DamageCauser, bool bMainRotor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnImpactOtherHoagie(const FVector& HitLocation, const FVector& NormalImpulse);

	UFUNCTION(BlueprintImplementableEvent)
	void OnImpactWhileCritical();

	UFUNCTION()
	void OnRefueledFromEmpty();

	UFUNCTION()
	void OnRep_HoagieState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotorDamageDealt(const FHitResult& Impact, bool bInner);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotorDamageDealtInner(const FHitResult& Impact);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotorDamageDealtOuter(const FHitResult& Impact);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotorDamagePlayer(const FHitResult& Impact);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRotorsStop();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartupBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartupEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTickRotors(float RotorAngleDegrees);

	UFUNCTION(BlueprintImplementableEvent)
	void SetMainRotorRotation(float Degrees);

	UFUNCTION(BlueprintImplementableEvent)
	void SetRotorWashActive(bool bActive);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTailRotorRotation(float Degrees);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowCooldownCue(AFortPlayerPawn* Pawn, float Duration);

	UFUNCTION(BlueprintCallable, Category="Vehicle")
	void UpdateDamageStateNative(float Damage);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateHoagieAnimBP();

	UPROPERTY(Transient)
	float LiftRumbleTimer;

	UPROPERTY(Transient)
	bool bLiftUp;

	UPROPERTY(Transient)
	uint64 LiftForceFeedbackHandle;

	UPROPERTY(Transient)
	uint64 PassiveForceFeedbackHandle;

	UPROPERTY(Transient)
	float Theta_Native;

	UPROPERTY(Transient)
	float WashAltAlpha_Native;

	UPROPERTY(Transient)
	float RotorWashTickTimer;

	UPROPERTY(Transient)
	TArray<FVector> RotorTraceArray;

	UPROPERTY(EditDefaultsOnly, Category="RotorWash")
	TArray<TEnumAsByte<EObjectTypeQuery>> RotorWashObjectsTypes;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortHoagieVehicleConfigs> FortHoagieVehicleConfigs;

	UPROPERTY(EditAnywhere, Category="Vehicle | UI")
	TObjectPtr<UCurveFloat> RumbleIntensity;

	UPROPERTY(Transient)
	FFortHeliFlightModel FlightModel;

	UPROPERTY(Transient)
	bool bClearPitchInput;

	UPROPERTY(Transient)
	float BoostTimeLeft;

	UPROPERTY(Transient)
	float BoostBrakingTimeLeft;

	UPROPERTY(Transient)
	float BoostCooldown;

	UPROPERTY(Transient)
	float ShutdownTimer;

	UPROPERTY(Transient)
	float FoliageDestructionTimer;

	UPROPERTY(Transient)
	float CrashingScrapingTimer;

	UPROPERTY(Transient)
	float CrashingNotMovingTimer;

	UPROPERTY(Transient)
	bool bCanSleep;

	UPROPERTY(Transient)
	bool bHasAppliedCrashDamage;

	UPROPERTY(Transient)
	bool bOrientedForLanding;

	UPROPERTY(Transient)
	bool bForceNegativeLift;

	UPROPERTY(Transient)
	float AltimeterTraceTimer;

	UPROPERTY(Transient)
	float LastRotorImpulseTime;

	UPROPERTY(Transient)
	float CriticalExplodeTimer;

	UPROPERTY(Transient)
	bool bCriticalExplosionPlayed;

	UPROPERTY(Transient)
	float TimeWhileCritical;

	UPROPERTY(Transient)
	float TimeWhileLanding;

	UPROPERTY(Transient)
	float LiftFromOverrideButton;

	UPROPERTY(Transient)
	FVector BoostDirection;

	UPROPERTY(Transient)
	FVector LastRotorSweepDirection;

	UPROPERTY(Transient)
	FHitResult AltimeterTraceResult;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HoagieState)
	int32 HoagieStateRep;

	UPROPERTY(Transient)
	EHoagieState CurrentHoagieState;

	UPROPERTY(Transient)
	float CurrentRotorSpeed;

	UPROPERTY(Transient)
	float CurrentRotorAngle;

	UPROPERTY(Transient)
	float RotorImpactTraceAngle;

	UPROPERTY(Transient)
	FVehicleGamepadLiftInputs LiftInputs;

	UPROPERTY(Transient)
	TArray<FRotorHit> RotorHits;

	UPROPERTY(Transient)
	TArray<FCachedSeatCollision> CachedSeatCollision;

	UPROPERTY()
	FVector RotorHitLinearImpulse;

	UPROPERTY()
	FVector RotorHitAngularImpulse;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> HoagieIdleFX_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> DamageFX_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> RotorWashFX_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Vehicle")
	TObjectPtr<UFortHoagieVehicleAnimInstance> HoagieAnimBP_Native;

private:
	UFUNCTION()
	void OnRep_ControlState();

	UFUNCTION(Server, Unreliable)
	void ServerUpdateControlState(FReplicatedHeliControlState InControlState);

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName AltimeterTraceSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName RotorDamageTraceSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName MainRotorCritSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName TailRotorCritSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TObjectPtr<UAnimMontage> SeatTransition_ToDriver;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TObjectPtr<UAnimMontage> SeatTransition_ToPassenger;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName RotorTraceProfile;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FName FoliageOverlapsBoxTag;

	UPROPERTY(ReplicatedUsing=OnRep_ControlState)
	FReplicatedHeliControlState ControlState;

	UPROPERTY(Transient)
	float CurrentViewDistanceScale;

	UPROPERTY(Transient)
	float CurrentHLODDistanceOverrideScale;

	UPROPERTY(Transient)
	float CurrentHLODMaxDrawDistanceScale;

	UPROPERTY(Transient)
	FHoagieDeathEffectInfo CachedDeathEffectInfo;

};

