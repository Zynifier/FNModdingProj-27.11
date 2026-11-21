// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityRepAnimMontage.h"
#include "Audio/ActorSoundParameterInterface.h"
#include "Engine/NetSerialization.h"
#include "Engine/ReplicatedState.h"
#include "GameFramework/Character.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/FortMutatorContext.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Components/FortPawnComponent_CustomDepth.h"
#include "Creative/MeleeBlockingInterface.h"
#include "FortEffectDistanceQuality.h"
#include "FortMovementEnums.h"
#include "Pawns/FortPlayerPawn.h"
#include "Sound/FortFootstepBank.h"
#include "FortPlayerPawnAthena.generated.h"

class AActor;
class ABuildingContainer;
class ABuildingGameplayActor;
class ABuildingSMActor;
class AController;
class AFortAthenaVehicle;
class AFortEmitterCameraLensEffectDirectional;
class AFortPlayerPawnAthena;
class AFortVolume;
class APawn;
class UAnimMontage;
class UAudioComponent;
class UDataTable;
class UFXSystemComponent;
class UForceFeedbackEffect;
class UFortContrailsComponent;
class UFortMobileInteractionComponent;
class UFortPawnComponent_CustomDepth;
class UFortSkinWeightOverrideManager;
class ULegacyCameraShake;
class UMaterialInstanceDynamic;
class UNiagaraSystem;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USoundBase;
class UTexture2D;
class UUnicornAthenaPawnSampler;
class UWorld;
enum class EBackpackType : uint8;
enum class EDeathCause : uint8;

UENUM(BlueprintType)
enum class EBackpackType : uint8
{
	Jetpack = 0,
	Medic = 1,
	StormTracker = 2,
	Glider = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentMovementStyleChanged, TEnumAsByte<EFortMovementStyle::Type>, PreviousMovementStyle, TEnumAsByte<EFortMovementStyle::Type>, CurrentMovementStyle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnDisplayHitNotify, double, Damage, bool, Critical, bool, Fatal, bool, Shield, AActor*, HitPawn, FVector, HitLocation, FGameplayTagContainer, Tags);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFortDeathCause, AFortPlayerPawnAthena*, FortPlayerPawnAthena, EDeathCause, DeathCause);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFortPlayerDied, AFortPlayerPawnAthena*, FortPlayerPawnAthena);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFortPlayerHitByVehicle, AFortAthenaVehicle*, InstigatingVehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionFailedCallback, AFortPlayerPawnAthena*, FortPlayerPawnAthena);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerLootedContainer, AFortPlayerPawnAthena*, FortPlayerPawnAthena, ABuildingContainer*, LootedContainer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShieldBreak, bool, bInOverShield);

USTRUCT()
struct FAthenaPawnReplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float HealthRatio;

	UPROPERTY()
	float ShieldRatio;

private:
	UPROPERTY()
	TArray<uint8> CipherText;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UWorld> World;

};

USTRUCT()
struct FFortPlayerAthenaAttributeReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float WalkSpeed;

	UPROPERTY()
	float RunSpeed;

	UPROPERTY()
	float SprintSpeed;

	UPROPERTY()
	float FlySpeed;

	UPROPERTY()
	float CrouchedRunSpeed;

	UPROPERTY()
	float CrouchedSprintSpeed;

};

USTRUCT()
struct FFortPlayerAthenaGravityAttributeReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float GravityZScale;

	UPROPERTY()
	float JumpZVelocity;

	UPROPERTY()
	float JumpHorizontalAcceleration;

	UPROPERTY()
	float JumpHorizontalVelocity;

};

USTRUCT()
struct FFortPlayerPawnAthenaMovementNoiseOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthenaMovementNoiseOverride")
	float MinNoiseGenerationRange;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthenaMovementNoiseOverride")
	float MaxNoiseGenerationRange;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthenaMovementNoiseOverride")
	bool bShouldAlwaysGenerateNoise;

};

USTRUCT()
struct FSharedRepMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FRepMovement RepMovement;

	UPROPERTY(Transient)
	FBasedMovementInfo RepRelativeBasedMovement;

	UPROPERTY(Transient)
	float RepTimeStamp;

	UPROPERTY(Transient)
	FVector_NetQuantizeNormal RepGravityDirection;

	UPROPERTY(Transient)
	FRotator VehiclePrimaryTurretRotation;

	UPROPERTY(Transient)
	int8 VehicleMountedWeaponSeatIndex;

	UPROPERTY(Transient)
	FVector_NetQuantize VehicleMountedWeaponCameraDirection;

	UPROPERTY(Transient)
	FVector_NetQuantize VehicleMountedWeaponCameraLocation;

	UPROPERTY(Transient)
	uint32 RemoteViewData32;

	UPROPERTY(Transient)
	uint16 AccelerationPack;

	UPROPERTY(Transient)
	int8 AccelerationZPack;

	UPROPERTY(Transient)
	uint8 RepMovementMode;

	UPROPERTY(Transient)
	uint8 JumpFlashCountPacked;

	UPROPERTY(Transient)
	uint8 LandingFlashCountPacked;

	UPROPERTY(Transient)
	TEnumAsByte<EFortMovementStyle::Type> CurrentMovementStyle;

	UPROPERTY(Transient)
	bool bReplicatesBasedRelativeMovement;

	UPROPERTY(Transient)
	bool bProxyIsJumpForceApplied;

	UPROPERTY(Transient)
	bool bIsCrouched;

	UPROPERTY(Transient)
	bool bIsSkydiving;

	UPROPERTY(Transient)
	bool bIsParachuteOpen;

	UPROPERTY(Transient)
	bool bIsSlopeSliding;

	UPROPERTY(Transient)
	bool bIsProxySimulationTimedOut;

	UPROPERTY(Transient)
	bool bIsTargeting;

	UPROPERTY(Transient)
	bool bIsWaterJump;

	UPROPERTY(Transient)
	bool bIsWaterSprintBoost;

	UPROPERTY(Transient)
	bool bIsWaterSprintBoostPending;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AI", "Movement", "AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortPlayerPawnAthena : public AFortPlayerPawn, public IFortMutatorContext, public IFortMarkableActorInterface, public IMeleeBlockingInterface, public IActorSoundParameterInterface
{
	GENERATED_BODY()

	friend class UFortAnimNotifyState_SpawnProp;

public:
	UFUNCTION(BlueprintCallable)
	void AddComponentToPawnHighlightSet(UPrimitiveComponent* PrimitiveComponent);

	UFUNCTION(BlueprintCallable, Category="Highlighting")
	FCustomHighlightingHandle AddCustomHighlightingDataOverride(const FCustomHighlighting& CustomHighlightingData, int32 Priority = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	uint8 AddDBNORevivingActor(const AActor* RevivingActorToAdd);

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay", meta=(DeprecatedFunction, DeprecationMessage="This functionality is no longer available."))
	void BushStateChanged(bool bNewBushState);

	UFUNCTION(BlueprintCallable, Category="AthenaMovement")
	void CancelMeleeCombatSlow();

	UFUNCTION(BlueprintPure, Category="Creative")
	bool CanPlayerCreateInCurrentVolume(AFortVolume*& OutCurrentVolume) const;

	UFUNCTION(Client, Reliable)
	void ClientSetGravityJumpMultipliers(float NewGravityVal, float NewVehicleGravityVal, float NewJumpZ, float NewJumpHorizontalAcceleration, float NewJumpHorizontalVelocity);

	UFUNCTION(BlueprintCallable, Category="Pawn|Flying")
	void CreativeToggleGhost(const bool bEnableOnly = false);

	UFUNCTION(BlueprintCallable, Category="Pawn|Creative")
	void CreativeToggleInvulnerable();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ForceReviveFromDBNO(AController* EventInstigator);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="Functionality has been stripped from the runtime."))
	float GetCurrentVoiceAmplitude();

	UFUNCTION(BlueprintCallable)
	float GetDefaultReviveFromDBNOTime();

	UFUNCTION(BlueprintPure)
	float GetDownedDBNOInvulnerableTime() const;

	UFUNCTION(BlueprintPure, Category="AthenaMovement")
	float GetMeleeCombatSlowSpeedMultiplier() const;

	UFUNCTION(BlueprintPure)
	uint8 GetNumberOfDBNORevivingActors() const;

	UFUNCTION(BlueprintPure)
	float GetReviveFromDBNOTime() const;

	UFUNCTION(BlueprintPure)
	bool IsBackpackEquipped(EBackpackType BackpackType) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingMinigame() const;

	UFUNCTION(BlueprintCallable)
	virtual bool LocalIsTryingToEnterVehicle();

	UFUNCTION(BlueprintCallable, Category="AthenaMovement")
	void MeleeCombatActivated();

	UFUNCTION(BlueprintCallable, Category="AthenaMovement")
	void MeleeCombatBlocked();

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_SuccessfulBuildingEdit();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeModeratorModeActivate();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeModeratorModeDeactivate();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeStartGhost();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeStartInvulnerable();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeStopGhost();

	UFUNCTION(BlueprintImplementableEvent, Category="Creative")
	void OnCreativeStopInvulnerable();

	UFUNCTION(BlueprintImplementableEvent, Category="Replay")
	void OnEnteredReplayRelevancy();

	UFUNCTION(BlueprintImplementableEvent, Category="Replay")
	void OnLeftReplayRelevancy();

	UFUNCTION(BlueprintImplementableEvent, Category="Gameplay")
	void OnOutsideSafeZonePhaseChanged(int32 SafeZonePhase);

	UFUNCTION(BlueprintImplementableEvent, Category="StormSurge")
	void OnReceivedStormSurgeDamage();

	UFUNCTION()
	void OnRep_AttributeProxy();

	UFUNCTION()
	void OnRep_CapsuleHalfHeightAthena();

	UFUNCTION()
	void OnRep_CapsuleRadiusAthena();

	UFUNCTION()
	void OnRep_GravityAttributeReplicationProxy();

	UFUNCTION()
	void OnRep_MeshHeightAdjustAthena();

	UFUNCTION()
	void OnRep_ReplayRepAnimMontageInfo();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic, Category="AthenaPawn")
	void OnResInDuringWarmup();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="AthenaPawn")
	void OnSignificantTick(float Significance);

	UFUNCTION(BlueprintImplementableEvent, Category="Spawn")
	void OnSpawnImmunityTimeReset();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSuccessfulBuildingEdit();

	UFUNCTION(BlueprintCallable, Category="Highlighting")
	bool RemoveCustomHighlightingDataOverride(UPARAM(ref) FCustomHighlightingHandle& HandleToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	uint8 RemoveDBNORevivingActor(const AActor* RevivingActorToRemove);

	UFUNCTION(BlueprintCallable)
	void ResetCachedDBNOInvulnerableTime();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerCreativeToggleGhost(const bool bEnableOnly = false);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Pawn|Creative")
	void ServerCreativeToggleInvulnerable();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetInteractingItem(AActor* InteractingItem, bool bClearInteraction);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSuicide(bool bSuppressResurrectionChip, int32 MatchPlacement);

	UFUNCTION(BlueprintCallable, Category="Gameplay", meta=(DeprecatedFunction, DeprecationMessage="This functionality is no longer available."))
	void SetBushEnabled(bool bEnableBush);

	UFUNCTION(BlueprintCallable, Category="AthenaPawn")
	void SetCapsuleHalfHeightAthena(float HalfHeight);

	UFUNCTION(BlueprintCallable, Category="AthenaPawn")
	void SetCapsuleRadiusAthena(float Radius);

	UFUNCTION(BlueprintCallable)
	bool SetCharacterBodyVisibilityForPossession(bool bVisible);

	UFUNCTION(BlueprintCallable)
	void SetEnableRenderCustomDepth(bool bInEnableRenderCustomDepth);

	UFUNCTION(BlueprintCallable)
	void SetFallInstigator(AController* NewFallInstigator, FGameplayTagContainer NewFallingDamageTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DBNO")
	void SetImprovedDBNO(bool bEnable);

	UFUNCTION(BlueprintCallable, Category="Significance")
	void SetIsSignificantForSpecialEventSequence(const bool bIsSignificant);

	UFUNCTION(BlueprintCallable, Category="AthenaPawn")
	void SetMeshHeightAdjustAthena(double HeightAdjust);

	UFUNCTION(BlueprintCallable)
	virtual void SetRimLightIntensity(float Multiplier, const TArray<UMaterialInstanceDynamic*>& AllPawnMaterials);

	UFUNCTION(BlueprintCallable)
	void SetShouldDropItemsOnDeath(bool bInShouldDropItemsOnDeath);

	UFUNCTION(BlueprintCallable)
	void SetShouldSkipMovementFullSimulation(bool bInShouldSkipMovementFullSimulation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetUpdateSharedReplicationWhileAttached(bool bNewValue);

	UFUNCTION()
	void StartConsumableUseAudio(USoundBase* Sound);

	UFUNCTION()
	void StopConsumableUseAudio();

	UFUNCTION(BlueprintPure, Category="Swinging")
	FVector Swinging_VectorToAttachPoint(const FString& CallerID);

	UFUNCTION(BlueprintCallable)
	void TeleportToSkyDive(float HeightAboveGround);

	UFUNCTION()
	void TurnOnCollisionAfterSkydiveDelay();

	UPROPERTY(BlueprintAssignable)
	FOnInteractionFailedCallback OnInteractionFailedCallback;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortPlayerPawnAthena")
	TObjectPtr<AActor> ItemInteractionActor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPawn")
	FVector PreviousVelocityXY;

	UPROPERTY(EditDefaultsOnly, Category="Revive Audio")
	TObjectPtr<USoundBase> OnReviveSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Athena")
	float ReviveFromDBNOTime;

	UPROPERTY(Transient)
	float DBNOStartTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Athena")
	float DBNOInvulnerableTime;

	UPROPERTY(Transient)
	float CachedDBNOInvulnerableTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Athena")
	float ConvertFromDBNOTime;

	UPROPERTY(Replicated)
	float ServerWorldTimeRevivalTime;

	UPROPERTY(Transient)
	bool bWasCrouchedBeforeDBNO;

	UPROPERTY(Transient, Replicated)
	FName ItemSpecialActorID;

	UPROPERTY(Transient, Replicated)
	FGameplayTag ItemSpecialActorCategoryTag;

	UPROPERTY(Transient)
	float BecameSpecialActorTime;

	UPROPERTY(Config)
	bool bPlaytestWithNoMouse;

	UPROPERTY(ReplicatedUsing=OnRep_CapsuleRadiusAthena)
	float CapsuleRadiusAthena;

	UPROPERTY(ReplicatedUsing=OnRep_CapsuleHalfHeightAthena)
	float CapsuleHalfHeightAthena;

	UPROPERTY(ReplicatedUsing=OnRep_MeshHeightAdjustAthena)
	double MeshHeightAdjustAthena;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Character|Land")
	TObjectPtr<UParticleSystem> LandEmitterTemplate;

	UPROPERTY(ReplicatedUsing=OnRep_AttributeProxy)
	FFortPlayerAthenaAttributeReplicationProxy AttributeReplicationProxy;

	UPROPERTY(ReplicatedUsing=OnRep_GravityAttributeReplicationProxy)
	FFortPlayerAthenaGravityAttributeReplicationProxy GravityAttributeReplicationProxy;

	UPROPERTY(ReplicatedUsing=OnRep_ReplayRepAnimMontageInfo)
	FGameplayAbilityRepAnimMontage ReplayRepAnimMontageInfo;

	UPROPERTY(Replicated)
	FMinimalGameplayCueReplicationProxy SimulatedProxyActiveGameplayCues;

	UPROPERTY(Replicated)
	FMinimalGameplayCueReplicationProxy SimulatedProxyMinimalReplicationGameplayCues;

	UPROPERTY(Replicated)
	FMinimalReplicationTagCountMap FastReplicationMinimalReplicationTags;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPawnAthena")
	TObjectPtr<UTexture2D> CurrentQuickChatIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerPawnAthena")
	bool bADSWhileNotOnGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultCrouchedFootstepSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultCrouchSprintFootstepSound;

	UPROPERTY(BlueprintAssignable)
	FOnFortPlayerDied OnFortPlayerDied;

	UPROPERTY(BlueprintAssignable)
	FOnFortDeathCause OnFortDeathCause;

	UPROPERTY(BlueprintAssignable)
	FOnFortPlayerHitByVehicle OnFortPlayerHitByVehicle;

	UPROPERTY()
	TObjectPtr<APawn> KillerForSpectatorRotation;

	UPROPERTY(Config)
	bool bDelaySimProxyCollisionInAircraftPhase;

	UPROPERTY(Config)
	float TimeToDelaySkydiveCollision;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	float SkydiveAudioMovementVolumeInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	float SkydiveAudioForwardDotInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Parachute Audio")
	float SkydiveAudioRightDotInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Effects Quality")
	FFortEffectDistanceQuality DamageFXSignificance;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerLootedContainer OnPlayerLootedContainer;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnDisplayHitNotify DisplayHitNotify;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnShieldBreak OnShieldBreak;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnCurrentMovementStyleChanged OnCurrentMovementStyleChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapons")
	TObjectPtr<UDataTable> PrototypeShootingModel;

	UPROPERTY(Transient)
	TObjectPtr<AController> FallInstigator;

	UPROPERTY(Transient)
	FGameplayTagContainer FallDamageTags;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> LastFloorBeforeFalling;

	UPROPERTY(Transient)
	float LastFallDistance;

	UPROPERTY(Transient)
	float SkydiveDebugTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	float MeleeCombatSlowSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaMovement")
	float MeleeCombatSlowDuration;

	UPROPERTY(Transient, Replicated)
	FAthenaPawnReplayData EncryptedPawnReplayData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Sounds", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> InAirAudioComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_PlayerWalkLand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_PlayerRunLand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="FX", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> PSC_HitDamage;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerRunDustKickupComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerWalkDustKickupComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> NiagaraPlayerLandDustPuffComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerRunDustKickup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerWalkDustKickup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TObjectPtr<UNiagaraSystem> NiagaraPlayerLandDustPuff;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FName PlayerKickupFXSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	FName PlayerKickupSurfaceParameterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FX")
	TArray<TEnumAsByte<EFortFootstepSurfaceType::Type>> PlayerKickupSurfaceParamList;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortContrailsComponent> ContrailsComponent;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bIsCreativeGhostModeActivated, Category="FortPlayerPawnAthena")
	bool bIsCreativeGhostModeActivated;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bIsCreativeModeratorModeActivated, Category="FortPlayerPawnAthena")
	bool bIsCreativeModeratorModeActivated;

	UPROPERTY()
	FGameplayTagContainer InvulnerabilityTags;

	virtual void GetActorSoundParams_Implementation(TArray<FAudioParameter>& Params) const override;

protected:
	UFUNCTION()
	void GameplayCue_Creative_PossessProp(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	void GameplayCue_PinkOatmeal_MeatPizza_PossessProp(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintNativeEvent)
	UAnimMontage* GetAdditiveHitReactsMontage();

	UFUNCTION()
	void LandscapeCheck();

	UFUNCTION()
	void OnRep_bIsCreativeGhostModeActivated();

	UFUNCTION()
	void OnRep_bIsCreativeModeratorModeActivated();

	UFUNCTION()
	void OnRep_ImprovedDBNOEnabled();

	UFUNCTION(Server, Reliable)
	void ServerForceImmediateLandscapeCheck();

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetDamageCameraShakeClass(TSubclassOf<ULegacyCameraShake> NewValue);

	UFUNCTION(BlueprintCallable, meta=(HidePin="bRegister"))
	void SpawnNiagaraEnvironmentComponents(const bool bRegister = true);

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void SwingingUpdateMeshRotation(float DeltaTime);

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FortPlayerPawnAthena", meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_CustomDepth> CustomDepthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	FGameplayTagContainer IgnoreLandGhostModeTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Character|Land")
	TObjectPtr<UParticleSystem> LandWindEmitterTemplate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	FVector LandFXLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float LandFXRotateYawMaxDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float LandFXMaxDrawDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float LandForceIntensityVelocityZFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float MinLandForceIntensity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float MaxLandForceIntensity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float MinLandForceDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float MaxLandForceDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float LandFXCoolDownTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character|Land")
	float LandFXPawnRecentRenderTolerance;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	TSubclassOf<AFortEmitterCameraLensEffectDirectional> ScreenEffectHealthDamage;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	TSubclassOf<AFortEmitterCameraLensEffectDirectional> ScreenEffectShieldDamage;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	TObjectPtr<UAnimMontage> AdditiveHitReactsMontage;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	FGameplayTagContainer DamageTagsToNotDisplayDirectionDamage;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	FGameplayTagContainer DamageTagsToNotAddCameraShake;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	FGameplayTagContainer WeaponTagsToNotPlayCircleAndStreakFX;

	UPROPERTY()
	bool bIsPlayerPawnReady;

	UPROPERTY(Transient)
	FVector LastFiredLocation;

	UPROPERTY(Transient)
	FVector LastFiredDirection;

	UPROPERTY(Transient)
	float LastFiredTime;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMobileInteractionComponent>> MobileInteractionComponents;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorFiftyFiftyPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerPawnAthena")
	float MaxIndicatorVisibilityDistForReplays;

	UPROPERTY(BlueprintReadOnly, Export, Category="Sounds", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ConsumableUseAudio;

	UPROPERTY(BlueprintReadOnly, Category="Sounds")
	float InAirAudioParameterValue;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	float InAirAudioFallDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="FX")
	float WalkDustActivateSpeed;

	UPROPERTY(EditDefaultsOnly, Category="FX")
	float WalkDustResetSpeed;

	UPROPERTY(EditDefaultsOnly, Category="FX")
	float RunParticleActivateSpeed;

	UPROPERTY()
	float LastHealthPostProcessWeight;

	UPROPERTY()
	float HealthPostProcessStartTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerPawnAthena")
	float HealthPostProcessMuteTime;

	UPROPERTY(Transient)
	TObjectPtr<UFortSkinWeightOverrideManager> SkinWeightManager;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FVector MarkerPositionOffset;

	UPROPERTY(EditDefaultsOnly, Category="Damage Reaction")
	TObjectPtr<UForceFeedbackEffect> DamageForceFeedback;

	UPROPERTY(EditDefaultsOnly, BlueprintSetter=SetDamageCameraShakeClass, Category="Damage Reaction")
	TSubclassOf<ULegacyCameraShake> DamageCameraShakeClass;

	UPROPERTY(EditDefaultsOnly, Category="Damage Reaction")
	FGameplayTagContainer DamageTagsExcludedFromCameraShake;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortPlayerPawnAthena")
	int32 UpdateSharedReplicationWhileAttachedCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float BP_RotationSpeedWhenTurnedOffByAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float BP_RotationSpeedOnDetach;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float BP_MaxRotationSpeedWhenAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float BP_TimeToReachMaxRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float BP_AddedRotationInfluenceFromForwardVectorOnAttach;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FRotator YawNegative90;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FString CallerID_update_mesh_rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float AttachPointNormalizeTolerance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float ForwardProjectedNormalizeTolerance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	TObjectPtr<ABuildingGameplayActor> Swinging_AttachBGA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FVector Swinging_RightVec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	float Swinging_LastAttachTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	bool bSwingingShouldRotateMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	bool bSwinging_UseProgrammaticRotation;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ImprovedDBNOEnabled)
	bool bImprovedDBNOEnabled;

	UPROPERTY(Replicated)
	uint8 DBNORevivingActorsCount;

private:
	UFUNCTION(NetMulticast, Unreliable)
	void FastSharedReplication(const FSharedRepMovement& SharedRepMovement);

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldPawnInstantDie;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldPawnDBNODisplayOnKillFeed;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldPawnDeathDisplayOnKillFeed;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldPawnLeaveEliminationIndicator;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldPawnAwardPoints;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldTriggerDeathAnalytics;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldDropItemsOnDeath;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	bool bShouldSkipMovementFullSimulation;

	UPROPERTY(EditDefaultsOnly, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	uint8 bEnableGroundInteractionEffects : 1;

	UPROPERTY(Replicated)
	FMinimalReplicationTagCountMap FastReplicationReplicatedLooseTags;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUnicornAthenaPawnSampler> UnicornPawnSampler;

};

