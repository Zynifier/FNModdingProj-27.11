// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemReplicationProxyInterface.h"
#include "ActiveGameplayEffectHandle.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Character.h"
#include "GameplayCueInterface.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "GameplayPrediction.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Perception/AISightTargetInterface.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "AI/AthenaAIBudgetManagerTypes.h"
#include "AI/FortAIEncounterInfoOwnerInterface.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Abilities/FortTargetSelectionInterface.h"
#include "Attributes/FortRegenHealthSetInterface.h"
#include "Conversation/FortConversation.h"
#include "Curie/FortCurieInterface.h"
#include "FGF_Character.h"
#include "FortAutoFireTargetInterface.h"
#include "FortClientSettingsRecord.h"
#include "FortCombatTypes.h"
#include "FortDamageZoneEnum.h"
#include "FortDamageableActorInterface.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortLockOnTargetInterface.h"
#include "FortMovementEnums.h"
#include "FortReplicationGraphInterface.h"
#include "FortSoundCameraLensEffect.h"
#include "FortSoundIndicatorInterface.h"
#include "FortSpottableActorInterface.h"
#include "FortTeamActorInterface.h"
#include "Items/FortPickupEntryData.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "Movement/FortMovementMode_ExtType.h"
#include "Pawns/FortPawnTypes.h"
#include "Sound/FortAudioTypes.h"
#include "Sound/FortFootstepBank.h"
#include "Sound/FortSwimmingAudioBank.h"
#include "Stats/FortStatManagerTag.h"
#include "FortPawn.generated.h"

class AActor;
class ABuildingActor;
class ABuildingContainer;
class AController;
class AEmitterCameraLensEffectBase;
class AFortEmitterCameraLensEffectDirectional;
class AFortPawn;
class AFortPickup;
class AFortSkyTube;
class AFortSoundCameraLensEffect;
class AFortWaterBodyActor;
class AFortWeapon;
class ICameraLensEffectInterface;
class IFortHolsterWeaponSourceInterface;
class UAbilitySystemComponent;
class UActorComponent;
class UAnimInstance;
class UAnimMontage;
class UAudioComponent;
class UAudioParameterComponent;
class UFXSystemComponent;
class UFortAIEncounterInfo;
class UFortAbilitySystemComponent;
class UFortAdvancedMovementSet;
class UFortAnimInputEvent;
class UFortAthenaAILODComponent;
class UFortControlResistanceSet;
class UFortDamageSet;
class UFortDecoItemDefinition;
class UFortEmoteComponent;
class UFortFeedbackBank;
class UFortFootstepAudioBank;
class UFortFootstepComponent;
class UFortGameStateComponent_AffiliationManager;
class UFortGameplayAbility;
class UFortGameplayModifierItemDefinition;
class UFortHealthBarIndicator;
class UFortHealthSet;
class UFortItemDefinition;
class UFortMovementMode_BaseExtLogic;
class UFortMovementSet;
class UFortPawnComponent;
class UFortSoundIndicatorComponent;
class UFortSoundLibraryComponent;
class UFortStormShieldComponent;
class UFortSurfaceTrackingComponent;
class UFortSwimmingAudioBank;
class UFortWeaponItemDefinition;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class UMeshComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPegasusGameEventCollector;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USkeletalMeshSocket;
class USoundAttenuation;
class USoundBase;
class USoundEffectSourcePresetChain;
class UTexture;
class UWeaponHitNotifyAudioBank;
enum class EFortAbilityTargetingSource : uint8;
enum class EFortControlRecoveryBehavior : uint8;
enum class EFortSoundIndicatorTypes : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterCrouchChangedDelegate, const bool, bCrouched);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortPawnEquippedWeaponSignature, AFortWeapon*, NewWeapon, AFortWeapon*, PrevWeapon);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FFortPawnHitSignature, AActor*, SelfActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortPawnUnEquippedWeaponSignature);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilityTargetingBlocked);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBaseChangedDelegate, AFortPawn*, Pawn, AActor*, NewBase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDBNOStateChangedEvent, AFortPawn*, FortPawn, bool, bInIsDBNO);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHolsteredEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnComponentAttached, AFortPawn*, OwnerPawn, UFortPawnComponent*, AttachedComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPawnHiddenForDeath);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnSearchedContainer, AFortPawn*, SearchingPawn, ABuildingContainer*, Container);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerStartDBNO);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSkyTubeChanged, AFortPawn*, Pawn, AFortSkyTube*, NewSkyTube, AFortSkyTube*, OldSkyTube);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldComponentCreated, UFortStormShieldComponent*, StormShieldComponent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnholsteredEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(FPawnDamagedSignature, AActor*, DamagedActor, float, Damage, AController*, InstigatedBy, AActor*, DamageCauser, FVector, HitLocation, UPrimitiveComponent*, FHitComponent, FName, BoneName, FVector, Momentum);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FPawnDeathEffectsSignature, AActor*, DeadActor, float, Damage, AFortPawn*, InstigatedBy, FVector, HitLocation, AActor*, DamageCauser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPawnEmoteSignature, const UFortItemDefinition*, MontageItemDef, AFortPawn*, PawnEmoting);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnHealthChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPawnLandedSignature, const FHitResult&, Hit);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnMaxOvershieldChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPawnTeleportedSignature, AFortPawn*, FortPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnUpdatedDecisionWindowStackSignature);

USTRUCT(BlueprintType)
struct FFortPawnPossessed
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPawnPossessed")
	TWeakObjectPtr<AController> Controller;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnPossessed")
	TWeakObjectPtr<AFortPawn> Pawn;

};

USTRUCT(BlueprintType)
struct FFortPawnUnpossessed
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPawnUnpossessed")
	TWeakObjectPtr<AController> Controller;

	UPROPERTY(BlueprintReadOnly, Category="FortPawnUnpossessed")
	TWeakObjectPtr<AFortPawn> Pawn;

};

USTRUCT()
struct FHolsterRequestData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TScriptInterface<IFortHolsterWeaponSourceInterface> HolsterSource;

	UPROPERTY()
	FName HolsterId;

};

USTRUCT()
struct FRepMovementModeExtension
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool DummyVar;

};

USTRUCT()
struct FSoundIndicatorTypesWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SoundIndicatorTypesWrapper")
	TArray<EFortSoundIndicatorTypes> FortSoundIndicatorTypes;

};

UCLASS(Abstract, MinimalAPI, HideCategories=("Actor", "Movement", "Game|Damage", "Navigation"))
class AFortPawn : public AFGF_Character, public IFortTeamActorInterface, public IGameplayTagAssetInterface, public IFortDamageableActorInterface, public IFortSpottableActorInterface, public IFortAbilitySystemInterface, public IGameplayCueInterface, public IFortTargetSelectionInterface, public IFortAIEncounterInfoOwnerInterface, public IVisualLoggerDebugSnapshotInterface, public IFortHealthRegenInterface, public IAISightTargetInterface, public IFortAutoFireTargetInterface, public IFortLockOnTargetInterface, public IAbilitySystemReplicationProxyInterface, public IFortCurieInterface, public IFortReplicationGraphInterface, public IFortSoundIndicatorInterface, public IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Components")
	UActorComponent* AddDynamicComponentByClass(TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintCallable, Category="Emote")
	void AddEmoteAudioComponent(FName SoundID, UAudioComponent* AudioComponent, float FadeOutTime, bool bPersistsOverMontages);

	UFUNCTION(BlueprintCallable)
	void AddProjectileIgnoreActor(AActor* ActorToIgnore);

	UFUNCTION(BlueprintCallable)
	void AddWeaponTraceIgnoreActor(AActor* ActorToIgnore);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void AlignRotationToHitDirection(const FVector& HitDirection);

	UFUNCTION(BlueprintCallable, Category="Animation")
	int32 AnimMontage_LocalJumpToRandomSection();

	UFUNCTION(BlueprintCallable, Category="Animation")
	bool AnimMontage_LocalJumpToSectionName(FName SectionName);

	UFUNCTION(BlueprintCallable, Category="Animation")
	void AnimMontage_LocalSetNextSectionName(UAnimMontage* AnimMontage, FName SectionName, FName NextSectionName);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="HitReaction")
	void ApplyKnockback(float KnockbackMagnitude, float KnockbackZAngle, FVector ImpulseDir);

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual bool AreEmoteAudioComponentsAllowed() const;

	UFUNCTION(BlueprintCallable, Category="Attachments")
	void AttachAssetToSocket(const FAssetAttachment& InAttachment);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Animation")
	void BroadcastLinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Animation")
	void BroadcastUnlinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(BlueprintPure, Category="Feedback")
	bool CanSpawnSoundVisuals(EFortSoundIndicatorTypes IndicatorType) const;

	UFUNCTION(BlueprintCallable, Category="Emote")
	void ClearEmoteAudioComponents(UFortItemDefinition* EmoteItemDef);

	UFUNCTION(BlueprintCallable, Category="Components")
	bool DestroyDynamicComponent(UActorComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Attachments")
	void DetachAssetFromSocket(FName SocketName);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	void DoFatalDamage(UAbilitySystemComponent* KillerAbilitySystemComponent);

	UFUNCTION(BlueprintCallable, Category="Emote")
	virtual void EmoteStarted(UFortItemDefinition* MontageItemDef);

	UFUNCTION(BlueprintCallable, Category="Emote")
	virtual void EmoteStopped(UFortItemDefinition* MontageItemDef);

	UFUNCTION(BlueprintCallable, Category="SkyTube")
	virtual void EnterSkyTube(AFortSkyTube* SkyTube, bool& bOutIsFirstTube);

	UFUNCTION(BlueprintCallable)
	virtual bool EquipBestWeapon();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Weapon")
	AFortWeapon* EquipWeaponDefinition(const UFortWeaponItemDefinition* WeaponData, FGuid ItemEntryGuid, FGuid TrackerGuid, bool bDisableEquipAnimation = false);

	UFUNCTION(BlueprintCallable, Category="SkyTube")
	virtual void ExitSkyTube(AFortSkyTube* SkyTube, bool& bOutIsLastTube);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	void ForceKill(FGameplayTag DeathReason, AController* KillerController, AActor* KillerActor);

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual TArray<UAudioComponent*> GetAllEmoteAudioComponents() const;

	UFUNCTION(BlueprintCallable, Category="Attachments")
	USkeletalMeshComponent* GetAssetSkeletalMeshComponentAttachment(FName SocketName);

	UFUNCTION(BlueprintPure, Category="Control Resistance")
	EFortControlRecoveryBehavior GetControlRecoveryBehavior() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetControlResistance() const;

	UFUNCTION(BlueprintCallable, Category="Animation")
	float GetCurrentMontageSectionTimeLeft();

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetCurrentOvershield() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	AFortSkyTube* GetCurrentSkyTube() const;

	UFUNCTION(BlueprintPure, Category="WaterBody")
	AFortWaterBodyActor* GetCurrentWaterBody() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	AFortWeapon* GetCurrentWeapon() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	const TArray<AFortWeapon*>& GetCurrentWeaponList() const;

	UFUNCTION(BlueprintPure, Category="DamageZones")
	virtual EFortDamageZone::Type GetDamageZone(const FHitResult& InHitResult) const;

	UFUNCTION(BlueprintPure, Category="Targeting")
	virtual FVector GetDefaultTargetingOrigin() const;

	UFUNCTION(BlueprintPure, Category="Targeting")
	virtual FRotator GetDefaultTargetingRotation() const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual UAudioComponent* GetEmoteAudioComponent(FName SoundId = NAME_None) const;

	UFUNCTION(BlueprintPure, Category="Emote")
	UFortEmoteComponent* GetEmoteComponent() const;

	UFUNCTION(BlueprintCallable, Category="Emote")
	virtual USkeletalMeshComponent* GetEmotePropAttachMesh();

	UFUNCTION(BlueprintPure, Category="Encounter")
	virtual UFortAIEncounterInfo* GetEncounterInfo() const;

	UFUNCTION(BlueprintPure, Category="Emote")
	virtual UAudioComponent* GetFirstValidEmoteAudioComponent() const;

	UFUNCTION(BlueprintPure, Category="Movement Audio")
	EFortFootstepSurfaceType::Type GetFootstepSurfaceType() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetHealth() const;

	UFUNCTION()
	virtual float GetHealthPercent() const;

	UFUNCTION(BlueprintPure, Category="FallDamage")
	FName GetIgnoreFallDamageComponentTag() const;

	UFUNCTION(BlueprintPure, Category="AthenaMovement")
	bool GetIsSlopeSliding() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool GetIsSwingAttached() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool GetIsSwinging() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetKnockbackMultiplier() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetKnockbackThreshold() const;

	UFUNCTION(BlueprintPure, Category="Spin")
	float GetLocalSpin() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetMaxControlResistance() const;

	UFUNCTION(BlueprintPure, Category="FallDamage")
	float GetMaxDistanceWithoutFallDamage() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	float GetMaxOvershield() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetMaxShield() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetMaxSignalInStorm() const;

	UFUNCTION(BlueprintPure, Category="Melee")
	int32 GetMeleeComboCounter() const;

	UFUNCTION(BlueprintPure, Category="Melee")
	float GetMeleeReticleStrikeAngle(bool bPrimaryInput = true) const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	FVector GetMovementPredictionPosition(float PredictionDeltaTime) const;

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	AActor* GetMyMovementBaseActor();

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetOvershield() const;

	UFUNCTION()
	virtual float GetOvershieldPercent() const;

	UFUNCTION(BlueprintCallable, Category="FortPawn", meta=(DisplayName="Get Dynamic Material Instance"))
	UMaterialInstanceDynamic* GetPawnMID(int32 ElementIndex);

	UFUNCTION(BlueprintPure, Category="Pawn|Character")
	FVector GetPendingLaunchVelocity() const;

	UFUNCTION(BlueprintPure)
	TArray<AActor*> GetProjectileIgnoredActors() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetShield() const;

	UFUNCTION()
	float GetShieldOrHealthPercent();

	UFUNCTION()
	virtual float GetShieldPercent() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	virtual float GetSignalInStorm() const;

	UFUNCTION(BlueprintPure)
	void GetSimplifiedSavedPositions(TArray<FSavedPosition>& OutPositions, bool bStopAtTeleport) const;

	UFUNCTION(BlueprintPure, Category="AthenaMovement")
	void GetSlopeSlidingAngles(float& LocalPitch, float& LocalRoll) const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	void GetSphericalHitDirection(const FVector& HitDirection, float& Azimuth, float& Elevation) const;

	UFUNCTION(BlueprintPure, Category="Footsteps")
	UFortSurfaceTrackingComponent* GetSurfaceTrackingComponent() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	FVector GetSwingAttachLocation() const;

	UFUNCTION(BlueprintCallable, Category="Swinging")
	float GetSwingingDistanceToGround();

	UFUNCTION(BlueprintPure, Category="Targeting")
	virtual FTransform GetTargetingTransform(EFortAbilityTargetingSource Source, UFortGameplayAbility* SourceAbility = nullptr) const;

	UFUNCTION(BlueprintPure)
	virtual uint8 GetTeam() const;

	UFUNCTION(BlueprintPure, Category="WaterBody")
	float GetWaterImmersionDepth() const;

	UFUNCTION()
	virtual void HandleIsDying();

	UFUNCTION()
	virtual void HandleIsHiddenForDeath();

	UFUNCTION(BlueprintPure, Category="Animation")
	bool HasCurrentMontage() const;

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void HideBodyOnDeath(bool bDeathAnimationPlayed);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void InitializeDeathHitSocket(FVector WorldLocation, FVector WorldNormal);

	UFUNCTION(BlueprintPure, Category="Pawn|Input")
	virtual bool IsActionInputIgnored() const;

	UFUNCTION(BlueprintPure, Category="Control Resistance")
	bool IsAllowChainStun() const;

	UFUNCTION(BlueprintPure, Category="Health")
	bool IsDBNO() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	bool IsDead() const;

	UFUNCTION(BlueprintPure, Category="WaterBody")
	bool IsForciblyWadingInWater() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	bool IsFrontalHit(const FVector& HitDirection) const;

	UFUNCTION(BlueprintPure, Category="Goop")
	bool IsInGoop() const;

	UFUNCTION(BlueprintPure)
	bool IsInsideHidingProp(const bool bIncludeTransition = false) const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsInSkyTube() const;

	UFUNCTION(BlueprintPure, Category="Vortex")
	bool IsInVortex() const;

	UFUNCTION(BlueprintPure, Category="Sliding")
	bool IsSlidingEnabled() const;

	UFUNCTION(BlueprintPure, Category="Spin")
	bool IsSpinning() const;

	UFUNCTION(BlueprintPure, Category="Control Resistance")
	bool IsStaggered() const;

	UFUNCTION(BlueprintPure, Category="WaterBody")
	bool IsSurfaceSwimming() const;

	UFUNCTION(BlueprintPure, Category="Turn Transition")
	bool IsTurnTransitionActiveAndControllingRotation() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	bool IsWeaponHiddenByHolstering() const;

	UFUNCTION(BlueprintPure, Category="Weapon")
	bool IsWeaponHolstered() const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Overlapping Buildings"))
	TArray<ABuildingActor*> K2_GetOverlappingBuildings() const;

	UFUNCTION(BlueprintCallable, Category="Pawn|Character")
	virtual void LaunchCharacterJump(FVector LaunchVelocity, bool bXYOverride, bool bZOverride, bool bIgnoreFallDamage = false, bool bPlayFeedbackEvent = true);

	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual void LinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(BlueprintCallable)
	void LogChugSplashEvent();

	UFUNCTION()
	virtual void MaxHealthStateChanged(bool bIsMaxHealth);

	UFUNCTION(BlueprintCallable, Category="Emote")
	void MovingEmoteStopped();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Animation")
	void MulticastLinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Animation")
	void MulticastUnlinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_Athena_BatchedDamageCues(FAthenaBatchedDamageGameplayCues_Shared SharedData, FAthenaBatchedDamageGameplayCues_NonShared NonSharedData);

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueAdded(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueAdded_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters Parameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueAddedAndWhileActive_FromSpec(const FGameplayEffectSpecForRPC& Spec, FPredictionKey PredictionKey) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueAddedAndWhileActive_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueExecuted(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueExecuted_FromSpec(const FGameplayEffectSpecForRPC Spec, FPredictionKey PredictionKey) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCueExecuted_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCuesAddedAndWhileActive_WithParams(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCuesExecuted(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_InvokeGameplayCuesExecuted_WithParams(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Animation")
	void OnAnimInputEvent(const UFortAnimInputEvent* AnimInputEvent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBaseChanged(AActor* NewBase);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnBeginWaterInteraction(FVector WaterSurfaceLocation, float WaterDepth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnBuildingHitPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, FGameplayEffectContextHandle EffectContext, bool bPlayerPlaced);

	UFUNCTION(BlueprintImplementableEvent, Category="HitReaction")
	void OnBumpPushedPawn(AFortPawn* InstigatedBy, float PushTimeLeft);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDamagePlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnDamageServer(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamageZoneStatusChanged(EFortDamageZone::Type Zone, bool bStatus);

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic)
	void OnDeathPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnDeathServer(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayHitNotify(float DamageDealt, bool bCriticalHit, bool bFatalHit, bool bShieldHit, AActor* HitActor, FGameplayTagContainer HitTags, FVector HitLocation);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnEndWaterInteraction(FVector PreviousWaterSurfaceLocation, float WaterDepth);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnEnteredWaterBody(AFortWaterBodyActor* WaterBody, bool bIsFirstBody);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnExitedWaterBody(AFortWaterBodyActor* WaterBody, bool bIsLastBody);

	UFUNCTION(BlueprintPure, Category="Spin")
	bool OnlySpinWhenFalling() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnMovementStyleChanged(EFortMovementStyle::Type PreviousMovementStyle, EFortMovementStyle::Type NewMovementStyle);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnOutOfControlResistanceServer(float ImpactDamageDone, const FGameplayTagContainer& SourceTags, const FGameplayEffectContextHandle& EffectContext, AController* EffectInstigator, AActor* EffectCauser);

	UFUNCTION()
	virtual void OnRep_bIsInvulnerable();

	UFUNCTION()
	void OnRep_bWeaponHolstered();

	UFUNCTION()
	virtual void OnRep_CurrentWeapon(AFortWeapon* OldWeapon);

	UFUNCTION()
	void OnRep_DamageZoneActiveBitMask();

	UFUNCTION()
	virtual void OnRep_EmoteWalkSpeed();

	UFUNCTION()
	virtual void OnRep_IsSkating();

	UFUNCTION()
	virtual void OnRep_IsSliding();

	UFUNCTION()
	virtual void OnRep_IsSynchedAction();

	UFUNCTION()
	virtual void OnRep_JumpFlashCount();

	UFUNCTION()
	virtual void OnRep_LandingFlashCount();

	UFUNCTION()
	virtual void OnRep_LastReplicatedEmoteExecuted(const UFortItemDefinition* PreviousValue);

	UFUNCTION()
	virtual void OnRep_MovingEmote();

	UFUNCTION()
	virtual void OnRep_MovingEmoteFollowingOnly();

	UFUNCTION()
	void OnRep_PawnUniqueID();

	UFUNCTION()
	void OnRep_ReplicatedIsInGoop();

	UFUNCTION()
	void OnRep_ReplicatedSkyTube();

	UFUNCTION()
	virtual void OnRep_SynchedActionWarpPointInfo();

	UFUNCTION()
	virtual void OnRep_TeleportCounter();

	UFUNCTION()
	virtual void OnRep_VocalChords();

	UFUNCTION()
	void OnRep_WeaponActivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	void OnStunned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeleported();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void PawnStartFire(uint8 FireModeNum = 0);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void PawnStartSecondaryFire(uint8 FireModeNum = 0);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void PawnStopFire(uint8 FireModeNum = 0);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	virtual void PawnStopSecondaryFire(uint8 FireModeNum = 0);

	UFUNCTION(BlueprintImplementableEvent)
	void PawnUniqueIDSet();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	virtual bool PickUpActor(AActor* PickupTarget, const UFortDecoItemDefinition* PlacementDecoItemDefinition);

	UFUNCTION(BlueprintCallable, Category="Audio")
	virtual void PlayFootStepSound(int32 FootDown);

	UFUNCTION(BlueprintCallable, Category="Animation")
	float PlayLocalAnimMontage(UAnimMontage* NewAnimMontage, float InPlayRate = 1.000000f, FName StartSectionName = NAME_None, bool bNoBlend = false);

	UFUNCTION(Client, Unreliable)
	void PlaySound(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier);

	UFUNCTION(BlueprintCallable, Category="Swimming Audio")
	void PlaySwimmingSound(EFortSwimmingAudioType::Type SoundType);

	UFUNCTION()
	void PooledCascadeCameraLensEffectCompleted(UParticleSystemComponent* FinishedComponent);

	UFUNCTION()
	void PooledNiagaraCameraLensEffectCompleted(UNiagaraComponent* FinishedComponent);

	UFUNCTION(BlueprintCallable, Category="Pawn|Character")
	void PrototypeCharacterMovement(EMovementMode MovementMode, FVector LaunchVelocity);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterAdditionalGameplayModifiers(const TArray<UFortGameplayModifierItemDefinition*>& ModifierDefinitions);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Callouts")
	void RemoveCallout(const FGameplayTag& CalloutTagToRemove);

	UFUNCTION(BlueprintCallable)
	void RemoveProjectileIgnoreActor(AActor* ActorToRemove);

	UFUNCTION(BlueprintCallable)
	void RemoveWeaponTraceIgnoreActor(AActor* ActorToRemove);

	UFUNCTION(BlueprintCallable, Category="Pawn|Character")
	void ResetFallingHeight();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTeleportNearLocation(FVector ActorLocation);

	UFUNCTION(BlueprintCallable, Category="Emote")
	virtual void SetAllowEmoteAudioComponents(const bool InAllowEmoteAudioComponents);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Callouts")
	void SetCallout(const FGameplayTag& CalloutTagToSet, float Duration = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="WaterBody")
	bool SetCommonWaterFXParams(UFXSystemComponent* FXComponent, const bool bUpdateWaveData = true, const bool bUpdatePlaneData = true, const bool bUpdateSurfaceData = true);

	UFUNCTION(BlueprintCallable, Category="Control Resistance")
	void SetControlRecoveryBehavior(EFortControlRecoveryBehavior NewBehavior);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetCurrentOvershield(float NewShieldValue);

	UFUNCTION(BlueprintCallable, Category="Pawn|Character")
	void SetFallingHeight(float FromHeight);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetFNameBasedOnHitDirection(const FVector& HitDirection, FName& NameResult, FName NameFront, FName NameBack, FName NameLeft, FName NameRight);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void SetGravityJumpMultipliers(float NewGravityVal, float NewVehicleGravityVal, float NewJumpZ, float NewJumpHorizontalAcceleration, float NewJumpHorizontalVelocity);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void SetGravityMultiplier(float NewGravityVal);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetHealth(float NewHealthVal);

	UFUNCTION(BlueprintCallable, Category="Weapon", meta=(DefaultToSelf="HolsterSource", DisplayName="Set Holster Weapon"))
	void SetHolsterWeaponBP(const TScriptInterface<IFortHolsterWeaponSourceInterface> HolsterSource, const bool bHolster, const bool bPlayEquipAnim = false, const FName HolsterId = NAME_None);

	UFUNCTION(BlueprintCallable, Category="Vortex")
	virtual void SetInVortex(bool bNewValue, float UpwardLaunchVelocity, float GravityFloorAltitude, float GravityFloorWidth, float GravityFloorGravityScalar, float GravityFloorTerminalVelocity, const bool bCanDeployGlider = true);

	UFUNCTION(BlueprintCallable, Category="Vortex")
	virtual void SetInVortexVolume(const bool bIsInVortexVolume, const float UpwardLaunchVelocity, const FTransform VolumeTransform, const float VolumeThickness, const float GravityScalar, const float VolumeEdgeTerminalVelocity, const bool bCanDeployGlider = true);

	UFUNCTION(BlueprintCallable, Category="Vortex")
	virtual void SetInVortexWithSpin(bool bNewValue, float UpwardLaunchVelocity, float GravityFloorAltitude, float GravityFloorWidth, float GravityFloorGravityScalar, float GravityFloorTerminalVelocity, FVector SpinCenter, float SpinRadius, float SpinVelocity);

	UFUNCTION(BlueprintCallable, Category="Goop")
	void SetIsInGoop(const bool bNewValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="HitReaction")
	void SetIsKnockedBack(bool bKnockback);

	UFUNCTION(BlueprintCallable, Category="Skating")
	void SetIsSkating(const bool bNewIsSkating);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetMaxHealth(float NewHealthVal);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetMaxOvershield(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetMaxShield(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetMaxSignalInStorm(float NewValue);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetMovementSpeedMultiplier(float NewMovementSpeedVal);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetPawnAndControlRotation(FRotator NewRotation);

	UFUNCTION(BlueprintCallable, Category="FortPawn", meta=(DisplayName="SetPawnVisibilityLocal", Keywords="Visible Hidden Show Hide"))
	virtual void SetPawnVisibility(const bool bNewHidden, const bool bPropagateToWeapon = true);

	UFUNCTION(BlueprintCallable, Category="FortPawn", meta=(DisplayName="SetPawnVisibilityLocalControllerOnly", Keywords="Visible Hidden Show Hide"))
	virtual void SetPawnVisibilityControllerOnly(const bool bNewHidden, const bool bPropagateToWeapon = true);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetShield(float NewShieldValue);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetSignalInStorm(float NewSignalInStormValue);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void SetSpawnSpot(AActor* InSpawnSpot);

	UFUNCTION(BlueprintCallable, Category="Turn Transition")
	void SetTurnTransitionActiveAndControllingRotation(bool bInControl);

	UFUNCTION(BlueprintCallable, Category="Feedback", meta=(DeprecatedFunction, DeprecationMessage="Prefer the version using the CameraLensEffectInterface (SpawnGenericCameraLensEffect)"))
	AEmitterCameraLensEffectBase* SpawnCameraLensEffect(TSubclassOf<AEmitterCameraLensEffectBase> LensEffectEmitterClass);

	UFUNCTION(BlueprintCallable, Category="Feedback", meta=(DeprecatedFunction, DeprecationMessage="Prefer the version using the FortEmitterCameraLensEffectDirectional (SpawnGenericCameraLensEffectDirectional)"))
	AFortEmitterCameraLensEffectDirectional* SpawnCameraLensEffectDirectional(TSubclassOf<AFortEmitterCameraLensEffectDirectional> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bDeferSpawn = false);

	UFUNCTION(BlueprintCallable, Category="Feedback")
	TScriptInterface<ICameraLensEffectInterface> SpawnGenericCameraLensEffect(TSubclassOf<AActor> LensEffectEmitterClass);

	UFUNCTION(BlueprintCallable, Category="Feedback")
	TScriptInterface<ICameraLensEffectInterface> SpawnGenericCameraLensEffectDirectional(TSubclassOf<AActor> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bDeferSpawn = false);

	UFUNCTION(BlueprintCallable, Category="Feedback", meta=(DeprecatedFunction, DeprecationMessage="Prefer the version using the FortEmitterCameraLensEffectDirectional (SpawnPooledGenericCameraLensEffectDirectional)"))
	AFortEmitterCameraLensEffectDirectional* SpawnPooledCameraLensEffectDirectional(TSubclassOf<AFortEmitterCameraLensEffectDirectional> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bShouldActivate = true);

	UFUNCTION(BlueprintCallable, Category="Feedback")
	TScriptInterface<ICameraLensEffectInterface> SpawnPooledGenericCameraLensEffectDirectional(TSubclassOf<AActor> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bShouldActivate = true);

	UFUNCTION(BlueprintCallable, Category="Feedback")
	AFortSoundCameraLensEffect* SpawnSoundLensEffectDirectional(AActor* TrackedActor, FVector HitInfo, const float MaxAudibleDistance, const float EvaluatedStrength, EFortSoundIndicatorTypes IndicatorType, const AActor* InstigatingActor = nullptr, FLinearColor Tint = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000), UTexture* OverrideIcon = nullptr);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void StartPushMomentum(FVector NewPushMomentum, float Duration = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Spin")
	void StartSpinning(float Value, bool bFallingOnly, bool bAdjustForInputYawScale = false);

	UFUNCTION()
	void StopBatchedLoopingWeaponActivation();

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void StopPushMomentum();

	UFUNCTION(BlueprintCallable, Category="Spin")
	void StopSpinning();

	UFUNCTION(BlueprintPure, Category="PawnStats")
	float TimeFromJumpApex() const;

	UFUNCTION(BlueprintCallable, Category="Animation")
	void TriggerAnimInputEvent(const UFortAnimInputEvent* AnimInputEvent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Feedback")
	void TriggerFeedbackEvent(FName EventName, AFortPawn* InstigatorPawn, AFortPawn* Recipient = nullptr, float OverriddenDelay = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual void UnlinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer);

	UFUNCTION(BlueprintPure, Category="Health")
	bool WasDBNOOnDeath() const;

	UFUNCTION(BlueprintPure, Category="FallDamage")
	bool WillFallFromHeightCauseDamage(float FallDistance) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PawnStats")
	uint8 bUseBaseChanged : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="FortPawn")
	uint8 bIgnoreNextFallingDamage : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortPawn")
	uint8 bAllowDeathFromFallingDamage : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=HandleIsDying, Category="Health")
	uint8 bIsDying : 1;

	UPROPERTY(Transient)
	uint8 bPlayedDying : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=HandleIsHiddenForDeath, Category="Health")
	uint8 bIsHiddenForDeath : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_IsKnockedBack, Category="Animation")
	uint8 bIsKnockedback : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Animation", meta=(ScriptName="IsStaggeredValue"))
	uint8 bIsStaggered : 1;

	UPROPERTY(EditAnywhere, Category="DamageZones")
	uint8 bCanCapsuleBeUsedForTargeting : 1;

	UPROPERTY(EditAnywhere, Category="DamageZones")
	uint8 bUseLineTestForDamageZoneBoneDetection : 1;

	UPROPERTY(ReplicatedUsing=OnRep_MovingEmote)
	uint8 bMovingEmote : 1;

	UPROPERTY(Replicated)
	uint8 bMovingEmoteForwardOnly : 1;

	UPROPERTY(ReplicatedUsing=OnRep_MovingEmoteFollowingOnly)
	uint8 bMovingEmoteFollowingOnly : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPawn")
	uint8 bMovingEmoteSkipLandingFX : 1;

	UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_bIsInvulnerable, Category="FortPawn")
	uint8 bIsInvulnerable : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bSpotted : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bRegisterWithAISight : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortPawn")
	uint8 bRegisterWithAimAssist : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortPawn")
	uint8 bPrimaryInputHeld : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortPawn")
	uint8 bSecondaryInputHeld : 1;

	UPROPERTY()
	uint8 bPrimaryInputQueued : 1;

	UPROPERTY(ReplicatedUsing=OnRep_WeaponActivated)
	uint8 bWeaponActivated : 1;

	UPROPERTY(Transient)
	uint8 bIsInGoop : 1;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedIsInGoop)
	uint8 bReplicatedIsInGoop : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSliding, Category="Sliding")
	uint8 bIsSliding : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSkating, Category="Skating")
	uint8 bIsSkating : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupData")
	FGameplayTagContainer AdditionalPickupTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupData")
	EFortPickupSpawnSource SpawnSourceOverride;

	UPROPERTY()
	uint8 bSkipAnalogJump : 1;

	UPROPERTY(EditDefaultsOnly, Category="Movement Audio")
	TEnumAsByte<ETraceTypeQuery> FootstepTraceTypeQuery;

	UPROPERTY(BlueprintReadOnly, Category="Movement Audio")
	TEnumAsByte<EFortFootstepSurfaceType::Type> FootstepSurfaceType;

	UPROPERTY(BlueprintAssignable)
	FOnBaseChangedDelegate OnBaseChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Pawn")
	FCharacterReachedApexSignature OnPawnJumped;

	UPROPERTY(BlueprintAssignable, Category="Pawn")
	FCharacterCrouchChangedDelegate OnPawnCrouchChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_PawnUniqueID, Category="Animation")
	int32 PawnUniqueID;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentWeapon, Category="Weapon")
	TObjectPtr<AFortWeapon> CurrentWeapon;

	UPROPERTY(Transient)
	FString PreviousAbilityWeaponNameForTelemetry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DefaultInventory")
	FName WeaponHandSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DefaultInventory")
	FName LeftHandWeaponHandSocketName;

	UPROPERTY(BlueprintReadOnly, Category="FortPawn")
	TObjectPtr<AActor> SpawnSpot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPawn")
	FGameplayTagContainer DeathTags;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortPawn")
	float SpawnImmunityTime;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPickup>> IncomingPickups;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Animation")
	bool bIsStunned;

	UPROPERTY(Replicated)
	FVortexParams VortexParams;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedSkyTube)
	TObjectPtr<AFortSkyTube> ReplicatedSkyTube;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortSkyTube>> OverlappedSkyTubes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkyTube")
	FScalableFloat bPrioritizeEarlierTubes;

	UPROPERTY(BlueprintAssignable)
	FOnSkyTubeChanged OnSkyTubeChanged;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="Server_OnSearchedContainer"))
	FOnPawnSearchedContainer OnSearchedContainer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation")
	int32 AdditiveCringeCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Animation")
	float AdditiveCringeDuration;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_PushMomentum, Category="HitReaction")
	FVector_NetQuantize PushMomentum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPawn")
	FGameplayCueTag DeathCueTag;

	UPROPERTY(EditDefaultsOnly, Category="Death")
	TArray<FFortStatManagerTag> DeathStatTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Death")
	TObjectPtr<USkeletalMeshSocket> DeathHitSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TeamBeacon")
	float TeamBeaconMaxDist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TeamBeacon")
	FColor TeamBeaconTextColor;

	UPROPERTY(Transient)
	float LastTakeHitTimeTimeout;

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	float LastDamagedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	float MaxFootstepDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DBNOLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultFootstepSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultFastFootstepSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultHardLandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundBase> DefaultJumpSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="HitNotifies")
	TObjectPtr<UWeaponHitNotifyAudioBank> DefaultHitNotifyAudioBank;

	UPROPERTY(EditDefaultsOnly, Category="Swimming Audio")
	TObjectPtr<UFortSwimmingAudioBank> DefaultSwimmingAudioBank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Sound Library", meta=(EditInline="true"))
	TObjectPtr<UFortSoundLibraryComponent> SoundLibraryComponent;

	UPROPERTY(EditAnywhere, Category="DamageZones")
	float LineTestForDamageZoneBoneDetectionRadius;

	UPROPERTY(EditAnywhere, Category="DamageZones", meta=(ArraySizeEnum="/Script/FortniteGame.EFortDamageZone"))
	FPawnDamageZones DamageZones[5];

	UPROPERTY(ReplicatedUsing=OnRep_DamageZoneActiveBitMask)
	uint8 DamageZoneActiveBitMask;

	UPROPERTY(BlueprintAssignable)
	FOnPawnHiddenForDeath OnPawnHiddenForDeath;

	UPROPERTY(ReplicatedUsing=OnRep_JumpFlashCount)
	uint8 JumpFlashCountPacked;

	UPROPERTY(ReplicatedUsing=OnRep_LandingFlashCount)
	uint8 LandingFlashCountPacked;

	UPROPERTY()
	TMap<FName, FEmoteAudioComponentData> EmoteAudioComps;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	TObjectPtr<USoundAttenuation> FrontEndEmoteAudioAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Emote")
	TObjectPtr<USoundAttenuation> InGameEmoteAudioAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emote")
	TObjectPtr<USoundEffectSourcePresetChain> InGameEmoteSoundEffectSoundPresetChain;

	UPROPERTY(BlueprintReadOnly, Export, Category="Emote", meta=(EditInline="true"))
	TMap<int32, TObjectPtr<UMeshComponent>> EmoteMeshComps;

	UPROPERTY(BlueprintReadOnly, Category="Emote")
	TMap<int32, TObjectPtr<AActor>> EmotePropActors;

	UPROPERTY(BlueprintReadOnly, Export, Category="Emote", meta=(EditInline="true"))
	TMap<int32, TObjectPtr<UParticleSystemComponent>> EmoteParticleSystemComps;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emote")
	int32 EmoteCount;

	UPROPERTY(Transient)
	float LastEmoteTime;

	UPROPERTY(Transient)
	float LastEmoteEndTime;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> LastEmoteItemDef;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LastReplicatedEmoteExecuted)
	TObjectPtr<UFortItemDefinition> LastReplicatedEmoteExecuted;

	UPROPERTY(Transient)
	bool bFireBlockedByEmoteCooldown;

	UPROPERTY(Config)
	float EmoteToFireCooldownTime;

	UPROPERTY(ReplicatedUsing=OnRep_EmoteWalkSpeed)
	float EmoteWalkSpeed;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> AdditionalModifierDefinitions;

	UPROPERTY(BlueprintAssignable)
	FPawnTeleportedSignature OnPawnTeleported;

	UPROPERTY(BlueprintAssignable)
	FPawnLandedSignature OnPawnLanded;

	UPROPERTY(BlueprintAssignable)
	FPawnEmoteSignature OnPawnStartedEmote;

	UPROPERTY(BlueprintAssignable)
	FPawnEmoteSignature OnPawnStoppedEmote;

	UPROPERTY(BlueprintAssignable)
	FFortPawnHitSignature OnHitPawn;

	UPROPERTY(BlueprintAssignable)
	FPawnDamagedSignature OnDied;

	UPROPERTY(BlueprintAssignable)
	FPawnDeathEffectsSignature OnDeathEffects;

	UPROPERTY(BlueprintAssignable)
	FPawnDamagedSignature OnDamaged;

	UPROPERTY(BlueprintAssignable)
	FPawnDamagedSignature OnDidDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Movement Audio")
	TObjectPtr<UFortFootstepAudioBank> FootstepBank;

	UPROPERTY(BlueprintAssignable, Category="FortPawn")
	FFortPawnEquippedWeaponSignature OnWeaponEquippedDelegate;

	UPROPERTY(BlueprintAssignable, Category="FortPawn")
	FFortPawnUnEquippedWeaponSignature OnWeaponUnEquippedDelegate;

	UPROPERTY(BlueprintAssignable, Category="FortPawn")
	FFortPawnEquippedWeaponSignature OnWeaponAttachmentChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnHolsteredEvent OnHolsteredEvent;

	UPROPERTY(BlueprintAssignable)
	FOnUnholsteredEvent OnUnholsteredEvent;

	UPROPERTY(EditAnywhere, Category="Feedback")
	float StaySpottedTime;

	UPROPERTY(EditDefaultsOnly, Category="Feedback")
	FName SpottedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	TObjectPtr<UFortFeedbackBank> DefaultFeedback;

	UPROPERTY()
	TArray<TObjectPtr<AFortEmitterCameraLensEffectDirectional>> ActiveSoundIndicators;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Feedback")
	TSubclassOf<AFortEmitterCameraLensEffectDirectional> DefaultSoundTrackingVisual;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Feedback")
	FGameplayTagContainer SoundTrackingVisibilityTags;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TMap<EFortSoundIndicatorTypes, float> PriorityModifiers;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	TMap<EVisualizeAudioPriority, FSoundIndicatorTypesWrapper> PrioritySoundIndicatorTypes;

	UPROPERTY(Transient, Replicated)
	bool bIsDisconnectedPawn;

	UPROPERTY(BlueprintAssignable)
	FPawnUpdatedDecisionWindowStackSignature OnAbilityDecisionWindowStackUpdated;

	UPROPERTY(Transient)
	TArray<FDamagerInfo> Damagers;

	UPROPERTY(Transient)
	TArray<FDamageDoneSourceInfo> TotalDamageDoneTrackers;

	UPROPERTY(Transient)
	TArray<FDamageDoneTargetInfo> TargetDamageDoneTrackers;

	UPROPERTY(Transient)
	TArray<FDamageDoneSourceInfo> TotalDamageTakenTrackers;

	UPROPERTY(Transient)
	TArray<FDamageDoneTargetInfo> TargetDamageTakenTrackers;

	UPROPERTY(Transient)
	float DamageDoneLastAtTime;

	UPROPERTY(Transient)
	float DamageTakenLastAtTime;

	UPROPERTY(Transient)
	float LastHitTime;

	UPROPERTY(Transient)
	float TotalPlayerDamageDealt;

	UPROPERTY(Transient)
	TObjectPtr<UFortHealthBarIndicator> HealthBarIndicator;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FPawnHealthChanged OnPawnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FPawnMaxOvershieldChanged OnPawnMaxOvershieldChanged;

	UPROPERTY()
	FAthenaBatchedDamageGameplayCues_Shared AccumulatedBatchData_Shared;

	UPROPERTY()
	FAthenaBatchedDamageGameplayCues_NonShared AccumulatedBatchData_NonShared;

	UPROPERTY()
	FGameplayCueParameters BatchedGameplayCueParameters;

	UPROPERTY(EditDefaultsOnly, Category="Replay/Unicorn")
	FGameplayTagContainer ReplayItemActions;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void ForceReplication() override;

protected:
	UFUNCTION(BlueprintCallable, Category="Tags")
	void AddNonReplicatedTagToPawn(const FGameplayTag& Tag);

	UFUNCTION()
	virtual void GameplayCue(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	virtual void GameplayCue_Damage(EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UFUNCTION()
	virtual void GameplayCue_InstantDeath(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure, Category="Audio Parameter")
	UAudioParameterComponent* GetAudioParameterComponent() const;

	UFUNCTION(BlueprintPure, Category="FortPawn")
	FText GetCurrentSentenceSpeechText() const;

	UFUNCTION(BlueprintPure, Category="Footsteps")
	UFortFootstepComponent* GetFootstepComponent() const;

	UFUNCTION(BlueprintPure, Category="AthenaMovement", meta=(DeprecatedFunction, DeprecationMessage="Use GetSlopeSlidingAngles() instead"))
	FVector GetSlopeSlidingNormal() const;

	UFUNCTION(BlueprintPure, Category="Sound Library", meta=(CPP_Default_InComponentTag="()"))
	UFortSoundLibraryComponent* GetSoundLibraryComponent(FGameplayTag InComponentTag) const;

	UFUNCTION()
	void KillDisconnectedPawn();

	UFUNCTION()
	void OnAllMontageInstancesEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClearSentence();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplaySentence(const FText& SpeechText);

	UFUNCTION()
	virtual void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	virtual void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	virtual void OnMontageStarted(UAnimMontage* Montage);

	UFUNCTION()
	void OnOverlappingBuildingDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnOverlappingBuildingDied(TWeakObjectPtr<ABuildingActor> Building);

	UFUNCTION()
	virtual void OnRep_IsDBNO();

	UFUNCTION()
	void OnRep_IsJumping();

	UFUNCTION()
	void OnRep_IsKnockedBack();

	UFUNCTION()
	virtual void OnRep_IsSlopeSliding();

	UFUNCTION()
	virtual void OnRep_IsSwinging();

	UFUNCTION()
	void OnRep_MovementModeExtension();

	UFUNCTION()
	void OnRep_ReplicatedIsInVortex();

	UFUNCTION()
	void OnRep_ReplicatedWaterBody();

	UFUNCTION()
	void OnRep_Sentence();

	UFUNCTION()
	void OnRep_StormShieldComponent();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaMovement")
	void OnSlidingStateChanged(bool bNewSlidingState);

	UFUNCTION(BlueprintCallable, Category="Tags")
	void RemoveNonReplicatedTagToPawn(const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, Category="FortPawn")
	void SetAimAssistTargetOverride(const USceneComponent* InOverride);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Death")
	bool ShouldDie(float Damage, AController* EventInstigator, AActor* DamageCauser);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSwinging, Category="FortPawn")
	uint8 bIsSwinging : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSynchedAction, Category="SynchedAction")
	uint8 bIsSynchedAction : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPawn")
	uint8 bSwingingAttached : 1;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPawn")
	FVector SwingAttachLocation;

	UPROPERTY(EditAnywhere, Category="Swinging")
	float SwingAttachLocationUpdateDistanceThreshold;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_SynchedActionWarpPointInfo)
	FSynchedActionWarpPointInfo_Replicated ReplicatedSynchedActionWarpPointInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Sound Indicator", meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(EditDefaultsOnly, Category="AnimationURO")
	EUpdateRateShiftBucket UroShiftBucket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Animation")
	uint8 bUpdateMeshComponentUpdateFlagOnServer : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AnimationURO")
	uint8 bUROCanTieToLODs : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bPostProcessNavLocation : 1;

	UPROPERTY()
	uint8 bHealthSynced : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bWeaponHolstered)
	uint8 bWeaponHolstered : 1;

	UPROPERTY(Transient)
	uint8 bSkipReticleColorTrace : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HitMarkers")
	uint8 bPrioritizePawnCollisionsOnAbilityTargetSelectionVisibilityTest : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HitMarkers")
	uint8 bTreatAsPawnForHitMarkers : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HitMarkers")
	uint8 bDisplayPawnHitMarkersForChildActors : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PawnStats")
	uint8 bUsesStats : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPawn")
	uint8 bAllowBuildingActorTeleport : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsDBNO, Category="Health", meta=(ScriptName="IsDBNOValue"))
	uint8 bIsDBNO : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bWasDBNOOnDeath : 1;

	UPROPERTY()
	uint8 bCachedIsInAthena : 1;

	UPROPERTY(Replicated)
	uint8 bShouldUseCharacterMovementIdleFastPath : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="FortPawn")
	TEnumAsByte<EFortMovementStyle::Type> CurrentMovementStyle;

	UPROPERTY(BlueprintReadOnly, Category="Control Resistance")
	EFortControlRecoveryBehavior ControlRecoveryBehavior;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TeleportCounter)
	uint8 TeleportCounter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PawnStats")
	FDataTableRowHandle PawnStatHandle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="PawnStats")
	FDataTableRowHandle OverridePawnStatHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PawnStats")
	float SlidingFriction;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsSlopeSliding, Category="FortPawn", meta=(AllowPrivateAccess="true"))
	uint8 bIsSlopeSliding : 1;

	UPROPERTY(Replicated)
	uint16 PackedReplicatedSlopeAngles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PawnStats")
	float SlidingBrakingDeceleration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_StormShieldComponent, Export, Category="FortPawn", meta=(EditInline="true"))
	TObjectPtr<UFortStormShieldComponent> StormShieldComponent;

	UPROPERTY(BlueprintAssignable, Category="FortPawn")
	FOnStormShieldComponentCreated OnStormShieldComponentCreated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPawn")
	EFortPawnPushSize PushSize;

	UPROPERTY(Transient)
	float LastRevivedFromDBNOTime;

	UPROPERTY(Transient)
	float LastSurfaceTraceTime;

	UPROPERTY(Transient)
	FVector LastSurfaceTraceLocation;

	UPROPERTY(ReplicatedUsing=OnRep_IsJumping)
	uint8 bIsJumping : 1;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> PreviousWeapon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	TArray<TObjectPtr<AFortWeapon>> CurrentWeaponList;

	UPROPERTY(EditDefaultsOnly, Category="FortPawn")
	bool bShouldSeeThroughFactionMembers;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> CachedAffiliationManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortWaterBodyActor> CurrentWaterBody;

	UPROPERTY(EditDefaultsOnly, Category="FortPawn")
	bool bShouldSupportSurfaceSwimming;

	UPROPERTY()
	TArray<FFortPickupEntryData> PickupDirectionData;

	UPROPERTY(Transient)
	uint8 bIsInVortex : 1;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedIsInVortex)
	uint8 bReplicatedIsInVortex : 1;

	UPROPERTY(Transient)
	TObjectPtr<AFortSkyTube> CurrentSkyTube;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPawn")
	bool bSupportsDamageNumbersAtHitLocation;

	UPROPERTY(Transient, Replicated)
	float LocalSpin;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPawn")
	bool bTurnTransitionActiveAndControllingRotation;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStartDBNO OnPlayerStartDBNO;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnDBNOStateChangedEvent OnDBNOStateChanged;

	UPROPERTY(EditAnywhere, Category="Death")
	float DefaultLifespanAfterDeath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPawn")
	float TargettingZOffset;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UActorComponent>> DynamicComponents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> HealthRegenDelayGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> HealthRegenGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> ShieldRegenDelayGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> ShieldRegenGameplayEffect;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> CurrentWeaponAnimLayerOverlayClass;

	UPROPERTY(Transient)
	TArray<FHolsterRequestData> HolsterWeaponRequests;

	UPROPERTY(Transient)
	float HolsterActiveDuration;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VocalChords)
	TArray<FFortPawnVocalChord> VocalChords;

	UPROPERTY()
	FActiveGameplayEffectHandle MaxHealthApplicationHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Health")
	TSubclassOf<UGameplayEffect> MaxHealthApplicationGameplayEffect;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortControlResistanceSet> ControlResistanceSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMovementSet> MovementSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAdvancedMovementSet> AdvancedMovementSet;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityTargetingBlocked OnAbilityTargetingBlocked;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TArray<FFortActiveMontageDecisionWindow> DecisionWindowStack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayTags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category="Display")
	FText DisplayName;

	UPROPERTY(Replicated)
	FGameplayTag CurrentCalloutTag;

	UPROPERTY(EditDefaultsOnly, Category="Callouts")
	TArray<FCalloutEntry> CalloutEntries;

	UPROPERTY(EditAnywhere, Category="HUD")
	float HealthBarWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUD")
	float HealthBarHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spotting")
	FSlateBrush SpottedBrush;

	UPROPERTY(EditDefaultsOnly, Category="Spotting")
	FVector SpottedIconOffset;

	UPROPERTY(EditDefaultsOnly, Category="AnimationURO")
	int32 ClientNonRenderedAnimUpdateRate;

	UPROPERTY(EditDefaultsOnly, Category="AnimationURO")
	int32 MaxEvalRateForInterpolation;

	UPROPERTY(EditDefaultsOnly, Category="AnimationURO")
	TArray<float> AnimUpdateRateVisibleMaxDistanceFactor;

	UPROPERTY(EditDefaultsOnly, Category="AnimationURO")
	TMap<int32, int32> LODToFrameSkipMap;

	UPROPERTY(ReplicatedUsing=OnRep_Sentence)
	FFortConversationSentence CurrentSentence;

	UPROPERTY(EditAnywhere, Replicated, Category="FortPawn")
	FGameplayTag FallbackTag;

	UPROPERTY(Replicated)
	FString DebugType;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<ABuildingActor>> OverlappingBuildings;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MovementModeExtension)
	FRepMovementModeExtension RepActiveMovementModeExtension;

	UPROPERTY(Transient)
	TMap<FMovementMode_ExtID, TObjectPtr<UFortMovementMode_BaseExtLogic>> RegisteredMovementModeExtentionLogic;

private:
	UFUNCTION(Client, Reliable)
	void ClientInternalEquipWeapon(AFortWeapon* Weapon);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastSetWeaponVisibility(AFortWeapon* Weapon, bool bIsVisible);

	UFUNCTION()
	void OnRep_ClientAILODSettings();

	UFUNCTION()
	void OnRep_PushMomentum();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerInternalEquipWeapon(AFortWeapon* Weapon);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedWaterBody)
	TObjectPtr<AFortWaterBodyActor> ReplicatedWaterBody;

	UPROPERTY(Replicated)
	TArray<FWindVolumeData> WindVolumes;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CurrentlyAttachedWeapon;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> CachedNavFloor;

	UPROPERTY(VisibleAnywhere, Export, Category="FortPawn", meta=(EditInline="true"))
	UFortEmoteComponent* EmoteComponent;

	UPROPERTY(EditDefaultsOnly, Category="Hiding", meta=(DisplayName="Inside Hiding Prop Tags"))
	FGameplayTagContainer HidingVisibilityTags;

	UPROPERTY(EditDefaultsOnly, Category="Hiding", meta=(DisplayName="Transition Hiding Prop Tags"))
	FGameplayTagContainer HidingTransitionVisibilityTags;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPegasusGameEventCollector> PegasusTimelineCollector;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAILODComponent> AILODComponent;

	UPROPERTY(ReplicatedUsing=OnRep_ClientAILODSettings)
	FClientAILODSettings ClientAILODSettings;

	UPROPERTY(Transient)
	TMap<uint32, FRecordedGunshot> RecordedGunshots;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPawnComponentAttached OnPawnComponentAttachedEvent;

};

