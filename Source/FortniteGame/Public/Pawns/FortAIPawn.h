// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityRepAnimMontage.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Engine/ReplicatedState.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/Character.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Perception/AIPerceptionListenerInterface.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "AI/FortAISpawnGroupUpgradeUIData.h"
#include "AI/FortAITypes.h"
#include "Abilities/GameplayAbilityRepSharedAnim.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "Athena/FortWalkableBaseInterface.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/CreatureManagerTypes.h"
#include "FortCombatTypes.h"
#include "FortCustomPartTypeEnum.h"
#include "FortDeathCauseEnum.h"
#include "FortGender.h"
#include "FortInteractInterface.h"
#include "FortMovementEnums.h"
#include "Items/FortInventoryOwnerInterface.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "Missions/FortSpawnableByPlacementSystemInterface.h"
#include "Pawns/FortPawn.h"
#include "UI/FortHUDTargetUnderReticleInterface.h"
#include "FortAIPawn.generated.h"

class AActor;
class ABuildingActor;
class ABuildingTrapDefender;
class AController;
class AFortAIPawn;
class AFortInventory;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerState;
class AFortPlayerStateZone;
class APawn;
class UAIGoalComponent;
class UAnimInstance;
class UAnimMontage;
class UBehaviorTree;
class UFortAIAssetLoader;
class UFortAIAttributesSet;
class UFortAIEncounterInfo;
class UFortAIPawnCustomizationDefinition;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortAccountItem;
class UFortCameraMode;
class UFortCharacterAttrSet;
class UFortCharacterPartsComponent;
class UFortConvertSet;
class UFortFeedbackBank;
class UFortGameplayModifierItemDefinition;
class UFortItem;
class UFortItemDefinition;
class UFortNavObstacleComponent;
class UFortSimpleMiniMapIndicator;
class UFortWeaponAttrSet;
class UMaterialInterface;
class UNavigationQueryFilter;
class UParticleSystem;
class UPrimitiveComponent;
class UShapeComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundBase;
class USplineComponent;
enum class EFortAILODLevel : uint8;
enum class EFortPickupSourceTypeFlag : uint8;
enum class EFortPickupSpawnSource : uint8;
enum class EFortressAIType : uint8;
enum class EScoreDistributionType : uint8;

UENUM()
enum class EFortAILevelRatingDisplayType : uint8
{
	DisplayRatingBasedOnDifficulty = 0,
	DisplayAIDifficultyAsRating = 1,
	DontDisplayRating = 2,
};

UENUM(BlueprintType)
enum class EFortAIPawnGender : uint8
{
	FAPG_Default = 0,
	FAPG_Female = 1,
	FAPG_Male = 2,
	//MAXIMUM

	FAPG_MAX = 3 UMETA(hidden),
};

UENUM(BlueprintType)
enum class EFortressAIType : uint8
{
	FAT_Dormant = 0,
	FAT_Cleaner = 1,
	FAT_DayWanderer = 2,
	FAT_NightWanderer = 3,
	// For AI not spawned by or controlled by the AI Director.

	FAT_DebugOnly = 4,
	FAT_Encounter = 5,
	//MAXIMUM

	FAT_MAX = 6 UMETA(hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortAIInteraction, AFortAIPawn*, AI, AFortPlayerController*, InteractingPlayerController, TEnumAsByte<EInteractionBeingAttempted>, InteractionBeingAttempted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortAIInventoryUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortAIOnInventoryInitialized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortAIPawnCustomizationsLoaded, AFortPawn*, ThisPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortAIPawnCustomizationsUnloaded, AFortPawn*, ThisPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortAIPawnOnTetheredFollowerChanged, AFortPawn*, NewFollower, AFortPawn*, OldFollower);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortCrowdOverlap, AFortPawn*, OtherPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortDBNO, AFortAIPawn*, DownedAI, AController*, DownedInstigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortUpdateFromVehicleInput, float, DeltaSeconds, const FFortAthenaVehicleInputState&, VehicleInputState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAIPawnPossessionChanged, APawn*, Pawn);

USTRUCT(BlueprintType)
struct FAIDeathInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	TWeakObjectPtr<AActor> FinisherOrDowner;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	TWeakObjectPtr<AActor> DeathInstigator;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	EDeathCause DeathCause;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	FVector DeathLocation;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	bool bInitialized;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	FGameplayTagContainer DeathTags;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	FGameplayTagContainer FinisherOrDownerTags;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	FGameplayTagContainer VictimTags;

	UPROPERTY(BlueprintReadOnly, Category="AIDeathInfo")
	FHitResult LastDamageHitResult;

};

USTRUCT()
struct FDamagerInfoAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DamageCauser;

	UPROPERTY()
	int32 DamageAmount;

};

USTRUCT(BlueprintType)
struct FFortAIAppearanceOverrideEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIAppearanceOverrideEntry")
	FName AppearanceName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIAppearanceOverrideEntry")
	bool bIsFemale;

private:
	UPROPERTY(EditAnywhere, Category="FortAIAppearanceOverrideEntry")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, Category="FortAIAppearanceOverrideEntry")
	TSoftObjectPtr<UFortFeedbackBank> FeedbackBank;

};

USTRUCT()
struct FFortAIAttributeReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 Health;

	UPROPERTY()
	uint32 MaxHealth;

};

USTRUCT()
struct FFortAIBatchedDamageCues
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bImpact;

	UPROPERTY()
	bool bImpactWeapon;

	UPROPERTY()
	bool bDamage;

	UPROPERTY()
	bool bDamageShields;

	UPROPERTY()
	bool bDamageWeapon;

	UPROPERTY()
	bool bFatal;

	UPROPERTY()
	bool bWeaponActivated;

	UPROPERTY()
	FVector_NetQuantize10 HitLocation;

	UPROPERTY()
	TObjectPtr<AActor> TargetActor;

};

USTRUCT(BlueprintType)
struct FFortAIPawnLootDropData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnLootDropData")
	float LootDropChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnLootDropData")
	FName WorldItemTierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnLootDropData")
	FName WorldItemInstancedTierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnLootDropData")
	FName AccountItemTierGroup;

};

USTRUCT()
struct FFortAIPawnSkeletalMeshAsyncMaterialLoadData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAIPawnSkeletalMeshAsyncMaterialLoadData")
	TSoftObjectPtr<UMaterialInterface> Material;

	UPROPERTY(EditAnywhere, Category="FortAIPawnSkeletalMeshAsyncMaterialLoadData")
	bool bRequireDynamicInstance;

};

USTRUCT()
struct FFortAIPawnSkeletalMeshAsyncLoadData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAIPawnSkeletalMeshAsyncLoadData")
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditAnywhere, Category="FortAIPawnSkeletalMeshAsyncLoadData")
	TArray<FFortAIPawnSkeletalMeshAsyncMaterialLoadData> OverrideMaterials;

	UPROPERTY(EditAnywhere, Category="FortAIPawnSkeletalMeshAsyncLoadData")
	TSoftClassPtr<UAnimInstance> AnimationBP;

};

USTRUCT()
struct FFortAISharedRepMovement
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FRepMovement RepMovement;

	UPROPERTY(Transient)
	FBasedMovementInfo RepRelativeBasedMovement;

	UPROPERTY(Transient)
	FVector_NetQuantizeNormal RepGravityDirection;

	UPROPERTY(Transient)
	float RepTimeStamp;

	UPROPERTY(Transient)
	uint8 RepMovementMode;

	UPROPERTY(Transient)
	bool bReplicatesBasedRelativeMovement;

	UPROPERTY(Transient)
	EFortAILODLevel RepCurrentFortAILODLevel;

	UPROPERTY(Transient)
	FGameplayAbilityRepSharedAnim_Index RepSharedAnimInfo;

};

USTRUCT()
struct FMinimapGoalByTagColorsData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MinimapGoalByTagColorsData")
	FGameplayTagContainer GoalTags;

	UPROPERTY(EditDefaultsOnly, Category="MinimapGoalByTagColorsData")
	FLinearColor MinimapColor;

};

USTRUCT()
struct FRunVariationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortAIPawn> FortAIPawn;

	UPROPERTY()
	float Distance;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Actor", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortAIPawn : public AFortPawn, public IFortSpawnableByPlacementSystemInterface, public IAIPerceptionListenerInterface, public IFortInteractInterface, public IFortInventoryOwnerInterface, public IFortHUDTargetUnderReticleInterface, public IFortMarkableActorInterface, public IFortWalkableBaseInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction, DeprecationMessage="AddFortAbilitySet is deprecated. Please use EquipFortAbilitySet instead."))
	void AddFortAbilitySet(UFortAbilitySet* FortAbilitySet);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void AddUnreachablePickup(AFortPickup* Pickup);

	UFUNCTION(BlueprintPure, Category="Customization")
	bool AreCustomizationsLoaded() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Interaction")
	bool BlueprintCanInteract(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="FortAIPawn")
	EPhysicalSurface BlueprintGetPrimaryPhysicalSurface() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Damage")
	float BlueprintModifyIncomingDamage(float Damage, const FGameplayTagContainer& DamageTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category="Gameplay Ability")
	bool CanHitTargetWithAbility(FGameplayTagContainer GameplayAbilityTag, AActor* CanHitTarget, bool bUseIdealYawRotationToTarget = false);

	UFUNCTION(BlueprintImplementableEvent)
	bool CanTetherJump();

	UFUNCTION(BlueprintCallable, Category="AI")
	void ClearAIFocalPoint(bool bUseAttackingPriority);

	UFUNCTION(BlueprintCallable, Category="AI")
	void DespawnAI(bool bDueToInactivity);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortAIPawn")
	const TArray<APawn*> FindValidPawnsUsedOrUsingThisAsABase();

	UFUNCTION()
	void FinishedEncounterSpawn();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void ForceKillNoDBNO();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	FVector GetBackpackLocation() const;

	UFUNCTION(BlueprintPure, Category="Controlled")
	bool GetBeingControlled() const;

	UFUNCTION(BlueprintPure, Category="Defender")
	EFortCustomGender::Type GetCharacterGender() const;

	UFUNCTION(BlueprintPure, Category="AI")
	AActor* GetCurrentAimTarget() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	void GetDeathInfo(FAIDeathInfo& OutDeathInfo) const;

	UFUNCTION(BlueprintPure, Category="Defender")
	FString GetDefenderItemInstanceId() const;

	UFUNCTION(BlueprintPure, Category="AI")
	float GetDifficultyLevel() const;

	UFUNCTION(BlueprintPure, Category="AI")
	float GetDifficultyRating() const;

	UFUNCTION(BlueprintPure, Category="Animation")
	static float GetGroundSpeedForUrgency(AFortAIPawn* FortAIPawn, EFortMovementUrgency::Type Urgency);

	UFUNCTION(BlueprintPure, Category="Sound")
	USoundBase* GetImpactPhysicalSurfaceSound(const FHitResult& Impact) const;

	UFUNCTION(BlueprintPure, Category="Defender", meta=(DisplayName="GetInventoryItemWithGuid"))
	UFortItem* GetInventoryItem(FGuid ItemGuid) const;

	UFUNCTION(BlueprintPure, Category="Animation")
	float GetLocomotionPlayRateScale() const;

	UFUNCTION(BlueprintPure, Category="Convert")
	float GetMaxConvertResistance() const;

	UFUNCTION(BlueprintPure, Category="Animation")
	static EFortMovementStyle::Type GetMovementStyle(const AFortAIPawn* FortAIPawn);

	UFUNCTION(BlueprintPure, Category="Animation")
	static EFortMovementUrgency::Type GetMovementUrgency(AFortAIPawn* FortAIPawn);

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	EScoreDistributionType GetScoreDistribution() const;

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	int32 GetScoreValue() const;

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	int32 GetScoreWithoutMutliplierValue() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	TArray<USkeletalMeshComponent*> GetSkeletalMeshesForAllParts() const;

	UFUNCTION(BlueprintPure, Category="Customization")
	USkeletalMeshComponent* GetSkeletalMeshForPartTag(FGameplayTag PartTag) const;

	UFUNCTION(BlueprintPure, Category="Customization")
	USkeletalMeshComponent* GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType) const;

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	const FGameplayTagQuery& GetSleepForGoalActors() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AI")
	FVector GetSpawnLocation() const;

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	int32 GetSpawnPointValue() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AI")
	FRotator GetSpawnRotation() const;

	UFUNCTION(BlueprintPure, Category="DBNO")
	bool GetUsesDBNO() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void GiveAmmo(const int32 AmmoQuantity);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void GrabPickup(AFortPickup* Pickup);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void GrabPickupCustomized(AFortPickup* Pickup, float FlyTime);

	UFUNCTION(BlueprintPure, Category="AI")
	bool HasTether() const;

	UFUNCTION(BlueprintPure, Category="FortAIPawn")
	bool IsDefender() const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsInCombat() const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsInsideTetherBounds(bool bUseRelaxedTetherBounds = false) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="FortAIPawn")
	bool IsUsedAsBaseByPawn() const;

	UFUNCTION(BlueprintPure, Category="AI", meta=(DisplayName="FindExistingItemForDefinition"))
	UFortItem* K2_FindExistingItemForDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, bool bInStorageVault = false) const;

	UFUNCTION(BlueprintPure, Category="Defender", meta=(DisplayName="GetDefenderItem"))
	UFortAccountItem* K2_GetDefenderItem() const;

	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_BatchedDamageCues(FFortAIBatchedDamageCues Data);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Animation")
	void NetMulticast_OnTurn(float TurnAngle, float TurnRate);

	UFUNCTION(BlueprintImplementableEvent)
	void OnApplyEffectOptimization(const int32 NewBudgetValue);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnBeginDeepWaterInteraction(FVector WaterSurfaceLocation, float WaterDepth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Animation")
	void OnBeginSleepEffects();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Controlled")
	void OnBeingControlledChanged(bool bControlled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCheatUpdateSpecialEventGE(bool bShouldUseSpecialEventGE);

	UFUNCTION()
	void OnEncounterSpawnEnableMeleeAttacking();

	UFUNCTION()
	void OnEncounterSpawnEnableRangedAttacking();

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnEndDeepWaterInteraction(FVector PreviousWaterSurfaceLocation, float WaterDepth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Animation")
	void OnEndSleepEffects();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Spawning")
	void OnFinishedEncounterSpawn();

	UFUNCTION(NetMulticast, Reliable)
	void OnForceEnterVehicle();

	UFUNCTION(NetMulticast, Reliable)
	void OnForceLeaveVehicle();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnOutOfConvertResistanceServer(float ConvertDamageDone, const FGameplayTagContainer& SourceTags, const FGameplayEffectContextHandle& EffectContext, AController* EffectInstigator, AActor* EffectCauser);

	UFUNCTION(BlueprintImplementableEvent)
	bool OnOutsideOfTetherBeyondMaxTimeAllowed();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAIPawn")
	void OnPawnStartedUsingMeAsWalkableBase(const APawn* PawnUsingThisAsBase);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAIPawn")
	void OnPawnStartedUsingOtherWalkableBase(const APawn* PawnUsedThisAsBase);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAIPawn")
	void OnPawnStoppedUsingMeAsWalkableBase(const APawn* PawnUsingThisAsBase);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReceiveReplicatedMovement();

	UFUNCTION()
	void OnRep_AttributeProxy();

	UFUNCTION()
	virtual void OnRep_CanInteract(bool bOldCanInteract);

	UFUNCTION()
	void OnRep_EnableBlockingCollisionWithOtherAI();

	UFUNCTION()
	void OnRep_Inventory();

	UFUNCTION()
	void OnRep_ReplicatedAnimMontage();

	UFUNCTION()
	void OnRep_SharedAnim();

	UFUNCTION()
	void OnRep_TetheredFollower();

	UFUNCTION()
	void OnSleepingAIsFloorBuildingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic, Category="Spawning")
	void OnStartedEncounterSpawn();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAIPawn")
	void OnTeamChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTetherRequestJump();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateFromVehicleInputEvent(float DeltaSeconds, const FFortAthenaVehicleInputState& VehicleInputState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTetheredFollower(AFortPawn* InTetheredFollower);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnWaterDeepNavMeshEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnWaterNavMeshEnter();

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnWaterNavMeshExit();

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	virtual void OverrideInteractionText(const FText& NewInteractionText);

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	virtual void OverrideInteractionType(const TEnumAsByte<TInteractionType>& NewInteractionType);

	UFUNCTION(BlueprintCallable, Category="HitReacts")
	void PlayAdditiveHitReactsNative(const FVector& HitDirection, UAnimMontage* NewAnimMontage);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	void ResetAIRotationRateToDefault();

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	virtual void RestoreInteractionText();

	UFUNCTION(BlueprintCallable, Category="InteractInterface")
	virtual void RestoreInteractionType();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void ReviveFromDBNO();

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetAIFocalPoint(AActor* FocusTarget, FVector FocalPoint, bool bUseAttackingPriority);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPawn")
	void SetAIRotationRate(const FRotator& AIRotationRate);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetAIType(EFortressAIType InAIType);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void SetBlockCollisionWithOtherAI(bool bInEnableBlockingCollisionWithOtherAI);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortAIPawn")
	void SetCanBeBaseForOtherPawns(bool bEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	virtual void SetCanInteract(bool CanInteract);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetCanSleep(bool InCanSleep);

	UFUNCTION(BlueprintCallable, Category="Collision")
	virtual void SetCollisionProfileName(FName InCollisionProfileName);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetCurrentAimTarget(AActor* AimTarget);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defender")
	void SetDefenderTrap(ABuildingTrapDefender* InDefenderTrap);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Customization")
	void SetDesiredCustomization(UFortAIPawnCustomizationDefinition* InCustomizationsToLoad);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void SetDisplayName(const FText& Name);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetEncounterInfo(UFortAIEncounterInfo* InEncounterInfo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Customization", meta=(BlueprintProtected="true"))
	virtual void SetEyeColor(FLinearColor NewEyeColor, float NewEyeBrightness);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetForceBossSignificance(bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIStates")
	virtual void SetIsCharging(bool bNewIsCharging);

	UFUNCTION(BlueprintCallable, Category="Animation")
	void SetLocomotionPlayRateScale(const float NewLocomotionPlayRateScale);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void SetMinimapViewableDistance(float NewMinimapViewableDistance);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetMinimumAILOD(EFortAILODLevel MinimumAILOD);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetMinSignificanceForAnimationCurves(float MinSignificance);

	UFUNCTION(BlueprintCallable, Category="Animation")
	virtual void SetMovementUrgency(EFortMovementUrgency::Type Urgency);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetOverridenScore(int32 InOverriddenScore);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetOverridenScoreDistribution(const EScoreDistributionType InOverriddenScoreDistribution);

	UFUNCTION(BlueprintCallable, Category="Gameplay Cue")
	void SetReplicateGameplayCuesWithFastAbilityReplication(const bool bReplicateGameplayCues);

	UFUNCTION(BlueprintCallable, Category="Gameplay Cue")
	void SetReplicateGrantedTagsWithFastAbilityReplication(const bool bReplicateGrantedTags);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetShouldStartSleeping(bool bHintStartSleeping);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Customization", meta=(BlueprintProtected="true"))
	virtual void SetSkinColor(FLinearColor NewSkinColor, float NewSkinBrightness);

	UFUNCTION(BlueprintCallable, Category="FortAIPawn")
	void SetSleepForGoalActors(const FGameplayTagQuery& InQuery);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DBNO")
	void SetUsesDBNO(bool bInUsesDBNO, TInteractionType InDBNOInteractionType = IT_NoInteraction, float InDBNOInteractionDuration = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="AI")
	void SetWeaponCollisionComponent(UShapeComponent* InWeaponCollisionComponent);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldUpdateSkeletalMesh();

	UFUNCTION(BlueprintNativeEvent, Category="Collision")
	bool ShouldUseFiringCapsuleCollision();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void SpawnPickupInWorldWithLootTierAsync(FName LootTierName, FVector Position, int32 OverrideMaxStackCount, bool bToss = true, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset);

	UFUNCTION(BlueprintCallable, Category="AI")
	void TriggerNoWeaponSpeech();

	UFUNCTION(BlueprintCallable, Category="Animation")
	void TurnOnSleepingOptimizations();

	UFUNCTION(BlueprintPure, Category="AI")
	bool WasDespawned() const;

	UPROPERTY()
	FGameplayCueParameters DeimosBatchedGameplayCueParameters;

	UPROPERTY(ReplicatedUsing=OnRep_AttributeProxy)
	FFortAIAttributeReplicationProxy AttributeReplicationProxy;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedAnimMontage)
	FGameplayAbilityRepAnimMontage RepAnimMontageInfo;

	UPROPERTY(ReplicatedUsing=OnRep_SharedAnim)
	FGameplayAbilityRepSharedAnim RepSharedAnimInfo;

	UPROPERTY(Replicated)
	FMinimalGameplayCueReplicationProxy SimulatedProxyGameplayCues;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bAttacking : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bDied : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bHitReact : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bFullBodyHitReact : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bDancing : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAIPawn")
	uint8 bRangedAttacking : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortAIPawn")
	uint8 bHasGoalActor : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="FortAIPawn")
	uint8 bFrozen : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	uint8 bUseSharedAnimation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	uint8 bAnimateOnServer : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability")
	uint8 bShouldUseRootComponentForTargetSelectionOverlap : 1;

	UPROPERTY()
	uint8 bNeedsDeathNotification : 1;

	UPROPERTY(Transient)
	uint8 bKilledOrDowned : 1;

	UPROPERTY(Transient)
	uint8 bDespawnedDueToInactivity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bNotifySpawnRift : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bUsesDBNO : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	uint8 bHasInventory : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	uint8 bShouldTossInventoryOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	uint8 bUseDefenderInventoryManagement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	uint8 bHasInstantReload : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	uint8 bHasInfiniteAmmo : 1;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	uint8 bAttemptLootDropOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIPawn")
	uint8 bIgnoreDefender : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIPawn")
	uint8 bCanUseWeapon : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI")
	uint8 bTrackNearbyPickups : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Replicated, Category="AI")
	uint8 bIsCharging : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="AI")
	uint8 bIsCowering : 1;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	uint8 bCanShowMinimapIndicator : 1;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	uint8 bShowMinimapFarOffDirectionArrow : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortAIPawn")
	uint8 bHasEngaged : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	uint8 bIsAlwaysGameplayRelevant : 1;

	UPROPERTY(EditDefaultsOnly, Category="Performance")
	uint8 bShowCustomCSVRelevantKey : 1;

	UPROPERTY(Transient)
	uint8 bIsDebugSpawnedAI : 1;

	UPROPERTY(Transient)
	uint8 bEncounterExpectedLifespanExpired : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EnableBlockingCollisionWithOtherAI)
	uint8 bEnableBlockingCollisionWithOtherAI : 1;

	UPROPERTY(EditDefaultsOnly, Category="Minimap")
	uint8 bSetMiniMapIconRotation : 1;

	UPROPERTY(Transient)
	uint8 bHasDroppedLoot : 1;

	UPROPERTY(Transient)
	uint8 bUseFastAbilityReplication : 1;

	UPROPERTY(Transient)
	uint8 bUseFastPreReplicationStep : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bTurnOffOnMatchEnd : 1;

	UPROPERTY(EditDefaultsOnly, Category="AIGoalSelection")
	uint8 bUseAIGoalComponent : 1;

	UPROPERTY(Replicated)
	FMinimalReplicationTagCountMap FastReplicationMinimalReplicationTags;

	UPROPERTY(Replicated)
	FMinimalGameplayCueReplicationProxy FastReplicationMinimalGameplayCueProxy;

	UPROPERTY(BlueprintAssignable, Category="FortItem")
	FFortAIOnInventoryInitialized OnInventoryInitialized;

	UPROPERTY(BlueprintAssignable, Category="FortItem")
	FFortAIInventoryUpdated OnInventoryUpdated;

	UPROPERTY(Replicated)
	float AIDifficultyLevel;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	EFortAILevelRatingDisplayType LevelRatingDisplayType;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> EncounterInfo;

	UPROPERTY(BlueprintReadWrite, Category="FortAIPawn")
	int32 SpawnSetIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortAIPawn")
	FGuid SpawnGroupGuid;

	UPROPERTY(BlueprintReadOnly, Category="FortAIPawn")
	int32 EnemyIndexInSpawnGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float FinishEncounterSpawnFallbackTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float EncounterSpawnDisableRangedAttackingTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float EncounterSpawnDisableMeleeAttackingTime;

	UPROPERTY()
	FTimerHandle EncounterExpectedLifespanTimerHandle;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortAIPawn")
	TObjectPtr<AActor> SpawnRift;

	UPROPERTY()
	FVector SpawnRiftLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortAIPawn")
	TObjectPtr<AActor> SpawnSourceActor;

	UPROPERTY(EditDefaultsOnly, Category="AIGoalSelection", meta=(EditCondition="bUseAIGoalComponent"))
	TSubclassOf<UAIGoalComponent> AIGoalComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float MaxTimeAllowedOutsideTether;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	TSubclassOf<UNavigationQueryFilter> DefaultNavFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	TSubclassOf<UNavigationQueryFilter> HuntingNavFilter;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Interaction", meta=(EditCondition="bUsesDBNO"))
	float DBNOInteractionDuration;

	UPROPERTY(BlueprintAssignable, Category="AI")
	FFortDBNO OnDowned;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Interaction", meta=(EditCondition="bUsesDBNO"))
	TEnumAsByte<TInteractionType> DBNOInteractionType;

	UPROPERTY(EditAnywhere, Category="AI", meta=(ArraySizeEnum="/Script/FortniteGame.EFortMovementUrgency"))
	TEnumAsByte<EFortMovementStyle::Type> MovementStyles[4];

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(editcondition="bTrackNearbyPickups"))
	float UpdateNearbyPickupFrequency;

	UPROPERTY(BlueprintReadOnly, Category="AI")
	FGameplayTag RequiredWeaponPickupTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI")
	FGameplayTagQuery RequiredWeaponPickupTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	bool bUsePickupDirectionOverride;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(EditCondition="bUsePickupDirectionOverride"))
	FVector PickupDirectionOverride;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	FName NoWeaponInCombatEventName;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	FName NoWeaponOutOfCombatEventName;

	UPROPERTY(Transient)
	FVector CachedHitLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Abilities")
	FGameplayTagContainer TurnTransitionGameplayAbilityTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	TSoftObjectPtr<UParticleSystem> DeathParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	int32 NumRunVariations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animation")
	int32 CurrentRunVariationIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	float RunVariationRadius;

	UPROPERTY(Transient, Replicated)
	float LocomotionPlayRateScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Customization")
	int32 EyeIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Customization")
	int32 SkinIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Customization")
	FLinearColor DefaultEyeColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Customization")
	float DefaultEyeBrightness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Customization")
	FLinearColor DefaultSkinColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Customization")
	float DefaultSkinGlow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MiniMap")
	FLinearColor MinimapDefaultIconColor;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	FLinearColor PlayerManagerMinimapColor;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapAboveBelowIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Minimap")
	TArray<FMinimapGoalByTagColorsData> MinimapGoalByTagColors;

	UPROPERTY(Transient, Replicated)
	int8 MinimapGoalByTagColorIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=(EditCondition="bUseAppearanceOverride", ExposeOnSpawn="TRUE"))
	FName AppearanceOverrideName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance", meta=(EditCondition="bUseAppearanceOverride", ExposeOnSpawn="TRUE"))
	EFortAIPawnGender AppearanceOverrideGender;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TEnumAsByte<EFortCombatEvents::Type> FollowPlayerEvent;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TEnumAsByte<EFortCombatEvents::Type> InCombatNearPlayerEvent;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	TEnumAsByte<TInteractionType> InteractionType;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float FollowPlayerRange;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionDuration;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FText InteractionText;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	TEnumAsByte<TInteractionType> SecondInteractionType;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float SecondInteractionDuration;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FText SecondInteractionText;

	UPROPERTY(BlueprintAssignable, Category="AI")
	FFortAIInteraction OnInteraction;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> InteractionSound;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAIPawn")
	TObjectPtr<ABuildingTrapDefender> DefenderTrap;

	UPROPERTY(BlueprintAssignable, Category="Collision")
	FFortCrowdOverlap OnActorBeginCrowdOverlap;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	bool bCollisionFreeBuildingOnlyAgainstPlayerBuilds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WaterInteraction")
	float DeepWaterImmersionDepth;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	TSubclassOf<UFortCameraMode> TetheredCamera;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawn")
	TSubclassOf<UFortCameraMode> TetheredTargetingCamera;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Tether")
	bool bIsTetheredBoosting;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherBoostMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherJumpServerCorrectionIgnoreTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tether")
	float TetherJumpLastTime;

	UPROPERTY(EditDefaultsOnly, Category="Tether")
	TSubclassOf<AActor> TetherBoundsXYSplineClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USplineComponent> TetherBoundsXYSplineComponent;

	UPROPERTY(BlueprintAssignable)
	FFortUpdateFromVehicleInput OnUpdateFromVehicleInput;

protected:
	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void HideMapMarker();

	UFUNCTION(BlueprintImplementableEvent, Category="Survivor")
	void OnAppearanceOverridden();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCustomizationsLoaded_BP();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCustomizationsUnloaded_BP();

	UFUNCTION(BlueprintImplementableEvent, Category="Defender")
	void OnDefenderTrapSet(ABuildingTrapDefender* OldDefenderTrap);

	UFUNCTION(BlueprintNativeEvent)
	FVector OnLaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride);

	UFUNCTION()
	void OnRep_AppearanceOverrideEntryIndex();

	UFUNCTION()
	void OnRep_BeingControlled();

	UFUNCTION()
	void OnRep_bIsSleeping();

	UFUNCTION()
	void OnRep_CurrentAIRotationRate();

	UFUNCTION()
	void OnRep_CustomizationsToLoad();

	UFUNCTION()
	void OnRep_MinimapViewableDistance();

	UFUNCTION()
	void OnRep_UpgradeUIData();

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Effects")
	bool ShouldApplyBuildingHitEffect(float Damage, FVector Location, FHitResult HitInfo, bool bPlayerPlaced) const;

	UFUNCTION(BlueprintPure)
	bool ShouldReplicateGameplayCuesWithFastAbilityReplication() const;

	UFUNCTION(BlueprintPure)
	bool ShouldReplicateGrantedTagsWithFastAbilityReplication() const;

	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void ShowMapMarker();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bDebugAI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bDebugAIAnim : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bUseBuildingAttackingHotspots : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bCanBeLaunched : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bCanMoveThroughWalls : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bCanUseNavWalking : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bCanUseSimpleCollisions : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bCanUseStepAside : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bCanUseDoors : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	uint8 bCanUseOpenedDoors : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bCanUseShootingHotspots : 1;

	UPROPERTY()
	uint8 bCanSleep : 1;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_bIsSleeping, Category="Animation")
	uint8 bIsSleeping : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bShouldStartSleeping : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bCanLookAtGoal : 1;

	UPROPERTY(Transient)
	uint8 bDespawnedDueToExpiration : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bAllowServerCosmeticComponentOptimizations : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bAllowCapsuleComponentsOnServer : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bRootComponentIgnoreQueryPawnCapsule : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	uint8 bCanUseMeshPooling : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	uint8 bUseCrowdSimulation : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="AI")
	uint8 bControlWalkingOffLedges : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Replicated, Category="AI")
	uint8 bCanBeBaseForOtherPawns : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	uint8 bUseAppearanceOverride : 1;

	UPROPERTY(ReplicatedUsing=OnRep_CanInteract)
	uint8 bCanInteract : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUD")
	uint8 bHideHealthBar : 1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bHasBuildingHitEffects : 1;

	UPROPERTY(EditDefaultsOnly, Category="FastAbilityReplication")
	uint8 bReplicateGrantedTagsWithFastAbilityReplication : 1;

	UPROPERTY(EditDefaultsOnly, Category="FastAbilityReplication")
	uint8 bReplicateGameplayCuesWithFastAbilityReplication : 1;

	UPROPERTY(EditDefaultsOnly, Category="FastAbilityReplication")
	uint8 bOnlySkipAbilitySystemComponentWithFastAbilityReplication : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Character")
	uint8 bShouldIgnoreThisBaseRotation : 1;

	UPROPERTY()
	FGameplayTagQuery SleepForTheseGoalActors;

	UPROPERTY(ReplicatedUsing=OnRep_BeingControlled)
	TWeakObjectPtr<AFortPlayerState> BeingControlledBy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="AI")
	TEnumAsByte<EFortMovementUrgency::Type> MovementUrgency;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="AI")
	EFortressAIType AIType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category="FortAIPawn")
	uint8 Team;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="AI")
	FName SimpleCollisionsProfileName;

	UPROPERTY(ReplicatedUsing=OnRep_UpgradeUIData)
	FFortAISpawnGroupUpgradeUIData UpgradeUIData;

	UPROPERTY(Transient)
	FSlateBrush CachedUpgradeUIDataUpgradeIconBrush;

	UPROPERTY()
	float ScoreMultiplier;

	UPROPERTY()
	int32 OverriddenScore;

	UPROPERTY()
	EScoreDistributionType OverriddenScoreDistribution;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	float LootDropConeHalfAngle;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	float LootDropSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	float MinItemTossDist;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	float MaxItemTossDist;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	float ItemTossDirectionConeHalfAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI")
	EFortHotSpotSlot HotspotType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI")
	EFortPartialPathUsage PartialPathUsage;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAIPawn")
	TObjectPtr<AFortPlayerStateZone> PlayerManager;

	UPROPERTY(Replicated)
	FString DefenderItemInstanceId;

	UPROPERTY(Replicated)
	FName DefenderSquadId;

	UPROPERTY(Replicated)
	float DefenderPlacedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float RecentlySeenInterval;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentAIRotationRate, Category="AI")
	FRotator CurrentAIRotationRate;

	UPROPERTY(EditAnywhere, Category="AI")
	float MoveSoundStimulusBroadcastInterval;

	UPROPERTY(EditAnywhere, Category="AI")
	float MoveSoundStimulusMaxRange;

	UPROPERTY(EditAnywhere, Category="AI")
	bool bGenerateMoveSoundInAllMovementModes;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UShapeComponent> WeaponCollisionComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Inventory)
	TObjectPtr<AFortInventory> Inventory;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAIPawn")
	TArray<TObjectPtr<AFortPickup>> NearbyPickups;

	UPROPERTY(Transient)
	TMap<TObjectPtr<AFortPickup>, float> UnreachablePickups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Appearance", meta=(EditCondition="bUseAppearanceOverride"))
	TArray<FFortAIAppearanceOverrideEntry> AppearanceOverrideEntries;

	UPROPERTY(ReplicatedUsing=OnRep_AppearanceOverrideEntryIndex)
	int32 AppearanceOverrideEntryIndex;

	UPROPERTY(BlueprintReadOnly, Category="AI")
	FVector SpawnLocation;

	UPROPERTY()
	FRotator SpawnRotation;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> SleepingFloor;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Collision")
	FName PelvisBoneName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Collision")
	FName HeadBoneName;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	uint8 bUpdateWeaponCollisionShapeOnKnockback : 1;

	UPROPERTY(EditDefaultsOnly, Category="Minimap")
	float MinimapIndicatorUpdateFrequency;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_MinimapViewableDistance, Category="MiniMap")
	float MinimapViewableDistance;

	UPROPERTY(EditDefaultsOnly, Category="HUD")
	float DistanceToPlayerManagerToShowHealthBar;

	UPROPERTY(EditDefaultsOnly, Category="HUD")
	float DistanceToOtherPlayersToShowHealthBar;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortAIAttributesSet> AttributesSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortCharacterAttrSet> CharacterAttrSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponAttrSet> WeaponAttrSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortConvertSet> ConvertSet;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TObjectPtr<USoundBase> ImpactPhysicalSurfaceSounds[35];

	UPROPERTY(EditAnywhere, Category="Effects")
	TObjectPtr<UParticleSystem> ImpactPhysicalSurfaceEffects[35];

	UPROPERTY(EditAnywhere, Category="AthenaAvoidance")
	FScalableFloat AthenaRVOWeightOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFortSimpleMiniMapIndicator> MiniMapIndicator;

	UPROPERTY(EditAnywhere, Category="UI|MiniMap")
	FVector2D MiniMapScale;

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbilities")
	TArray<TObjectPtr<UFortAbilitySet>> DefaultGameplayAbilitySets;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAbilitySet>> SpawnInheritedCharacterAbilitySets;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> SpawnModifierDefinitions;

	UPROPERTY(BlueprintReadOnly, Export, Category="GameplayAbilities", meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AIPawnAbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbilities")
	FGameplayTagContainer WallAttackGameplayAbilityTags;

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbilities")
	FGameplayTagContainer WallRangedAttackGameplayAbilityTags;

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbilities")
	FGameplayTagContainer CeilingAttackGameplayAbilityTags;

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbilities")
	FGameplayTagContainer FloorAttackGameplayAbilityTags;

	UPROPERTY(Transient)
	TArray<FGameplayTagContainer> FailedAbilityQueryTags;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AActor> CurrentAimTarget;

	UPROPERTY(Transient, Replicated)
	FVector CurrentAimLocation;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortNavObstacleComponent> NavObstacleComponent;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float BuildingHitMaxDistanceToPlayer;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float BuildingHitMaxDistanceToHitLocation;

	UPROPERTY(EditDefaultsOnly, Category="DamageZones")
	float HeadHeightPercent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking", meta=(EditCondition="bCanBeMarked"))
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	bool bCanBeMarked;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	FScalableFloat IsBlockingBuilding;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_CustomizationsToLoad, Category="FortAIPawn")
	TObjectPtr<UFortAIPawnCustomizationDefinition> CustomizationsToLoad;

	UPROPERTY(EditAnywhere, Replicated, Category="FortAIPawn")
	bool bCanUnloadCustomization;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIPawnCustomizationDefinition> UsedCustomization;

	UPROPERTY(BlueprintAssignable, Category="Customization")
	FFortAIPawnCustomizationsLoaded OnCustomizationsLoadedEvent;

	UPROPERTY(BlueprintAssignable, Category="Customization")
	FFortAIPawnCustomizationsUnloaded OnCustomizationsUnloadedEvent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCharacterPartsComponent> CachedPartsComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIAssetLoader> AIAssetLoader;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AllowPrivateAccess="true"))
	uint8 bReplicateInventory : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortAIPawn")
	FHitResult LastDamageHitResult;

	UPROPERTY(EditAnywhere, Category="FortAIPawn")
	FVector CustomBounceVelocityForPickup;

	UPROPERTY(EditAnywhere, Category="FortAIPawn")
	FVector CustomBouncePawnOffsetForPickup;

	UPROPERTY(EditDefaultsOnly, Category="AdvancedMovementSet")
	bool bSupportsAdvancedMovementSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert")
	bool bSupportsConvertSet;

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	void DropAllItems(bool bSpawnPickups = true);

	UFUNCTION(NetMulticast, Unreliable)
	void FastSharedReplication(const FFortAISharedRepMovement& SharedRepMovement);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_Dormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_BelowLower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_Lower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_AboveLower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_BelowNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_Normal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	FScalableFloat NetUpdateFrequency_AboveNormal;

	UPROPERTY(Transient)
	TObjectPtr<UFortAccountItem> DefenderItem;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TetheredFollower, Category="FortAIPawn", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortPawn> TetheredFollower;

};

