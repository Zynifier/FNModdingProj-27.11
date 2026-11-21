// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "FortEventScreenBase.generated.h"

class AFortItemPreviewWorld;
class UAthenaRewardItemTypeRarityTag;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortAccountItemDefinition;
class UFortChallengeBundleItemDefinition;
class UFortEventModalBase;
class UFortEventScreenData;
class UFortEventTrackerModule_CustomText;
class UFortLazyImage;
class UMaterialInstanceDynamic;
class UNamedSlot;
class UPanelWidget;
class UWidget;
enum class EEventScreenView : uint8;

UENUM(BlueprintType)
enum class EEventScreenRewardPreviewType : uint8
{
	None = 0,
	RewardTrack = 1,
	SpecialItem = 2,
	SpecialPremiumItem = 3,
};

UENUM(BlueprintType)
enum class EEventScreenView : uint8
{
	None = 0,
	LandingPage = 1,
	RewardPreview = 2,
	MoreInfo = 3,
	PurchaseLevels = 4,
	PurchasePremiumTrack = 5,
	LoadError = 6,
};

UCLASS(Abstract, MinimalAPI)
class UFortEventScreenBase : public UFortItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortEventModalBase* GetActiveModal() const;

	UFUNCTION(BlueprintPure)
	UMaterialInstanceDynamic* GetVaultWorldBackgroundMID() const;

	UFUNCTION(BlueprintPure)
	UMaterialInstanceDynamic* GetVaultWorldFloorMID() const;

	UFUNCTION(BlueprintPure)
	bool HasAllRewardsCollected() const;

	UFUNCTION(BlueprintPure)
	bool HasPurchasedPremiumTrack() const;

	UFUNCTION(BlueprintPure)
	bool IsCalendarEventActive(const FString& EventName) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCalendarEventEnded(const FString& EventName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCalendarEventStarted(const FString& EventName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFirstViewAfterCompletion();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardPreviewItemChanged(const UFortAccountItemDefinition* Item, const bool bFreeTrack);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardTrackReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnScreenViewChanged(const EEventScreenView PrevScreenView, const EEventScreenView NewScreenView);

	UFUNCTION(BlueprintImplementableEvent)
	void RegisterLayoutSlots();

	UFUNCTION(BlueprintImplementableEvent)
	void SetItemShopCallout(const FText& ItemShopCalloutText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetItemShopOfferInfoVisibility(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetRewardTrackLegal(const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVariantCounter(int32 CurrentVariantIndex, int32 TotalNumVariants);

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortEventScreenBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UNamedSlot>> LayoutTemplateSlots;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_KeyArt;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewQuests;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PurchaseLevels;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Preview;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShowInItemShop;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Previous;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Next;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortEventTrackerModule_CustomText> CustomText_InspectItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_LoadError;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileClose;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SetDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventScreenBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaRewardItemTypeRarityTag> ItemRewardTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Event Data")
	TObjectPtr<UFortEventScreenData> EventScreenData;

	UPROPERTY(BlueprintReadOnly, Category="FortEventScreenBase")
	EEventScreenRewardPreviewType ActiveRewardPreviewType;

	UPROPERTY(Transient)
	TObjectPtr<UFortChallengeBundleItemDefinition> LoadedQuestBundle;

	UPROPERTY(Transient)
	TObjectPtr<AFortItemPreviewWorld> CachedVaultWorld;

private:
	UFUNCTION()
	void HandleActiveSeasonDataChanged(const TArray<FString>& ActiveEventFlags);

	UFUNCTION()
	void HandleGiftBoxClosed();

	UFUNCTION()
	void HandleItemShown(const UFortAccountItemDefinition* AccountItemDef);

	UFUNCTION()
	UWidget* HandleRewardListNavigateRightEvent(EUINavigation InNavigation);

	UFUNCTION()
	UWidget* HandleRewardListNavigateUpEvent(EUINavigation InNavigation);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bVisible);

	UFUNCTION()
	UWidget* HandleUpsellPromptNavigateUpEvent(EUINavigation InNavigation);

	UPROPERTY(EditDefaultsOnly, Category="FortEventScreenBase")
	float TimeBetweenVariantsRestart;

	UPROPERTY(EditDefaultsOnly, Category="FortEventScreenBase")
	float TimeBetweenVariants;

	UPROPERTY(Transient)
	TArray<FFortCosmeticVariantPreview> CachedVariantPreviews;

};

