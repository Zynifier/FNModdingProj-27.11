// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Timespan.h"
#include "SeasonPass/BattlePassScreenBase.h"
#include "SeasonPass/BattlePassTypes.h"
#include "BattlePassScreenS27.generated.h"

class UAthenaExclusiveRewardBanner;
class UAthenaLoadingScreenPreviewPanel;
class UAthenaRewardItemTypeRarityTag;
class UAthenaSeasonItemData_BattleStar;
class UAthenaSeasonItemEntryBase;
class UBorder;
class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortBattlePassPurchaseResourcesWidget;
class UFortBattlePassResourcesWidgetBase;
class UFortBattlePassTutorialTooltipS27;
class UFortCTAButton;
class UFortItemDefinition;
class UFortPersistentResourceItemDefinition;
class UFortSwipePanel;
class UWidget;
class UWidgetSwitcher;
enum class EBattlePassCurrencyType : uint8;
enum class EBattlePassRewardPrerequisiteType : uint8;
enum class EBattlePassStatusBarTypeS27 : uint8;
enum class ERewardWarningTooltipType27 : uint8;

UENUM(BlueprintType)
enum class EBattlePassStatusBarTypeS27 : uint8
{
	Hidden = 0,
	Prerequisite = 1,
	Delayed = 2,
	Unclaimable = 3,
	Claimable = 4,
	Special = 5,
	Owned = 6,
};

UENUM(BlueprintType)
enum class ECustomizationCategory : uint8
{
	Rewards = 0,
	Patterns = 1,
	Banners = 2,
	Max = 3,
};

UENUM(BlueprintType)
enum class ERewardWarningTooltipType27 : uint8
{
	None = 0,
	Custom = 1,
	AgeGating = 2,
	Sparks = 3,
	DelMar = 4,
	Juno = 5,
	Max = 6,
};

USTRUCT(BlueprintType)
struct FCustomizationRewardInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 OwnedRewards;

	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 TotalRewards;

	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 CompletedPatterns;

	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 TotalPatterns;

	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 CompletedBanners;

	UPROPERTY(BlueprintReadWrite, Category="Customization Rewards")
	int32 TotalBanners;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UBattlePassScreenS27 : public UBattlePassScreenBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void GoBackOneScreen();

	UFUNCTION(BlueprintCallable)
	void HandleSwitcherVisibilityShown();

	UFUNCTION(BlueprintCallable)
	void OverviewShowAnimationFinished();

protected:
	UFUNCTION(BlueprintPure)
	FTimespan GetQuestPageDelay() const;

	UFUNCTION(BlueprintPure)
	bool IsSeasonalCustomizationItemOwned() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassGiftingAllowed(const bool bGiftingAllowed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassOwned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInsufficientFunds(const EBattlePassCurrencyType CurrencyType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInsufficientResource(const UFortPersistentResourceItemDefinition* PersistentResource);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemDelayed(const FTimespan Delay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetBaseRewardsInfo(const int32 OwnedRewards, const int32 TotalRewards, const int32 CompletedPages, const int32 TotalPages);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetBonusRewardsInfo(const bool bIsUnlocked, const int32 OwnedRewards, const int32 TotalRewards, const int32 CompletedPages, const int32 TotalPages, const int32 ClaimedOutfits, const int32 TotalOutfits);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCoverPageData(const FText& Title, const FText& Description, const bool bPageComplete);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCrewInfo(bool bIsNextMonthRewards, const FText& MonthText, const FTimespan& NextMonthlyRewardTimespan, const FText& CharacterDisplayName, const FText& CharacterDescription);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCustomizationRewardsInfo(const FTimespan& DelayTimespan, const FCustomizationRewardInfo& RewardInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetItemPrice(const int32 Cost, const EBattlePassCurrencyType CurrencyType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPrerequisiteInfo(const FText& Description, const int32 CurrentAmount, const int32 NeededAmount, EBattlePassRewardPrerequisiteType PrerequisiteType, const bool bShowPrerequisiteLock);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetQuestRewardsInfo(const FTimespan& DelayTimespan, const int32 OwnedRewards, const int32 TotalRewards, const int32 CompletedPages, const int32 TotalPages);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetResourcePrice(const int32 Cost, const UFortPersistentResourceItemDefinition* PersistentResource);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetWarningToolTip(const ERewardWarningTooltipType27& WarningTooltipType, const FText& Description);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetWeeklyRewardsInfo(const FTimespan& DelayTimespan, const int32 AvailableRewards, const int32 OwnedRewards, const int32 TotalRewards, const int32 AvailablePages, const int32 CompletedPages, const int32 TotalPages);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionItemDetails(const bool bTransitionForward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateBattlePassRequiredBar(const bool bPassRequiredVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateStatusBar(const FText& StatusText, const EBattlePassStatusBarTypeS27& BarType);

	UPROPERTY(EditAnywhere, Category="Purchase Resources")
	TSubclassOf<UFortBattlePassPurchaseResourcesWidget> ResourcePurchaseScreenClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TouchClose;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ToggleViewDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ReplayTrailer;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ReplayTrailer_Mobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowAbout;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowAbout_Mobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowAboutCustomization;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowAboutCustomization_Mobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BulkBuyRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageComplete;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GiftBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_PlatformBasedButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassResourcesWidgetBase> BattlePassCurrencyPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaExclusiveRewardBanner> AthenaExclusiveRewardBanner;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaRewardItemTypeRarityTag> ItemRewardTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SetDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_PrerequisiteInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Prerequisite;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_PrerequisiteProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_LevelUpMessageFree;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_LevelUpMessagePremium;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_CustomResourceMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_PrimaryAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_BuyLevels;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_BuyBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_ClaimReward;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewQuests;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviewLoadingScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_RequiresBP;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_PageLocked;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_BaseItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_Prerequisite;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_CompletePage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_NotEnough_Currency;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_Cost;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_Owned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Tag_Delayed;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenS27")
	FGameplayTag QuestCategoryParentTag;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenS27")
	TSubclassOf<UAthenaLoadingScreenPreviewPanel> PreviewLoadingScreenWidgetClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_BattleStar> SeasonData_BattleStar;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemEntryBase> CurrentSelectedEntry;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenS27")
	TObjectPtr<UFortItemDefinition> SeasonalBaseCustomizationItem;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassScreenS27")
	bool bHasSubscription;

private:
	UFUNCTION()
	void HandleClaimRewardComplete(const bool bSuccess, const TArray<FString>& OfferTemplateIdList);

	UFUNCTION()
	void HandleFullscreenMapToggled(bool bMapVisible);

	UPROPERTY(EditAnywhere, Category="BattlePassScreenS27")
	TArray<EBattlePassView> SwitcherSubPageTypes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_SubPage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltipS27> TutorialTooltip_BattleStars;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltipS27> TutorialTooltip_StylePoints;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_Navigation;

};

