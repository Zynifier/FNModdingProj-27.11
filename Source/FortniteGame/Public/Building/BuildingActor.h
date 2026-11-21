// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "NavLinkHostInterface.h"
#include "AI/FortAITypes.h"
#include "AI/Navigation/AthenaNavRelevantActorInterface.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "ActorMetadata/FortActorMetadataInterface.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "Building/BuildingTypes.h"
#include "Creative/Components/DeviceTrackingInterface.h"
#include "Curie/FortCurieInterface.h"
#include "DynamicDestruction/DynamicDestructionObjectInterface.h"
#include "FortActorLabelOverride.h"
#include "FortCombatTypes.h"
#include "FortDamageSourceInterface.h"
#include "FortDamageableActorInterface.h"
#include "FortDeviceInterface.h"
#include "FortEditorPreviewInterface.h"
#include "FortHolsterWeaponSourceInterface.h"
#include "FortInitializationInterface.h"
#include "FortInteractInterface.h"
#include "FortReplicationGraphInterface.h"
#include "FortTeamActorInterface.h"
#include "FortTeamEnum.h"
#include "FortTransientOverrideUtils.h"
#include "FortUserOptionDefinitionContainer.h"
#include "FortUserOptionValues.h"
#include "FortVersionedSparseClassData.h"
#include "LevelSaveSpawnableInterface.h"
#include "Missions/FortSpawnableByPlacementSystemInterface.h"
#include "Physics/FortPhysicsObjectInterface.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "BuildingActor.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortAthenaVehicle;
class AFortDecoTool;
class AFortMission;
class AFortPawn;
class AFortPlacementActor;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerState;
class AFortPlayerStateZone;
class UActorComponent;
class UBuildingActorEditorComponent;
class UBuildingActorHotSpotConfig;
class UBuildingActorHotSpotRenderingComponent;
class UBuildingTargetingData;
class UFortAbilitySystemComponent;
class UFortBuildingActorSet;
class UFortDamageSet;
class UFortHealthBarIndicator;
class UFortInteractContextInfoWidget;
class UFortPhysicsObjectComponent;
class UNavArea;
class UNavLinkDefinition;
class UObject;
class UPrimitiveComponent;
class UProjectileMovementComponent;
class USoundBase;
class UTexture2D;
enum class EFortDayPhase : uint8;
enum class ENavigationObstacleOverride : uint8;

UENUM()
enum class EAttributeInitLevelSource : uint8
{
	/** Level is specified directly from the world difficulty */
	WorldDifficulty = 0,
	/** Level is specified from the player building skill attribute */
	PlayerBuildingSkill = 1,
	/** Level value is determined by Athena playlist's BuildingLevelOverride value */
	AthenaPlaylist = 2,
};

UENUM()
enum class EBuildingActorComponentCreationPolicy : uint8
{
	/** Never create a component. */
	Never = 0,
	/** Create a component when it is first accessed. Client-side access of the ability system component before it is created and replicated will return nullptr. */
	Lazy = 1,
	/** Always a component when this actor is created. More efficient for actors where you know it will always need one. */
	Always = 2,
};

UENUM()
enum class EBuildingTickReason : uint8
{
	Dynamic = 0,
	Damaged = 1,
	GameplayCue_Damage = 2,
	GameplayCue_Healing = 3,
	GameplayCue_InstantDeath = 4,
	UnderConstruction = 5,
	UnderRepair = 6,
	Editing = 7,
	BuildingAnimation = 8,
	DynamicLODAnim = 9,
	DynamicShrinkAnim = 10,
	AutoBuild = 11,
	FullHealthEffect = 12,
	BounceAnimation = 13,
	DoorOpenStyleChanged = 14,
	DoorOpenChanged = 15,
	DoorInteract = 16,
	CinematicCamera = 17,
	Blueprint = 18,
};

UENUM()
namespace EDynamicBuildingPlacementType
{
	enum Type
	{
		//This means it counts towards the final bounding box

		CountsTowardsBounds = 0 UMETA(DisplayName="Counts Towards Bounds"),
		//this means that if it is in the way, it gets destroyed

		DestroyIfColliding = 1 UMETA(DisplayName="Destroy If Colliding"),
		//this means that it will destroy anything in its way when placed

		DestroyAnythingThatCollides = 2 UMETA(DisplayName="Destroy Anything That Collides"),
	};
}

UENUM()
enum class ENavLinkPreviewMode : uint8
{
	None = 0,
	Definition = 1,
	Cache = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorHealthChanged, AActor*, Actor, float, NewHealth);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuildingActorOnInteract, ABuildingActor*, SelfActor, AFortPawn*, InteractingPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(FBuildingDamagedSignature, AActor*, DamagedActor, float, Damage, AController*, InstigatedBy, AActor*, DamageCauser, FVector, HitLocation, UPrimitiveComponent*, FHitComponent, FName, BoneName, FVector, Momentum);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBuildingHealthChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilitySystemComponentInitialized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnDeathPlayEffectsDelegate, float, Damage, const FGameplayTagContainer&, DamageTags, FVector, Momentum, const FHitResult&, HitInfo, AFortPawn*, InstigatedBy, AActor*, DamageCauser, FGameplayEffectContextHandle, EffectContext);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPostDuplicate, bool, bDuplicateForPie);

USTRUCT(BlueprintType)
struct FBuildingActorClassData : public FUserOptionDefinitionContainer
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, AdvancedDisplay, Category="Debug", meta=(NoGetter))
	FFortVersionedSparseClassData VersionData;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Attributes", meta=(NoGetter))
	FFortAttributeInitializationKey AttributeInitKeys[2];

	UPROPERTY(EditDefaultsOnly, Category="Attributes", meta=(NoGetter))
	EAttributeInitLevelSource AttributeInitLevelSource;

	UPROPERTY(EditDefaultsOnly, Category="Navigation", meta=(DisplayName="Navigation Links Class", editcondition="bIsNavigationModifier", NoGetter))
	TSoftClassPtr<UNavLinkDefinition> NavigationLinkSoftClass;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	int32 MaximumBuildingLevel;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	float LifespanAfterDeath;

	UPROPERTY(EditDefaultsOnly, Category="HealthBar")
	float HealthBarIndicatorWidth;

	UPROPERTY(EditDefaultsOnly, Category="HealthBar")
	float HealthBarIndicatorVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="HealthBar", meta=(GetByRef))
	FName HealthBarIndicatorSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction", meta=(DisplayName="Interaction Text", NoGetter))
	FText BuildingActorInteractionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction", meta=(GetByRef))
	TSubclassOf<UFortInteractContextInfoWidget> InteractionOverrideWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction", meta=(GetByRef))
	TSubclassOf<UFortInteractContextInfoWidget> SecondInteractionOverrideWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	TObjectPtr<UBuildingTargetingData> BuildingTargetingDataOverride;

};

USTRUCT()
struct FBuildingDestructionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPawn> PawnInstigator;

	UPROPERTY()
	TWeakObjectPtr<AActor> DamageCauser;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), ClassGroup=("Building"), ConversionRoot, SparseClassDataType=BuildingActorClassData)
class ABuildingActor : public AActor, public IFortInteractInterface, public INavLinkHostInterface, public IFortTeamActorInterface, public IFortInitializationInterface, public IAthenaNavRelevantActorInterface, public INavRelevantInterface, public INavAgentInterface, public IFortSpawnableByPlacementSystemInterface, public IGameplayTagAssetInterface, public IGameplayCueInterface, public IFortDamageableActorInterface, public IEditorPreviewInterface, public IFortAbilitySystemInterface, public ILevelSaveSpawnable, public IFortCurieInterface, public IFortReplicationGraphInterface, public IFortPhysicsObjectInterface, public IFortDamageSourceInterface, public IUserOptionValuesInterface, public IFortActorLabelOverrideInterface, public INativePlayStopPauseInterface, public IDeviceTrackingInterface, public IFortActorMetadataInterface, public IFortHolsterWeaponSourceInterface, public IDynamicDestructionObjectInterface, public IFortExposedAssetProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tags")
	FORTNITEGAME_API void AddEditorOnlyInstanceGameplayTags(const FGameplayTagContainer& NewTags);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void AddUniqueTransientOverride(FName InObjectName, FName InPropertyName, bool bInMarkTransient = true);

	UFUNCTION(BlueprintCallable, Category="Spawning", meta=(BlueprintInternalUseOnly="true", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject"))
	FORTNITEGAME_API static ABuildingActor* BeginDeferredBuildingActorSpawnFromClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, AActor* OptionalOwner = nullptr, bool bTransient = false);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Interaction")
	FORTNITEGAME_API bool BlueprintCanInteract(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted = FirstInteraction, const TInteractionType InteractionType = IT_Simple) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Gameplay", meta=(DisplayName="Die"))
	FORTNITEGAME_API void BlueprintDie(FGameplayTag DeathReason, AController* Killer, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Interaction")
	FORTNITEGAME_API bool BlueprintDisplaySubInteractIcon(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted = FirstInteraction, const TInteractionType InteractionType = IT_Simple) const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	FORTNITEGAME_API bool BlueprintGetAllHighlightableComponents(TArray<UPrimitiveComponent*>& OutHighlightableComponents) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API FText BlueprintGetFailedInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API FText BlueprintGetFailedSubInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API TSoftObjectPtr<UTexture2D> BlueprintGetFailedSubTextTexture(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API FText BlueprintGetInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	FORTNITEGAME_API bool BlueprintGetInteractionTime(const AFortPawn* InteractingPawn, float& OutInteractionTime, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API FText BlueprintGetSubInteractionString(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Interaction")
	FORTNITEGAME_API void BlueprintOnBeginInteract(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted, const TInteractionType InteractionType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Interaction")
	FORTNITEGAME_API void BlueprintOnInteract(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Interaction")
	FORTNITEGAME_API void BlueprintOnInterruptInteract();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Interaction")
	FORTNITEGAME_API bool BlueprintOnLocalInteract(AFortPlayerPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	FORTNITEGAME_API void BlueprintUpdateDynamicInteractionOptions(FGameplayTagContainer& OutGameplayTags, const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="GetDebugString"))
	FORTNITEGAME_API FString BP_GetDebugString() const;

	UFUNCTION(BlueprintPure, Category="Physics")
	FORTNITEGAME_API bool CanClientSimulate() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static bool CanDestroyBuildingActor(ABuildingActor* BuildingActor, AController* DamageInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void ClearPlayedDying();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void CustomStateChanged();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API bool DeleteOnResetMinigamePlayerIfAttached() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	FORTNITEGAME_API bool DoesMutatorBlockIncomingDamage() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Gameplay")
	FORTNITEGAME_API void ForceBuildingHealth(float NewHealth = 1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AbilitySystem")
	FORTNITEGAME_API void ForceChangeOwnerInstigator(AFortPlayerController* NewInstigator);

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API UFortBuildingActorSet* GetBuildingAttributeSet() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API UFortBuildingActorSet* GetBuildingAttributeSet_DontCreate() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API virtual FVector GetCentroid() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API virtual int32 GetCurrentBuildingLevel() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API virtual FString GetCustomState() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API virtual FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="Tags")
	FORTNITEGAME_API void GetEditorTestTags(FGameplayTagContainer& TagContainer) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Tags")
	FORTNITEGAME_API const FGameplayTagContainer& GetGameplayTags() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetHealth() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetHealthPercent() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetMaxShield() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API float GetMissingHealth() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API UClass* GetNavigationLinksClass() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	FORTNITEGAME_API FGameplayTag GetOverrideItemInteractAbilityTag() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API AController* GetOwningController() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API AFortPlayerState* GetOwningPlayerState() const;

	UFUNCTION(BlueprintCallable, Category="Building Actor | Physics Simulation Support")
	FORTNITEGAME_API static UFortPhysicsObjectComponent* GetPhysicsObjectComponent(ABuildingActor* Building);

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetShield() const;

	UFUNCTION()
	FORTNITEGAME_API float GetShieldOrHealthPercent();

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API virtual float GetShieldPercent() const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API bool HasHealthLeft() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual void InitializeKismetSpawnedBuildingActor(ABuildingActor* BuildingOwner, AFortPlayerController* SpawningController, bool bUsePlayerBuildAnimations = true, ABuildingActor* ReplacedBuilding = nullptr);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Building")
	FORTNITEGAME_API bool IsAcceptablePositionForPlacement(const FVector& InLocation, const FRotator& InRotation, AFortDecoTool* DecoTool, bool bIsCDO, FText& OutFailureReason) const;

	UFUNCTION(BlueprintPure, Category="Health")
	FORTNITEGAME_API bool IsDamaged() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API bool IsLockedFromGameEditing() const;

	UFUNCTION(BlueprintPure, Category="BuildingActor")
	FORTNITEGAME_API bool IsPlayerBuilt() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API bool IsPreviewBuildingActor() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building", meta=(DisplayName="SpawnBuildingActor", ScriptName="SpawnBuildingActor", WorldContext="WorldContextObject"))
	FORTNITEGAME_API static ABuildingActor* K2_SpawnBuildingActor(const UObject* WorldContextObject, TSubclassOf<ABuildingActor> Class, const FTransform& Transform, AActor* OptionalOwner = nullptr, AActor* OptionalInstigator = nullptr, const bool bDeferConstruction = false, const bool bTransient = false);

	UFUNCTION(BlueprintNativeEvent, Category="UserOptions")
	FORTNITEGAME_API void MigrateLegacyUserOptions();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	FORTNITEGAME_API bool ObstructsTrapTargetingGivenTags(const FGameplayTagContainer& TrapDefTags) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API void OnBuildingActorInitialized(EFortBuildingInitializationReason::Type InitializationReason, EFortBuildingPersistentState::Type BuildingPersistentState);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnDamagePlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	FORTNITEGAME_API void OnDamageServer(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnDeathPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	FORTNITEGAME_API void OnDeathServer(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, Category="Building")
	FORTNITEGAME_API void OnIsForPreviewingChangedBP(const bool bNewIsForPreviewing);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnMatchStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	FORTNITEGAME_API void OnPreCloningSetupStarted();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_InstantDeath();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnSetCustomDepthStencilValue(const TArray<UPrimitiveComponent*>& PrimComponents, bool bUseCustomDepth, int32 StencilValue, bool& bOutConsume);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnWorldReady();

	UFUNCTION(BlueprintNativeEvent, Category="Building", meta=(DisplayName="PlacedByPlacementTool"))
	FORTNITEGAME_API void PlacedByPlacementTool();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Building Actor")
	FORTNITEGAME_API void PlacedByPlayer(const AFortPlayerStateZone* PlayerState);

	UFUNCTION(BlueprintCallable, Category="Tags")
	FORTNITEGAME_API void RemoveEditorOnlyInstanceGameplayTags(const FGameplayTagContainer& TagsToRemove);

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API void ReplaceNavAreaClass(const TSubclassOf<UNavArea>& ReplacementAreaClass);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	FORTNITEGAME_API void SetAlwaysExportNavRelevantComponent(const bool bInAlwaysExportNavRelevantComponent);

	UFUNCTION(BlueprintCallable, Category="Draw Distance")
	FORTNITEGAME_API void SetBRDrawDistances(float NewBRMinDrawDistance, float NewBRMaxDrawDistance);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetCanBeSavedToCreativeVolume(bool bCanBeSaved);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	FORTNITEGAME_API void SetCanExportNavigationObstacle(bool InCanExportNavigationObstacle);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual void SetCustomState(const FString& NewState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetHealthBarIndicatorDifficultyRating(int32 InDisplayLevel);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetIsNavigationRelevant(const bool bInIsNavigationRelevant);

	UFUNCTION(BlueprintCallable, Category="Health")
	FORTNITEGAME_API virtual bool SetMaxHealth_DontCreateASC(float NewMaxHealth);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	FORTNITEGAME_API void SetNavigationIndestructible(const bool bNavIndestructible);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	FORTNITEGAME_API void SetNavigationModifier(bool bEnableModifier);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	FORTNITEGAME_API void SetNavigationObstacleOverride(const ENavigationObstacleOverride NavOverride);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetQuestHighlight(bool Enabled);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetSuppressHealthBar(bool bNewValue);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void SetTeam(uint8 InTeam);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Death")
	FORTNITEGAME_API bool ShouldDie(float Damage, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API bool ShouldDisplayDamageNumbers() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	FORTNITEGAME_API bool ShouldDisplayFirstInteractPrompt(const AFortPawn* InteractingPawn, const TInteractionType InteractionType) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool ShouldDisplayMobileInteractPrompt() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	FORTNITEGAME_API bool ShouldDisplaySecondInteractPrompt(const AFortPawn* InteractingPawn, const TInteractionType InteractionType) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Gameplay")
	FORTNITEGAME_API virtual void SilentDie(const bool bPropagateSilentDeath = false);

	UFUNCTION(BlueprintCallable, Category="Culling")
	FORTNITEGAME_API virtual void UpdateCullDistance(const bool bIgnoreLODParent = false);

	UFUNCTION(BlueprintNativeEvent, Category="Health")
	FORTNITEGAME_API bool UseDefaultHealthBar() const;

	UPROPERTY(DuplicateTransient)
	FGuid MyGuid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Navigation", meta=(editcondition="bIsNavigationModifier"))
	TSoftClassPtr<UNavArea> AreaClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EPhysicalSurface> PrimarySurfaceType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(BlueprintAssignable)
	FOnAbilitySystemComponentInitialized OnAbilitySystemComponentInitialized;

	UPROPERTY(Transient)
	TArray<FGameplayCueParameters> PendingDamageImpactCues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	ENavigationObstacleOverride NavigationObstacleOverride;

	UPROPERTY(EditDefaultsOnly, Category="Persistence")
	uint8 bPersistToWorld : 1;

	UPROPERTY(EditDefaultsOnly, Category="Persistence", meta=(EditCondition="bPersistToWorld"))
	uint8 bRefreshFullSaveDataBeforeZoneSave : 1;

	UPROPERTY(Transient)
	uint8 bBeingDragged : 1;

	UPROPERTY()
	uint8 bRotateInPlaceGame : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingActor")
	uint8 bBeingOneHitDisassembled : 1;

	UPROPERTY(EditDefaultsOnly, Category="BuildingActor")
	uint8 bBoundsAreInvalidForMelee : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Navigation")
	uint8 bIsNavigationModifier : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bBlockNavigationLinks : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bCanExportNavigationCollisions : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bCanExportNavigationObstacle : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bCreateObstacleNavModifierForEachComponent : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bMirrorNavLinksX : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bMirrorNavLinksY : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bIgnoreMoveGoalCollisionRadius : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bForceDisableRootNavigationRelevance : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bForceAutomationPass : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bForceAutomationPass_NavmeshOnTop : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bForceAutomationPass_SmashableFlat : 1;

	UPROPERTY(Transient)
	uint8 bPredictedBuildingActor : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Building")
	uint8 bIgnoreCollisionWithCriticalActors : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="PlayerBuilt")
	uint8 bIsPlayerBuildable : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	uint8 bFireBuiltAndDestroyedEvents : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Building")
	uint8 bStructurallySupportOverlappingActors : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	uint8 bAllowInteract : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bShowFirstInteractPrompt : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bShowSecondInteractPrompt : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bAllowHostileBlueprintInteraction : 1;

	UPROPERTY(EditDefaultsOnly, Category="BuildingActor")
	uint8 bEndAbilitiesOnDeath : 1;

	UPROPERTY(Transient)
	uint8 bSkipNavigationDirtiness : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Building")
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY(BlueprintAssignable)
	FBuildingDamagedSignature OnDied;

	UPROPERTY(BlueprintAssignable)
	FBuildingDamagedSignature OnOutOfHealthNotDestroyed;

	UPROPERTY(BlueprintAssignable)
	FBuildingDamagedSignature OnDamaged;

	UPROPERTY(BlueprintAssignable)
	FOnDeathPlayEffectsDelegate OnDeathPlayEffectsDelegate;

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FBuildingActorOnInteract OnInteract;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	FCurveTableRowHandle InteractionSpeed;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBuildingActorHotSpotRenderingComponent> HotSpotPreviewComp;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Transient, Category="AI")
	EFortHotSpotPreview HotSpotPreviewType;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Transient, Category="AI")
	EFortHotSpotDirection HotSpotPreviewDirection;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Transient, Category="AI")
	uint8 bShowSmashHotSpotExtraConfig : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="AI")
	ENavLinkPreviewMode NavLinkPreviewMode;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="AI")
	uint8 bShowNavLinkLandingHeight : 1;
#endif

	UPROPERTY(BlueprintAssignable, Category="Health")
	FBuildingHealthChanged OnBuildingHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FActorHealthChanged OnActorHealthChanged;

	FORTNITEGAME_API virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

	FORTNITEGAME_API virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Building Actor|Physics Simulation Support", meta=(DisplayName="HandlePhysicsObjectActivated"))
	FORTNITEGAME_API void BP_HandlePhysicsObjectActivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Building Actor|Physics Simulation Support", meta=(DisplayName="HandlePhysicsObjectAwakeChanged"))
	FORTNITEGAME_API void BP_HandlePhysicsObjectAwakeChanged(const bool bAwake);

	UFUNCTION(BlueprintImplementableEvent, Category="Building Actor|Physics Simulation Support", meta=(DisplayName="HandlePhysicsObjectDeactivated"))
	FORTNITEGAME_API void BP_HandlePhysicsObjectDeactivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Building Actor|Physics Simulation Support", meta=(DisplayName="HandlePhysicsObjectWasSetup"))
	FORTNITEGAME_API void BP_HandlePhysicsObjectWasSetup();

	UFUNCTION(BlueprintCallable, meta=(DisplayName="SetTemporarilyTicking"))
	FORTNITEGAME_API void BP_SetTemporarilyTicking(const bool bEnabled);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_Healing(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_InstantDeath(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API UPrimitiveComponent* GetCurieCollisionComponentOverride() const;

	UFUNCTION(BlueprintCallable, Category="Loot")
	FORTNITEGAME_API FName GetLootTierGroupOverride();

	UFUNCTION()
	FORTNITEGAME_API virtual void HandleDestroyed();

	UFUNCTION(BlueprintImplementableEvent, Category="EditorPreview", meta=(DisplayName="Can Editor Import With Static Mobility"))
	FORTNITEGAME_API bool K2_CanEditorImportWithStaticMobility(bool& bCanBeImportedWithStaticMobility) const;

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Changed"))
	FORTNITEGAME_API void K2_HandleUserOptionsChanged(const TArray<FName>& ChangedPropertyNames);

	UFUNCTION(BlueprintImplementableEvent, Category="UserOptions", meta=(DisplayName="Handle User Options Loaded"))
	FORTNITEGAME_API void K2_HandleUserOptionsLoaded();

	UFUNCTION(BlueprintImplementableEvent, Category="EditorPreview", meta=(DisplayName="Setup For Editor Preview"))
	FORTNITEGAME_API void K2_SetupForEditorPreview();

	UFUNCTION(BlueprintImplementableEvent, Category="EditorPreview", meta=(DisplayName="Update Editor Preview"))
	FORTNITEGAME_API void K2_UpdateEditorPreview(bool bHasMoved);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_bCollisionBlockedByPawns();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_bDestroyed();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_CurrentBuildingLevel();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_CustomState();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_InitialOverlappingVehicles();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_Team();

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API void RefreshRemovedFoliageAroundBounds(bool bUseNonCollidingBounds = false);

	UFUNCTION()
	FORTNITEGAME_API void RemoveAbilitySystemComponentAfterAutoBuildIfFullHealth();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void Resave();

	UFUNCTION(BlueprintCallable, Category="Health")
	FORTNITEGAME_API void SetHealth(float NewHealth);

	UFUNCTION(BlueprintCallable, Category="Health")
	FORTNITEGAME_API void SetHealth_DontCreateASC(float NewHealth);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetUsesDayPhaseChange(bool bUseDayPhase);

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API virtual void SnapDmgVisualsToCurrentHealth();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void UpdatePropertyForLiveEdit(const FString& PropertyName);

	UPROPERTY(EditInstanceOnly, SaveGame, Category="BuildingActor")
	float SavedHealthPct;

	UPROPERTY(Transient)
	TSubclassOf<UFortBuildingActorSet> BuildingAttributeSetClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBuildingActorSet> BuildingAttributeSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageAttributeSet;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	EBuildingActorComponentCreationPolicy AbilitySystemComponentCreationPolicy;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortHealthBarIndicator> HealthBarIndicator;

	UPROPERTY()
	uint8 LastMetadataRelevant;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleInstanceOnly, Category="Tags")
	FGameplayTagContainer EditorOnlyMapTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleInstanceOnly, Category="Tags")
	FGameplayTagContainer EditorOnlyVolumeTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Tags")
	FGameplayTagContainer EditorOnlyInstanceTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, DuplicateTransient, Category="Tags")
	FGameplayTagContainer EditorOnlyInstanceTagsNoCopy;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Category="Rendering")
	bool bEditorOnlyRenderCustomDepth;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer DefaultTags;
#endif

	UPROPERTY()
	float CullDistance;

	UPROPERTY(Transient, Replicated)
	uint8 bPreviewBuildingActor : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bLockedFromGameEditing : 1;

	UPROPERTY(Transient)
	uint8 bPlayedDying : 1;

	UPROPERTY(Transient)
	uint8 bHasRegisteredActorStateAtLeastOnce : 1;

	UPROPERTY(Transient)
	uint8 bDirtyForLevelRecordSave : 1;

	UPROPERTY(Transient)
	uint8 bSavedMetaPropertiesProcessed : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bUpgradeUsesSameClass : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bDisplayLevelInInfoWidget : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bAllowUpgradeRegardlessOfPlayerBuildLevel : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Navigation")
	uint8 bAlwaysExportNavRelevantComponent : 1;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	uint8 bDisplayDamageNumbersInAthena : 1;

	UPROPERTY(EditDefaultsOnly, Category="HealthBar")
	uint8 bUseFortHealthBarIndicator : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	uint8 bSurpressHealthBar : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	uint8 bCreateVerboseHealthLogs : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	uint8 bIsIndestructibleForTargetSelection : 1;

	UPROPERTY(EditAnywhere, Category="Draw Distance")
	uint8 bPropagateDrawDistanceOnAdditionalComponent : 1;

	UPROPERTY(EditAnywhere, Category="Building Actor|Physics Simulation Support")
	uint8 bCreatePhysicsObjectComponent : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building Actor")
	uint8 bIsGameFrameworkComponentReceiver : 1;

	UPROPERTY(EditDefaultsOnly, Config, Category="Creative")
	uint8 bCanBeSavedInCreativeVolume : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Navigation")
	uint8 bIsNavigationRelevant : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Navigation")
	uint8 bIsNavigationIndestructible : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bBlockNavLinksInCell : 1;

	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bUseHotSpotAsMoveGoalReplacement : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bHasCustomAttackLocation : 1;

	UPROPERTY(Transient)
	uint8 bWorldReadyCalled : 1;

	UPROPERTY(Transient)
	uint8 bBeingTranslated : 1;

	UPROPERTY(Transient)
	uint8 bBeingRotated : 1;

	UPROPERTY(Transient)
	uint8 bBeingScaled : 1;

	UPROPERTY()
	uint8 bRotateInPlaceEditor : 1;

	UPROPERTY(Transient)
	uint8 bEditorPlaced : 1;

	UPROPERTY(Transient)
	uint8 bShouldTick : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	uint8 bUsesDayPhaseChange : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Gameplay")
	uint8 bIsDynamic : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Gameplay")
	uint8 bIsDynamicOnDedicatedServer : 1;

	UPROPERTY(Transient)
	uint8 bIsDedicatedServer : 1;

	UPROPERTY(Transient)
	uint8 bIsTemporarilyTicking : 1;

	UPROPERTY(Transient)
	uint8 bUseTickManager : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Gameplay")
	uint8 bIsMovable : 1;

	UPROPERTY(Transient)
	uint8 bRegisteredForDayPhaseChange : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	uint8 bForceDamagePing : 1;

	UPROPERTY(EditDefaultsOnly, Category="Foliage")
	uint8 bDestroyFoliageWhenPlaced : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bObstructTrapTargeting : 1;

	UPROPERTY(EditDefaultsOnly, Category="Replication")
	uint8 bAlwaysUseNetCullDistanceSquaredForRelevancy : 1;

	UPROPERTY(Transient)
	uint8 bHighlightDirty : 1;

	UPROPERTY(EditAnywhere, Category="Team", meta=(DisplayAfter="Team"))
	uint8 bAllowTeamDamage : 1;

	UPROPERTY(EditDefaultsOnly, Category="Highlight")
	uint8 bIgnoreAffiliationInteractHighlight : 1;

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(DisplayAfter="InteractionText"))
	uint8 bSuppressInteractionWidget : 1;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	uint8 bAutoReleaseCurieContainerOnDestroyed : 1;

	UPROPERTY(EditDefaultsOnly, Category="BuildingActor")
	uint8 bSpawnIntoGridSublevel : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bUseMinLifeSpan : 1;

	UPROPERTY(EditDefaultsOnly, Category="Building Actor|Physics Simulation Support", meta=(Categories="PhysicsObject.ImpactDamageData"))
	uint8 bIgnoreDeterminePhysicsObjectImpactDataAutomatically : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Tags")
	FGameplayTagContainer ConstTags;

	UPROPERTY()
	FGameplayTagContainer StaticGameplayTags;

	UPROPERTY(Transient, Replicated)
	int32 DeviceTrackingGUID;

	UPROPERTY(Transient, Replicated)
	int32 DeviceNameIndex;

	UPROPERTY(EditAnywhere, Category="Draw Distance")
	float BRMinDrawDistance;

	UPROPERTY(EditAnywhere, Category="Draw Distance")
	float BRMaxDrawDistance;

	UPROPERTY(EditAnywhere, Category="Draw Distance")
	float StWMinDrawDistance;

	UPROPERTY(EditAnywhere, Category="Draw Distance")
	float StWMaxDrawDistance;

	UPROPERTY()
	int32 DataVersion;

	UPROPERTY(Transient)
	float LastTakeHitTimeTimeout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	TObjectPtr<USoundBase> PlayHitSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GridSnapping")
	float SnapGridSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GridSnapping")
	float VertSnapGridSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GridSnapping")
	FVector3f SnapOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GridSnapping")
	FVector3f CentroidOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GridSnapping")
	FVector3f BaseLocToPivotOffset;

	UPROPERTY(EditAnywhere, Category="Building")
	TArray<TSubclassOf<UActorComponent>> ComponentTypesWhitelistedForReplication;

	UPROPERTY(VisibleAnywhere, Transient, Category="Building")
	TArray<TSubclassOf<UActorComponent>> RuntimeAddedComponentTypesWhitelistedForReplication;

	UPROPERTY(BlueprintReadWrite, Export, Category="Building Actor", meta=(EditInline="true"))
	TArray<TObjectPtr<UPrimitiveComponent>> OverridePrimitivesToExcludeFoliage;

	UPROPERTY(EditAnywhere, Category="AI")
	TObjectPtr<UBuildingActorHotSpotConfig> HotSpotConfig;

	UPROPERTY(EditDefaultsOnly, Category="Transience")
	TArray<FTransientOverride> TransientOverrides;

	UPROPERTY(Transient)
	TArray<FTransientOverride> GeneratedTransientOverrides;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="CurieIdentification", meta=(Categories="Curie.Element,Curie.Material"))
	FGameplayTag CurieEntityIdentifier;
#endif

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(BlueprintAssignable, Category="Team")
	FOnTeamIndexChangedDelegate OnTeamIndexChangedDelegate;

	UPROPERTY(EditAnywhere, Category="Building Actor|Physics Simulation Support", meta=(Categories="PhysicsObject.Preset"))
	FGameplayTag PhysicsObjectPresetTag;

	UPROPERTY(EditAnywhere, Category="Building Actor|Physics Simulation Support", meta=(Categories="PhysicsObject.PhysData"))
	FGameplayTag PhysicsObjectPhysicalDataTag;

	UPROPERTY(EditAnywhere, Category="Building Actor|Physics Simulation Support", meta=(Categories="PhysicsObject.BuoyancyData"))
	FGameplayTag PhysicsObjectBuoyancyDataTag;

	UPROPERTY(EditAnywhere, Category="Building Actor|Physics Simulation Support", meta=(Categories="PhysicsObject.ImpactDamageData"))
	FGameplayTag PhysicsObjectImpactDamageDataTag;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPhysicsObjectComponent> PhysicsObjectComponent;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FFortAttributeInitializationKey AttributeInitKeys_DEPRECATED[2];
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	EAttributeInitLevelSource AttributeInitLevelSource_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSubclassOf<UNavLinkDefinition> NavigationLinksClass_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int32 MaximumBuildingLevel_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float LifespanAfterDeath_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float HealthBarIndicatorWidth_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float HealthBarIndicatorVerticalOffset_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FName HealthBarIndicatorSocketName_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FText InteractionText_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSubclassOf<UFortInteractContextInfoWidget> InteractionOverrideWidget_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSubclassOf<UFortInteractContextInfoWidget> SecondInteractionOverrideWidget_DEPRECATED;
#endif

private:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_AbilitySystemComponent();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_BuildingAttributeSet();

	UPROPERTY(EditInstanceOnly, SaveGame, Replicated, Category="Persistence")
	int16 OwnerPersistentID;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InitialOverlappingVehicles)
	TArray<TObjectPtr<AFortAthenaVehicle>> InitialOverlappingVehicles;

	UPROPERTY(EditDefaultsOnly, SaveGame, AssetRegistrySearchable, ReplicatedUsing=OnRep_CurrentBuildingLevel, Category="Gameplay")
	int32 CurrentBuildingLevel;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BuildingAttributeSet, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBuildingActorSet> ReplicatedBuildingAttributeSet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AbilitySystemComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> ReplicatedAbilitySystemComponent;

	UPROPERTY(Replicated)
	int32 HealthBarIndicatorDifficultyRating;

	UPROPERTY(Replicated)
	uint8 ForceMetadataRelevant;

	UPROPERTY(EditAnywhere, Category="BuildingBounds")
	TEnumAsByte<EDynamicBuildingPlacementType::Type> DynamicBuildingPlacementType;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="BuildingActor", meta=(AllowPrivateAccess="true"))
	uint8 bIsInvulnerable : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bDestroyed, Category="BuildingActor", meta=(AllowPrivateAccess="true"))
	uint8 bDestroyed : 1;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, SaveGame, Replicated, Category="Gameplay", meta=(AllowPrivateAccess="true"))
	uint8 bPlayerPlaced : 1;

	UPROPERTY(ReplicatedUsing=OnRep_InstantDeath)
	uint8 bInstantDeath : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Building", meta=(AllowPrivateAccess="true"))
	uint8 bDoNotBlockBuildings : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Building", meta=(AllowPrivateAccess="true"))
	uint8 bForceBlockBuildings : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Building", meta=(AllowPrivateAccess="true"))
	uint8 bDestroyOnPlayerBuildingPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Building", meta=(AllowPrivateAccess="true"))
	uint8 bUseCentroidForBlockBuildingsCheck : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bCollisionBlockedByPawns)
	uint8 bCollisionBlockedByPawns : 1;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	uint8 bShouldClearMarkerOnInteract : 1;

	UPROPERTY(EditAnywhere, SaveGame, Category="Team", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EFortTeam::Type> Team;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Team, Category="Team", meta=(AllowPrivateAccess="true"))
	uint8 TeamIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Missions", meta=(AllowPrivateAccess="true", ExposeOnSpawn="true"))
	TObjectPtr<AFortMission> AssociatedMissionParam;

	UPROPERTY(SaveGame, Replicated)
	TObjectPtr<AFortPlacementActor> OriginatingPlacementActor;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBuildingActorEditorComponent> EdRenderComp;
#endif

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_CustomState)
	FString CustomState;

	UPROPERTY(VisibleAnywhere, Category="BuildingActor")
	FGuid SavedActorGuid;

	UPROPERTY(SaveGame, Replicated)
	float BaselineScale;

	UPROPERTY(Transient)
	float AccumulatedDeltaSinceLastVisualsTick;

	UPROPERTY(EditAnywhere, SaveGame, Category="Building Actor")
	FName ActorTemplateID;

	UPROPERTY(EditAnywhere, SaveGame, Category="Building Actor")
	FName PlaysetPackagePathName;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions|Hidden")
	FString LabelOverride;

};

UCLASS(BlueprintType)
class UBuildingTargetingData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	float BuildingTargetingDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InfoDisplay")
	bool bShowHealthWhenFull;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InfoDisplay")
	bool bShowNumbersOnHealthBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InfoDisplay")
	float HideBuildingInfoAfterSeconds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InfoDisplay")
	FVector BuildingInfoWorldOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="InfoDisplay")
	FVector2f HealthBarSizeOverride;

};

