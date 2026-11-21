// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavPathObserverInterface.h"
#include "AIController.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Perception/AIPerceptionTypes.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "AI/DebugMinimapData.h"
#include "AI/FortAthenaAIControllerInterface.h"
#include "AI/FortAthenaEntitySubsystemInterface.h"
#include "AI/Navigation/FortDoorLinkOpenerInterface.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Analytics/FortAnalyticsControllerInterface.h"
#include "Athena/AI/FortAthenaAIBotPerceptionSkillSet.h"
#include "Athena/AI/FortAthenaAITargetHandler.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSProviderInterface.h"
#include "Building/BuildingWeakSpot.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/FortCosmeticLoadoutOwner.h"
#include "FortTeamActorInterface.h"
#include "FortVehicleUserInterface.h"
#include "Items/FortInventoryOwnerInterface.h"
#include "Pawns/FortPlayerPawn.h"
#include "FortAthenaAIBotController.generated.h"

class AActor;
class AAthenaAIController;
class ABuildingActor;
class ACharacter;
class AController;
class AFortAIPawn;
class AFortAthenaAIBotController;
class AFortAthenaAILeashVolume;
class AFortGameModeAthena;
class AFortInventory;
class AFortPawn;
class AFortPickup;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStateZone;
class AFortWeapon;
class AGameplayVolume;
class APawn;
class IFortAIAimingInterface;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
class UAthenaAIServicePlayerBots;
class UAthenaCosmeticItemDefinition;
class UAthenaDanceItemDefinition;
class UAthenaMarkerComponent;
class UBehaviorTree;
class UCustomCharacterPart;
class UFortAICombatTokenConsumerComponent;
class UFortAIControllerPerksComponent;
class UFortActorComponent_Affiliation;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAIBotCustomizationData;
class UFortAthenaAIBotHarvestDigestedSkillSet;
class UFortAthenaAIBotInventoryDigestedSkillSet;
class UFortAthenaAIBotInventoryItems;
class UFortAthenaAIBotLootingDigestedSkillSet;
class UFortAthenaAIBotMovementDigestedSkillSet;
class UFortAthenaAIBotPerceptionDigestedSkillSet;
class UFortAthenaAIBotPlayStyleDigestedSkillSet;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;
class UFortAthenaAIBotSkillSet;
class UFortAthenaAIBotUnstuckDigestedSkillSet;
class UFortAthenaAIBotVehicleDigestedSkillSet;
class UFortAthenaAIRuntimeParametersComponent;
class UFortAthenaAIRuntimeParameters_AIBotRespawn;
class UFortAthenaAIRuntimeParameters_AffiliationBase;
class UFortAthenaAIRuntimeParameters_Inventory;
class UFortAthenaAIRuntimeParameters_Leash;
class UFortAthenaMutator_SpawningPolicyData;
class UFortAthenaNpcPatrollingComponent;
class UFortBotNameSettings;
class UFortControllerComponent_Telemetry;
class UFortGameStateComponent_AffiliationManager;
class UFortInteractContextInfo;
class UFortItemDefinition;
class UFortWeaponItemDefinition;
class UFortWorldItem;
class UFortWorldMultiItemDefinition;
class UPrimitiveComponent;
class UStatManager;
enum class EAlertLevel : uint8;
enum class EAthenaCustomizationCategory : uint8;
enum class EBlackboardUpdateType : uint8;
enum class ELeashReturnLocationMode : uint8;
enum class EPerceptionState : uint8;
enum class EStimType : uint8;

UENUM(BlueprintType)
enum class EBlackboardUpdateType : uint8
{
	NoUpdate = 0,
	UpdateNow = 1,
	UpdateNextTick = 2,
};

UENUM()
enum class EBotControllerClamberStatus : uint8
{
	Invalid = 0,
	MoveStarted = 1,
	MoveDone = 2,
	MoveFailed = 3,
};

UENUM()
enum class EDefensivePlayerStyleSource : uint8
{
	/** Unknown */
	Unknown = 0,
	Escape = 1,
	MAX = 2,
};

UENUM()
enum class EHarvestResult : uint8
{
	None = 0,
	InProgress = 1,
	Success = 2,
	Fail = 3,
};

UENUM()
enum class EObstacleType : uint8
{
	/** Incoming smashable actor on the path from path following comp */
	IncomingSmashable = 0,
	/** Blocking smashable actor while navigating from path following comp */
	BlockingSmashable = 1,
	/** Incoming detected trap on our path to destroy */
	BlockingDetectedTrap = 2,
	Unknown = 3,
	Count = 3,
};

UENUM()
enum class EReachLocationValidationMode : uint8
{
	/** No test, automatically valid */
	None = 0,
	/** Takes storm into account to know if location is safe to reach */
	Storm = 1,
	/** Uses leash radius to know location can be reached */
	Leash = 2,
	/** Uses soft leash radius: bot can choose to go out deliberately */
	SoftLeash = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAIBotControllerOnPickupCreated, const AFortAthenaAIBotController*, AIBotController, AFortPickup*, Pickup);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIPawnKilledByBot, const AFortAthenaAIBotController*, AIBotController, AFortAIPawn*, KilledAIPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAgentDBNOStatusChangedEvent, AFortAthenaAIBotController*, BotController, bool, bIsDBNO);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAgentDiedEvent, AFortAthenaAIBotController*, BotController, AFortPawn*, AgentPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAgentGameOver, AFortAthenaAIBotController*, BotController, AFortPawn*, AgentPawn, AController*, InstigatedBy);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAlertLevelChangedEvent, AFortAthenaAIBotController*, BotController, EAlertLevel, OldAlertLevel, EAlertLevel, NewAlertLevel);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentTargetChanged, AActor*, OldTarget, AActor*, NewTarget);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerPawnAISpawned, AFortAthenaAIBotController*, BotController, AFortPlayerPawnAthena*, BotPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerPawnKilledByBot, const AFortAthenaAIBotController*, AIBotController, const AFortPlayerPawn*, KilledPlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnStealthMeterChangedEvent, AFortAthenaAIBotController*, BotController, float, StealthMeterTarget, float, StealthMeterTargetTime);

USTRUCT()
struct FFortBotInventoryInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> FortItem;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponItemDefinition> WeaponDefinitionCache;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldMultiItemDefinition> MultiItemDefinitionCache;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> BotController;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Collision", "Rendering", "Transformation"))
class FORTNITEAI_API AFortAthenaAIBotController : public AAIController, public ICosmeticLoadoutOwner, public IFortAnalyticsControllerInterface, public IFortAthenaAIControllerInterface, public IFortAthenaMutator_EQSProviderInterface, public IFortInventoryOwnerInterface, public IFortDoorLinkOpenerInterface, public IFortTeamActorInterface, public IFortVehicleUserInterface, public INavPathObserverInterface, public IFortAthenaEntitySubsystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddTargetInfo(AActor* Target, const bool bForceTarget = false, const EPerceptionState PerceptionState = EPerceptionState::Threat_Seeing, const float ForgetTime = 5.000000f, const float ForgetDistance = 2000.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddTargetInfos(const TArray<AActor*>& Targets, const EPerceptionState PerceptionState = EPerceptionState::Threat_Seeing, const float ForgetTime = 5.000000f, const float ForgetDistance = 2000.000000f);

	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintOnBehaviorTreeStarted();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant);

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ClearForcedCosmeticItems();

	UFUNCTION(Server, Reliable, WithValidation)
	void Cheat_ForceAthenaCosmeticItemInSlot(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index);

	UFUNCTION(BlueprintCallable)
	AFortWeapon* EquipBestWeapon(const bool bUpdateBB = false);

	UFUNCTION(BlueprintCallable)
	AFortWeapon* EquipMeleeWeapon();

	UFUNCTION(BlueprintCallable)
	virtual AFortWeapon* EquipWeapon(const UFortWorldItem* Weapon, const bool bUpdateBB = false);

	UFUNCTION(BlueprintCallable)
	AFortWeapon* EquipWeaponByTag(const FGameplayTag& WeaponTag);

	UFUNCTION(BlueprintPure)
	AActor* GetBotOwner() const;

	UFUNCTION(BlueprintPure)
	AActor* GetCurrentTarget() const;

	UFUNCTION(BlueprintPure)
	AActor* GetCurrentThreat() const;

	UFUNCTION(BlueprintPure)
	UAthenaMarkerComponent* GetMarkerComponent() const;

	UFUNCTION(BlueprintPure)
	const UFortWorldItem* GetSlotItemByItemDefinition(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure)
	const UFortWorldItem* GetSlotItemByTag(const FGameplayTag& TagToCheck) const;

	UFUNCTION(BlueprintPure)
	bool IsAnAthenaGameParticipant() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void NotifyPickupsSpawnedOnDeath(const TArray<AFortPickup*>& SpawnedPickups, const int32 SpawnRequestId = -1);

	UFUNCTION()
	void OnAgentDBNO(AFortPawn* InPlayer, bool bInIsDBNO);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAlertLevelChanged(const EAlertLevel OldAlertLevel, const EAlertLevel NewAlertLevel);

	UFUNCTION()
	void OnBeginSpectating(AFortPlayerStateZone* Spectator);

	UFUNCTION()
	void OnEndSpectating(AFortPlayerStateZone* Spectator);

	UFUNCTION(BlueprintCallable)
	void OnKnockbacked(const FGameplayTag KnockbackTypeTag);

	UFUNCTION(BlueprintCallable)
	void OnLaunched(const FVector LaunchVelocity, const bool bXYOverride, const bool bZOverride);

	UFUNCTION()
	void OnMovementModeChange(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void OnPawnDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnPawnWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon);

	UFUNCTION()
	virtual void OnPerceptionSensed(AActor* SourceActor, FAIStimulus Stim);

	UFUNCTION()
	void OnPossesedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnPossessedPawnReceiveDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnServerMarkerAdded(const FFortWorldMarkerData& MarkerData);

	UFUNCTION()
	void OnTargetActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnTargetBuildingDestroyed(ABuildingActor* Building, AAthenaAIController* AIController);

	UFUNCTION()
	void OnTargetPawnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnTargetPawnDead(AFortPawn* FortPawn);

	UFUNCTION()
	void OnTargetPawnDestroyed();

	UFUNCTION(BlueprintCallable)
	void OverrideAggressivenessPlayStyle(bool bInIsAggressive);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OverrideSkill(const float NewSkill);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PlayEmote(const FPrimaryAssetId& EmotePrimaryAssetId);

	UFUNCTION(BlueprintCallable)
	void QueueStim(AActor* SourceActor, const FVector& SourceLocation, const FVector& SourceDirection, const EStimType NewStimType, const float StimStrength, const FName StimTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveEmoteRequest();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveSkillSet(TSubclassOf<UFortAthenaAIBotSkillSet> SkillSetClass);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RequestEmote(const FPrimaryAssetId& EmotePrimaryAssetId, float InfiniteEmoteMaxDuration = -1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RequestMoveAwayFromBox(const FBox& MoveAwayBox);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetPerceptionAndTargets(const EBlackboardUpdateType BlackboardUpdateType);

	UFUNCTION(BlueprintCallable)
	void SetBotOwner(AActor* InBotOwner);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(CPP_Default_LeashLocationUpdateRate="5.000000", CPP_Default_LocalOffset))
	void SetLeashActorToFollow(const AActor* ActorToFollow, const float LeashLocationUpdateRate, const FVector LocalOffset);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetLeashGameplayVolume(const AGameplayVolume* InLeashGameplayVolume);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetLeashReturnLocationMode(ELeashReturnLocationMode ReturnMode);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetLeashVolume(AFortAthenaAILeashVolume* InLeashVolume);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetPatrollingEnable(const bool bEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRadialLeashAlertLevelOverride(const FLeashInfoOverride& LeashInfoOverride, EAlertLevel AlertLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRadialLeashInnerRadius(const float InnerRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRadialLeashLocation(const FVector& Location);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRadialLeashOuterRadius(const float OuterRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetSkillSet(TSubclassOf<UFortAthenaAIBotSkillSet> SkillSetClass);

	UFUNCTION(BlueprintCallable)
	void StartFire();

	UFUNCTION(BlueprintCallable)
	void StartSecondaryFire();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopEmote();

	UFUNCTION(BlueprintCallable)
	void StopFire();

	UFUNCTION(BlueprintCallable)
	void StopSecondaryFire(const bool bFireWhenStopping);

	UFUNCTION(BlueprintCallable)
	void SwitchTeam(uint8 TeamIndex);

	UPROPERTY(BlueprintAssignable)
	FAIBotControllerOnPickupCreated OnPickupCreated;

protected:
	UFUNCTION()
	void OnCurrentHarvestableDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void ReleaseBuildTool();

	UFUNCTION()
	void ThankBusDriver();

	UFUNCTION()
	void UpdateLeashActorToFollowLocation();

	UPROPERTY(BlueprintAssignable, Category="Team")
	FOnTeamIndexChangedDelegate OnTeamSetDelegate;

	UPROPERTY(Transient)
	TMap<FGuid, FFortAbilitySetHandle> AppliedInGameModifierAbilitySetHandles;

	UPROPERTY(Transient)
	TSet<FGuid> GadgetTrackedAttributeItemInstanceIds;

	UPROPERTY(Transient)
	FFortBotTargetHandler TargetHandler;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Athena", meta=(AllowPrivateAccess="true"))
	uint8 bIsAnAthenaGameParticipant : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Perception", meta=(AllowPrivateAccess="true"))
	uint8 bEnableBotPerception : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Athena", meta=(AllowPrivateAccess="true"))
	EReachLocationValidationMode ReachLocationValidationMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BehaviorTree", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(Transient)
	FFortBotInventoryInfo SlotItems[6];

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotInventoryDigestedSkillSet> CacheInventoryDigestedSkillSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortPlayerPawnAthena> PlayerBotPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UAthenaAIServicePlayerBots> CachedAIServicePlayerBots;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortGameModeAthena> CachedGameMode;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortAthenaAIRuntimeParametersComponent> CachedAIRuntimeParametersComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAthenaAIRuntimeParameters_Leash> CachedLeashRuntimeParameters;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAthenaAIRuntimeParameters_AffiliationBase> CachedAffiliationRuntimeParameters;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAthenaAIRuntimeParameters_Inventory> CachedInventoryRuntimeParameters;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortAthenaNpcPatrollingComponent> CachedPatrollingComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortAIControllerPerksComponent> CachedAIPerksComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortAICombatTokenConsumerComponent> CachedTokenConsumerComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true"))
	TScriptInterface<IFortAIAimingInterface> CachedAIAimingInterface;

	UPROPERTY(Transient)
	TArray<FBotDelayedStimulus> DelayedStimulus;

	UPROPERTY(Transient)
	TArray<FFortBotThreatActorInfo> ObjectsThreatList;

	UPROPERTY(Transient)
	TArray<FFortBotThreatActorInfo> TrapsThreatList;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AlertLevel", meta=(AllowPrivateAccess="true"))
	EAlertLevel CurrentAlertLevel;

	UPROPERTY(Transient)
	FAlertLevelInfo DefaultAlertLevelInfo;

	UPROPERTY(BlueprintAssignable, Category="AlertLevel", meta=(AllowPrivateAccess="true", DisplayName="On Alert Level Changed Event"))
	FOnAlertLevelChangedEvent OnAlertLevelChangedEventDelegate;

	UPROPERTY(BlueprintAssignable, Category="AlertLevel", meta=(AllowPrivateAccess="true", DisplayName="On Stealth Meter Changed Event"))
	FOnStealthMeterChangedEvent OnStealthMeterChangedEventDelegate;

	UPROPERTY(BlueprintAssignable, Category="DBNO", meta=(AllowPrivateAccess="true", DisplayName="On DBNO Status Changed Event"))
	FOnAgentDBNOStatusChangedEvent OnAgentDBNOStatusChangedEventDelegate;

	UPROPERTY(BlueprintAssignable, Category="Death", meta=(AllowPrivateAccess="true", DisplayName="On Agent Died Event"))
	FOnAgentDiedEvent OnAgentDiedEventDelegate;

	UPROPERTY(BlueprintAssignable, Category="Death", meta=(AllowPrivateAccess="true", DisplayName="On Agent Game Over Event"))
	FOnAgentGameOver OnAgentGameOver;

	UPROPERTY(BlueprintAssignable, Category="Death", meta=(AllowPrivateAccess, DisplayName="On Player Pawn Killed by bot"))
	FOnPlayerPawnKilledByBot OnPlayerPawnKilledByBot;

	UPROPERTY(BlueprintAssignable, Category="Death", meta=(AllowPrivateAccess, DisplayName="On AI Pawn Killed by bot"))
	FOnAIPawnKilledByBot OnAIPawnKilledByBot;

	UPROPERTY(BlueprintAssignable, Category="Perception", meta=(AllowPrivateAccess, DisplayName="On Current Target Changed Event"))
	FOnCurrentTargetChanged OnCurrentTargetChangedDelegate;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortInventory> Inventory;

	UPROPERTY(EditDefaultsOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	float Skill;

	UPROPERTY(EditDefaultsOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	uint8 bAllowUnsupportedItemsInDefaultInventory : 1;

	UPROPERTY(EditDefaultsOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	uint8 bMultiplyEffectivenessOfWeaponWithSurfaceDamageToFindBestWeapon : 1;

	UPROPERTY(EditDefaultsOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> BotSkillSetClasses;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Customization", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAthenaAIBotInventoryItems> StartupInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	FFortAthenaLoadout CosmeticLoadoutBC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UCustomCharacterPart>> CustomCharacterPartOverridesBC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="Customization", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortBotNameSettings> NameSettingsBC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spectate", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpectateOnDeathMinTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spectate", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpectateOnDeathMaxTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Emote", meta=(AllowPrivateAccess="true"))
	FScalableFloat EmotesMaxCount;

	UPROPERTY(EditDefaultsOnly, Category="Leash")
	FVector LeashGameplayVolumeProjectExtent;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotPerceptionDigestedSkillSet> CachePerceptionDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotHarvestDigestedSkillSet> CacheHarvestDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CacheMovementSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotLootingDigestedSkillSet> CacheLootingSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAttackingDigestedSkillSet> CacheAttackingSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotPlayStyleDigestedSkillSet> CachePlayStyleSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotUnstuckDigestedSkillSet> CacheUnstuckSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotRangeAttackDigestedSkillSet> CacheRangeAttackSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotVehicleDigestedSkillSet> CacheVehicleSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortInteractContextInfo> InteractContextInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAimingDigestedSkillSet> CacheAimingDigestedSkillSet;

	UPROPERTY(EditAnywhere, Category="Cleanup", meta=(AllowPrivateAccess="true"))
	uint8 bCanBeDestroyedOnDeath : 1;

	UPROPERTY(Transient)
	FVector LastDeathLocation;

	UPROPERTY(Transient)
	FRotator LastDeathRotation;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> CachedWorldItem;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CacheWeaponUsedToCalculateType;

	UPROPERTY(Transient)
	bool bCachedIsUsingArcedProjectileWeapon;

	UPROPERTY(Transient)
	float CachedProjectileGravityScale;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CachedWeaponUsedToCalculateProjectileData;

	UPROPERTY(Transient)
	TObjectPtr<UStatManager> StatManager;

	UPROPERTY(Transient)
	TArray<FBuildingWeakSpotData> ActiveWeakSpots;

	UPROPERTY(Transient)
	TSubclassOf<AFortPawn> CacheBotPawnClass;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentLootActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> MarkerComponent;

	UPROPERTY(Transient)
	FString BotPlayerName;

	UPROPERTY(Transient)
	FGameplayTag DescriptorTag;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AllowPrivateAccess="true"))
	FString BotIDSuffix;

	UPROPERTY(Transient)
	FString BotPlayerNameWithSkillRating;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaMutator_SpawningPolicyData> PolicyDataSpawner;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortControllerComponent_Telemetry> FortControllerComponent_Telemetry;

	UPROPERTY(Transient)
	bool bForceUsingBuildingTool;

	UPROPERTY(Transient)
	bool bForceHolsterWeapon;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> PendingEquipWeapon;

	UPROPERTY(Transient)
	TObjectPtr<APawn> PlayerToSpectateOnDeath;

	UPROPERTY(BlueprintAssignable, Category="Spawning", meta=(AllowPrivateAccess="true", DisplayName="On Player Pawn AI Spawned Event"))
	FOnPlayerPawnAISpawned OnPlayerPawnAISpawnedDelegate;

	UPROPERTY(Transient)
	TObjectPtr<UAISenseConfig_Sight> AISenseConfig_SightOverride;

	UPROPERTY(Transient)
	TObjectPtr<UAISenseConfig_Hearing> AISenseConfig_HearingOverride;

	UPROPERTY(Transient)
	TObjectPtr<AActor> BotOwner;

	UPROPERTY(Transient)
	int32 BotControllerUID;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawnAthena> ReviveTarget;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotCustomizationData> BotData;

	UPROPERTY(Transient)
	FDebugMinimapData DebugMinimapData;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawnAthena> RevivePlayerPawnToken;

	UPROPERTY(Transient)
	TObjectPtr<AActor> LeashActorToFollow;

	UPROPERTY(Transient)
	FVector LeashActorToFollowLocalOffset;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAILeashVolume> LeashVolume;

	UPROPERTY(Transient)
	TWeakObjectPtr<AGameplayVolume> LeashGameplayVolume;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> CachedAffiliationManager;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAthenaAIBotController", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortActorComponent_Affiliation> CachedAffiliationComponent;

	UPROPERTY(Transient)
	bool bIsAffectedByMutatorHealthAndShieldModifiers;

	UPROPERTY(Transient)
	bool bHasChangedPawnCullDistanceToAggroMode;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIBotRespawn> RespawnRuntimeParameters;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> CurrentBlockingObstacle;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> NoSmashActors;

	UPROPERTY(Transient)
	TObjectPtr<APawn> FinisherPawn;

	UPROPERTY(Transient)
	EFortPawnStasisMode PreviousStasisMode;

	UPROPERTY(Transient)
	bool bPostponeGiveWeaponCheat;

	UPROPERTY(Transient)
	bool bPostponeGiveMaterialsCheat;

	UPROPERTY(Transient)
	float StartSpectatingTime;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaDanceItemDefinition> RequestedEmoteAsset;

	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTree> BTAssetToRunOnPawnAISpawned;

private:
	UPROPERTY(Transient)
	TObjectPtr<AActor> PreviousVehicle;

};

