// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Components/SceneCaptureComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/LatentActionManager.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Misc/Timespan.h"
#include "ScalableFloat.h"
#include "Abilities/AttributeInfo.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "Abilities/FortGameplayAbility.h"
#include "Abilities/FortGameplayEffectContainerSpec.h"
#include "Building/BuildingTypes.h"
#include "FortCombatTypes.h"
#include "FortEventName.h"
#include "FortGender.h"
#include "FortItemQuantityPair.h"
#include "FortMovementEnums.h"
#include "FortTeamEnum.h"
#include "FortTypes.h"
#include "Items/FortItemEntry.h"
#include "Items/FortPickupSourceTypeFlag.h"
#include "Items/FortTrapStats.h"
#include "Pawns/FortPawnStats.h"
#include "STW/AI/GameDifficulty/FortGameDifficultyCalculationData.h"
#include "Sound/FortFeedbackManager.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "Weapons/Data/FortWeaponRangedItemDefinition.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortKismetLibrary.generated.h"

class AActor;
class ABuildingActor;
class ABuildingFoundation;
class ABuildingGameplayActor;
class ABuildingSMActor;
class AController;
class AFortAIDirector;
class AFortAIGoalManager;
class AFortAreaOfEffectCloud;
class AFortGameStateAthena;
class AFortMusicManager;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerState;
class AFortProjectileBase;
class AFortTeamInfo;
class AFortThreatVisualsManager;
class AFortTracerBase;
class AFortWorldSettings;
class AInfo;
class ANavigationData;
class APawn;
class APlayerController;
class IAbilitySystemInterface;
class IFortInventoryOwnerInterface;
class IFortTimeOfDayManagerInterface;
class UAbilitySystemComponent;
class UActorComponent;
class UBuildingStructuralSupportSystem;
class UCameraComponent;
class UCameraModifier;
class UControllerComponent;
class UCustomCharacterPart;
class UDataLayerInstance;
class UFXSystemComponent;
class UForceFeedbackEffect;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortGameUserSettings;
class UFortGameplayAbility;
class UFortHeldObjectComponent;
class UFortItem;
class UFortItemDefinition;
class UFortRegisteredPlayerInfo;
class UFortResourceItemDefinition;
class UFortSeasonalEventManager;
class UFortTooltip;
class UFortTooltipContext;
class UFortWeaponItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;
class UGameplayAbility;
class UGameplayEffect;
class UMaterialInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class UPrimitiveComponent;
class USceneCaptureComponent2D;
class USceneComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundBase;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture;
class UTextureRenderTarget2D;
class UWorld;
enum class EAnalyticMatchCounts : uint8;
enum class EAthenaWinCondition : uint8;
enum class EFortDayPhase : uint8;
enum class EFortItemType : uint8;
enum class EFortPickupSourceTypeFlag : uint8;
enum class EFortPickupSpawnSource : uint8;
enum class EFortQuickBars : uint8;
enum class EFortRarity : uint8;
enum class EFortSoundIndicatorTypes : uint8;
enum class EFortWeaponUpgradeDirection : uint8;
enum class ELicensedAudioTreatment : uint8;
enum class ESubGame : uint8;

USTRUCT(BlueprintType)
struct FGiveInventoryItemParams_StateValue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams_StateValue")
	TEnumAsByte<EFortItemEntryState::Type> Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams_StateValue")
	int32 Value;

};

USTRUCT(BlueprintType)
struct FGiveInventoryItemParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams")
	bool bNotifyPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams")
	int32 ItemLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams")
	int32 PickupInstigatorHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams")
	bool bUseItemPickupAnalyticEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GiveInventoryItemParams")
	TArray<FGiveInventoryItemParams_StateValue> StateValues;

};

USTRUCT(BlueprintType)
struct FSpawnItemVariantParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	TObjectPtr<UFortWorldItemDefinition> WorldItemDefinition;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	int32 NumberToSpawn;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	FVector Position;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	FVector Direction;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	int32 OverrideMaxStackCount;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	bool bToss;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	bool bRandomRotation;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	bool bBlockedFromAutoPickup;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	int32 PickupInstigatorHandle;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	EFortPickupSourceTypeFlag SourceType;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	EFortPickupSpawnSource Source;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	TObjectPtr<AFortPlayerController> OptionalOwnerPC;

	UPROPERTY(BlueprintReadWrite, Category="SpawnItemVariantParams")
	bool bPickupOnlyRelevantToOwner;

};

USTRUCT(BlueprintType)
struct FSpawnProjectileParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	FVector SpawnLocation;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	FRotator SpawnRotation;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	FRotator SpawnDirection;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	bool bUseDefaultPhysics;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	TObjectPtr<AActor> HomingTarget;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	float InitialSpeed;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	float MaxSpeed;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	float GravityScale;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	float ChargePercent;

	UPROPERTY(BlueprintReadWrite, Category="SpawnProjectileParams")
	TObjectPtr<UFortWorldItemDefinition> OptionalAssociatedItemDef;

};

UCLASS(Config=Engine, MinimalAPI)
class UFortKismetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void ActivateQuickBarSlot(AFortPlayerPawn* PlayerPawn, EFortQuickBars InQuickBar, int32 Slot, float ActivateDelay = 0.000000f, bool bUpdatePreviousFocusedSlot = true, bool bForceExecution = false);

	UFUNCTION(BlueprintCallable, Category="Helpers", meta=(WorldContext="WorldContextObject"))
	static void AddActorToClear(UObject* WorldContextObject, ABuildingActor* Building);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Camera")
	static UCameraModifier* AddCameraModifierForOwningPlayerController(TSubclassOf<UCameraModifier> InCameraModifierClass, AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Components")
	static UControllerComponent* AddControllerComponent(AController* Controller, TSubclassOf<UControllerComponent> ControllerCompClass);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void AddRegenItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* RegenItemDefinition, int32 NumberToGive = 1, bool bNotifyPlayer = true, bool bResetRegenCooldown = true);

	UFUNCTION(BlueprintCallable, Category="Scoring")
	static void AddScoringEvent(AFortPlayerController* Controller, FGameplayTagContainer TargetTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Cosmetic", meta=(WorldContext="WorldContextObject"))
	static void ApplyCharacterCosmetics(UObject* WorldContextObject, TArray<UCustomCharacterPart*> CharacterParts, AFortPlayerState* PlayerState, bool& bSuccess);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities")
	static void ApplyEventOverrides(const FString& EventSection, bool& bSuccess);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="ApplyGameplayEffectSpecToActorsInRange", WorldContext="WorldContextObject"))
	static void ApplyGameplayEffectSpecToActorsInRange(UObject* WorldContextObject, const FGameplayEffectSpecHandle& EffectSpecToApply, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, const FVector& SourcePosition, const float Range, const TArray<AActor*>& IgnoredActors, const bool bRequireLOS, UAbilitySystemComponent* InstigatorAbilitySystemComp = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="ApplyGameplayEffectsToActor", WorldContext="WorldContextObject"))
	static void ApplyGameplayEffectsToActor(AActor* TargetActor, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, const FVector& SourcePos, const bool bRequireLOS, const int32 EffectLevel, UAbilitySystemComponent* InstigatorAbilitySystemComp = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="ApplyGameplayEffectToActorsInBox", WorldContext="WorldContextObject"))
	static void ApplyGameplayEffectsToActorsInBox(UObject* WorldContextObject, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, const FVector& BoxCenter, const FVector& BoxExtents, const FRotator& BoxOrientation, TArray<AActor*>& IgnoredActors, const bool bRequireLOS, const int32 GameplayEffectLevel, const float DebugLifeTime);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="ApplyGameplayEffectToActorsInRange", WorldContext="WorldContextObject"))
	static void ApplyGameplayEffectToActorsInRange(UObject* WorldContextObject, TArray<TSubclassOf<UGameplayEffect>> EffectsToApply, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, const FVector& SourcePosition, float Range, TArray<AActor*>& IgnoredActors, const bool bRequireLOS, const int32 GameplayEffectLevel, UAbilitySystemComponent* InstigatorAbilitySystemComp = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Environment")
	static void ApplyGlobalEnvironmentDamageToActor(AActor* DamageTargetActor, float EnvironmentDamage, FGameplayTagContainer AdditionalContextTags, TSubclassOf<UGameplayEffect> EnvironmentDamageGE = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Environment", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void ApplyGlobalEnvironmentGameplayEffect(UObject* WorldContextObject, TSubclassOf<UGameplayEffect> GameplayEffect, int32 GameplayEffectLevel, FGameplayTagContainer AdditionalContextTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Environment")
	static FActiveGameplayEffectHandle ApplyGlobalEnvironmentGameplayEffectToActor(AActor* EffectTargetActor, TSubclassOf<UGameplayEffect> GameplayEffect, int32 GameplayEffectLevel, FGameplayTagContainer AdditionalContextTags);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool AreAthenaVehiclesEnabled();

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool AreCampaignVehiclesEnabled();

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities")
	static AFortPlayerState* AttemptGetPlayerStateForPawn(const AFortPlayerPawn* FortPawn);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static TArray<AFortPlayerPawn*> AuthorityGetFortPossessedPlayerPawns(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Collision", meta=(AutoCreateRefTerm="ActorsToIgnore", DisplayName="BoxOverlapActors", WorldContext="WorldContextObject"))
	static bool BoxOverlapActors(const UObject* WorldContextObject, const FTransform& BoxTransform, const FVector& BoxExtent, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors);

	UFUNCTION(BlueprintCallable, Category="Collision", meta=(AutoCreateRefTerm="ActorsToIgnore", DisplayName="BoxOverlapComponents", WorldContext="WorldContextObject"))
	static bool BoxOverlapComponents(const UObject* WorldContextObject, const FTransform& BoxTransform, const FVector& BoxExtent, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, UClass* ComponentClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<UPrimitiveComponent*>& OutComponents);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(WorldContext="WorldContextObject"))
	static void BroadcastAbilityImpactAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* Instigator, const FVector& Position, const float Radius, const FName Tag, const bool bSubtractLocalNoise = false);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(WorldContext="WorldContextObject"))
	static void BroadcastAbilitySpinThrustAtLocation(UObject* WorldContextObject, USoundBase* InSound, UObject* Instigator, const FVector& Position, float Radius, FName Tag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static void BroadcastMessage(UObject* WorldContextObject, const FText& Message);

	UFUNCTION(BlueprintPure, Category="Audio", meta=(WorldContext="WorldContextObject"))
	static bool BroadcastPlayerImpactAtLocation(UObject* WorldContextObject, APlayerController* Player, const FVector& Position, float& Loudness, float& Duration, bool bRelativePosition = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Audio", meta=(PitchMultiplier="1.0", VolumeMultiplier="1.0", WorldContext="WorldContextObject"))
	static void BroadcastSound(UObject* WorldContextObject, USoundBase* InSound, float VolumeMultiplier = 1.000000f, float PitchMultiplier = 1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Audio", meta=(PitchMultiplier="1.0", VolumeMultiplier="1.0", WorldContext="WorldContextObject"))
	static void BroadcastSoundAtLocation(UObject* WorldContextObject, USoundBase* InSound, FVector Location, float VolumeMultiplier = 1.000000f, float PitchMultiplier = 1.000000f);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool CanFollowNextOrPreviousTeammate(const APlayerController* OwningControler);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool CanPerformNativeAction(const UFortAbilitySystemComponent* FortAbilitySystem, const FGameplayTag& NativeActionTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Teams")
	static void ChangeTeam(AActor* PlayerToSwitch, AActor* Instigator, uint8 NewTeam, FGameplayTagContainer ChangeTeamTags);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool CheckHasEnoughResourcesForSmartConsume(int32 ResourceCost, AFortPlayerController* SourcePlayer);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="CheckLineOfSightToActor"))
	static bool CheckLineOfSightToActor(const FVector& SourcePos, const AActor* Target, const AActor* Source = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="CheckLineOfSightToActorWithChannel"))
	static bool CheckLineOfSightToActorWithChannel(const FVector& SourcePos, const AActor* Target, ECollisionChannel TargetFilterChannel, const AActor* Source = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="CheckPlayerLineOfSightToPawn"))
	static bool CheckPlayerLineOfSightToPawn(const AFortPlayerPawn* SourcePawn, const AFortPawn* TargetPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void ClearDroppableItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bAllowShouldDropItemOverride = false);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void ClearTutorialHighlights(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void ClientForceFireSelectedWeapon(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Openable")
	static bool CloseActor(AActor* OpenableInterfaceActor, AController* OptionalControllerInstigator);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="ComputePhysicsAngularVelocity"))
	static FVector ComputePhysicsAngularVelocity(const FVector& Current, const FVector& Target, const FVector& BackupAxis, const float SpeedCoef, const float DeltaTime);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float ConvertToGameTime(UObject* WorldContextObject, float InRealTime);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float ConvertToRealTime(UObject* WorldContextObject, float InGameTime);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void CopyHideElements(const UMaterialInterface* SourceMaterial, UMaterialInstanceDynamic* TargetMID);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void CopyJerseyElements(UMaterialInstanceDynamic* SourceMID, UMaterialInstanceDynamic* TargetMID);

	UFUNCTION(BlueprintPure, Category="Loot")
	static FFortItemEntry CreateItemEntry(const UFortItemDefinition* InItemDefinition, int32 InCount = 1, int32 InLevel = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite | Weapon", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static AFortPickup* CreateTossAmmoPickupForWeaponItemDefinitionAtLocation(UObject* WorldContextObject, const UFortWeaponItemDefinition* WeaponItemDefinition, const FGameplayTagContainer& SourceTags, const FVector& Location, const EFortPickupSourceTypeFlag SourceTypeFlag = EFortPickupSourceTypeFlag::Tossed, const EFortPickupSpawnSource SpawnSource = EFortPickupSpawnSource::Unset);

	UFUNCTION(BlueprintCallable, Category="Helpers", meta=(WorldContext="WorldContextObject"))
	static void CustomHandleActorStreamedInEditor(AActor* SourceActor);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void DeactivateAttachedParticleSystems(const AFortPlayerPawn* PlayerPawn, TArray<UFXSystemComponent*>& FXComponents, bool bOnlyActiveSystems = true);

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(WorldContext="WorldContextObject"))
	static void DebugBoxSendToAll(UObject* WorldContextObject, const FVector& Center, const FVector& Extent, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.000000f, uint8 DepthPriority = 0, float Thickness = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(WorldContext="WorldContextObject"))
	static void DebugCapsuleSendToAll(UObject* WorldContextObject, const FVector& Center, float HalfHeight, float Radius, const FQuat& Rotation, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.000000f, uint8 DepthPriority = 0, float Thickness = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(WorldContext="WorldContextObject"))
	static void DebugLineSendToAll(UObject* WorldContextObject, const FVector& LineStart, const FVector& LineEnd, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.000000f, uint8 DepthPriority = 0, float Thickness = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(WorldContext="WorldContextObject"))
	static void DebugOrientedBoxSendToAll(UObject* WorldContextObject, const FVector& Center, const FVector& Extent, const FRotator& Rotation, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.000000f, uint8 DepthPriority = 0, float Thickness = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Debug", meta=(WorldContext="WorldContextObject"))
	static void DebugSphereSendToAll(UObject* WorldContextObject, const FVector& Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.000000f, uint8 DepthPriority = 0, float Thickness = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void DestroyItemInQuickBarSlot(AFortPlayerPawn* PlayerPawn, const UFortItemDefinition* ItemToDestroyFromInventory, FGuid ItemVariantGuid);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool DeviceSupportsForceFeedback();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void DisableTutorialHighlight(UObject* WorldContextObject, FName WidgetName);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite", meta=(CompactNodeTitle="/", DisplayName="(double)integer64 / (double)integer64", IgnoreTypePromotion, Keywords="/ divide division"))
	static float Divide_Int64Int64UsingFloatingPoint(int64 A, int64 B);

	UFUNCTION(BlueprintPure, Category="Weapon")
	static bool DoesItemConsumeUniqueRangedWeaponAmmo(const UFortItem* Item);

	UFUNCTION(BlueprintPure, Category="Weapon")
	static bool DoesItemDefinitionConsumeUniqueRangedWeaponAmmo(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool DoesItemDefinitionHaveGameplayTag(const UFortItemDefinition* ItemDefinition, const FGameplayTag& Tag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static TArray<AFortPickup*> DropInstancedLoot(AFortPawn* PawnContext, const FName& LootTierGroup, const TArray<AFortPlayerController*>& RelevantPlayers, bool bAllowCombining);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(WorldContext="WorldContextObject"))
	static TArray<AFortPickup*> DropInstancedLootAtLocation(UObject* WorldContextObject, const FName& LootTierGroup, const TArray<AFortPlayerController*>& RelevantPlayers, bool bAllowCombining, FVector DropLocation, EFortPickupSourceTypeFlag SourceTypeFlag = EFortPickupSourceTypeFlag::Tossed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void DropItemByGuid(AController* Controller, const FGuid ItemGuid, const int32 AmountToDrop = -1);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility")
	static void DumpChildrenComponents(const USceneComponent* ParentComponent, const bool bIncludeAllDescendants);

	UFUNCTION(BlueprintCallable, Category="Ability|EffectContext", meta=(DisplayName="AddSourceObject"))
	static void EffectContextAddSourceObject(FGameplayEffectContextHandle EffectContext, UObject* Src);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static bool EmptyQuickBarSlot(UObject* WorldContextObject, EFortQuickBars QuickBarType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void EnableTutorialHighlight(UObject* WorldContextObject, FName WidgetName);

	UFUNCTION(BlueprintPure, Category="Online|UniqueNetIdRepl", meta=(CompactNodeTitle="==", DisplayName="Equal (UniqueIdRepl)", Keywords="== equal"))
	static bool EqualEqual_UniqueNetIdReplUniqueNetIdRepl(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ability")
	static FFortAbilitySetHandle EquipFortAbilitySet(TScriptInterface<IAbilitySystemInterface> AbilitySystemInterfaceActor, UFortAbilitySet* AbilitySet, UObject* OverrideSourceObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static bool EquipItemToQuickBarSlot(UObject* WorldContextObject, const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, EFortQuickBars QuickBarType, int32 SlotIndex);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool EvaluateCurveTableRow(FCurveTableRowHandle CurveTableRowHandle, float InXY, float& OutXY, const FString& ContextString);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="ClientEvent", meta=(BlueprintInternalUseOnly="true", GenericFloat="0", WorldContext="WorldContextObject"))
	static void ExecuteClientEvent(UObject* WorldContextObject, FFortClientEventName EventType, UObject* EventSource, UObject* EventFocus);

	UFUNCTION(BlueprintPure, Category="Skeletal Mesh")
	static USkeletalMesh* ExtractSkeletalMesh(TSubclassOf<AActor> BlueprintClass);

	UFUNCTION(BlueprintPure, Category="Skeletal Mesh")
	static FVector ExtractSkeletalMeshScale(TSubclassOf<AActor> BlueprintClass);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(WorldContext="WorldContextObject"))
	static bool FilterSingleTargetActor(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(WorldContext="WorldContextObject"))
	static bool FilterSingleTargetHitResult(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const FHitResult& HitResult);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(WorldContext="WorldContextObject"))
	static TArray<AActor*> FilterTargetActorList(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const TArray<AActor*>& ActorsToFilter, bool& bAtLeastOneActorLeft);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(WorldContext="WorldContextObject"))
	static TArray<FHitResult> FilterTargetHitResultList(UObject* WorldContextObject, const FFortTargetFilter& Filter, const AActor* RequestingActor, const TArray<FHitResult>& HitResultsToFilter, bool& bAtLeastOneActorLeft);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility", meta=(WorldContext="WorldContextObject"))
	static TArray<AActor*> FindActorsContainingName(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FString& Name);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility", meta=(WorldContext="WorldContextObject"))
	static TArray<UActorComponent*> FindAllComponents(const UObject* WorldContextObject, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility")
	static bool FindFirstTagForParentTagChecked(const AActor* TargetActor, const FGameplayTag& ParentTagToCheck, FGameplayTag& OutChildTag);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static FVector FindGroundLocationAt(UWorld* World, const AActor* IgnoreActor, const FVector& InLocation, float TraceStartZ, float TraceEndZ, FName TraceName);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static FVector FindGroundLocationUsingWorldContextAt(UObject* WorldContextObject, const AActor* IgnoreActor, const FVector& InLocation, float TraceStartZ, float TraceEndZ, FName TraceName);

	UFUNCTION(BlueprintCallable, Category="Components", meta=(DeterminesOutputType="ComponentClass"))
	static UActorComponent* FindOrAddArbitraryComponent(AActor* TargetActor, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static FVector FindStaticGroundLocationAt(UWorld* World, const FVector& InLocation, const AActor* IgnoreActor = nullptr, float TraceStartZ = 20000.000000f, float TraceEndZ = -10000.000000f);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static FVector FindStaticGroundLocationUsingWorldContextAt(UObject* WorldContextObject, const FVector& InLocation, const AActor* IgnoreActor = nullptr, float TraceStartZ = 20000.000000f, float TraceEndZ = -10000.000000f);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static FVector FindStaticGroundLocationWithExtentAt(UWorld* World, const FVector& InLocation, const FQuat& ActorRotation, const FVector& ActorExtent, const AActor* IgnoreActor = nullptr, float TraceStartZ = 10000.000000f, float TraceEndZ = -5000.000000f);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Rendering", meta=(AdvancedDisplay="1", DefaultToSelf="ModifyingObject"))
	static void ForceEnableCustomDepthStencil(bool bForceEnable, UObject* ModifyingObject = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility", meta=(CallableWithoutWorldContext, WorldContext="WorldContextObject"))
	static void FortBlueprintLog(const UObject* WorldContextObject, const FString& InString);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void FortShippingLog(UObject* WorldContextObject, const FString& InString, bool bLogAsWarning);

	UFUNCTION(BlueprintCallable, Category="GUID", meta=(AdvancedDisplay="bOnlyStrings"))
	static FGuid GenerateGuidFromObject(const UObject* InObject, bool bOnlyStrings = false);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static void GetActorCollisionComponentBounds(FVector& OutOrigin, FVector& OutBoxExtent, const AActor* BoundsActor, const bool bIncludeFromChildActors);

	UFUNCTION(BlueprintPure, Category="Team")
	static bool GetActorPvPTeamIndex(const AActor* Actor, uint8& TeamIndex);

	UFUNCTION(BlueprintPure, Category="Team")
	static uint8 GetActorTeam(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Team")
	static AFortTeamInfo* GetActorTeamInfo(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static FBox GetActorVisualComponentBounds(const AActor* BoundsActor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortAIDirector* GetAIDirector(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="AI", meta=(WorldContext="WorldContextObject"))
	static AFortAIGoalManager* GetAIGoalManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetAimedAtEnemy"))
	static AFortPawn* GetAimedAtEnemy(const AFortPlayerController* SourcePlayer, const float RectHalfWidth, const float RectHalfHeight, const float Range, const bool bTargetAIPawns);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Fortnite", meta=(AdvancedDisplay="bIncludeNonSpectators, bIncludeSpectators", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static TArray<AFortPlayerController*> GetAllFortPlayerControllers(const UObject* WorldContextObject, const bool bIncludeNonSpectators = true, const bool bIncludeSpectators = false);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetFortPlayerPawns", WorldContext="WorldContextObject"))
	static void GetAllFortPlayerPawns(const UObject* WorldContextObject, TArray<AFortPlayerPawn*>& OutFortPlayerPawns);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Weapon|Ammo")
	static TArray<FAmmoItemState> GetAmmoItemDefinitionsFromInventoryWeapons(AFortPlayerController* Controller);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetAngleDegrees"))
	static float GetAngleDegrees(const FVector& Source, const FVector& Target);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetBestAimedAtPawnByAngle"))
	static AFortPawn* GetBestAimedAtPawnByAngle(const AFortPlayerPawn* SourcePawn, FVector DestOffsetVec, const float MaxAngleInDegree, const float Range, const bool bTargetAIPawns, EFortTeamAffiliation::Type TeamAffiliationRequirement);

	UFUNCTION(BlueprintPure, Category="Building")
	static float GetBuildingHealthPercentage(const ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintPure, Category="Building", meta=(WorldContext="WorldContextObject"))
	static void GetBuildingStructuralSupportSystem(UObject* WorldContextObject, UBuildingStructuralSupportSystem*& BuildingStructuralSupportSystem);

	UFUNCTION(BlueprintCallable, Category="CalendarEvents", meta=(WorldContext="WorldContextObject"))
	static void GetCalendarEventInformation(UObject* WorldContextObject, const FString& EventName, bool& bIsEventActive, FTimespan& TimeSinceBegin, FTimespan& TimeUntilEnd, float& TimeSpanRatio);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Camera")
	static bool GetCameraComponentAdditiveOffset(FTransform& OutAdditiveTransformOffset, float& OutAdditiveFOVOffset, const UCameraComponent* CameraComponent);

	UFUNCTION(BlueprintCallable, Category="Helpers")
	static bool GetCameraLookHitResult(FHitResult& OutHitResult, const AFortPlayerController* PlayerController, const float CameraForwardTraceDistance = 10000.000000f, const bool bTraceComplex = true);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static AActor* GetClosestActorFromArray(const AActor* Actor, const TArray<AActor*>& ArrayOfActors);

	UFUNCTION(BlueprintPure, Category="Building")
	static ABuildingSMActor* GetClosestBuildingActorFromArray(const AActor* Actor, const TArray<ABuildingSMActor*>& ArrayOfBuildings);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortPlayerPawn* GetClosestFortPlayerPawn(const UObject* WorldContextObject, const FVector& Position);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortPlayerPawn* GetClosestFortPlayerPawnByTeamAffiliation(const UObject* WorldContextObject, const FVector& Position, const AActor* TeamAffiliationActor = nullptr, const EFortTeamAffiliation::Type TeamAffiliation = EFortTeamAffiliation::Hostile);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static TScriptInterface<IFortTimeOfDayManagerInterface> GetContextualTimeOfDayManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static AController* GetControllerFromActor(AActor* Actor);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="PlayerInfo")
	static void GetControllerObjectiveStatSourceTags(const AController* Controller, FGameplayTagContainer& OutTags, bool bIsInitiator = false);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="PlayerInfo")
	static void GetControllerSpecialStatSourceTags(const AController* Controller, FGameplayTagContainer& InOutTags, const AController* InitiatorPC, bool bNeedToFetchClassTags, bool bInitiatorHadFriendHelp = false);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static EAthenaWinCondition GetCurrentAthenaWinCondition(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static EFortDayPhase GetCurrentDayPhase(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="SafeZone", meta=(WorldContext="WorldContextObject"))
	static int32 GetCurrentSafeZonePhase(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="PlayerInfo")
	static FString GetDebugStringForUniqueId(const FUniqueNetIdRepl& UniqueID);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float GetDefaultAbsoluteTimeOfDaySpeed(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TargetSelection")
	static FRotator GetDirectionActorToActor(AActor* SourceActor, AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static FVector GetEffectDirection(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure, Category="Fortnite | Factions")
	static FGameplayTagContainer GetFactionTagContainerForActor(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(AdvancedDisplay="1", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static AFortPlayerController* GetFirstLocalFortPlayerController(const UObject* WorldContextObject, bool bIncludeNonSpectators = true, bool bIncludeSpectators = false);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float GetFloatHoursUntilDayPhase(UObject* WorldContextObject, EFortDayPhase DayPhase);

	UFUNCTION(BlueprintPure, Category="Settings")
	static UFortGameUserSettings* GetFortGameUserSettings();

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetFortPawnsInRange", WorldContext="WorldContextObject"))
	static void GetFortPawnsInRange(UObject* WorldContextObject, const FVector& SourcePosition, const float Range, const bool bDo2DCheck, TArray<AFortPawn*>& OutFortPawns);

	UFUNCTION(BlueprintPure, Category="Collision")
	static EPhysicalSurface GetFortPhysicalSurface(const FHitResult& Hit);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static AFortPlayerController* GetFortPlayerControllerFromActor(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DeprecatedFunction, WorldContext="WorldContextObject"))
	static TArray<AFortPlayerPawn*> GetFortPlayerPawns(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetFortPlayerPawnsInRange", WorldContext="WorldContextObject"))
	static void GetFortPlayerPawnsInRange(UObject* WorldContextObject, const FVector& SourcePosition, const float Range, const bool bDo2DCheck, TArray<AFortPlayerPawn*>& OutFortPlayerPawns);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortWorldSettings* GetFortWorldSettingsInEditor(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="GameContext", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetGameContextGameplayTags(UObject* WorldContextObject, FGameplayTagContainer& OutGameContextGameplayTags);

	UFUNCTION(BlueprintPure, Category="Fortnite | Athena | Game State", meta=(WorldContext="WorldContextObject"))
	static AFortGameStateAthena* GetGameStateAthena(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite | Athena | Game State")
	static AFortGameStateAthena* GetGameStateAthenaFromContext(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite | Utility", meta=(DefaultToSelf="Actor"))
	static void GetGenericDamageSurfaceTypeTag(const AActor* Actor, FGameplayTag& OutSurfaceTypeTag);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static TScriptInterface<IFortTimeOfDayManagerInterface> GetGlobalTimeOfDayManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Held Objects")
	static AActor* GetHeldObjectAttachedToPlayer(const AFortPlayerPawn* FortPawn);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Held Objects")
	static UFortHeldObjectComponent* GetHeldObjectComponentAttachedToPlayer(const AFortPlayerPawn* FortPawn);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Held Objects")
	static AFortPlayerPawn* GetHeldObjectsOwningPlayer(const AActor* HeldObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static float GetHostilityPercentage(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static int32 GetHoursUntilDayPhase(UObject* WorldContextObject, EFortDayPhase DayPhase);

	UFUNCTION(BlueprintPure, Category="Misc")
	static FString GetHumanReadableName(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static void GetImpulseData(FGameplayEffectContextHandle EffectContext, FVector& ImpulseDirection, float& KnockbackMagnitude, float& KnockbackZAngle);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	static const UFortItem* GetInventoryItemWithGuid(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FGuid ItemGuid);

	UFUNCTION(BlueprintPure, Category="Broadcast", meta=(WorldContext="WorldContextObject"))
	static bool GetIsBroadcastClient(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Replay", meta=(WorldContext="WorldContextObject"))
	static bool GetIsPlayingReplay(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static UFortItemDefinition* GetItemDefinitionFromItemQuantityPair(const FFortItemQuantityPair& ItemQuantityPair);

	UFUNCTION(BlueprintPure, Category="Inventory")
	static int32 GetItemQuantityOnInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortItemDefinition* ItemDefinition, const FGuid ItemVariantGuid);

	UFUNCTION(BlueprintPure, Category="Inventory")
	static int32 GetItemQuantityOnPlayerByGUID(AFortPlayerController* PlayerController, const FGuid& ItemGuid);

	UFUNCTION(BlueprintPure, Category="Editor", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static bool GetLevelViewportCameraInfo(UObject* WorldContextObject, FVector& CameraLocation, FRotator& CameraRotation);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Audio", meta=(WorldContext="WorldContextObject"))
	static ELicensedAudioTreatment GetLicensedAudioTreatment(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(AdvancedDisplay="1", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static TArray<AFortPlayerController*> GetLocalFortPlayerControllers(const UObject* WorldContextObject, const bool bIncludeNonSpectators = true, const bool bIncludeSpectators = false);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Loot", meta=(WorldContext="WorldContextObject"))
	static int32 GetLootLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Matchmaking")
	static void GetMatchmakingDifficultyRangeFromDifficultyInfo(const FGameDifficultyInfo& DifficultyInfo, float& OutMinDifficulty, float& OutMaxDifficulty);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static float GetMatchTime(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetMeleeWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortMeleeWeaponStats& OutRow);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="Get Dynamic Material Instance"))
	static UMaterialInstanceDynamic* GetMIDForSkeletalMeshComponent(USkeletalMeshComponent* SkeletalMeshComponent, int32 ElementIndex);

	UFUNCTION(BlueprintPure, Category="Music", meta=(WorldContext="WorldContextObject"))
	static AFortMusicManager* GetMusicManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite | AI", meta=(WorldContext="WorldContext"))
	static ANavigationData* GetNavigationDataForActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities", meta=(DeterminesOutputType="ActorClass", DynamicOutputParam="OutActors", WorldContext="WorldContextObject"))
	static int32 GetNumActorsOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetNumberOfRegisteredPlayers", WorldContext="WorldContextObject"))
	static int32 GetNumberOfRegisteredPlayers(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool GetNumericCVar(const FString& CVar, float& OutValue);

	UFUNCTION(BlueprintPure, Category="Fortnite | Water Helpers", meta=(WorldContext="WorldContextObject"))
	static float GetOceanTotalHeight(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetPawnStatsRow(FDataTableRowHandle DataTableRowHandle, FFortPawnStats& OutRow);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static int64 GetPhysicalMemoryMB();

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetPlayerAimPoint"))
	static FVector GetPlayerAimPoint(const AFortPlayerController* SourcePlayer, const float MaxRange, const TArray<AActor*>& IgnoredActors, const bool NoTrace = false);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="GetPlayerAimPointHit"))
	static FHitResult GetPlayerAimPointHit(const AFortPlayerController* SourcePlayer, const float MaxRange, const TArray<AActor*>& IgnoredActors);

	UFUNCTION(BlueprintCallable, Category="PlayerInfo", meta=(WorldContext="WorldContextObject"))
	static UFortRegisteredPlayerInfo* GetPlayerInfoFromUniqueID(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static FString GetPlayerNameSafe(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static FString GetPlayerOrObjectNameSafe(const AActor* InActor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static bool GetPlaylistAllowsTeamSwitching(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static bool GetPlaylistUsesCustomCharacterParts(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static EFortDayPhase GetPreviousDayPhase(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static UGameplayAbility* GetPrimaryAbilityInstanceOfAbilitySystemComponent(UFortAbilitySystemComponent* AbilitySystemComponent, TSubclassOf<UFortGameplayAbility> AbilityClass);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static UGameplayAbility* GetPrimaryInstance(const FGameplayAbilitySpec& Spec);

	UFUNCTION(BlueprintCallable)
	static void GetProjectileTrajectoryData(FFortProjectileTrajectoryData& TrajectoryData, const AActor* Instigator, const TSubclassOf<AActor> ProjectileClass, const float DefaultSpeed, const float DefaultGravityScale = 0.800000f);

	UFUNCTION(BlueprintCallable, Category="Survivors", meta=(WorldContext="WorldContextObject"))
	static FText GetRandomSurvivorName(UObject* WorldContextObject, EFortDisplayGender::Type Gender, bool bRemoveFromList = true);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite")
	static int32 GetRandomWeightedIndex(const TArray<float>& InWeights);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetRangedWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortRangedWeaponStats& OutRow);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static float GetRealMatchTime(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Inventory")
	static int32 GetResourceMaxStackSize(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType);

	UFUNCTION(BlueprintCallable, Category="SafeZone", meta=(WorldContext="WorldContextObject"))
	static bool GetSafeZoneLocation(UObject* WorldContextObject, int32 SafeZoneIndex, FVector& OutLocation);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static UFortSeasonalEventManager* GetSeasonalEventManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite|Sync|Time", meta=(WorldContext="WorldContextObject"))
	static float GetServerWorldRealTimeSeconds(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite|Sync|Time", meta=(WorldContext="WorldContextObject"))
	static float GetServerWorldTimeSeconds(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static bool GetShowTeamSelectButton(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Asset")
	static FString GetSoftPtrAssetName(const TSoftObjectPtr<UObject> Asset);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static FDataTableRowHandle GetSpecialActorInputActionDataTableRow(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static void GetStaticMeshComponentsForClass(const TSubclassOf<AActor> Class, TArray<UStaticMeshComponent*>& OutStaticMeshComponents);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static void GetStaticMeshesForClass(const TSubclassOf<AActor> Class, TArray<UStaticMesh*>& OutStaticMeshes);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static float GetStunTime(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static ESubGame GetSubGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Team")
	static EFortTeamAffiliation::Type GetTeamAffiliation(const AActor* ActorA, const AActor* ActorB);

	UFUNCTION(BlueprintPure, Category="Team")
	static EFortTeamAffiliation::Type GetTeamAffiliationBetweenTeams(uint8 TeamA, uint8 TeamB);

	UFUNCTION(BlueprintPure, Category="Team", meta=(WorldContext="WorldContextObject"))
	static EFortTeamAffiliation::Type GetTeamAffiliationForActorToLocalPlayer(const AActor* Actor, bool bIncludeNonSpectators = true, bool bIncludeSpectators = false);

	UFUNCTION(BlueprintPure, Category="Team", meta=(WorldContext="WorldContextObject"))
	static EFortTeamAffiliation::Type GetTeamAffiliationToLocalPlayer(UObject* WorldContextObject, uint8 Team, bool bIncludeNonSpectators = true, bool bIncludeSpectators = false);

	UFUNCTION(BlueprintPure, Category="Team", meta=(WorldContext="WorldContextObject"))
	static AFortTeamInfo* GetTeamInfo(UObject* WorldContextObject, uint8 Team);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static AFortThreatVisualsManager* GetThreatVisualsManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float GetTimeDayPhaseBegins(UObject* WorldContextObject, EFortDayPhase DayPhase);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float GetTimeOfDay(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static float GetTimeOfDaySpeed(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="TimeOfDay", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static float GetTimeUntilInRealTimeSeconds(UObject* WorldContextObject, float GameTime);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipDescription(UObject* WorldContextObject, const UObject* ObjectToDescribe, FGameplayTag Tag, const UFortTooltipContext* Context, TArray<FText>& Description, bool bSummaryTooltip = false);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipDescriptionFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, FGameplayTag Tag, const UFortTooltipContext* Context, TArray<FText>& Description, bool bSummaryTooltip = false);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipNumericValue(UObject* WorldContextObject, const UObject* ObjectToDescribe, FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, float& Value);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipNumericValueFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, float& Value);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipTextFromToken(UObject* WorldContextObject, const UObject* ObjectToDescribe, const FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, FText& OutText);

	UFUNCTION(BlueprintPure, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static bool GetTooltipTextFromTokenFromTooltipClass(UObject* WorldContextObject, const UObject* ObjectToDescribe, TSubclassOf<UFortTooltip> TooltipClass, const FGameplayTag Tag, const UFortTooltipContext* Context, const FGameplayTag Token, FText& OutText);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetTrapStatsRow(FDataTableRowHandle DataTableRowHandle, FFortTrapStats& OutRow);

	UFUNCTION(BlueprintPure, Category="Ability|EffeactContext")
	static float GetUnmodifiedDamage(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure, Category="Weapon")
	static UFortWeaponItemDefinition* GetUpgradedWeaponItemFromTable(UFortWeaponItemDefinition* ItemToUpgrade, EFortWeaponUpgradeDirection UpgradeDirection);

	UFUNCTION(BlueprintPure, Category="Weapon")
	static UFortWeaponItemDefinition* GetUpgradedWeaponItemVerticalToRarity(const UFortWeaponItemDefinition* ItemToUpgrade, EFortRarity NewRarity);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetWeaponDurabilityByRarityStatsRow(FDataTableRowHandle DataTableRowHandle, FFortWeaponDurabilityByRarityStats& OutRow);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetWeaponStatsRow(FDataTableRowHandle DataTableRowHandle, FFortBaseWeaponStats& OutRow);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static const UFortWorldItem* GiveItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive = 1, bool bNotifyPlayer = true, int32 ItemLevel = -1, int32 PickupInstigatorHandle = -1, bool bUseItemPickupAnalyticEvent = false, int32 WeaponAmmoOverride = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static const UFortWorldItem* GiveItemToInventoryOwnerWithParams(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive, const FGiveInventoryItemParams& Params);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	static bool HasMultipleVisibleRewards(const FFortRewardInfo& RewardInfo);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	static bool HasRewards(const FFortRewardInfo& RewardInfo);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	static bool HasSelectableRewards(const FFortRewardInfo& RewardInfo);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void HideTutorialWidget(UObject* WorldContextObject, FName WidgetName);

	UFUNCTION(BlueprintCallable, Category="Analytics", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static int32 IncrementAnalyticMatchCount(const UObject* WorldContextObject, const EAnalyticMatchCounts MatchCountID, const int32 AmountToAdd = 1);

	UFUNCTION(BlueprintPure, Category="Editor", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static bool InEditor(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Editor", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static bool InEditorOrPIE(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite | DataLayer", meta=(WorldContext="WorldContext"))
	static bool IsActorInDataLayerInstance(const AActor* Actor, const UDataLayerInstance* DataLayerInstance);

	UFUNCTION(BlueprintPure, Category="Fortnite | Water Helpers")
	static bool IsActorSubmergedInOcean(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Fortnite|POI", meta=(WorldContext="WorldContextObject"))
	static bool IsActorWithinGoldenPOI(const UObject* WorldContextObject, const AActor* InActor);

	UFUNCTION(BlueprintPure, Category="Asset")
	static bool IsAssetNull(TSoftObjectPtr<UObject> Asset);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Visibility", meta=(WorldContext="WorldContextObject"))
	static bool IsBoundsInAnyView(const UObject* WorldContextObject, const FBoxSphereBounds& Bounds, const FVector& Location, float BoundsScalar = 1.000000f);

	UFUNCTION(BlueprintCallable, Category="Helpers", meta=(WorldContext="WorldContextObject"))
	static bool IsBoxOverlappingKillVolume(UObject* WorldContextObject, const FVector& Location, const FVector& BoxExtent);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsCellConnection();

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsCompetitivePlaylist(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsConsolePlatform();

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Reactive|Frontend", meta=(DefaultToSelf="CosmeticObject", Keywords="menu frontend cosmetic is shown"))
	static bool IsCosmeticObjectDisplayedAsPreview(const UObject* CosmeticObject);

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Reactive|Frontend", meta=(DefaultToSelf="CosmeticObject", Keywords="menu frontend cosmetic is shown"))
	static bool IsCosmeticObjectDisplayedInFrontendContext(const UObject* CosmeticObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsCreativeOrPlaygroundModePlaylist(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsCreativeRoyalePlaylist(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static bool IsCriticalHit(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsCurveTableRowValid(const FCurveTableRowHandle& CurveTableRowHandle, const FString& ContextString);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static bool IsDiceCritical(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility")
	static bool IsEnvQueryResultValid(const FEnvQueryResult Result, FString& OutDebugString);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static bool IsFatalHit(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintPure, Category="Ability|EffectContext")
	static bool IsFullBodyHit(FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Held Objects")
	static bool IsHeldObjectBeingHeld(const AActor* HeldObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool IsItemDefinitionAnAbilityOrVehcileWeapon(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category="Inventory", meta=(DisplayName="Is Item Random Customization Selector"))
	static bool IsItemDefRandomCustomizationSelector(const UFortItemDefinition* InItemDef);

	UFUNCTION(BlueprintCallable, Category="SafeZone", meta=(WorldContext="WorldContextObject"))
	static bool IsLocationInSafeZone(UObject* WorldContextObject, const FVector& Location);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static bool IsMobileGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsMobilePlatform();

	UFUNCTION(BlueprintPure, Category="Fortnite | AI", meta=(WorldContext="WorldContext"))
	static bool IsNavigationDataBuildInProgress(ANavigationData* NavigationData);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsPapayaPlaylist(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsPhoneGame();

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsRunningNoMCP();

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsSpatialGameplayExperience(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsTabletGame();

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsUsingBattlEye();

	UFUNCTION(BlueprintCallable, Category="Attribute")
	static bool IsValid(const FAttributeInfo& AttributeInfo);

	UFUNCTION(BlueprintPure, Category="Online|UniqueNetIdRepl", meta=(CompactNodeTitle="isValid?", DisplayName="Is Valid (UniqueIdRepl)"))
	static bool IsValid_UniqueNetIdRepl(const FUniqueNetIdRepl& InUniqueNetIdRepl);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsVkEditPlaylist(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsXPSystemEnabled(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static bool IsXPSystemEnabledForWorld(const UWorld* World);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static TArray<UObject*> JonLHack_GetAllObjectsOfClassFromPath(const FString& Path, UClass* Class, bool bIncludeClassObjects = false);

	UFUNCTION(BlueprintCallable, Category="Building")
	void K2_CycleBuildingMaterial(AFortPlayerController* Controller, bool bBroadcast, bool bDoUIFeedback, bool bHonorAutoSwitch = true);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="DoesInventoryOwnerHaveItems"))
	static bool K2_DoesInventoryOwnerHaveItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const TArray<EFortItemType>& ExcludedItemTypes);

	UFUNCTION(BlueprintPure, Category="World", meta=(DisplayName="GetClosestAxisXY"))
	static FVector K2_GetClosestAxisXY(FVector InVector);

	UFUNCTION(BlueprintCallable, Category="Building")
	static EFortResourceType::Type K2_GetCurrentResourceType(AFortPlayerController* Controller);

	UFUNCTION(BlueprintPure, Category="Inventory", meta=(DisplayName="GetInventorySpace"))
	static int32 K2_GetInventorySpace(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner);

	UFUNCTION(BlueprintPure, Category="Inventory", meta=(DisplayName="Get Item Quantity On Player"))
	static int32 K2_GetItemQuantityOnPlayer(AFortPlayerController* PlayerController, UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid);

	UFUNCTION(BlueprintCallable, Category="Building")
	static int32 K2_GetNumAvailableBuildingResources(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="GetOverflowCountIfItemWasAddedToInventory"))
	static int32 K2_GetOverflowCountIfItemWasAddedToInventory(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable, Category="Building")
	static UFortResourceItemDefinition* K2_GetResourceItemDefinition(const EFortResourceType::Type ResourceType);

	UFUNCTION(BlueprintCallable, Category="Building")
	static void K2_GiveBuildingResource(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="GiveItemToAllPlayers", WorldContext="WorldContextObject"))
	static void K2_GiveItemToAllPlayers(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive = 1, bool bNotifyPlayer = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DeprecatedFunction, DeprecationMessage="Use GiveItemToInventoryOwner instead.", DisplayName="GiveItemToPlayer"))
	static void K2_GiveItemToPlayer(AFortPlayerController* PlayerController, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 NumberToGive = 1, bool bNotifyPlayer = true);

	UFUNCTION(BlueprintCallable, Category="Building")
	static bool K2_HasBuildingResourcesAvailable(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount);

	UFUNCTION(BlueprintCallable, Category="Building")
	static int32 K2_PayBuildingResourceCost(AFortPlayerController* Controller, const EFortResourceType::Type ResourceType, const int32 ResourceAmount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveFortItemFromPlayer"))
	static int32 K2_RemoveFortItemFromPlayer(AFortPlayerController* PlayerController, UFortItem* Item, int32 AmountToRemove = -1, bool bForceRemoval = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveItemFromAllPlayers", WorldContext="WorldContextObject"))
	static void K2_RemoveItemFromAllPlayers(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 AmountToRemove = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveItemFromPlayer"))
	static int32 K2_RemoveItemFromPlayer(AFortPlayerController* PlayerController, UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, int32 AmountToRemove = -1, bool bForceRemoval = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveItemFromPlayerByGuid"))
	static int32 K2_RemoveItemFromPlayerByGuid(AFortPlayerController* PlayerController, FGuid ItemGuid, int32 AmountToRemove = -1, bool bForceRemoval = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveItemsFromPlayerByIntStateValue"))
	static int32 K2_RemoveItemsFromPlayerByIntStateValue(AFortPlayerController* PlayerController, EFortItemEntryState::Type StateType, int32 StateValue, bool bForceRemoval = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="RemoveItemsFromPlayerByNameStateValue"))
	static int32 K2_RemoveItemsFromPlayerByNameStateValue(AFortPlayerController* PlayerController, EFortItemEntryState::Type StateType, FName StateValue, bool bForceRemoval = false);

	UFUNCTION(BlueprintCallable, Category="Building")
	void K2_SetCurrentResourceType(AFortPlayerController* Controller, EFortResourceType::Type NewMaterial);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorld", WorldContext="WorldContextObject"))
	static AFortPickup* K2_SpawnPickupInWorld(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, int32 PickupInstigatorHandle = -1, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorldWithClass", WorldContext="WorldContextObject"))
	static AFortPickup* K2_SpawnPickupInWorldWithClass(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, TSubclassOf<AFortPickup> PickupClass, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, int32 PickupInstigatorHandle = -1, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorldWithClassAndItemEntry", WorldContext="WorldContextObject"))
	static AFortPickup* K2_SpawnPickupInWorldWithClassAndItemEntry(UObject* WorldContextObject, const FFortItemEntry& ItemEntry, TSubclassOf<AFortPickup> PickupClass, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorldWithClassWithLevel", WorldContext="WorldContextObject"))
	static AFortPickup* K2_SpawnPickupInWorldWithClassAndLevel(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 WorldLevel, TSubclassOf<AFortPickup> PickupClass, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, int32 PickupInstigatorHandle = -1, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorldWithLevel", WorldContext="WorldContextObject"))
	static AFortPickup* K2_SpawnPickupInWorldWithLevel(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 WorldLevel, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false, int32 PickupInstigatorHandle = -1, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, AFortPlayerController* OptionalOwnerPC = nullptr, bool bPickupOnlyRelevantToOwner = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnPickupInWorldWithLootTier", WorldContext="WorldContextObject", CPP_Default_OptionalASCInterface="None", CPP_Default_bToss="true", CPP_Default_bTossWithVelocity="false", CPP_Default_TossVelocity))
	static TArray<AFortPickup*> K2_SpawnPickupInWorldWithLootTier(UObject* WorldContextObject, FName LootTierName, FVector Position, int32 OverrideMaxStackCount, AActor* OptionalASCInterface, bool bToss, bool bTossWithVelocity, FVector TossVelocity, EFortPickupSourceTypeFlag SourceType = EFortPickupSourceTypeFlag::Tossed, EFortPickupSpawnSource Source = EFortPickupSpawnSource::Unset, int32 LootWorldLevel = 0);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void KeepCGPathOptimizations(const AController* RequestedBy, int64 ExpectedBudget, float Duration = -1.000000f);

	UFUNCTION(BlueprintCallable, Category="Feedback", meta=(AdvancedDisplay="3", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
	static void MakeAllPlayersTalkToSelf(UObject* WorldContextObject, FLatentActionInfo LatentInfo, USoundBase* Audio, float Delay = 0.000000f, bool bInterruptCurrentLine = true, bool bCanBeInterrupted = false, bool bCanCue = true, EFortFeedbackBroadcastFilter BroadcastFilter = FFBF_Speaker, bool bLatent = true);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static EFortBuildingState::Type MakeBuildingState(EFortBuildingState::Type Value);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static EFortDayPhase MakeDayNightPhase(EFortDayPhase Value);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static FFortGameplayEffectContainerSpec MakeGameplayEffectContainerSpecFromAbility(const FFortGameplayEffectContainer& EffectContainer, UGameplayAbility* Ability, int32 GameplayEffectLevel = 1);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static FFortGameplayEffectContainerSpec MakeGameplayEffectContainerSpecFromAbilityComponent(const FFortGameplayEffectContainer& EffectContainer, UAbilitySystemComponent* AbilityComp, int32 GameplayEffectLevel = 1);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static EFortMovementStyle::Type MakeMovementStyle(EFortMovementStyle::Type Value);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static EFortResourceType::Type MakeResourceType(EFortResourceType::Type Value);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static EFortWeaponCoreAnimation::Type MakeWeaponCoreAnimation(EFortWeaponCoreAnimation::Type Value);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static FVector NormalizedAngleInDegreesToVector(float A);

	UFUNCTION(BlueprintPure, Category="Online|UniqueNetIdRepl", meta=(CompactNodeTitle="!=", DisplayName="Not Equal (UniqueIdRepl)", Keywords="!= not equal"))
	static bool NotEqual_UniqueNetIdReplUniqueNetIdRepl(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Inventory")
	static void NotifyProjectileThrown(TSubclassOf<AFortProjectileBase> ProjClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, float Speed);

	UFUNCTION(BlueprintPure, Category="Squad")
	static bool OnSameSquad(const AFortPlayerPawnAthena* PlayerPawnA, const AFortPlayerPawnAthena* PlayerPawnB);

	UFUNCTION(BlueprintPure, Category="Team")
	static bool OnSameTeam(const AActor* ActorA, const AActor* ActorB);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Openable")
	static bool OpenActor(AActor* OpenableInterfaceActor, AController* OptionalControllerInstigator, bool bRequestFastOpen = false);

	UFUNCTION(BlueprintPure, Category="Math|Color|Fortnite", meta=(DisplayName="Pack HSV to Float", Keyword="/ Pack HSV Float"))
	static float PackHSVToFloat(float Hue, float Saturation, float Value);

	UFUNCTION(BlueprintPure, Category="Math|Color|Fortnite", meta=(DisplayName="Pack Linear Color HSV to Float", Keyword="/ Pack Linear Color HSV Float"))
	static float PackLinearColorHSVToFloat(const FLinearColor& LinearColor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Loot", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool PickLootDrops(UObject* WorldContextObject, TArray<FFortItemEntry>& OutLootToDrop, const FName TierGroupName, const int32 WorldLevel, const int32 ForcedLootTier = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Loot", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool PickLootDropsWithNamedWeights(UObject* WorldContextObject, TArray<FFortItemEntry>& OutLootToDrop, const FName TierGroupName, const int32 WorldLevel, const TMap<FName, float>& NamedWeightsMap, const int32 ForcedLootTier = -1);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static void PlayLocalForceFeedbackAtLocation(UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FVector Location, float Radius, FName Tag);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Fortnite", meta=(WorldContext="WorldContextObject"))
	static void PlayLocalForceFeedbackAtLocationMulti(UObject* WorldContextObject, UForceFeedbackEffect* NearForceFeedbackEffect, UForceFeedbackEffect* FarForceFeedbackEffect, FVector Location, float InnerRadius, float OuterRadius, FName Tag);

	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly))
	static void ProfilerBookmark(const FString& BookmarkStr);

	UFUNCTION(BlueprintCallable, Category="TargetSelection")
	static FVector PushOffHitLocation(AActor* RequestedBy, const FHitResult& Hit, float Distance);

	UFUNCTION(BlueprintCallable, Category="TargetSelection")
	static FTransform PushOffTransformByHitLocation(AActor* RequestedBy, const FTransform& InTransform, const FHitResult& Hit, float Distance);

	UFUNCTION(BlueprintCallable, Category="Helpers", meta=(WorldContext="WorldContextObject"))
	static bool RandomGroundLocationInCircle(UObject* WorldContextObject, const FVector& CircleCenter, float CircleRadius, const AActor* TraceIgnoreActor, float TraceStartZ, float TraceEndZ, float TraceRadius, FCollisionProfileName TraceProfile, FVector& OutLocation);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite")
	static FVector2D RandPointInDonut(const float& InnerCircleRadius, const float& OuterCircleRadius);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite")
	static FVector2D RandUniformPointInDonut(const float& InnerCircleRadius, const float& OuterCircleRadius);

	UFUNCTION(BlueprintCallable, Category="Rendering", meta=(Keywords="ReadRenderTargetToBoolArray", WorldContext="WorldContextObject"))
	static bool ReadRenderTargetToBoolArray(UObject* WorldContextObject, UTextureRenderTarget2D* TextureRenderTarget, float Threshold, TArray<bool>& OutBoolArray, bool bDebugPrintToLog = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void ReduceDroppableResources(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const float ReductionPercentage);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities")
	static void RegisterComponent(UActorComponent* InComponent);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	static void RegisterDayPhaseHitCallback(UObject* Object, const FString& FunctionName, EFortDayPhase Phase, bool bRecurring = false, bool bBlockTriggeringThisCycle = false);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay")
	static void RegisterDayTimeHitCallback(UObject* Object, const FString& FunctionName, float TimeInHours, bool bRecurring = false, bool bBlockTriggeringThisCycle = false);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void RegisterGridFoundation(ABuildingFoundation* BuildingFoundation);

	UFUNCTION(BlueprintPure, Category="Building")
	static void RemoveActorsOfClassFromBuildingSMActorArray(const TArray<ABuildingSMActor*>& ArrayToRemoveClassFrom, TSubclassOf<ABuildingSMActor> ClassToRemove, TArray<ABuildingSMActor*>& ArrayWithClassRemoved);

	UFUNCTION(BlueprintCallable, Category="Components")
	static void RemoveArbitraryComponent(AActor* TargetActor, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintCallable, Category="Components")
	static void RemoveControllerComponent(AController* Controller, TSubclassOf<UControllerComponent> ControllerCompClass);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities")
	static void RemoveEventOverrides(const FString& EventSection, bool& bSuccess);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Environment", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void RemoveGlobalEnvironmentGameplayEffect(UObject* WorldContextObject, TSubclassOf<UGameplayEffect> GameplayEffect);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void RemoveItemFromInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory")
	static void RemoveNonResourceDroppableItems(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static FFortGameplayEffectContainer ReplaceHalfExtentsInGameplayEffectContainer(FFortGameplayEffectContainer EffectContainer, const FVector& NewHalfExtents);

	UFUNCTION(BlueprintCallable, Category="Ability")
	static FFortGameplayEffectContainer ReplaceRangeInGameplayEffectContainer(FFortGameplayEffectContainer EffectContainer, const FScalableFloat& NewRange);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities")
	static AFortPlayerState* ResolvePlayerStateFromContextualObjects(TArray<UObject*> Objects);

	UFUNCTION(BlueprintCallable, Category="Fortnite", meta=(DisplayName="RotateVectorTowardVector"))
	static FVector RotateVectorTowardVector(const FVector& Source, const FVector& Target, const float Degrees);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite")
	static FRotator RotatorLerpWithAxisSpeeds(const FRotator& A, const FRotator& B, const FRotator& AxisSpeeds, const float DeltaSeconds);

	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly))
	static void ScriptEnsureIsValid(const FString& Message, UObject* Object);

	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly))
	static void ScriptError(const FString& Message);

	UFUNCTION(BlueprintPure, Category="Selection")
	static UMaterialInstance* SelectMaterialInstance(UMaterialInstance* A, UMaterialInstance* B, bool bSelectA);

	UFUNCTION(BlueprintCallable, Category="Collision", meta=(DefaultToSelf="Target"))
	static void SetActorEnableCollision_WithChildren(AActor* Target, const bool bEnable);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Camera")
	static void SetCameraComponentAdditiveOffset(UCameraComponent* CameraComponent, const FTransform& AdditiveTransformOffset, const float AdditiveFOVOffset);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void SetCanBeDamaged(AActor* Actor, bool bCanBeDamaged);

	UFUNCTION(BlueprintCallable, Category="Fortnite | AI", meta=(WorldContext="WorldContext"))
	static void SetComponentAffectNavigationGeneration(UActorComponent* Component, bool bAffectNavigation);

	UFUNCTION(BlueprintCallable, Category="Fortnite | Utility")
	static void SetExtendedSafeZoneInfo(const AActor* ControllerOrPawn, bool bEnable);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static void SetGlobalTimeOfDayManager(UObject* WorldContextObject, TSoftClassPtr<AInfo> InTimeOfDayManager);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void SetNiagaraAssetMatchActivation(UNiagaraComponent* NiagaraComponent, UNiagaraSystem* NiagaraSystem, bool bResetExistingOverrideParameters = true);

	UFUNCTION(BlueprintCallable, Category="TimeOfDay", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void SetOutlinePostProcessEnabled(UObject* WorldContextObject, const bool bEnablePostProcess);

	UFUNCTION(BlueprintCallable, Category="Projectile")
	static void SetProjectileMovementDrunkData(AFortProjectileBase* Projectile, const FProjectileMovementDrunkConfig& NewConfig);

	UFUNCTION(BlueprintCallable, Category="SceneCapture")
	static void SetSceneCaptureShowFlags(USceneCaptureComponent2D* SceneCaptureComponent, const TArray<FEngineShowFlagsSetting>& ShowFlagSettings);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static void SetTimeOfDay(UObject* WorldContextObject, float TimeOfDay);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TimeOfDay", meta=(WorldContext="WorldContextObject"))
	static void SetTimeOfDaySpeed(UObject* WorldContextObject, float TimeOfDaySpeedFactor);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool ShouldBlockQuestProgressReport(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="HUD")
	static bool ShouldDisableMatchStatsDisplay(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial")
	static bool ShouldHideTutorialWidget(FName WidgetName);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Fortnite", meta=(AutoCreateRefTerm="IgnoreOnControllers", WorldContext="WorldContextObject"))
	static void ShowSoundIndicatorLocal(UObject* WorldContextObject, AActor* TrackedActor, FVector Location, float MaxAudibleDistance, EFortSoundIndicatorTypes IndicatorType, const TArray<AFortPlayerController*>& IgnoreOnControllers, const AActor* Instigator = nullptr, FLinearColor Tint = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000), UTexture* OverrideIcon = nullptr, USoundBase* SoundBase = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Fortnite", meta=(AutoCreateRefTerm="IgnoreOnControllers", WorldContext="WorldContextObject"))
	static void ShowSoundIndicatorLocalForTeam(UObject* WorldContextObject, AActor* TrackedActor, FVector Location, float MaxAudibleDistance, EFortSoundIndicatorTypes IndicatorType, const TArray<AFortPlayerController*>& IgnoreOnControllers, uint8 Team, TArray<TEnumAsByte<EFortTeamAffiliation::Type>> Affiliations, const AActor* Instigator = nullptr, FLinearColor Tint = FLinearColor(0.000000, 0.000000, 0.000000, 0.000000), UTexture* OverrideIcon = nullptr, const USoundBase* SoundBase = nullptr);

	UFUNCTION(BlueprintPure, Category="Fortnite")
	static FVector SnapToFortBuildingGrid(const FVector& InVector, const FVector PreSnapOffset, const FVector PostSnapOffset);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AreaOfEffect")
	static AFortAreaOfEffectCloud* SpawnAreaOfEffectCloud(TSubclassOf<AFortAreaOfEffectCloud> AreaOfEffectClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator& SpawnRotation, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	static ABuildingGameplayActor* SpawnBuildingGameplayActor(TSubclassOf<ABuildingGameplayActor> BGAClass, const FTransform& Transform, AActor* Instigator, const bool bAutomaticallyInitialize = false, const bool bTransient = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building", meta=(WorldContext="WorldContextObject"))
	static ABuildingGameplayActor* SpawnBuildingGameplayActorFromWorldContext(UObject* WorldContextObject, TSubclassOf<ABuildingGameplayActor> BGAClass, const FTransform& Transform, AActor* OptionalOwner, APawn* OptionalInstigator, const bool bTransient = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(DisplayName="SpawnInstancedPickupInWorld", WorldContext="WorldContextObject"))
	static bool SpawnInstancedPickupInWorld(UObject* WorldContextObject, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0, bool bToss = true, bool bRandomRotation = true, bool bBlockedFromAutoPickup = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Inventory", meta=(WorldContext="WorldContextObject"))
	static AFortPickup* SpawnItemVariantPickupInWorld(UObject* WorldContextObject, FSpawnItemVariantParams Params);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	static AFortProjectileBase* SpawnProjectile(TSubclassOf<AFortProjectileBase> ProjectileClass, AActor* RequestedBy, const FVector& SpawnLocation, const FRotator SpawnRotation, const FRotator& SpawnDirection, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnHit, FFortGameplayEffectContainerSpec EffectContainerSpecToApplyOnExplode, bool bUseDefaultPhysics, AActor* HomingTarget = nullptr, float InitialSpeed = 0.000000f, float GravityScale = 1.000000f, float ChargePercent = 0.000000f, const UFortWorldItemDefinition* OptionalAssociatedItemDef = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	static AFortProjectileBase* SpawnProjectileWithParams(TSubclassOf<AFortProjectileBase> ProjectileClass, AActor* RequestedBy, FSpawnProjectileParams SpawnProjectileParams);

	UFUNCTION(BlueprintCallable, Category="Effects", meta=(WorldContext="WorldContextObject"))
	static AFortTracerBase* SpawnTracerFromPool(UObject* WorldContextObject, TSubclassOf<AFortTracerBase> TracerClass, const FVector& Origin, const FVector& Destination, AFortPawn* Instigator);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities", meta=(DeterminesOutputType="ActorClass", DynamicOutputParam="SpawnedActor", WorldContext="WorldContextObject"))
	static void SpawnTransientActor(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, AActor*& SpawnedActor, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, AActor* OwnerActor = nullptr, APawn* InstigatorPawn = nullptr);

	UFUNCTION(BlueprintCallable, Category="Fortnite|Utilities", meta=(DeterminesOutputType="ComponentClass", DynamicOutputParam="SpawnedComponent"))
	static void SpawnTransientSceneComponent(TSubclassOf<USceneComponent> ComponentClass, USceneComponent*& SpawnedComponent, AActor* OwnerActor, USceneComponent* InAttachParent = nullptr, bool bRegister = true);

	UFUNCTION(BlueprintPure, Category="Fortnite | Utility")
	static FString ToLowerExceptIslandCode(const FString& InString);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite | Container", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void TossPickupFromContainer(UObject* WorldContextObject, AActor* Container, AFortPickup* Pickup, const int32 NumSteps, const int32 Step, const float LootTossConeHalfAngle, const FRotator& LootTossDirection, const float LootTossSpeed, const bool bForceHidePickupMinimapIndicator);

	UFUNCTION(BlueprintPure, Category="Fortnite | Utility")
	static FString ToUpperExceptIslandCode(const FString& InString);

	UFUNCTION(BlueprintCallable, Category="Feedback")
	static void TriggerFeedbackEvent(UObject* WorldContextObject, FFortFeedbackHandle EventHandle, AFortPawn* InstigatorPawn = nullptr, AFortPawn* Recipient = nullptr, float OverriddenDelay = -1.000000f, bool bOverriddenQueuing = true, bool bAllowReplication = true);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool TrySmartConsumeResources(int32 ResourceCost, AFortPlayerController* SourcePlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Ability")
	static void UnequipFortAbilitySet(UPARAM(ref) FFortAbilitySetHandle& AbilitySetHandle);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void UnhideAllTutorialWidgets(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tutorial", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject", WorldContext="WorldContextObject"))
	static void UnhideTutorialWidget(UObject* WorldContextObject, FName WidgetName);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static void UnregisterGridFoundation(ABuildingFoundation* BuildingFoundation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Cosmetic")
	static void UpdatePlayerCustomCharacterPartsVisualization(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Weapon", meta=(WorldContext="WorldContextObject"))
	static bool UpgradeAllWeaponsVerticalToRarity(AFortPlayerController* PlayerController, EFortRarity NewRarity, bool bThrottle = true);

	UFUNCTION(BlueprintPure, Category="Helpers")
	static bool ValidateOwnershipForGroupEmote(AFortPawn* Pawn, const UFortItemDefinition* EmoteDef);

	UFUNCTION(BlueprintPure, Category="Math|Fortnite", meta=(CompactNodeTitle="Vector Slerp", DisplayName="Vector Slerp", Keywords="/ Slerp Lerp Vector"))
	static FVector VectorSlerp(const FVector& Origin, const FVector& Start, const FVector& End, const float Alpha);

	UFUNCTION(BlueprintPure, Category="Fortnite", meta=(BlueprintThreadSafe))
	static float VectorToNormalizedAngleInDegrees(FVector V);

	UPROPERTY(Config)
	TArray<FName> FortShippingLogSuppressedObjects;

};

