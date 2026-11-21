// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Math/RandomStream.h"
#include "Athena/FortAthenaSKMotorVehicle.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortDagwoodTypes.h"
#include "FortDagwoodVehicleConfigs.h"
#include "FortVehicleTypes.h"
#include "Vehicles/Components/FortVehicleSeatComponent.h"
#include "FortDagwoodVehicle.generated.h"

class ABuildingActor;
class AFortPawn;
class AFortValetAudioController;
class UDagwoodNetworkPhysicsComponent;
class UFortCameraMode;
class UFortCameraMode_AthenaVehicle;
class UFortDagwoodVehicleConfigs;
class UFortSplatterSourceComponent;
class ULegacyCameraShake;
class UNiagaraComponent;
class UNiagaraSystem;
class UStaticMesh;
class UStaticMeshComponent;
enum class ETireLocations : uint8;
enum class ETireStates : uint8;
enum class ETireSurfaces : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartHandBrakeCatchupForce);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartHandbrake);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopHandbrake);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTireModHealthChanged, const FAttachedWheel&, WheelData);

USTRUCT()
struct FDagwoodActionDefForUI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DagwoodActionDefForUI")
	TArray<FActionDefForUI> ActionDefForUI;

};

USTRUCT()
struct FDagwoodInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortDagwoodVehicleConfigs> FortDagwoodVehicleConfigs;

	UPROPERTY()
	FDagwoodRuntimeModifiers DagwoodRuntimeModifiedProperties;

};

USTRUCT()
struct FDagwoodInternal : public FFortVehicleInternalPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FDagwoodOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FDagwoodOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	bool bHasTraction;

	UPROPERTY(NotReplicated)
	bool bStartHandBrakeCatchupForce;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortDagwoodVehicle : public AFortAthenaSKMotorVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CleanupLoopingPooledFX();

	UFUNCTION(BlueprintPure)
	bool ForwardOrReverseInputPressed() const;

	UFUNCTION(BlueprintPure)
	float GetTireHealthPercent(ETireLocations TireIndex) const;

	UFUNCTION(BlueprintPure)
	ETireSurfaces GetTireSurface(ETireLocations TireIndex) const;

	UFUNCTION(BlueprintPure)
	bool IsOnLandscape() const;

	UFUNCTION(BlueprintPure)
	bool IsTireSkidding(const float MinSpeedForSkid, const float AngleForSkid, const float SpeedForPeelout, const float SpeedForBraking) const;

	UFUNCTION(BlueprintCallable)
	virtual void MakeInoperable();

	UFUNCTION(BlueprintCallable)
	void MakeOperable(bool bAddGas = false);

	UFUNCTION(BlueprintImplementableEvent)
	void OnClientBeginAltInteract(AFortPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFlipImpactDamage();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInoperableChanged(bool bInoperable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnServerAltInteract(AFortPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartHandbrake();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopHandbrake();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTickAudioController(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTickAudioFade(float FadeParam);

	UFUNCTION()
	void SelfDestructCleanup();

	UFUNCTION(Server, Reliable)
	void ServerSelfDestructActivated();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="NativeFade")
	void ServerSetFadeDuration(const float NewFadeDuration);

	UFUNCTION(BlueprintCallable)
	void SetValetAudioController(AFortValetAudioController* ValetAudio);

	UFUNCTION(BlueprintCallable)
	void StartFade();

	UPROPERTY(BlueprintAssignable)
	FOnStartHandbrake OnStartHandbrakeDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnStopHandbrake OnStopHandbrakeDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnStartHandBrakeCatchupForce OnStartHandBrakeCatchupForceDelegate;

	UPROPERTY(EditAnywhere, Category="FortDagwoodVehicle")
	TSubclassOf<ULegacyCameraShake> HardLandingCameraShake;

	UPROPERTY(EditAnywhere, Category="NativeShakes")
	TSubclassOf<ULegacyCameraShake> DriverCamShakeClass;

	UPROPERTY(EditAnywhere, Category="NativeShakes")
	TSubclassOf<ULegacyCameraShake> HandBrakeCamShakeClass;

	UPROPERTY(EditAnywhere, Category="FortDagwoodVehicle")
	EVehicleClass VehicleClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NativeFade")
	float FadeDelay;

	UPROPERTY(EditAnywhere, Transient, Replicated, Category="NativeFade")
	float FadeDuration;

	UPROPERTY(EditAnywhere, Category="Skid")
	float MinBrakeForceForSkid;

	UPROPERTY(EditAnywhere, Category="Skid")
	float MinForwardSpeedForSkid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag SpeedLinesCueTag;

	UPROPERTY(Transient)
	float FadeStartTime;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="Vehicle", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UDagwoodNetworkPhysicsComponent> NetworkPhysicsComponent;

	UPROPERTY(BlueprintAssignable)
	FTireModHealthChanged OnTireModHealthChanged;

	UPROPERTY(EditAnywhere, Category="FortDagwoodVehicle")
	TObjectPtr<UStaticMesh> TireBootMesh;

	UPROPERTY(EditDefaultsOnly, Category="FortDagwoodVehicle")
	TMap<int32, FDagwoodActionDefForUI> MapSelfDestructActionDefForUI;

	UPROPERTY(EditDefaultsOnly, Category="FortDagwoodVehicle")
	float MinimumTimeBetweenSelfDestructPromptChanges;

protected:
	UFUNCTION(BlueprintCallable)
	void AddRuntimeGearsInfoOnServer(const FRuntimeGearInfo& GearInfo);

	UFUNCTION(BlueprintPure)
	float GetBumpiness() const;

	UFUNCTION(BlueprintCallable)
	const FDagwoodRuntimeModifiers& GetCurrentDagwoodRuntimeProperties();

	UFUNCTION(BlueprintPure)
	float GetMiddleAxleForwardAdjust() const;

	UFUNCTION()
	void HandleCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION(BlueprintPure)
	bool IsNativeBPTickEnabled() const;

	UFUNCTION(BlueprintPure)
	float NativeCalculateAccelRumbleIntensity(float MaxIntensity) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDestroyedPropFromCollision(const ABuildingActor* BuildingHitActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldSelfDestructStarted(AFortPawn* DriverPawn, const float ExitDuration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldSelfDestructStopped(AFortPawn* DriverPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDamageInfoOnServer(const bool bInDamageFriendlyVehicles, const bool bInDamageOtherVehicles, const bool bInDamageOwnVehicle, const bool bInDamageAllowedFromOtherVehicle);

	UFUNCTION(BlueprintCallable)
	void SetRuntimeBoostInfoOnServer(const FRuntimeBoostInfo& BoostInfo);

	UFUNCTION(BlueprintCallable)
	void SetRuntimeDriveInfoOnServer(float MaxIncline, float MaxTilt);

	UFUNCTION(BlueprintCallable)
	void SetRuntimeFuelInfoOnServer(const FRuntimeFuelInfo& FuelInfo);

	UFUNCTION(BlueprintCallable)
	void SetRuntimeGravityOnServer(float GravMult);

	UFUNCTION(BlueprintCallable)
	void SetRuntimeSpringsInfoOnServer(const FRuntimeSpringsInfo& SpringsInfo);

	UPROPERTY(Replicated)
	float RechargeableBoostPercent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSplatterSourceComponent> SplatterSourceComp;

	UPROPERTY(EditAnywhere, Category="FortDagwoodVehicle")
	bool bEnableNativizedTick;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<FName> PassengerLeanSockets;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<FVector> PassngerLeanRelativeOffsets;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode_AthenaVehicle> PassengerCameraModeClass;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> PassengerCameraModeClass_ADS;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<FName> WheelSocketNames;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortDagwoodVehicleConfigs> FortDagwoodVehicleConfigs;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<int32> RearShocks;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTagContainer OffroadEnvironmentDamageTags;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTagContainer FireDamageTags;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector NativeWheelScaleRear;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector NativeWheelScaleFront;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector NativeTireScaleRear;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector NativeTireScaleFront;

	UPROPERTY(Transient)
	bool bTireSmokeActive;

	UPROPERTY(Transient)
	bool bBoostFailed;

	UPROPERTY(Transient)
	bool bCanBoostPitch;

	UPROPERTY(Transient)
	uint64 AccelForceFeedbackHandle;

	UPROPERTY(Transient)
	uint64 SkidForceFeedbackHandle;

	UPROPERTY(Transient)
	uint64 BrakeForceFeedbackHandle;

	UPROPERTY(Transient)
	uint64 HandBrakeForceFeedbackHandle;

	UPROPERTY(Transient)
	bool bSpeedLinesActive;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DagwoodRuntimeModifiers)
	FDagwoodRuntimeModifiers DagwoodRuntimeModifiedProperties;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerRepWheelData)
	TArray<FAttachedWheel> ServerRepWheelData;

	UPROPERTY(Transient)
	FVector FlipYawForwardTargetDirection;

	UPROPERTY(Transient)
	FVector FlipYawOriginalForward;

	UPROPERTY(Transient)
	ETireLocations LastPoppedTire;

	UPROPERTY(Transient)
	float RoadTopSpeedMultiplier;

	UPROPERTY(Transient)
	float CurrentBumpiness;

	UPROPERTY(Transient)
	float CurrentForwardAcceleration;

	UPROPERTY(Transient)
	float PreviousTurnAlpha;

	UPROPERTY(Transient)
	float CurrentCameraAssistStrength;

	UPROPERTY(Transient)
	float LostGripTime;

	UPROPERTY(Transient)
	float LostGripRightAlpha;

	UPROPERTY(Transient)
	float HandbrakeTime;

	UPROPERTY(Transient)
	float HandbrakeStartTime;

	UPROPERTY(Transient)
	float HandbrakeEndTime;

	UPROPERTY(Transient)
	float FlipYawMult;

	UPROPERTY(Transient)
	float FlipTimer;

	UPROPERTY(Transient)
	float FlipExplodeTimer;

	UPROPERTY(Transient)
	float FlipPushForceTimer;

	UPROPERTY(Transient)
	float FlipAirTimer;

	UPROPERTY(Transient)
	float FlipLanding;

	UPROPERTY(Transient)
	float FlipStartTime;

	UPROPERTY(Transient)
	float LastFlipDamageTime;

	UPROPERTY(Transient)
	float PreFlipControlLossTimer;

	UPROPERTY(Transient)
	bool bDidCinematicFlip;

	UPROPERTY(Transient)
	bool bCanCinematicFlip;

	UPROPERTY(Transient)
	bool bInPopTireVeer;

	UPROPERTY(Transient)
	bool bInFlipRecovery;

	UPROPERTY(Transient)
	bool bExplodeAfterFlip;

	UPROPERTY(Transient)
	bool bLostGrip;

	UPROPERTY(Transient)
	bool bApplyHandbrakeCatchupForce;

	UPROPERTY(Transient)
	bool bDidHandbrakeCatchup;

	UPROPERTY(Transient)
	bool bInFlipRoll;

	UPROPERTY(Transient)
	bool bInFlipYaw;

	UPROPERTY(Transient)
	bool bInFlipPitch;

	UPROPERTY(Transient)
	bool bFlipDidLeaveGround;

	UPROPERTY(Config)
	bool bBreakBuildingsIfBlockingLeaningPassenger;

	UPROPERTY(Transient)
	float LeanBreakTimeAccumulator;

	UPROPERTY(EditDefaultsOnly, Category="FortDagwoodVehicle")
	float LeanBreakCheckInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortDagwoodVehicle")
	TArray<FName> SeatToWindowShapeNames;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> OffroadCameraShakeInstance;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> DriverCameraShakeInstance;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> AccelCameraShakeInstance;

	UPROPERTY(Transient)
	TObjectPtr<ULegacyCameraShake> HandBrakeCameraShakeInstance;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Valet|Road And Exhaust|Niagara", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_RoadAndExhaust;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Valet|Road And Exhaust|Niagara", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_TireSkid;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Valet|Road And Exhaust|Niagara", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_Damage;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Valet|Road And Exhaust|Niagara", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NativeComp_SpeedLines;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Valet|Road And Exhaust|Niagara")
	TObjectPtr<UNiagaraSystem> NativeSys_TireExhaust;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Valet|Road And Exhaust|Niagara")
	TObjectPtr<UNiagaraSystem> NativeSys_SpeedLines;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Valet|Road And Exhaust|Niagara")
	TObjectPtr<UNiagaraSystem> NativeSys_TireSkid;

	UPROPERTY(EditDefaultsOnly, Category="Valet|Road And Exhaust|Niagara")
	TArray<TEnumAsByte<EPhysicalSurface>> RoadAndExhaustSurfaceTypeArrayForFX;

	UPROPERTY(EditDefaultsOnly, Category="Valet|Road And Exhaust|Niagara")
	FName RoadAndExhaustPeelOutColorIndexName;

	UPROPERTY(EditDefaultsOnly, Category="Valet|Road And Exhaust|Materials")
	FName BrakeLightsName;

	UPROPERTY(EditDefaultsOnly, Category="FortDagwoodVehicle")
	uint8 bSelfDestructEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortDagwoodVehicle")
	uint8 bClientUsesSelfDestructTimer : 1;

private:
	UFUNCTION()
	void ApplyRuntimeModifiers();

	UFUNCTION()
	void OnRep_DagwoodRuntimeModifiers(const FDagwoodRuntimeModifiers& PrevMods);

	UFUNCTION()
	void OnRep_FakeTires(const TArray<ETireStates>& PrevTireStates);

	UFUNCTION()
	void OnRep_IsInoperable();

	UFUNCTION()
	void OnRep_PoppedTireReaction();

	UFUNCTION()
	void OnRep_RandSeed();

	UFUNCTION()
	void OnRep_ServerRepWheelData(const TArray<FAttachedWheel>& PrevWheelData);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FakeTires)
	TArray<ETireStates> FakeTireStates;

	UPROPERTY(Transient)
	EPoppedTireReactionStates ActivePoppedTireReaction;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PoppedTireReaction)
	EPoppedTireReactionStates ReplicatedPoppedTireReaction;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortValetAudioController> ValetAudio;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> TireMeshes;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> FakeTireMeshes;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsInoperable)
	bool bIsInoperable;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RandSeed)
	int32 RandomSeed;

	UPROPERTY(Transient)
	FRandomStream RandStream;

	UPROPERTY(Transient)
	bool bHasTraction;

	UPROPERTY(Transient)
	bool bStartHandBrakeCatchupForce;

};

