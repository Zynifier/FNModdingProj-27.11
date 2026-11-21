// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chat/SocialChatChannel.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataAsset.h"
#include "Engine/Scene.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Chat/SocialChatMessageEntry.h"
#include "FortBrushSize.h"
#include "FortUIPickerTrapSortModifier.h"
#include "FortUITypes.h"
#include "ItemCards/FortItemCardConfigurationData.h"
#include "Items/FortItemTypeEnum.h"
#include "FortUIDataConfiguration.generated.h"

class UAthenaBroadcastHUDBase;
class UAthenaChallengeDisplayData;
class UAthenaHUDBase;
class UAthenaItemShopConfiguration;
class UAthenaMatchReadyDesktopPopup;
class UAthenaTeamDisplayData;
class UAthenaUIStateWidget_Frontend;
class UCommonActivatableWidget;
class UCommonTextStyle;
class UDataTable;
class UEnableMultiFactorModal;
class UFortEulaWidget;
class UFortFrontendItemViewSettingsManager;
class UFortItemDefinition;
class UFortItemPairsInspectionScreen;
class UFortItemPresentationDisplayData;
class UFortKeybindWidget;
class UFortMobileHUDLayoutToolV2;
class UFortMultiSizeBrushAsset;
class UFortParentalControls;
class UFortPlayerFeedbackModal;
class UFortPlayerSurveyWidgetBase;
class UFortServerBrowserCreative;
class UFortShowdownDetailView;
class UFortSocialDisplayData;
class UFortSocialPanel;
class UFortStoreDisplayData;
class UFortTeamMemberManage;
class UFortTooltipDisplayStatsLookupTable;
class UFortUIDataProfileStats;
class UFortUIStateWidget_Login;
class UFortUIStateWidget_NUI;
class UFortUIStateWidget_NightNightBase;
class UFortVideoDisplayData;
class UMaterialInterface;
class UObject;
class UPaperSprite;
class USlateBrushAsset;
class USpatialFactionScreen;
class UStartUpUIStateWidget_SubgameSelect;
class UTexture2D;
class UUserWidget;

UENUM()
enum class EFortNamedBundle : uint8
{
	Menu = 0,
	MenuCampaign = 1,
	MenuAthena = 2,
	Zone = 3,
	ZoneCampaign = 4,
	ZoneAthena = 5,
	Client = 6,
	ClientCampaign = 7,
	ClientAthena = 8,
};

USTRUCT()
struct FStateWidgetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="StateWidgetEntry")
	TSoftClassPtr<UFortUIStateWidget_NUI> Class;

	UPROPERTY(EditAnywhere, Category="StateWidgetEntry")
	EFortNamedBundle Bundle;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortUIDataConfiguration : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Icons|Defenders")
	static UFortMultiSizeBrushAsset* GetDefenderSubtypeIconMultiSizeBrushByTag(const FGameplayTag DefenderSubtypeTag);

	UPROPERTY(Config)
	FString DefaultUIDataConfigurationPath;

	UPROPERTY(Config)
	FString DefaultBROnlyUIDataConfigurationPath;

	UPROPERTY(Config)
	FString MobileBROnlyUIDataConfigurationPath;

	UPROPERTY(EditDefaultsOnly, Category="State Widgets", meta=(ArraySizeEnum="/Script/FortniteUI.EFortUIState"))
	FStateWidgetEntry StateWidgetClasses[13];

	UPROPERTY(EditDefaultsOnly, Category="State Widgets")
	FStateWidgetEntry CampaignFrontEndWidget;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UFortUIStateWidget_Login> StartupStateWidget_Login;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="Menu"))
	TSoftClassPtr<UStartUpUIStateWidget_SubgameSelect> StartupStateWidget_SubgameSelect;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UAthenaUIStateWidget_Frontend> AthenaStateWidget_Frontend;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UAthenaUIStateWidget_Frontend> AthenaStateWidget_MobileFrontend;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="MenuAthena"))
	TSoftClassPtr<UFortUIStateWidget_NightNightBase> AthenaStateWidget_NightNightMode;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="ZoneAthena"))
	TSoftClassPtr<UAthenaHUDBase> AthenaStateWidget_HUD;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="ZoneAthena"))
	TSoftClassPtr<UAthenaHUDBase> AthenaStateWidget_MobileHUD;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortMobileHUDLayoutToolV2> HUDLayoutToolV2SoftClass;

	UPROPERTY(EditDefaultsOnly, Category="New State Widgets", meta=(AssetBundles="ZoneAthena"))
	TSoftClassPtr<UAthenaBroadcastHUDBase> AthenaStateWidget_Replay;

	UPROPERTY(EditAnywhere, Config, Category="Matchmaking Widgets", meta=(AssetBundles="Matchmaking"))
	TSoftClassPtr<UEnableMultiFactorModal> MFA_ModalClass;

	UPROPERTY(EditAnywhere, Config, Category="Matchmaking Widgets", meta=(AssetBundles="Matchmaking"))
	TSoftClassPtr<UFortEulaWidget> EulaClass;

	UPROPERTY(EditAnywhere, Config, Category="Matchmaking Widgets", meta=(AssetBundles="Matchmaking"))
	TSoftClassPtr<USpatialFactionScreen> FactionScreenSoftClassRef;

	UPROPERTY(EditAnywhere, Config, Category="Matchmaking Widgets", meta=(AssetBundles="Matchmaking"))
	TSoftClassPtr<UFortServerBrowserCreative> CreativeServerBrowserSoftClassRef;

	UPROPERTY(EditAnywhere, Config, Category="Matchmaking Widgets", meta=(AssetBundles="Matchmaking"))
	TSoftClassPtr<UFortShowdownDetailView> RegionLockMessageWidgetClass;

	UPROPERTY(EditAnywhere, Config, Category="Parental Controls Widgets", meta=(AssetBundles="ParentalControls"))
	TSoftClassPtr<UFortParentalControls> ParentalControlsWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Miscellaneous")
	TMap<TEnumAsByte<EFortBrushSize::Type>, int32> StandardImageBrushSizes;

	UPROPERTY(EditDefaultsOnly, Category="Power Rating", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> PowerRatingIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Power Rating")
	FLinearColor PowerRatingEnchantedPositiveColorOverride;

	UPROPERTY(EditDefaultsOnly, Category="Power Rating")
	FLinearColor PowerRatingEnchantedNegativeColorOverride;

	UPROPERTY(EditDefaultsOnly, Category="Tier Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> FilledTierPipMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Tier Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> UnfilledTierPipMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Tier Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> PreviewingTierPipMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Tier Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> PromotedTierPipMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Upgrade Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> UpgradeArrowMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Comparison Result Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ComparisonUpArrowMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Comparison Result")
	FLinearColor BetterComparisonResultColor;

	UPROPERTY(EditDefaultsOnly, Category="Comparison Result")
	FLinearColor WorseComparisonResultColor;

	UPROPERTY(EditDefaultsOnly, Category="Inventory Overflow Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> InventoryOverflowIndicatorMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Tracked Schematic Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> TrackedSchematicIndicatorMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Favorited Item Indicator", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> FavoritedItemIndicatorMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Athena variant widget map", meta=(AssetBundles="Menu"))
	TMap<TSubclassOf<UObject>, TSoftClassPtr<UUserWidget>> VariantToWidgetMaping;

	UPROPERTY(EditDefaultsOnly, Category="UIManager", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortPlayerSurveyWidgetBase> PlayerSurveyWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Social")
	bool bEnableSocialFeatures;

	UPROPERTY(EditDefaultsOnly, Category="Social")
	bool bEnableChat;

	UPROPERTY(EditDefaultsOnly, Category="Social")
	bool bEnablePartyFeatures;

	UPROPERTY(EditDefaultsOnly, Category="Social")
	TMap<ESocialChannelType, FSocialChatMessageEntryStyle> ChatChannelStyles;

	UPROPERTY(EditDefaultsOnly, Category="Social")
	TSubclassOf<UFortSocialPanel> SocialPanelClass;

	UPROPERTY(EditDefaultsOnly, Category="Team Member Interaction")
	TSubclassOf<UFortTeamMemberManage> TeamMemberManageClass;

	UPROPERTY(EditDefaultsOnly, Category="Squad Slot", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> UnlockedSquadSlotBorderMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Squad Slot", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> LockedSquadSlotBorderMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Squad Slot", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ReadOnlySquadSlotBorderMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> DefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> AssaultDefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> PistolDefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> MeleeDefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> SniperDefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Defenders", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ShotgunDefenderIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Survivors", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> LeadSurvivorIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Survivors", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> SurvivorIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Traps", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> TrapIconMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortKeybindWidget> KeybindWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftClassPtr<UUserWidget> HiddenCursorWidget;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(AssetBundles="Client"))
	TSoftClassPtr<UUserWidget> VirtualCursorWidget;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling", meta=(DisplayName="In-Game DPI Curve", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve UIScaleCurve;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scaling", meta=(DisplayName="Out of game DPI Curve", XAxisName="Resolution", YAxisName="Scale"))
	FRuntimeFloatCurve FrontEndUIScaleCurve;

	UPROPERTY(EditDefaultsOnly, Category="Events", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> EventsStyleDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Competitive", meta=(AssetBundles="MenuAthena"))
	TSoftObjectPtr<UMaterialInterface> DefaultDivisionRoundIcon;

	UPROPERTY(EditDefaultsOnly, Category="Competitive", meta=(AssetBundles="MenuAthena"))
	TMap<int32, TSoftObjectPtr<UMaterialInterface>> DivisionRoundToIcons;

	UPROPERTY(EditDefaultsOnly, Category="Competitive", meta=(AssetBundles="MenuAthena"))
	TMap<int32, TSoftObjectPtr<UMaterialInterface>> DivisionRoundToFancyIcons;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Item Cards|Account Item", meta=(AssetBundles="Client", DisplayName="Item Card Power Rating Text Styles By Brush Size"))
	TMap<TEnumAsByte<EFortBrushSize::Type>, TSubclassOf<UCommonTextStyle>> ItemCardPowerRatingTextStylesByBrushSize;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Item Cards|World Item", meta=(AssetBundles="Client"))
	TMap<TEnumAsByte<EFortBrushSize::Type>, TSubclassOf<UCommonTextStyle>> ItemCardStackCountTextStylesByBrushSize;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Account Item", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> ItemCardLevelMeterMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|World Item", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> ItemCardDurabilityMeterMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards")
	FSlateBrush ItemCardBackgroundPlateBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards")
	FSlateBrush ItemCardRarityGradientBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Defenders")
	FSlateBrush ItemCardDefenderPortraitBackgroundBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Heroes")
	FSlateBrush ItemCardHeroPortraitBackgroundBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Survivors")
	FSlateBrush ItemCardLeadSurvivorPortraitBackgroundBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Schematics")
	FSlateBrush ItemCardSchematicBackgroundBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Traits", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ItemCardRewardTraitsBackgroundMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards|Traits", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ItemCardSchematicTraitsBackgroundMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Athena", meta=(AssetBundles="Client"))
	TSoftClassPtr<UAthenaMatchReadyDesktopPopup> MatchReadyDesktopPopupWidgetType;

	UPROPERTY(EditDefaultsOnly, Category="Main Menu")
	TSoftClassPtr<UFortPlayerFeedbackModal> PlayerFeedbackModalWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rendering")
	bool bLimitedToES2Features;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rendering")
	FWeightedBlendables FrontEndFFPostProcessMaterials;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot Screen")
	bool bUseSpecificPinataWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sound")
	bool bQuestVOEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2")
	TMap<EFortItemCardSize, FVector2D> PersonnelAndSchematicCardSizes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2")
	TMap<EFortItemCardSize, FVector2D> OtherItemCardSizes;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> PersonnelAndSchematicItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> CardPackItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> InstanceItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> TransformKeyItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> CosmeticItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2")
	TArray<EFortItemType> ItemTypesWhoseImagesReplaceCardBackgrounds;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2")
	TSet<EFortItemType> ItemTypesToHideCountWhenCountEqualsOne;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortItemCardSize, TSoftObjectPtr<UMaterialInterface>> ItemCardDetailAreaMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> FavoriteBookmarkMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> PermanentTransformKeykMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMultiSizeBrushAsset> ConsumableTransformKeykMultiSizeBrush;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<FGameplayTag, TSoftObjectPtr<UTexture2D>> DefenderSubtypeWeaponTextures;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortBuffState, TSoftObjectPtr<UMaterialInterface>> EnchantedCustomRatingBlockBackgroundMaterial;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TMap<EFortBuffState, TSoftObjectPtr<UMaterialInterface>> NormalCustomRatingBlockBackgroundMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2")
	FMargin CustomRatingBlockBackgroundBrushMargin;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardDurabilityMeterMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardLevelMeterMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardTraitIconMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardUnearnedTierIconMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardAvailableTierIconMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardEarnedTierIconMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> UniversalItemCardPromotedTierIconMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortItemDefinition> MysteryItemDefinition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UTexture2D> LoadingCardTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXL")
	FFortItemCard_XL_PersonnelAndSchematics_Configuration ItemCardConfig_XXL_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXL")
	FFortItemCard_XL_ItemInstance_Configuration ItemCardConfig_XXL_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXL")
	FFortItemCard_XL_TransformKey_Configuration ItemCardConfig_XXL_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XL")
	FFortItemCard_XL_PersonnelAndSchematics_Configuration ItemCardConfig_XL_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XL")
	FFortItemCard_XL_ItemInstance_Configuration ItemCardConfig_XL_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XL")
	FFortItemCard_XL_TransformKey_Configuration ItemCardConfig_XL_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|L")
	FFortItemCard_L_PersonnelAndSchematics_Configuration ItemCardConfig_L_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|L")
	FFortItemCard_L_ItemInstance_Configuration ItemCardConfig_L_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|L")
	FFortItemCard_L_TransformKey_Configuration ItemCardConfig_L_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|M")
	FFortItemCard_M_PersonnelAndSchematics_Configuration ItemCardConfig_M_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|M")
	FFortItemCard_M_ItemInstance_Configuration ItemCardConfig_M_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|M")
	FFortItemCard_M_TransformKey_Configuration ItemCardConfig_M_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|S")
	FFortItemCard_S_PersonnelAndSchematics_Configuration ItemCardConfig_S_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|S")
	FFortItemCard_S_ItemInstance_Configuration ItemCardConfig_S_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|S")
	FFortItemCard_S_TransformKey_Configuration ItemCardConfig_S_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XS")
	FFortItemCard_XS_PersonnelAndSchematics_Configuration ItemCardConfig_XS_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XS")
	FFortItemCard_XS_ItemInstance_Configuration ItemCardConfig_XS_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XS")
	FFortItemCard_XS_TransformKey_Configuration ItemCardConfig_XS_TransformKey;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXS")
	FFortItemCard_XS_PersonnelAndSchematics_Configuration ItemCardConfig_XXS_PersonnelAndSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXS")
	FFortItemCard_XXS_ItemInstance_Configuration ItemCardConfig_XXS_ItemInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Item Cards V2|XXS")
	FFortItemCard_XS_TransformKey_Configuration ItemCardConfig_XXS_TransformKey;

	UPROPERTY(EditDefaultsOnly, Category="Health Warning", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> HealthyGamingDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Trap Picker", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> TrapPickerGameplayTagSettings;

	UPROPERTY(EditDefaultsOnly, Category="Trap Picker")
	FFortUIPickerTrapSortScores TrapPickerSortScores;

	UPROPERTY(EditDefaultsOnly, Category="Tooltips")
	TObjectPtr<UFortTooltipDisplayStatsLookupTable> ObjClassToTooltipStatsMap;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TSoftClassPtr<UUserWidget> LoadingScreenBacchusTutorialWidget;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen")
	TSoftClassPtr<UUserWidget> LoadingScreenReturnToKairosWidget;

	UPROPERTY(EditDefaultsOnly, Category="LegacyNativeUI", meta=(AssetBundles="Client"))
	TSoftObjectPtr<USlateBrushAsset> ActorCanvasArrowBrush;

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	TSoftObjectPtr<UDataTable> UITutorialData;

	UPROPERTY(EditDefaultsOnly, Category="Pawn Health Bar")
	TSoftObjectPtr<UObject> PawnHealthBarPowerRatingBacking;

	UPROPERTY(EditDefaultsOnly, Category="InspectionScreen")
	TSoftClassPtr<UFortItemPairsInspectionScreen> ItemPairsInspectionScreen;

	UPROPERTY(EditDefaultsOnly, Category="Real Money Purchases", meta=(AssetBundles="MenuAthena, ZoneAthena"))
	TSoftClassPtr<UCommonActivatableWidget> RealMoneyPurchaseSpecialInfoModal;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float AnalogRotateSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float DragRotateSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float TouchSwipeRotateRate;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float MouseWheelZoomSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float DragZoomSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float TriggerZoomSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float TouchZoomPinchRate;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float ItemViewCompetingAxisInputThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	TArray<EFortItemType> ItemTypesToUseVaultCamera;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	TSubclassOf<UFortFrontendItemViewSettingsManager> FrontendItemViewSettingsManager;

	UPROPERTY(EditDefaultsOnly, Category="Picture-in-Picture Test")
	TObjectPtr<UDataTable> PipTest;

protected:
	UPROPERTY(EditDefaultsOnly, Category="DisplayData", meta=(DisplayName="Widget Alisases"))
	TMap<FGameplayTag, TSoftClassPtr<UUserWidget>> WidgetAliasesDefault;

private:
	UPROPERTY(EditDefaultsOnly, Category="Athena Stat Styles", meta=(Categories="GameplayStat.Profile"))
	TArray<TObjectPtr<UFortUIDataProfileStats>> ProfileStatStyleSets;

	UPROPERTY(EditDefaultsOnly, Category="LegacyNativeUI", meta=(AssetBundles="Client"))
	TMap<FName, TSoftObjectPtr<USlateBrushAsset>> LegacyNativeUIBrushMap;

	UPROPERTY(EditDefaultsOnly, Category="LegacyNativeUI", meta=(AssetBundles="Client"))
	TMap<FName, TSoftObjectPtr<UObject>> LegacyNativeUIAssetMap;

	UPROPERTY(EditDefaultsOnly, Category="Item Shop")
	TObjectPtr<UAthenaItemShopConfiguration> ItemShopConfiguration;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UFortVideoDisplayData> VideoDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UFortSocialDisplayData> SocialDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UAthenaChallengeDisplayData> ChallengeDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UAthenaTeamDisplayData> SquadStyleData;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UFortStoreDisplayData> StoreDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="DisplayData")
	TObjectPtr<UFortItemPresentationDisplayData> ItemPresentationDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="Icons|Resources", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	TSoftObjectPtr<UPaperSprite> ResourceSprites[6];

};

