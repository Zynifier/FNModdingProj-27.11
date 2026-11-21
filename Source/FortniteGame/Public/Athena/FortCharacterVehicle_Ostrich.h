// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortCharacterVehicle.h"
#include "FortVehicleTypes.h"
#include "FortCharacterVehicle_Ostrich.generated.h"

class AActor;
class AFortWeaponRanged_Ostrich;
class UAbilitySystemComponent;
class UAnimMontage;
class UAudioComponent;
class UBaseStatManager;
class UCapsuleComponent;
class UFortAnimWorldStriderComponent;
class UFortCameraMode;
class UFortMontageItemDefinitionBase;
class UFortOstrichVehicleConfigs;
class UFortVehicleAudioVoice;
class UGameplayEffect;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
enum class EOstrichDetonationState : uint8;

UENUM(BlueprintType)
enum class EOstrichDetonationState : uint8
{
	None = 0,
	Detonate = 1,
	SelfDestruct = 2,
	Instant = 3,
};

USTRUCT()
struct FOstrichWeapon_RetainedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 LoadedShotgunAmmo;

	UPROPERTY()
	float RocketsCooldownElapsed;

	UPROPERTY()
	bool bHasPrevious;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AI", "AI", "AI", "Movement", "AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortCharacterVehicle_Ostrich : public AFortCharacterVehicle
{
	GENERATED_BODY()

	friend class UFortAnimNotifyState_EmoteSound;

public:
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void AirDash(const FVector& InDirection, float Speed, float MinVerticalSpeed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ostrich (Mech)")
	void ForceDetonate(bool bExplode = false);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_Fire_Single(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_Fire_Start();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_Fire_Stop();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_Load();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_LoadSingleRocket(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void GameplayCue_Athena_Ostrich_Reload();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	FVector GetAimPoint() const;

	UFUNCTION(BlueprintImplementableEvent)
	float GetChargeJumpingFloat();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool GetDashAnimationActive() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	float GetDriverTurnAngleDelta() const;

	UFUNCTION(BlueprintImplementableEvent)
	bool GetGroundSlamBool();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	float GetGunnerAimAngleDelta() const;

	UFUNCTION(BlueprintCallable)
	AFortWeaponRanged_Ostrich* GetGunnerWeapon();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool GetIsChargingJump() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool GetIsDashing() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	float GetJumpChargeCursor() const;

	UFUNCTION(BlueprintCallable)
	UFortAnimWorldStriderComponent* GetWorldStriderComponent();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool IsFiringRockets() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool IsRocketOnCooldown() const;

	UFUNCTION(BlueprintPure, Category="Gameplay")
	bool IsShotgunReloading() const;

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnDashFinished();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnDashStart();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnKickFinished();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnKickStomp();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingRockets(bool bStarting);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPressShieldBoost();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OnStartShotgunReload();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void SetLinearAudioComp(UFortVehicleAudioVoice* LinearAudio);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void SetRotationalAudioComp(UFortVehicleAudioVoice* RotAudio);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void SetShieldActor(AActor* InShieldActor);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void SetTargetingLaserAudioComp(UAudioComponent* TargetingLaserAudio);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void GunnerShieldTakeDamage(float Damage);

	UFUNCTION(BlueprintImplementableEvent)
	bool IsGunnerShieldActive();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastDriverInput(bool bIsPrimaryFire);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Shotgun Fired (single)"))
	void NotiftyBlueprintShotgunFired();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Shotgun Start Reload"))
	void NotifyBlueprintShotgunReload();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetonateTimerStart(EOstrichDetonationState InDetonationState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDriverPrimaryFire();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDriverSecondaryFire();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFailedShieldBoost();

	UFUNCTION()
	void OnPickupCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPressHonk();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReleaseChargeJump(float ChargeAlpha);

	UFUNCTION()
	void OnRep_ChargeJump();

	UFUNCTION()
	void OnRep_Detonating();

	UFUNCTION()
	void OnRep_IsDashing();

	UFUNCTION()
	void OnRep_Kick();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartChargeJump();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyDriverInput(bool bIsPrimaryFire);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetJumpCharging(bool bNewCharging);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharacterVehicle_Ostrich")
	bool bExplodeOnDetonate;

	UPROPERTY(Transient)
	FVector GunnerAimPoint;

	UPROPERTY(Transient, Replicated)
	TWeakObjectPtr<AActor> ShieldActor;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAbilitySystemComponent> SelfDestructAbilityComp;

	UPROPERTY(Transient)
	FTimerHandle DriverPrimaryCooldownHandle;

	UPROPERTY(Transient)
	FTimerHandle DriverSecondaryCooldownHandle;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<TSubclassOf<UGameplayEffect>> KillExplosions;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TArray<TObjectPtr<UAnimMontage>> StopMontagesOnGunnerExit;

	UPROPERTY(EditAnywhere, Category="Vehicle|UI")
	TArray<FVehicleSpecificUIDetails> CustomUI;

	UPROPERTY()
	TArray<FActiveVehicleUI> ActiveUI;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FVector ApproxGunnerCameraOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LandingMovementLockDurationMin;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LandingMovementLockDurationMax;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float KneelingGunnerSeatVerticalOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float KneelingDriverSeatVerticalOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName PassengerCameraSocket;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName PassengerRootSocket;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName BeamScaleName;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName BeamLifeName;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FName BeamAttachName;

	UPROPERTY(EditAnywhere, Category="Analytics")
	FName OstrichShieldBoostStatName;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float PassengerCameraFixedVerticalOffset;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float PassengerCameraFixedVerticalOffsetNoDriver;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float DriverPrimaryCooldownTime;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float DriverSecondaryCooldownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float DetonateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float DetonateDelaySelfDestruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float DetonateRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float DriverKickMoveLockDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float KickRootMotionDelay;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float KickRootMotionDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float ShieldBoostCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float ShieldRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float SelfDestructInteractDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AccelFromIdle;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AccelFromIdleDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float IdleTimeThreshold;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float LockoutDurationAfterRequestSeatChange;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float MaxBeamLen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> DriverToGunnerTransition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> GunnerToDriverTransition;

	UPROPERTY(EditAnywhere, Category="Mech Vehicle")
	float BlockDriverStompImmersionPercent;

	UPROPERTY(EditAnywhere, Category="Mech Vehicle")
	float BlockDriverDashImmersionPercent;

	UPROPERTY(EditAnywhere, Category="Mech Vehicle")
	float BlockDriverJumpImmersionPercent;

	UPROPERTY(EditAnywhere, Category="Mech Vehicle")
	float BlockGunnerMissilesImmersionPercent;

	UPROPERTY(EditAnywhere, Category="Mech Vehicle")
	float BlockGunnerShotgunImmersionPercent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ChargeJump)
	bool bChargingJump;

	UPROPERTY(Transient)
	bool bDriverLocalChargingJump;

	UPROPERTY(Transient, Replicated)
	bool bChargingRockets;

	UPROPERTY(Transient, Replicated)
	bool bAutomaticallyFiringShotgun;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_Detonating, Category="FortCharacterVehicle_Ostrich")
	EOstrichDetonationState DetonationState;

	UPROPERTY(Transient)
	bool bLocalSimulatedChargingJump;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsDashing)
	bool bDashing;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Kick)
	bool bKickRep;

	UPROPERTY(Transient)
	bool bLoadingRockets;

	UPROPERTY(Transient)
	bool bKickActive;

	UPROPERTY(Transient)
	bool bLocalJumpButtonDown;

	UPROPERTY(Transient)
	bool bAllowEnter;

	UPROPERTY(Transient)
	bool bAcceleratingFromIdle;

	UPROPERTY(Transient)
	float IdleTime;

	UPROPERTY(Transient)
	float MovingTime;

	UPROPERTY(Transient)
	float RequestSeatChangeTime;

	UPROPERTY(Transient)
	float ChargeJumpStartTime;

	UPROPERTY(Transient)
	float GroundDashStartTime;

	UPROPERTY(Transient)
	float ShieldBoostStartTime;

	UPROPERTY(Transient)
	float KickStartTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> SpawnedBeam;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> SpawnedImpact;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> SpawnedImpactEnemy;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> SpawnedSource;

	UPROPERTY(Transient)
	float BlendedPassengerVerticalCamOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float OverrideLandingMoveLockDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	int32 ShieldBoostResourceCost;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float KickAnimationDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float DestroyDelayAfterExplosion;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float PawnRotationRate;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float AirDashOverrideAngle;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float GunnerAimPointUpdateRate;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float GunnerAimPointTraceRange;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float GroundDashAnimationDuration;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	float GunnerAimPointUpdateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float MechMissileDamageToGunnerShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	float SimulatedProxyFixupRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	bool bEnableTargetingLaser;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Vehicle")
	bool bEnableSimulatedProxyFixup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag RocketSettleCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag RocketFireCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag RocketLoadingCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag ReloadShotgunTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag FireShotgunTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag MissilesTag;

	UPROPERTY(EditAnywhere, Category="Gameplay", meta=(Categories="Gameplay"))
	FGameplayTagContainer KickStompTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag IndividualRocketFired;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag IndividualRocketLoaded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTag LocalSelfDestructPrimeUnderway;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TSubclassOf<UFortCameraMode> DriverChargeJumpCamera;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UParticleSystem> BeamTemplate;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UParticleSystem> BeamHitTemplate;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UParticleSystem> BeamHitEnemyTemplate;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	TObjectPtr<UParticleSystem> BeamSourceTemplate;

	UPROPERTY(Transient)
	float PassengerCamBlendTarget;

	UPROPERTY(Transient)
	float GunnerAimpointUpdateTimer;

	UPROPERTY(Transient)
	bool bDriverPrimaryCooldownReady;

	UPROPERTY(Transient)
	bool bDriverSecondaryCooldownReady;

	UPROPERTY(Transient)
	bool bBufferedDriverExit;

	UPROPERTY(Transient)
	bool bHoldingSelfDestruct;

	UPROPERTY(Transient)
	bool bLocalDriverRequestedExit;

	UPROPERTY(Transient)
	bool bLocalPrimaryFireButtonDown;

	UPROPERTY(Transient)
	bool bLocalSecondaryFireButtonDown;

	UPROPERTY(Transient)
	bool bEmoteAudioForceStopped;

	UPROPERTY(Transient)
	bool bAimedAtEnemy;

	UPROPERTY(Transient)
	bool bAimedAtSky;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> NativeLinearMovementAudio;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> NativeRotationalMovementAudio;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> NativeTargetingLaserAudio;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TSubclassOf<UFortOstrichVehicleConfigs> FortOstrichVehicleConfigsClass;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	FScalableFloat EmotesEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="Emote")
	TArray<FGameplayTag> ExcludedEmoteTags;

	UPROPERTY(EditDefaultsOnly, Config, Category="Emote")
	TArray<TSoftObjectPtr<UFortMontageItemDefinitionBase>> ExcludedEmotes;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Export, Category="World Strider", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortAnimWorldStriderComponent> WorldStriderComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<UFortOstrichVehicleConfigs> FortOstrichVehicleConfigs;

	UPROPERTY(Replicated)
	FOstrichWeapon_RetainedData CachedWeaponState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Character", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UCapsuleComponent> PickupCapsuleComponent;

	UPROPERTY()
	TObjectPtr<UBaseStatManager> OstrichCustomStats;

	UPROPERTY(EditDefaultsOnly, Category="SpecialActor")
	FScalableFloat SelfDestructInStormDelay;

private:
	UPROPERTY(Replicated)
	bool bDriverStompImmersionBlocked;

	UPROPERTY(Replicated)
	bool bDriverDashImmersionBlocked;

	UPROPERTY(Replicated)
	bool bDriverJumpImmersionBlocked;

	UPROPERTY(Replicated)
	bool bGunnerMissilesImmersionBlocked;

	UPROPERTY(Replicated)
	bool bGunnerShotgunImmersionBlocked;

};

