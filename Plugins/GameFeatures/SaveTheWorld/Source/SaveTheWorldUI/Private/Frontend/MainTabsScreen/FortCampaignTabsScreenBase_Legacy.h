// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "Feature/FortUIFeature.h"
#include "FortCampaignTabsScreenBase_Legacy.generated.h"

class UCommonButtonBase;
class UFortTabListWidgetBase_Legacy;
class UHorizontalBox;
enum class EFortUIFeature : uint8;
enum class EFortUIFeatureState : uint8;
enum class EFortUIFeatureStateReason : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortCampaignTabsScreenBase_Legacy : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ConstructTabs();

	UFUNCTION()
	void HandleFeatureNavigateRequest(EFortUIFeature Feature);

	UFUNCTION()
	void HandleFeatureStateChanged(EFortUIFeature ChangedFeature, EFortUIFeatureState NewState, EFortUIFeatureStateReason Reason);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMainTabCreated(FName TabNameId, UCommonButtonBase* TabButton);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMainTabSelected(FName TabNameId);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Main Tabs Screen")
	TMap<EFortUIFeature, FName> FeaturesTabsMap;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignTabsScreenBase_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> TopTabContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignTabsScreenBase_Legacy", meta=(EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TopTabList;

	UPROPERTY(EditAnywhere, Category="Main Tabs Screen")
	TSubclassOf<UFortTabListWidgetBase_Legacy> MainTabSet;

};

