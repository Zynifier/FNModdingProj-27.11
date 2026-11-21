// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassCrewContentInterface.h"
#include "Common/CMSBackgroundWidget.h"
#include "BattlePassPurchaseScreen.generated.h"

class UBattlePassCrewPurchaseButton;
class UBattlePassSeasonHeading;
class UCommonActivatableWidget;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
enum class EBattlePassPurchaseState : uint8;

UENUM(BlueprintType)
enum class EBattlePassPurchaseState : uint8
{
	Purchase = 0,
	Confirm = 1,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBattlePassPurchaseScreen : public UCMSBackgroundWidget, public IBattlePassCrewContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchaseConfirmed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchaseStateChanged(EBattlePassPurchaseState InCurrentState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetNavButtonNotificationText(const FText& NotificationText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetScreenInteractable(bool bInteractable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowNavButtonNotification(const bool bShowNotification);

	UFUNCTION(BlueprintCallable)
	void RefreshFocus();

private:
	UPROPERTY(EditDefaultsOnly, Category="BattlePassPurchaseScreen")
	float CrewTransitionDelayTime;

	UPROPERTY(EditAnywhere, Category="BattlePassPurchaseScreen")
	TSubclassOf<UCommonActivatableWidget> PurchaseCompleteModal;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ToCrew;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_Purchase;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GiftBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_ConfirmBase;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_ConfirmBundle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassSeasonHeading> Heading_Primary;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassSeasonHeading> Heading_Secondary;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Disclaimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_PurchaseState;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBattlePassSeasonHeading : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Season;

};

