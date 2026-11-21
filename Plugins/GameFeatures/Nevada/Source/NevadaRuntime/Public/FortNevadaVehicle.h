// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/Vehicle/FortTowhookModel.h"
#include "FortNevadaVehicleConfigs.h"
#include "FortVehicleInterface.h"
#include "FortNevadaVehicle.generated.h"

class AActor;
class AController;
class AFortAthenaVehicle;
class AFortNevadaAudioController;
class ALandscapeProxy;
class UAudioComponent;
class UChildActorComponent;
class UCurveFloat;
class UForceFeedbackEffect;
class UFortCameraMode_AthenaVehicle;
class UFortNevadaVehicleConfigs;
class ULegacyCameraShake;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class USoundBase;
class UStaticMeshComponent;
enum class ENevadaFlightStates : uint8;

UENUM()
enum ETractorBeamState
{
	TBS_Inactive = 0 UMETA(DisplayName="Inactive"),
	TBS_Charging = 1 UMETA(DisplayName="Charging"),
	TBS_Active = 2 UMETA(DisplayName="Active"),
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortNevadaVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetBatteryCharge() const;

	UFUNCTION(BlueprintPure)
	float GetBoostChargeProgress() const;

	UFUNCTION(BlueprintPure)
	int32 GetBoostChargesAvailable() const;

	UFUNCTION(BlueprintPure)
	float GetBoostChargeTimeRemaining() const;

	UFUNCTION(BlueprintPure)
	ENevadaFlightStates GetCurrentVehicleState() const;

	UFUNCTION(BlueprintCallable)
	void GetDriverSeatRotationAnimParams(float& OutLeftRight, float& OutForwardBack);

	UFUNCTION(BlueprintPure)
	int32 GetNumRebootsAvailable() const;

	UFUNCTION(BlueprintPure)
	FVector GetTractorBeamAttachLocation() const;

	UFUNCTION(BlueprintPure)
	bool IsTractorBeamActive() const;

	UFUNCTION(BlueprintPure)
	bool IsTractorBeamAttached() const;

	UFUNCTION(BlueprintPure)
	bool IsTractorBeamDisrupted() const;

	UFUNCTION(BlueprintCallable)
	void NativeToggleCockpit(bool bEnable);

	UFUNCTION()
	void OnAttachedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnAttachedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBatteryRegen(float Newcharge);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostChargeRefilled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCrashedImpact();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCrashingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOutOfBattery();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootStarted();

	UFUNCTION()
	void OnRep_ReplicatedTargetedActors();

	UFUNCTION()
	void OnRep_TargetedActorChanged();

	UFUNCTION()
	void OnRep_TractorBeamChargeStarted();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetCannonEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetTractorBeamEnabled(const bool bEnabled);

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> PassengerCameraModeClass;

	UPROPERTY(Transient)
	float CockpitHealth;

	UPROPERTY(Transient)
	float Native_CockpitEnabled;

	UPROPERTY(Transient)
	float LastCockpitHealthTickTime;

	UPROPERTY(Transient)
	float LastCockpitDamageTime;

	UPROPERTY(Transient)
	float CockpitDissolveStartTime;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	FScalableFloat CockpitMaxHealth;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	FScalableFloat CockpitHealthTickRate;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	FScalableFloat CockpitHealthPerTick;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	FScalableFloat CockpitRegenDelay;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UCurveFloat> CockpitHitMaterialWobble;

	UPROPERTY(Transient)
	float LastDamageAlpha;

	UPROPERTY(Transient)
	bool bDissolvingCockpit;

	UPROPERTY(Transient)
	bool bRestoringCockpit;

	UPROPERTY(Transient)
	bool bCockpitWobble;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortNevadaVehicle", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> NativeComp_ShieldMesh;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortNevadaVehicle")
	TObjectPtr<UMaterialInstanceDynamic> Native_CockpitMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> Native_EnergyRingMatInstance;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> Native_EnergyFieldMatInstance;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> NativeComp_DamageStateLastLife;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> NativeComp_DamageState;

	UPROPERTY(Transient)
	FVector Native_LastHitLocation;

	UPROPERTY(Transient)
	FVector Native_LastHitNormal;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortNevadaVehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_DamageStateFX;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortNevadaVehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_HologramScreen;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortNevadaVehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_SpeedLines;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UMaterialInterface> Native_EnergyRingMat;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UMaterialInterface> Native_EnergyFieldMat;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UNiagaraSystem> NativeSys_DamageStateFX;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UNiagaraSystem> NativeSys_CockpitDestroyed;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<USoundBase> CockpitDamagedSound;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<USoundBase> CockpitDestroyedSound;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<USoundBase> CockpitRespawnSound;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<USoundBase> Native_DamageStateSound;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<USoundBase> Native_DamageStateLastLifeSound;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TObjectPtr<UForceFeedbackEffect> CockpitDeactivatedForceFeedback;

	UPROPERTY(EditAnywhere, Category="FortNevadaVehicle")
	TSubclassOf<ULegacyCameraShake> CockpitDestroyedCamShake;

protected:
	UFUNCTION(BlueprintCallable)
	void AddPhysicsImpulseToTractorBeamAttachedActor(const FVector& Impulse, FName BoneName, bool bVelChange);

	UFUNCTION(BlueprintCallable)
	void DisruptTractorBeam();

	UFUNCTION(BlueprintCallable)
	void EnablePilotBubbleCollisionOnServer(bool bNewCollisionEnabled);

	UFUNCTION(BlueprintPure, Category="Audio")
	AFortNevadaAudioController* GetAudioController() const;

	UFUNCTION(BlueprintPure)
	float GetEnergyCanonChargePercent() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewVehicleState(ENevadaFlightStates NewVehicleState);

	UFUNCTION()
	void OnRep_NevadaState(const FNevadaState& PrevState);

	UFUNCTION()
	void OnRep_TractorBeamAttached();

	UFUNCTION()
	void OnRep_TractorBeamState(const ETractorBeamState PreviousState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartAscend();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartDescend();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetedActorChanged(AActor* NewTargetedActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamAttached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamChargeStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamDeactivated(const FVector& LastBeamPosition);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamDetached(AActor* DetachedActor, const FVector& LastBeamPosition);

	UFUNCTION(BlueprintCallable)
	void SetAttachedPawnAddedVelocity(const FVector& AddedVelocity);

	UFUNCTION(BlueprintCallable)
	void SetTractorBeamInactive();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NevadaState)
	FNevadaState ServerReplicatedState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortNevadaVehicleConfigs> FortNevadaVehicleConfigs;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TSubclassOf<AFortNevadaAudioController> FortNevadaAudioControllerClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> AudioControllerActor;

	UPROPERTY(Transient)
	TObjectPtr<AFortNevadaAudioController> FortNevadaAudioController;

	UPROPERTY(Transient)
	FVehicleGamepadLiftInputs LiftInputs;

	UPROPERTY(Transient)
	float LastBatteryRegenTickTime;

	UPROPERTY(Transient)
	bool bBoostThrust;

	UPROPERTY(Transient)
	bool bBoostDrag;

	UPROPERTY(Transient)
	bool bBoostInputReleased;

	UPROPERTY(Transient)
	bool bUseTractorBeamUprightForce;

	UPROPERTY(Transient)
	bool bDeadBattery;

	UPROPERTY(Transient, Replicated)
	float TractorBeamExtraLengthForExtents;

	UPROPERTY(Transient)
	FVector CrashingDesiredUp;

	UPROPERTY(Transient)
	float BoostStartTime;

	UPROPERTY(Transient)
	float BoostPitchAlpha;

	UPROPERTY(Transient)
	float BoostChargeProgress;

	UPROPERTY(Transient)
	int32 BoostChargesAvailable;

	UPROPERTY(Transient)
	FVector CachedBoostMoveDir;

	UPROPERTY(Transient)
	float CurrentStateStartTime;

	UPROPERTY(Transient)
	float HeightAtLandingTime;

	UPROPERTY(Transient)
	float CrashingScrapingTime;

	UPROPERTY(Transient)
	float CrashingNotMovingTimer;

	UPROPERTY(Transient)
	float AltimeterTraceHitDistance;

	UPROPERTY(Transient)
	float TractorBeamAppliedForceMagnitude;

	UPROPERTY(Transient)
	float AnimParamDriverSeatLeftRight;

	UPROPERTY(Transient)
	float AnimParamDriverSeatForwardBack;

	UPROPERTY(Transient)
	bool bForceNegativeLift;

	UPROPERTY(Transient)
	bool bForcePositiveLift;

	UPROPERTY(Transient)
	bool bInitialLift;

	UPROPERTY(Transient)
	ENevadaFlightStates CurrentVehicleState;

	UPROPERTY(Transient)
	TWeakObjectPtr<ALandscapeProxy> CachedLandscapeProxy;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TractorBeamChargeStarted)
	bool bTractorBeamChargeStarted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TractorBeam")
	FTowhookParams TowHookParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TractorBeam")
	TSubclassOf<AFortAthenaVehicle> AttachedPawnHiddenVehicle;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TractorBeamAttached, Export)
	TWeakObjectPtr<UPrimitiveComponent> TractorBeamAttachedPrimitive;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaVehicle> SpawnedTractorBeamVictimVehicle;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UPrimitiveComponent> PreviousTractorBeamAttachedPrimitive;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ReplicatedTargetedActors, Category="FortNevadaVehicle")
	TArray<TObjectPtr<AActor>> TractorBeamTargetedActors;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> PreviouslyTargetedActors;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortNevadaVehicle")
	TObjectPtr<AActor> TractorBeamAttachedActor;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TargetedActorChanged, Category="FortNevadaVehicle")
	TObjectPtr<AActor> TractorBeamTargetedActor;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortNevadaVehicle")
	FVector TractorBeamTargetPosition;

	UPROPERTY(Transient)
	bool bBeamButtonReleased;

	UPROPERTY(EditDefaultsOnly, Category="TractorBeam")
	TArray<TEnumAsByte<EObjectTypeQuery>> TractorBeamObjectsTypes;

	UPROPERTY(EditDefaultsOnly, Category="TractorBeam")
	FGameplayTagContainer DisallowedBeamTags;

	UPROPERTY(EditDefaultsOnly, Category="TractorBeam")
	FGameplayTagContainer AlwaysAllowedBeamTags;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TObjectPtr<UNiagaraSystem> TractorBeamFX_Unattached;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TObjectPtr<UNiagaraSystem> TractorBeamFX_Attached;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortNevadaVehicle", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> BeamPSC;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TractorBeamState, Category="FortNevadaVehicle")
	TEnumAsByte<ETractorBeamState> TractorBeamState;

	UPROPERTY(Transient, Replicated)
	float TractorBeamDeactivationTimestamp;

	UPROPERTY(Transient, Replicated)
	float TractorBeamDisruptedTimestamp;

	UPROPERTY(EditDefaultsOnly, Category="TractorBeam")
	TArray<TSubclassOf<AActor>> TractorBeamDisallowedClasses;

};

