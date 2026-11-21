// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Feature/FortUIFeature.h"
#include "FortCampaignTabsScreenBase.generated.h"

class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UFortTabListWidgetBase;
class UHorizontalBox;
enum class EFortUIFeature : uint8;
enum class EFortUIFeatureState : uint8;
enum class EFortUIFeatureStateReason : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortCampaignTabsScreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ConstructTabs();

	UFUNCTION()
	void HandleFeatureStateChanged(EFortUIFeature ChangedFeature, EFortUIFeatureState NewState, EFortUIFeatureStateReason Reason);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMainTabCreated(FName TabNameId, UCommonButtonBase* TabButton);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMainTabSelected(FName TabNameId);

	UFUNCTION(BlueprintPure)
	bool ShouldShowItemShopBang() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateItemShopButtonBang(const FName Tab);

	UPROPERTY(EditAnywhere, Category="Main Tabs Screen")
	TMap<EFortUIFeature, FName> FeaturesTabsMap;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignTabsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> TopTabContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignTabsScreenBase", meta=(EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase> TopTabList;

	UPROPERTY(EditAnywhere, Category="Main Tabs Screen")
	TSubclassOf<UFortTabListWidgetBase> MainTabSet;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_TabContent;

};

