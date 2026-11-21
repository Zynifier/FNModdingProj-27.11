// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemReplicationProxyInterface.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/CurveTable.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "GameplayPrediction.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "WorldPartition/HLOD/HLODDestruction.h"
#include "Building/BuildingActor.h"
#include "Building/BuildingTypes.h"
#include "Building/EditorOnlyBuildingInstanceMaterialParameters.h"
#include "Building/FortAttachToActorInterface.h"
#include "Building/FortWeakPointProviderInterface.h"
#include "Items/FortLootQuotaData.h"
#include "TimeOfDay/FortDayPhase.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "BuildingSMActor.generated.h"

class AActor;
class ABuildingActor;
class ABuildingFoundation;
class ABuildingSMActor;
class ABuildingTrap;
class ABuildingWeakSpot;
class AController;
class AFortConstructorBASE;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateZone;
class UAudioComponent;
class UBaseBuildingStaticMeshComponent;
class UBoxComponent;
class UBuildingEditModeMetadata;
class UBuildingEditModeSupport;
class UBuildingTextureData;
class UCurveLinearColor;
class UFXSystemAsset;
class UFortWeakPointComponent;
class UMaterialInstanceConstant;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNaniteDisplacedMesh;
class UObject;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class URuntimeVirtualTexture;
class USoundBase;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;
class UTexture;
enum class EBuildingAnim : uint8;

UENUM()
enum class EBuildingAnim : uint8
{
	EBA_None = 0,
	EBA_Building = 1,
	EBA_Breaking = 2,
	EBA_Constructed = 3,
	EBA_Destruction = 4,
	EBA_Placement = 5,
	EBA_DynamicLOD = 6,
	EBA_DynamicShrink = 7,
};

UENUM()
namespace EBuildingAttachmentSide
{
	enum Type
	{
		// Attached to the front / top side of a building

		Front = 0,
		// Attached to the bottom / back side of a building

		Back = 1,
		Any = 2,
	};
}

UENUM()
enum EBuildingAttachmentSlot
{
	// Accepts floor attachments and ceiling below

	SLOT_Floor = 0,
	// Accepts wall attachments, and corners

	SLOT_Wall = 1,
	// Accepts ceiling attachments only

	SLOT_Ceiling = 2,
	SLOT_None = 3,
};

UENUM()
enum class EBuildingNavObstacleType : uint8
{
	// marks navmesh as unwalkable for all AI

	UnwalkableAll = 0,
	// marks navmesh as unwalkable for husks, no effect on smasher

	UnwalkableHuskOnly = 1,
	// creates smashable area even if there's not enough room above (e.g. under stairs)

	SmashWhenLowHeight = 2,
	// creates smashable area only if there's not enough room above (e.g. under stairs)

	SmashOnlyLowHeight = 3,
	// creates smashable area for smasher, no effect on husk

	SmashSmasherOnly = 4,
	// creates smashable area for all AI

	SmashAll = 5,
};

UENUM(BlueprintType)
enum EBuildingReplacementType
{
	// Building is as was initially placed; No conversion applied

	BRT_None = 0,
	// Building came into existence as an edit operation

	BRT_Edited = 1,
	// Building came into existence as a building upgrade operation

	BRT_Upgrade = 2,
};

UENUM()
enum class EFortDamageVisualsState : uint8
{
	UnDamaged = 0,
	DamagedAndAnimating = 1,
	DamagedAndStatic = 2,
};

UENUM()
namespace EPlacementType
{
	enum Type
	{
		Free = 0,
		Grid = 1,
		None = 2,
	};
}

UENUM()
enum class ESavedSupportStatus : uint8
{
	UnknownState = 0,
	// unknown if the actor is supported or not. Physics check recommended

	Supported = 1,
	UnSupported = 2,
};

UENUM()
enum class EStructuralSupportCheck : uint8
{
	Stable = 0,
	Unstable = 1,
	Max_None = 2 UMETA(DisplayName="None"),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuildingReplacementDestruction, TEnumAsByte<EBuildingReplacementType>, ReplacementType, const ABuildingSMActor*, NewBuildingActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConstructionComplete, ABuildingSMActor*, BuildingSMActor);

USTRUCT()
struct FAddOrRemoveGameplayTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AddOrRemoveGameplayTags")
	FGameplayTagContainer Added;

	UPROPERTY(EditAnywhere, Category="AddOrRemoveGameplayTags")
	FGameplayTagContainer Removed;

};

USTRUCT()
struct FLightProperty_Color
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LightProperty_Color")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="LightProperty_Color")
	FLinearColor Color;

	UPROPERTY(EditAnywhere, Category="LightProperty_Color")
	bool bUsingSRGB;

};

USTRUCT()
struct FTaggedInLightProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TaggedInLightProperties")
	FName Tag;

	UPROPERTY(EditAnywhere, Category="TaggedInLightProperties")
	FLightProperty_Color ColorSubstitute;

};

USTRUCT()
struct FTaggedParticleSubstitution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TaggedParticleSubstitution")
	FName Tag;

	UPROPERTY(EditAnywhere, Category="TaggedParticleSubstitution")
	TObjectPtr<UParticleSystem> Substitute;

};

USTRUCT()
struct FTaggedSoundSubstitution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TaggedSoundSubstitution")
	FName Tag;

	UPROPERTY(EditAnywhere, Category="TaggedSoundSubstitution")
	TObjectPtr<USoundBase> Substitute;

};

USTRUCT()
struct FTaggedStaticMeshSubstitution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TaggedStaticMeshSubstitution")
	FName Tag;

	UPROPERTY(EditAnywhere, Category="TaggedStaticMeshSubstitution")
	TObjectPtr<UStaticMesh> Substitute;

};

USTRUCT(BlueprintType)
struct FMeshSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	float Weight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	uint8 bDoNotBlockBuildings : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	uint8 bDestroyOnPlayerBuildingPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<UStaticMesh> BaseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<UParticleSystem> BreakEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<UParticleSystem> DeathParticles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	FName DeathParticleSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<USoundBase> DeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<UParticleSystem> ConstructedEffect;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers")
	TArray<FTaggedParticleSubstitution> SwapInParticles;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers")
	TArray<FTaggedSoundSubstitution> SwapInSounds;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers")
	TArray<FTaggedStaticMeshSubstitution> SwapInMeshes;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers")
	TArray<FTaggedInLightProperties> SwapInLightProperties;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers")
	FAddOrRemoveGameplayTags BuildingOwnedTagDelta;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TObjectPtr<UStaticMesh> SearchedMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	FCurveTableRowHandle SearchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	float LootNoiseRange;

#if WITH_EDITORONLY_DATA
	UPROPERTY(NotReplicated)
	float LootNoiseLoudness_DEPRECATED;
#endif

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	FVector3f LootSpawnLocation;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMeshSetChanged, ABuildingSMActor*, BuildingSMActor, const FMeshSet&, NewMeshSet);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FiveParams(FOnResourcesEarnedOverrideSignature, AController*, InstigatorController, ABuildingSMActor*, BuildingSMActor, float, ResourcesEarned, bool, bJustHitWeakspot, float&, ModifiedResourcesEarned);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRepairFinishedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRepairStartedDelegate, AFortPlayerController*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTrapAttachedDelegate, const ABuildingTrap*, Trap, const bool, bDetached);

USTRUCT(BlueprintType)
struct FAnimatingMaterialPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="PlayerBuilt")
	TObjectPtr<UMaterialInterface> Original;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="PlayerBuilt")
	TObjectPtr<UMaterialInterface> Override;

};

USTRUCT()
struct FBuildingActorMinimalReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint16 Health;

	UPROPERTY()
	uint16 MaxHealth;

};

USTRUCT()
struct FBuildingDamageHistoryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AController> Instigator;

	UPROPERTY(Transient)
	float Timestamp;

	UPROPERTY(Transient)
	float Damage;

};

USTRUCT(BlueprintType)
struct FBuildingDuplicationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingDuplicationData")
	TSubclassOf<UObject> ClassData;

	UPROPERTY(EditAnywhere, Category="BuildingDuplicationData", meta=(ArraySizeEnum="/Script/FortniteGame.EFortTextureDataSlot"))
	TObjectPtr<UBuildingTextureData> TextureData[4];

};

USTRUCT()
struct FBuildingNavObstacle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Navigation")
	FBox LocalBounds;

	UPROPERTY(EditAnywhere, Category="Navigation")
	EBuildingNavObstacleType ObstacleType;

};

USTRUCT()
struct FBuildingSMActorAttemptSpawnResourcesParams
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> InstigatorPawn;

};

USTRUCT()
struct FRandomDayphaseFX
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	TObjectPtr<UParticleSystem> ParticleSystem;

	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	TArray<TObjectPtr<UParticleSystem>> AltParticleSystems;

	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	TArray<EFortDayPhase> RequiredDayphases;

	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	float ChanceToSpawnFX;

	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	TEnumAsByte<EDetailMode> DetailMode;

	UPROPERTY(EditAnywhere, Category="RandomDayphaseFX")
	float MaxDrawDistance;

};

USTRUCT(BlueprintType)
struct FTierMeshSets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	int32 Tier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LootTiers")
	TArray<FMeshSet> MeshSets;

};

USTRUCT(BlueprintType)
struct FBuildingSMActorClassData : public FBuildingActorClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Effects", meta=(NoGetter))
	TSoftObjectPtr<UFXSystemAsset> DeathParticles;

	UPROPERTY(EditDefaultsOnly, Category="LootTiers", meta=(GetByRef))
	TArray<FTierMeshSets> AlternateMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDrop", meta=(NoGetter))
	FName DestructionLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="Wind", meta=(NoGetter))
	TSoftObjectPtr<UCurveLinearColor> WindSpeedCurve;

	UPROPERTY(EditDefaultsOnly, Category="Wind", meta=(NoGetter))
	TSoftObjectPtr<UCurveLinearColor> WindPannerSpeedCurve;

	UPROPERTY(EditDefaultsOnly, Category="Wind", meta=(NoGetter))
	TSoftObjectPtr<USoundBase> WindAudio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh", meta=(GetByRef))
	FVector2D RandomScaleRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayerBuilt", meta=(DisplayAfter="AnimatingSubObjects"))
	uint8 NumFrameSubObjects;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float ShieldBuffMaterialParamValue1;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float ShieldBuffMaterialParamValue2;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	float AnimatingDistanceFieldSelfShadowBias;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayerBuilt")
	float AnimatingSubObjects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attachment")
	float PlayerGridSnapSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayerBuilt", meta=(NoGetter))
	FVector3f BuildingPlacementDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDrop", meta=(NoGetter))
	FCurveTableRowHandle BuildingResourceAmountOverride;

	UPROPERTY(EditDefaultsOnly, Category="Wind", meta=(NoGetter))
	TArray<TSoftObjectPtr<UMaterialInterface>> IntenseWindMaterials;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EditMode", meta=(NoGetter))
	TObjectPtr<UBuildingEditModeMetadata> EditModePatternData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LootQuota", meta=(NoGetter))
	uint8 bCanSpawnAtLowerQuotaLevels : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LootQuota", meta=(NoGetter))
	TEnumAsByte<ELootQuotaLevel::Type> MaximumQuotaLevelBound;

	UPROPERTY(EditDefaultsOnly, Category="CurieIdentification")
	uint8 bDeriveCurieIdentifierFromResourceType : 1;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(NoGetter))
	float InfluenceMapWeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Mesh")
	uint8 bNoAIPawnCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	uint8 bBlocksCeilingPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh", meta=(NoGetter))
	uint8 bBlocksAttachmentPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	uint8 bUsePhysicalSurfaceForFootstep : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	uint8 bRandomYawOnPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	uint8 bRandomScaleOnPlacement : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mesh")
	uint8 bClearMIDWhenReturningToUndamagedState : 1;

	UPROPERTY(EditDefaultsOnly, Category="Mesh", meta=(GetByRef))
	TArray<TObjectPtr<UMaterialInstanceConstant>> BlueprintMICs;

	UPROPERTY(EditDefaultsOnly, Category="Effects", meta=(GetByRef))
	TArray<FRandomDayphaseFX> RandomDayphaseFXList;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction")
	uint8 bUseDynamicDestructionMaterial : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction")
	uint8 bUseDynamicDestructionNiagaraSystem : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDrop")
	uint8 bAllowResourceDrop : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bHideOnDeath : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bPlayDestructionEffects : 1;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	uint8 bSkipConstructionSounds : 1;

};

USTRUCT()
struct FChosenQuotaInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 LootTier;

	UPROPERTY()
	FName LootTierKey;

};

USTRUCT()
struct FProxyGameplayCueDamage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayEffectContextHandle EffectContext;

private:
	UPROPERTY()
	uint32 ProxyGameplayCueDamageMagnitude;

};

USTRUCT()
struct FRandomDayphaseFXState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bRandomSelectionAlreadyHappened;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> SpawnedComponent;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData, meta=(DisplayName="Building Static Mesh"))
class ABuildingSMActor : public ABuildingActor, public IFortAttachToActorInterface, public IAbilitySystemReplicationProxyInterface, public IFortWeakPointProviderInterface, public IWorldPartitionDestructibleInHLODInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Structural Support")
	FORTNITEGAME_API void AddToGrid(const bool bFromDynamicBuilder = false);

	UFUNCTION(BlueprintCallable, Category="Attachment")
	FORTNITEGAME_API virtual void AttachBuildingActorToMe(ABuildingActor* ActorToAttach, bool bForceAttachment = false);

	UFUNCTION(BlueprintNativeEvent, Category="Resources", meta=(DisplayName="CanAttemptGenerateResources"))
	FORTNITEGAME_API bool BlueprintCanAttemptGenerateResources(const FGameplayTagContainer& InTags, AController* InstigatorController) const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API const TSubclassOf<ABuildingWeakSpot> BlueprintGetBuildingWeakspotOverride() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool CanBeDamaged(const AController* DamageInstigator, const AActor* DamageCauser) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual void CancelRepair();

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool CanDoBuildingAnimations() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void ClearResourcesEarnedOverrideDelegate();

	UFUNCTION(BlueprintCallable, Category="Attachment")
	FORTNITEGAME_API virtual void DetachBuildingActorFromMe(ABuildingActor* ActorToAttach, bool bBeingDestroyed = false, AController* Killer = nullptr);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlyRemoveInstanceMaterialRTVParameter(FName ParamName);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlyRemoveInstanceMaterialScalarParameter(FName ParamName);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlyRemoveInstanceMaterialTextureParameter(FName ParamName);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlyRemoveInstanceMaterialVectorParameter(FName ParamName);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlySetInstanceMaterialRTVParameter(FName ParamName, URuntimeVirtualTexture* Value);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlySetInstanceMaterialScalarParameter(FName ParamName, float Value);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlySetInstanceMaterialTextureParameter(FName ParamName, UTexture* Value);

	UFUNCTION(BlueprintCallable, Category="EditorOnlyParameters")
	FORTNITEGAME_API void EditorOnlySetInstanceMaterialVectorParameter(FName ParamName, FLinearColor Value);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="Curve")
	FORTNITEGAME_API int32 FindDestructionLootTier() const;

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Building")
	FORTNITEGAME_API void ForceIntoStructuralGridDuringRuntime();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API TArray<ABuildingActor*> GetAttachedBuildingActors() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API TArray<ABuildingSMActor*> GetAttachedBuildingSMActors() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API UStaticMeshComponent* GetBuildingMeshComponent() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Building")
	FORTNITEGAME_API void GetBuildingTextureData(TArray<UBuildingTextureData*>& OutTextureDataArray) const;

	UFUNCTION(BlueprintPure, Category="ItemDrop")
	FORTNITEGAME_API const FName& GetDestructionLootTierGroup() const;

	UFUNCTION(BlueprintCallable, Category="Displacement")
	FORTNITEGAME_API UNaniteDisplacedMesh* GetDisplacedMesh();

	UFUNCTION(BlueprintNativeEvent, Category="Building")
	FORTNITEGAME_API FGameplayTagQuery GetInvalidTrapTagQuery() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual int32 GetLogicalBuildingIndex() const;

	UFUNCTION(BlueprintPure)
	static FORTNITEGAME_API const int32 GetMaximumLegalReplicatedHealthValue();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API UMaterialInstanceDynamic* GetOrCreateMIDOnDefaultMesh(int32 ElementIndex);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API ABuildingSMActor* GetParentActorToAttachTo() const;

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API virtual EBuildingReplacementType GetReplacementDestructionReason();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API float GetWeakSpotEnabledTimeout(AFortPlayerController* Controller) const;

	UFUNCTION(BlueprintPure, Category="Curve")
	FORTNITEGAME_API bool HasDestructionLoot() const;

	UFUNCTION(BlueprintPure, Category="Building", meta=(UnsafeDuringActorConstruction="true"))
	FORTNITEGAME_API virtual bool IsStructurallySupported() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API virtual bool IsSupportedByWorld() const;

	UFUNCTION(BlueprintPure, Category="Building")
	FORTNITEGAME_API bool IsUnderConstruction() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Structural Support")
	FORTNITEGAME_API void MarkConnectedBuildingsForStructuralIntegrityCheck();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API float ModifyIncomingDamageForBuildingActorAttachedToMe(const ABuildingSMActor* AttachedBuildingSMActor, float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser) const;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueAdded(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueAdded_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters Parameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueAddedAndWhileActive_FromSpec(const FGameplayEffectSpecForRPC& Spec, FPredictionKey PredictionKey) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueAddedAndWhileActive_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueExecuted(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueExecuted_FromSpec(const FGameplayEffectSpecForRPC Spec, FPredictionKey PredictionKey) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCueExecuted_WithParams(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCuesAddedAndWhileActive_WithParams(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCuesExecuted(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext) override;

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void NetMulticast_InvokeGameplayCuesExecuted_WithParams(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters) override;

	UFUNCTION(BlueprintImplementableEvent, Category="Attachment")
	FORTNITEGAME_API void OnAttachToBuilding(ABuildingActor* AttachedToBuilding);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnBounceAnimationUpdate(const FFortBounceData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category="Attachment")
	FORTNITEGAME_API void OnDetachFromBuilding(ABuildingActor* AttachedToBuilding, bool bBeingDestroyed);

	UFUNCTION()
	FORTNITEGAME_API void OnPhysicsStateChanged(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_Mirrored();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_NoCameraCollision();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_NoCollision();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ProxyGameplayCueDamage();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ReplicationProxy();

	UFUNCTION(BlueprintImplementableEvent, Category="Health")
	FORTNITEGAME_API void OnRepairStarted();

	UFUNCTION(BlueprintCallable, Category="Structural Support")
	FORTNITEGAME_API virtual void PostForceMove();

	UFUNCTION(BlueprintCallable, Category="Structural Support")
	FORTNITEGAME_API virtual void PreForceMove(AController* EventInstigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual void RepairBuilding(AFortPlayerController* RepairingController, int32 ResourcesSpent);

	UFUNCTION(BlueprintCallable, Category="Displacement")
	FORTNITEGAME_API bool SetDisplacedMesh(UNaniteDisplacedMesh* NaniteDisplacedMesh);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	FORTNITEGAME_API virtual void SetMirrored(bool bIsMirrored);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	FORTNITEGAME_API void SetNoCameraCollision(bool bValue);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	FORTNITEGAME_API void SetNoPhysicsCollision(bool bValue);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetResourcesEarnedOverrideDelegate(FOnResourcesEarnedOverrideSignature InOnResourcesEarnedOverrideDelegate);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetResourceType(EFortResourceType::Type NewResourceType);

	UFUNCTION(BlueprintNativeEvent, Category="Mesh")
	FORTNITEGAME_API bool ShouldUsePhysicalMaterialForFootstep() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API virtual void StartBounceAnimation(const float StartTime, const float Radius, const FVector& Normal, const FVector& Center, EFortBounceType::Type InBounceType = EFortBounceType::Hit, const bool bLocalInstigator = false);

	UFUNCTION()
	FORTNITEGAME_API void UpdateComponentCollisionModes();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building", meta=(UnsafeDuringActorConstruction="true"))
	FORTNITEGAME_API bool WillRegisterWithStructuralGrid() const;

	UPROPERTY(EditDefaultsOnly, Category="BuildingSMActor")
	uint8 bForceReplicateSubObjects : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintSetter=SetNoPhysicsCollision, ReplicatedUsing=OnRep_NoCollision, Category="Mesh")
	uint8 bNoPhysicsCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintSetter=SetNoCameraCollision, ReplicatedUsing=OnRep_NoCameraCollision, Category="Mesh")
	uint8 bNoCameraCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bNoPawnCollision : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cheat")
	uint8 bAllowBuildingCheat : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bCameraOnlyCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bNoWeaponCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bNoRangedWeaponCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bNoProjectileCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bDoNotBlockInteract : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingSMActor")
	uint8 bNeedsMIDsForCreative : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	uint8 bAllowCustomMaterial : 1;

	UPROPERTY(Transient)
	FFortBounceData BounceData;

	UPROPERTY(Transient)
	float DestroyedTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> BASEEffectMeshComponent;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	TArray<FBuildingNavObstacle> NavObstacles;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnConstructionComplete OnConstructionComplete;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FOnMeshSetChanged OnMeshSetChanged;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FRepairStartedDelegate OnRepairBuildingStarted;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FRepairFinishedDelegate OnRepairBuildingFinished;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FTrapAttachedDelegate OnTrapPlacementChanged;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FBuildingReplacementDestruction OnReplacementDestruction;

	FORTNITEGAME_API virtual void ForceReplication() override;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Building", meta=(DisplayName="OnStructurallyStable"))
	FORTNITEGAME_API void BlueprintOnStructurallyStable();

	UFUNCTION(BlueprintNativeEvent, Category="Building", meta=(DisplayName="OnStructurallyUnstable"))
	FORTNITEGAME_API void BlueprintOnStructurallyUnstable();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API virtual void CancelAutoBuild();

	UFUNCTION()
	FORTNITEGAME_API void ClearRequestedBuildingAnimation();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="ExposedAssetProvider")
	FORTNITEGAME_API void CollectBuildingTextureDataAssetReferences(UPARAM(ref) FFortExposedAssetReferenceCollector& Collector) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API virtual void ForceVisualState(EBuildingAnim VisualState);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_Abilities_Activation_Generic_BannerWallBuff1(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void GameplayCue_Abilities_Activation_Generic_BannerWallBuff2(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API UFXSystemAsset* GetDeathParticles() const;

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API FBuildingDuplicationData GetDuplicationData();

	UFUNCTION(BlueprintCallable, Category="Wind")
	FORTNITEGAME_API bool GetIntenseWindMaterialsForPreview(TArray<UMaterialInterface*>& Materials);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	FORTNITEGAME_API UMaterialInterface* GetOverrideMeshMaterial(UStaticMeshComponent* MeshComp, int32 MatIdx) const;

	UFUNCTION(BlueprintPure, Category="Wind")
	FORTNITEGAME_API UCurveLinearColor* GetWindPannerSpeedCurveForPreview() const;

	UFUNCTION(BlueprintPure, Category="Wind")
	FORTNITEGAME_API UCurveLinearColor* GetWindSpeedCurveForPreview() const;

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category="Building")
	FORTNITEGAME_API void MulticastPlayFullHealthEffects();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Building")
	FORTNITEGAME_API void OnBuildingCompleteCosmetic();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Building")
	FORTNITEGAME_API void OnBuildingPlaced();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnDynamicShrinkAndDestroyEffectFinished();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnLODOverrideEffectFinished();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_BuildingAnimation();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_bUnderConstruction();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_bUnderRepair();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_EditingPlayer();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_HiddenDueToTrapPlacement();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_MetaData();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_RelevantBASE();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ReplicatedDrawScale3D();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_ResourceType(EFortResourceType::Type OldType);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	FORTNITEGAME_API virtual void PlayBreakEffects();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	FORTNITEGAME_API virtual void PlayConstructionBounce();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	FORTNITEGAME_API void PlayDestructionEffects();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	FORTNITEGAME_API virtual void PlayFullHealthEffects();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API TArray<UTexture2D*> ReadTextureData();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetBuildingTextureData(const int32 Index, UBuildingTextureData* NewBuildingTextureData);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetDeathParticles(UParticleSystem* InPS);

	UFUNCTION(BlueprintCallable, Category="Attachement")
	FORTNITEGAME_API void SetParentActorToAttachTo(ABuildingSMActor* InParentActorToAttachTo);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetTextureData(const TArray<UTexture2D*>& InTextures);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	FORTNITEGAME_API virtual void StartFullHealthAnimation();

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API void TransferBuildingData(ABuildingSMActor* SourceDataActor);

	UFUNCTION(BlueprintCallable, Category="Building")
	FORTNITEGAME_API void TransferFromDuplicationData(FBuildingDuplicationData SourceData);

	UFUNCTION()
	FORTNITEGAME_API virtual void UpdateDynamicShrinkAndDestroyEffect(float CurveValue);

	UFUNCTION()
	FORTNITEGAME_API virtual void UpdateLODOverrideEffect(float CurveValue);

	UFUNCTION()
	FORTNITEGAME_API virtual void UpdateRepairMaterialAnim(float CurveValue);

	UPROPERTY(EditAnywhere, Category="Mesh")
	uint8 bUseSingleMeshCullDistance : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_NoCollision, Category="Mesh", meta=(AllowPrivateAccess="true"))
	uint8 bNoCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mesh")
	uint8 bNoVisibilityCollision : 1;

	UPROPERTY(Transient)
	uint8 bSupportedDirectly : 1;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="StructuralSupport")
	uint8 bForciblyStructurallySupported : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="StructuralSupport")
	uint8 bRegisterWithStructuralGrid : 1;

	UPROPERTY(Transient)
	uint8 bCurrentlyBeingEdited : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeakSpots")
	uint8 bAllowWeakSpots : 1;

	UPROPERTY(EditAnywhere, Category="WeakSpots")
	uint8 bUseComplexForWeakSpots : 1;

	UPROPERTY(EditDefaultsOnly, Category="Wind")
	uint8 bNeedsWindMaterialParameters : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instance")
	uint8 bShowDamageCracks : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instance")
	uint8 bPlayBounce : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instance", meta=(DisplayAfter="bPlayBounce", EditCondition="bPlayBounce"))
	uint8 bPropagateBounce : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instance", meta=(DisplayAfter="bPropagateBounce", EditCondition="bPropagateBounce"))
	uint8 bPropagatesBounceEffects : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	uint8 bConsiderOverrideMaterialsOnAnimationCleanup : 1;

	UPROPERTY(EditDefaultsOnly, Category="Cull Distance")
	uint8 bIncludeChildActorsForCullDistance : 1;

	UPROPERTY(EditInstanceOnly, TextExportTransient, NonPIEDuplicateTransient, SaveGame, Category="BuildingSMActor")
	ESavedSupportStatus SavedDirectlySupportedStatus;

	UPROPERTY(Transient)
	uint8 CurAnimSubObjectNum;

	UPROPERTY(Transient)
	uint8 CurAnimSubObjectTargetNum;

	UPROPERTY(EditInstanceOnly, Category="EditorInstanceParams")
	FEditorOnlyBuildingInstanceMaterialParameters EditorOnlyInstanceMaterialParameters;

	UPROPERTY(Transient)
	FChosenQuotaInfo DestructionLootTierChosenQuotaInfo;

	UPROPERTY(Transient)
	uint8 bSelectedForQuota;

	UPROPERTY(SaveGame)
	FName DestructionLootTierKey;

	UPROPERTY(Transient)
	int32 MaxResourcesToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	TObjectPtr<UParticleSystem> BreakEffect;

	UPROPERTY(EditAnywhere, Category="Instance")
	TObjectPtr<URuntimeVirtualTexture> RVTHeightOverride;

	UPROPERTY(EditAnywhere, Category="Instance")
	TObjectPtr<URuntimeVirtualTexture> RVTColorOverride;

	UPROPERTY(Transient)
	TObjectPtr<UFXSystemAsset> DeathParticlesInst;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effects")
	FName DeathParticleSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	TObjectPtr<USoundBase> DeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Effects")
	TObjectPtr<UParticleSystem> ConstructedEffect;

	UPROPERTY()
	TArray<FRandomDayphaseFXState> RandomDayphaseFXStates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> ConstructionAudioComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> CachedDestructionInstigator;

	UPROPERTY(Transient)
	float LastDamageAmount;

	UPROPERTY(Transient)
	FVector3f LastDamageHitImpulseDir;

	UPROPERTY(Transient)
	TArray<FBuildingDamageHistoryEntry> DamageHistory;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> CachedAnimatingStaticMeshes;

	UPROPERTY(Transient)
	int32 UndermineGroup;

	UPROPERTY(Transient)
	int32 LogicalBuildingIdx;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> AnimatingMaterial_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> DamagedButNotAnimatingMaterial_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> AnimatingMaterialMobile_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> DamagedButNotAnimatingMaterialMobile_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TMap<TObjectPtr<UMaterialInterface>, TObjectPtr<UMaterialInterface>> AnimatingMaterials_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TMap<TObjectPtr<UMaterialInterface>, TObjectPtr<UMaterialInterface>> DamagedButNotAnimatingMaterials_DEPRECATED;
#endif

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="PlayerBuilt")
	TArray<FAnimatingMaterialPair> AnimatingMaterialMappings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="PlayerBuilt")
	TArray<FAnimatingMaterialPair> DamagedButNotAnimatingMaterialMappings;

	UPROPERTY()
	TSubclassOf<UBuildingEditModeSupport> EditModeSupportClass;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeSupport> EditModeSupport;

	UPROPERTY(Transient)
	float HealthToAutoBuild;

	UPROPERTY(Transient)
	float AccumulatedAutoBuildTime;

	UPROPERTY(Transient)
	TEnumAsByte<EBuildingReplacementType> ReplacementDestructionReason;

	UPROPERTY(Transient)
	EBuildingAnim CurBuildingAnimType;

	UPROPERTY(Transient)
	EFortDamageVisualsState DamageVisualsState;

	UPROPERTY(Transient)
	float CurBuildProgress;

	UPROPERTY(Transient)
	float CurBuildingAnimStartTime;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> BlueprintMIDs;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> BlueprintMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attachment")
	FVector3f BuildingAttachmentPointOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attachment")
	float BuildingAttachmentRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attachment")
	TEnumAsByte<EBuildingAttachmentType> BuildingAttachmentType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Attachment")
	TEnumAsByte<EPlacementType::Type> BuildingPlacementType;

	UPROPERTY(Transient)
	EStructuralSupportCheck LastStructuralCheck;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Attachment")
	TObjectPtr<ABuildingSMActor> ParentActorToAttachTo;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EBuildingAttachmentSide"))
	TObjectPtr<ABuildingActor> AttachmentPlacementBlockingActors[2];

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingSMActor>> ActorsForcedAttachToMe;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<UFXSystemAsset> DeathParticles_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FTierMeshSets> AlternateMeshes_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FName DestructionLootTierGroup_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<UCurveLinearColor> WindSpeedCurve_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<UCurveLinearColor> WindPannerSpeedCurve_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<USoundBase> WindAudio_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FVector2D RandomScaleRange_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 NumFrameSubObjects_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float ShieldBuffMaterialParamValue1_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float ShieldBuffMaterialParamValue2_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float AnimatingDistanceFieldSelfShadowBias_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float AnimatingSubObjects_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float PlayerGridSnapSize_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FVector3f BuildingPlacementDistance_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FCurveTableRowHandle BuildingResourceAmountOverride_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<TSoftObjectPtr<UMaterialInterface>> IntenseWindMaterials_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UBuildingEditModeMetadata> EditModePatternData_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bCanSpawnAtLowerQuotaLevels_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TEnumAsByte<ELootQuotaLevel::Type> MaximumQuotaLevelBound_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bDeriveCurieIdentifierFromResourceType_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	float InfluenceMapWeight_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bNoAIPawnCollision_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bBlocksCeilingPlacement_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bBlocksAttachmentPlacement_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bUsePhysicalSurfaceForFootstep_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bRandomYawOnPlacement_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bRandomScaleOnPlacement_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bClearMIDWhenReturningToUndamagedState_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<TObjectPtr<UMaterialInstanceConstant>> BlueprintMICs_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FRandomDayphaseFX> RandomDayphaseFXList_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bUseDynamicDestructionMaterial_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bUseDynamicDestructionNiagaraSystem_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bAllowResourceDrop_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bHideOnDeath_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bPlayDestructionEffects_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint8 bSkipConstructionSounds_DEPRECATED;
#endif

private:
	UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MetaData, Category="Instance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortTextureDataSlot"))
	TObjectPtr<UBuildingTextureData> TextureData[4];

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_MetaData, Category="Mesh", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, SaveGame, AssetRegistrySearchable, ReplicatedUsing=OnRep_ResourceType, Category="Resource", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_MetaData)
	int32 AltMeshIdx;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, ReplicatedUsing=OnRep_Mirrored, Category="Instance", meta=(AllowPrivateAccess="true"))
	uint8 bMirrored : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Repair", meta=(AllowPrivateAccess="true"))
	uint8 bSupportsRepairing : 1;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_HiddenDueToTrapPlacement, Category="BuildingSMActor", meta=(AllowPrivateAccess="true"))
	uint8 bHiddenDueToTrapPlacement : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bAttachmentPlacementBlockedFront : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bAttachmentPlacementBlockedBack : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bUnderConstruction)
	uint8 bUnderConstruction : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bUnderRepair)
	uint8 bUnderRepair : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bIsInitiallyBuilding : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BuildingAnimation)
	EBuildingAnim BuildingAnimation;

	UPROPERTY(Transient)
	uint16 ActorIndexInFoundation;

	UPROPERTY(VisibleAnywhere, Category="Displacement")
	TObjectPtr<UNaniteDisplacedMesh> DisplacedMesh;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedDrawScale3D)
	FVector3f ReplicatedDrawScale3D;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Export, Category="Debug", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UBaseBuildingStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(Transient, Export, meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UFortWeakPointComponent> WeakPointComponent;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BoxComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Export, Category="EditorOnly", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> EditorOnlyStaticMeshComponent;
#endif

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicationProxy)
	FBuildingActorMinimalReplicationProxy MinimalReplicationProxy;

	UPROPERTY(Transient, Replicated)
	TEnumAsByte<EBuildingReplacementType> BuildingReplacementType;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EditingPlayer)
	TObjectPtr<AFortPlayerStateZone> EditingPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="Attachment", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<EBuildingAttachmentSlot> BuildingAttachmentSlot;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> AttachedBuildingActors;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> BuildingActorsAttachedTo;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingFoundation> Foundation;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="Gameplay", meta=(AllowPrivateAccess="true", ExposeOnSpawn="true"))
	TObjectPtr<ABuildingSMActor> DamagerOwner;

	UPROPERTY(ReplicatedUsing=OnRep_RelevantBASE)
	TWeakObjectPtr<AFortConstructorBASE> RelevantBASE;

	UPROPERTY(Transient)
	FWorldPartitionHLODDestructionTag HLODDestructionTag;

	UPROPERTY()
	TWeakObjectPtr<AFortConstructorBASE> LastRelevantBASE;

	UPROPERTY(ReplicatedUsing=OnRep_ProxyGameplayCueDamage)
	FProxyGameplayCueDamage ProxyGameplayCueDamage;

};

