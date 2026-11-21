// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CrewScreenContentBlockingInterface.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "Subscriptions/SubscriptionContentInterface.h"
#include "FortTemporaryItemsScreen.generated.h"

class UCommonButtonBase;
class UFortSubscriptionPlatformModal;
class UFortSubscriptionVM;
class UFortTemporaryItemsRow;
class UFortTemporaryItemsScreenItemInfo;
class UFortTemporaryItemsVM;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTemporaryItemsScreen : public UFortItemPreviewScreen, public IFortSubscriptionContentInterface, public ICrewScreenContentBlockingInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Container Tab Visibility Updated"))
	void BP_OnContainerTabVisibilityUpdated(const bool bTabsVisible, const float SpacingAdjustmentForTabs);

	UFUNCTION(BlueprintPure)
	FText GetRemainingDaysLabel(const UFortTemporaryItemsVM* TemporaryItemsVM) const;

	UFUNCTION(BlueprintImplementableEvent)
	UFortSubscriptionVM* GetSubscriptionVM();

	UFUNCTION(BlueprintCallable)
	void SetupRowEntry(UFortTemporaryItemsRow* RewardRow);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTemporaryItemsScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_CategoryList;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTemporaryItemsScreenItemInfo> Widget_Description;

	UPROPERTY(EditDefaultsOnly, Category="FortTemporaryItemsScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> MoreInfoModalClass;

};

