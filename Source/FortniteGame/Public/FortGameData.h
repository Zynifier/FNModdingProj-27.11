// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Components/SlateWrapperTypes.h"
#include "DataRegistryId.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Materials/MaterialExpressionChannelMaskParameterColor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortSubGameTypes.h"
#include "FortTypes.h"
#include "OnlineAccountTexts.h"
#include "FortGameData.generated.h"

class ABuildingWeakSpot;
class AFortClientAnnouncement_ZoneModifiers;
class AFortDamageNumbersActor;
class AFortGlobalAbilityTargetingActor;
class AFortPhysicsObjectManager;
class AFortPickupEffect;
class AFortWeap_BuildingTool;
class AFortWeap_EditingTool;
class APlayerCameraManager;
class UCurveFloat;
class UCurveVector;
class UDataTable;
class UFortAbilitySet;
class UFortAbilityTagRelationshipMapping;
class UFortAmmoItemDefinition;
class UFortAnalyticsData;
class UFortAppActivationSoundMixManager;
class UFortAttributeCategory;
class UFortAttributeLookupTable;
class UFortBakedPropertyMetadataCache;
class UFortBuildingAudioBank;
class UFortDeathCauseData;
class UFortDeathCauseFromTagMapping;
class UFortEditToolItemDefinition;
class UFortGamepadSettings;
class UFortGamepadSettingsV2;
class UFortGameplayEffectData;
class UFortGameplayTagData;
class UFortInputData;
class UFortItemCategory;
class UFortLoadingConfig;
class UFortLockerConfig;
class UFortMarkerDetailsTable;
class UFortMinigameTeamIdentification;
class UFortMissionCSVEventMap;
class UFortMissionGenerationData;
class UFortPhysicsCollisionHandler;
class UFortPhysicsObjectAssetSetupData;
class UFortPlacementActorTagTest;
class UFortPreferredItemSlotSettings;
class UFortQuestIndicatorData;
class UFortRarityData;
class UFortResourceItemDefinition;
class UFortSeasonItemIndicatorData;
class UFortSoundIndicatorComponent;
class UFortSurfaceTypeToSurfaceTypeTagMapping;
class UFortTagUIDataLookupTable;
class UFortTeamIdentification;
class UFortTokenToAttributeTable;
class UFortTokenToTextTable;
class UFortTokenType;
class UFortTooltipMap;
class UFortTouchInputSettings;
class UFortUINotification;
class UFortWeaponRechargeAmmoItemMapping;
class UGameplayEffect;
class UGameplayTagTableManager;
class UMaterialInterface;
class UMaterialParameterCollection;
class UNiagaraSystem;
class UParticleSystem;
class UPersistenceFrameworkSettings;
class UPhysicalMaterial;
class USoundBase;
class USoundMix;
class UStaticMesh;
class UTexture2D;
class UWorld;

UENUM(BlueprintType)
enum class ESubGameAccessReason : uint8
{
	/** User does not have access to play */
	NoAccess = 0,
	/** All users are allowed to play */
	OpenAccess = 1,
	/** User owns item that grants access*/
	TokenItemAccess = 2,
	/** User has home-sharing access*/
	XboxHomeSharingAccess = 3,
	/** User is given complimentary access during a service outage */
	XboxServiceOutageAccess = 4,
	/** User has limited access */
	LimitedAccess = 5,
};

USTRUCT()
struct FDynamicDestructionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionConfig")
	float MaterialTextureSizeMin;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionConfig")
	float MaterialTextureSizeMax;

};

USTRUCT()
struct FDynamicDestructionOpacityMask
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionOpacityMask")
	FName MaskName;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionOpacityMask")
	TEnumAsByte<EChannelMaskParameterColor::Type> MaskChannel;

};

USTRUCT()
struct FDynamicDestructionParamNamesConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig", meta=(DisplayName="Material Source Opacity Masks (Evaluated in order of array)"))
	TArray<FDynamicDestructionOpacityMask> MaterialSourceOpacityMasks;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialOpacityChannel;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialSphereRadius;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialOpacityMask;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialHitLocation;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialHitVector;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialDestructionTimeStamp;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialDissolveDuration;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialTextureSize;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName MaterialResource;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraDestroyedMesh;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraRadius;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraScale;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraHitLocation;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraHitVector;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraBounds;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraResource;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraDamageDealt;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraIsCurieFireDamage;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraIsInstantDeath;

	UPROPERTY(EditDefaultsOnly, Category="DynamicDestructionParamNamesConfig")
	FName NiagaraStaticMeshInstanceIndex;

};

USTRUCT()
struct FFortHighlightColors
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Highlight")
	FLinearColor OutlineColor;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FLinearColor SceneModulationColor1;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FLinearColor SceneModulationColor2;

};

USTRUCT()
struct FFortHighlightColorsContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Highlight")
	FFortHighlightColors ValidHighlight;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FFortHighlightColors InvalidHighlight;

	UPROPERTY(EditAnywhere, Category="Highlight", meta=(GetOptions="FortniteGame.FortGameData.GetHighlightParamProfileNames"))
	FName ParamProfileName;

};

USTRUCT()
struct FFortHighlightParamProfile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Highlight")
	FName UniqueProfileName;

	UPROPERTY(EditAnywhere, Category="Highlight", meta=(GetOptions="FortniteGame.FortGameData.GetHighlightStencilParamNames"))
	FName StencilParamName;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FName OutlineColorParamName;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FName SceneModulationColorOneParamName;

	UPROPERTY(EditAnywhere, Category="Highlight")
	FName SceneModulationColorTwoParamName;

};

USTRUCT()
struct FSettingsHUDVisibilityAndText
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	FGameplayTag HUDVisibilityGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	ESlateVisibility DefaultHUDVisibility;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText DisplayText;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText TooltipText;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	bool bPlatformConstraintPC;

};

USTRUCT(BlueprintType)
struct FSubGameInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SubGameInfo")
	TObjectPtr<UFortTokenType> AccessToken;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SubGameInfo")
	bool RequiredFullInstall;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SubGameInfo")
	bool bCanPartyWithoutFullInstall;

};

USTRUCT()
struct FTagQueryTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TagQuery")
	FGameplayTagQuery TagQuery;

};

UCLASS(Config=Game, MinimalAPI)
class UFortGameData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static TArray<FName> GetHighlightParamProfileNames();

	UFUNCTION()
	static TArray<FName> GetHighlightStencilParamNames();

	UPROPERTY(EditAnywhere, Category="PickupVisuals")
	float PickupSplineOffsetRange[2];

	UPROPERTY(EditAnywhere, Category="PickupVisuals")
	float PickupSplineRandomMax;

	UPROPERTY(EditAnywhere, Category="PickupVisuals")
	float PickupSplineDropToGroundLength;

	UPROPERTY(EditAnywhere, Category="PickupVisuals")
	float PickupMaxCollectionTime;

	UPROPERTY(EditAnywhere, Category="PickupVisuals")
	float PickupMaxDelayPerItem;

	UPROPERTY(VisibleAnywhere, Config, Category="Pickup")
	TArray<FName> ExclusivePickupGroupTagsDenyList;

	UPROPERTY(EditAnywhere, Category="QuickBar")
	FGameplayTagContainer AutoEquipTagContainer;

	UPROPERTY(EditAnywhere, Category="Effects")
	FLinearColor BuildingFullHealthFlashColor;

	UPROPERTY(EditAnywhere, Category="Effects")
	FLinearColor InvalidEditPatternColor;

	UPROPERTY(EditAnywhere, Category="Effects")
	TArray<FFortHighlightParamProfile> HighlightParamProfiles;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EBuildingHighlightType"))
	FFortHighlightColorsContainer HighlightColors[5];

	UPROPERTY(EditDefaultsOnly, Category="Mobile Interaction")
	FVector MobileInteractionIconScale;

	UPROPERTY(EditDefaultsOnly, Category="Mobile Interaction", meta=(ArraySizeEnum="/Script/FortniteGame.EFortRarity"))
	FLinearColor MobileRarityColor[8];

	UPROPERTY(EditAnywhere, Category="Combat")
	FCurveTableRowHandle CritRatingTable;

	UPROPERTY(EditAnywhere, Category="Combat")
	FCurveTableRowHandle ArmorToDamageResistanceTable;

	UPROPERTY(EditAnywhere, Category="LootData")
	float DefaultLootInstancingRange;

	UPROPERTY(EditAnywhere, Category="Quests")
	TArray<FFortQuestPackInfo> QuestPackInfos;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer DamageDoneTargetQuest_AllowedTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	FGameplayTagContainer DamageDoneQuest_AllowedTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	TArray<FDamageDistanceTagEval> DamageDoneQuest_DistanceTags;

	UPROPERTY(EditAnywhere, Category="Quests")
	TObjectPtr<UFortQuestIndicatorData> QuestIndicatorData;

	UPROPERTY(EditAnywhere, Category="SeasonItems")
	TObjectPtr<UFortSeasonItemIndicatorData> SeasonItemIndicatorData;

	UPROPERTY(EditAnywhere, Category="Mcp")
	FOnlineAccountTexts OnlineAccountTexts;

	UPROPERTY(EditAnywhere, Category="Mcp")
	TArray<FName> ServerOnlyAssetTypes;

	UPROPERTY(EditAnywhere, Category="Inventory")
	TObjectPtr<UFortLockerConfig> BaseLockerConfig;

	UPROPERTY(EditAnywhere, Category="Inventory")
	TMap<ESubGame, TObjectPtr<UFortLockerConfig>> LockerConfigSubGameOverrides;

	UPROPERTY(EditAnywhere, Category="LoadingScreen")
	TSoftObjectPtr<UFortLoadingConfig> LoadingConfig;

private:
	UPROPERTY(EditAnywhere, Category="Vehicle")
	int32 VehicleDepthStencilValue;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	int32 VehicleDepthStencilValueForHighlightedVehicle;

	UPROPERTY(EditAnywhere, Category="Vehicle")
	FGameplayTag VehicleGameplayTag;

	UPROPERTY(EditAnywhere, Category="Camera", meta=(AssetBundles="Client, Server"))
	TSoftClassPtr<APlayerCameraManager> DefaultCameraManager;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortAnalyticsData> AnalyticsData;

	UPROPERTY(EditAnywhere, Category="FortGameData", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortGameplayTagData> GameplayTagData;

	UPROPERTY(EditAnywhere, Category="FortGameData", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortGameplayEffectData> GameplayEffectData;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortTooltipMap> ObjClassToTooltipClassMap;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortTokenToTextTable> TooltipTokenToTextTable;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortTokenToAttributeTable> TooltipTokenToAttributeTable;

	UPROPERTY(EditAnywhere, Category="PickupVisuals", meta=(ClampMax="90.000000", ClampMin="0.100000", UIMax="90.000000", UIMin="0.100000"))
	float AutoPickupViewAngle;

	UPROPERTY(EditAnywhere, Category="PickupVisuals", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UCurveVector> PickupSplineCurve;

	UPROPERTY(EditAnywhere, Category="PickupVisuals", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<USoundBase> PickupLandedSound;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortRarityData> RarityData;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemCategory> ItemCategories;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortAppActivationSoundMixManager> AppActivationSoundMixManager;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<USoundMix> LoadingScreenSoundMix;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<USoundMix> BaseSoundMix;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<AFortGlobalAbilityTargetingActor> AbilityTargetingActorBlueprintClass;

	UPROPERTY(meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> DefaultCooldownGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="Mobile Interaction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> MobileInteractionMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Mobile Interaction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UStaticMesh> MobileInteractionMesh;

	UPROPERTY(EditDefaultsOnly, Category="Mobile Interaction", meta=(ArraySizeEnum="/Script/FortniteGame.EMobileInteractionIconTypes", AssetBundles="Client,Server"))
	TSoftObjectPtr<UTexture2D> MobileInteractionIcons[4];

	UPROPERTY(EditAnywhere, Category="Sound Indicator")
	TSubclassOf<UFortSoundIndicatorComponent> DoorSoundIndicatorClass;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="PlacementActors")
	TArray<TSoftClassPtr<UFortPlacementActorTagTest>> PlacementTagTests;
#endif

	UPROPERTY(EditAnywhere, Category="SubGames")
	FSubGameInfo SubGameInfo[2];

	UPROPERTY(EditDefaultsOnly, Category="PlacementActors", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer PlacementActorUsedTags;

	UPROPERTY(EditAnywhere, Category="Announcements", meta=(ArraySizeEnum="/Script/FortniteGame.EFortAnnouncementChannel"))
	float QueuedAnnouncementPauseTimes[3];

	UPROPERTY(EditAnywhere, Category="Balance")
	FCurveTableRowHandle WeakSpotEnabledTimeoutHandle;

	UPROPERTY(EditAnywhere, Category="Balance")
	float BuildingRetestSupportedByWorldDelay;

	UPROPERTY(EditAnywhere, Category="Balance")
	float BuildingStructuralCollapseDelay;

	UPROPERTY(EditAnywhere, Category="Balance")
	float BuildingStructuralCollapseDelayVariance;

	UPROPERTY(EditAnywhere, Category="Balance")
	float BuildingStructuralCollapseCellDistAdditiveDelay;

	UPROPERTY(EditAnywhere, Category="Balance")
	float BuildingStructuralCollapseCellDistAdditiveDelayVariance;

	UPROPERTY(EditAnywhere, Category="Balance")
	float EditModeCancelDistance;

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingCostHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingDeconCostMultHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle PlayerBuildingDeconCostMultHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingInitialHealthPercentHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle AthenaBuildingInitialHealthPercentHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle AthenaBuildingDropPercentHandles[6];

	UPROPERTY(EditAnywhere, Category="Balance", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingRepairCostMultiplierHandles[6];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingBreakAnimDurationHandles[6];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingDestroyAnimDurationHandles[6];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingPlacementAnimDurationHandles[6];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingCritDamagePctHandles[6];

	UPROPERTY(EditAnywhere, Category="Effects", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FCurveTableRowHandle BuildingCritDestroyAnimScaleCapHandles[6];

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortBuildingAudioBank> BuildingAudioBank;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialParameterCollection> StencilDefinitionCollection;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FText ResourceNames[6];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortBuildingType"))
	FText BuildingTypeNames[12];

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(ClampMin="1", UIMin="1"))
	uint32 LowOnBuildingResourcesWarningThreshold;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortResourceItemDefinition> StoneItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortResourceItemDefinition> WoodItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortResourceItemDefinition> MetalItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortResourceItemDefinition> GoldCurrencyItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAmmoItemDefinition> PistolAmmoItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortResourceItemDefinition> PermaniteItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAmmoItemDefinition> ShotgunAmmoItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAmmoItemDefinition> RifleAmmoItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAmmoItemDefinition> AssaultAmmoItemDefinition;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAmmoItemDefinition> EnergyAmmoItemDefinition;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortInputData> FortInputData;

	UPROPERTY(EditAnywhere, Category="Missions", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortMissionGenerationData> MissionGenerationData;

	UPROPERTY(EditAnywhere, Category="Missions", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortMissionCSVEventMap> MissionCSVEventMap;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortPreferredItemSlotSettings> PreferredItemSlotSettings;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortGamepadSettings> GamepadSettingsDefault;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortGamepadSettings> GamepadSettingsSony;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortGamepadSettings> GamepadSettingsXboxOne;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortGamepadSettings> GamepadSettingsSwitch;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortGamepadSettingsV2> GamepadSettingsV2;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortTouchInputSettings> TouchInputSettings;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TMap<ECommonInputType, TObjectPtr<UTexture2D>> InputTypeIcons;

	UPROPERTY(EditDefaultsOnly, Category="Persistence", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UPersistenceFrameworkSettings> PersistenceFrameworkSettings;

	UPROPERTY(EditAnywhere, Category="LootData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> LootQuotaData;

	UPROPERTY(EditAnywhere, Category="LootData", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> LootLevelData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Calendar Events")
	TSoftObjectPtr<UDataTable> CalendarEventInventoryTransforms;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Catalog")
	TSoftObjectPtr<UDataTable> MtxCurrenciesDataTable;
#endif

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Team", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortTeamIdentification> TeamIdentifications[255];

	UPROPERTY()
	FDataRegistryType SurfaceRatioByAffiliationRegistryType;

	UPROPERTY()
	FDataRegistryType SurfaceRatioBySurfaceCategoryRegistryType;

	UPROPERTY(EditDefaultsOnly, Category="Team", meta=(AssetBundles="Client,Server"))
	TArray<TSoftClassPtr<UFortMinigameTeamIdentification>> MinigameTeamIdentifications;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> StatNamesToTrackTable;

	UPROPERTY(EditAnywhere, Category="AttributeLookup", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortAttributeLookupTable> AttributeLookupTable;

	UPROPERTY(EditAnywhere, Category="AttributeLookup", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortAttributeCategory> AttributeCategories;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(AssetBundles="Client"))
	TSoftClassPtr<AFortDamageNumbersActor> DamageNumbersActorClass;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(AssetBundles="Client"))
	TSoftClassPtr<ABuildingWeakSpot> WeakSpotBlueprintClass;

	UPROPERTY(EditAnywhere, Category="PhysicsMaterials", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UPhysicalMaterial> WeakSpotWoodPhysicalMaterial;

	UPROPERTY(EditAnywhere, Category="PhysicsMaterials", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UPhysicalMaterial> WeakSpotStonePhysicalMaterial;

	UPROPERTY(EditAnywhere, Category="PhysicsMaterials", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UPhysicalMaterial> WeakSpotMetalPhysicalMaterial;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortTagUIDataLookupTable> UITagDataTable;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(AssetBundles="Client"))
	TSoftClassPtr<AFortPickupEffect> PickupEffectBlueprintClass;

	UPROPERTY(EditAnywhere, Category="Gameplay Tag Tables", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UGameplayTagTableManager> TagTableManager;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortEditToolItemDefinition> EditToolItem;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<AFortWeap_BuildingTool> BuildingToolClass;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<AFortWeap_EditingTool> EditToolClass;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAbilitySet> GenericTrapAbilitySet;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAbilitySet> GenericVehicleAbilitySet;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAbilityTagRelationshipMapping> AbilityTagRelationshipMapping;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortWeaponRechargeAmmoItemMapping> WeaponRechargeAmmoItemMapping;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortDeathCauseFromTagMapping> FortDeathCauseFromTagMapping;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortDeathCauseData> FortDeathCauseData;

	UPROPERTY(Transient)
	TObjectPtr<UFortDeathCauseData> CompositeDeathCauseData;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortSurfaceTypeToSurfaceTypeTagMapping> SurfaceTypeToSurfaceTypeTagMapping;

	UPROPERTY(EditAnywhere, Category="Meta", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortBakedPropertyMetadataCache> BakedPropertyMetadata;

	UPROPERTY(EditAnywhere, Category="Environment", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> EnvironmentDamageTemplateGE;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> FallingDamageTemplateGE;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> VehicleImpactDamageTemplateGE;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> HealingTemplateGE;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> FatalDamageTemplateGE;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortUINotification> BasicNotificationClass;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortUINotification> FriendNotificationClass;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortUINotification> BattlePassPageUnlockNotificationClass;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftClassPtr<AFortClientAnnouncement_ZoneModifiers> ZoneModifiersAnnouncementClass;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> HealthScreenDamagePostProcessMat;

	UPROPERTY(EditAnywhere, Category="UI")
	FScalableFloat bShowTrapInfoUiInAthena;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortMarkerDetailsTable> MarkerDetailsTable;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UParticleSystem> FallbackDeathParticles;

	UPROPERTY(EditAnywhere, Category="FortGameData")
	TSoftObjectPtr<UParticleSystem> MobileOverrideDeathParticles;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UParticleSystem> WallFallbackDeathParticles;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UParticleSystem> FallbackConstructedEffect;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UParticleSystem> RepairEffect;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<USoundBase> ConstructionCompleteSound;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> DamageMaterial;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> BounceCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> BlueprintParentMaterial;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> EditCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveVector> BlueprintDamageCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> FullHealthAnimCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> RepairAnimCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> DynamicLODEffectCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> InteractFullBounceCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> InteractFullBounceNormalCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> InteractEmptyBounceCurve;

	UPROPERTY(Transient, meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveFloat> InteractEmptyBounceNormalCurve;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> DynamicDestructionMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction")
	FDynamicDestructionParamNamesConfig DynamicDestructionParamNamesConfig;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction")
	FDynamicDestructionConfig DynamicDestructionConfig;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UNiagaraSystem> DynamicDestructionNiagaraSystem;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float ConversationSoundRange;

	UPROPERTY(EditAnywhere, Category="FrontEnd")
	TSoftObjectPtr<UWorld> DefaultLobbyBackgroundLevel;

	UPROPERTY(EditAnywhere, Category="Physics Objects", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortPhysicsObjectAssetSetupData> PhysicsObjectAssetSetupData;

	UPROPERTY(EditAnywhere, Category="Physics Objects", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> PhysicsObjectImpactDamageTemplateGE;

	UPROPERTY(EditAnywhere, Category="Physics Objects", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<AFortPhysicsObjectManager> PhysicsObjectManagerClass;

	UPROPERTY(EditAnywhere, Category="Physics Objects", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortPhysicsCollisionHandler> PhysicsCollisionHandlerClass;

};

