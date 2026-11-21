// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassCrewContentInterface.h"
#include "Common/CMSBackgroundWidget.h"
#include "CrewScreenContentBlockingInterface.h"
#include "Subscriptions/SubscriptionContentInterface.h"
#include "CrewPurchaseScreen.generated.h"

class UBattlePassCrewPurchaseButton;
class UCommonBorder;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonTextBlock;
class UCrewTileDetails;
class UDynamicEntryBox;
class UFortSubscriptionCancellationModal;
class UFortSubscriptionPlatformModal;
class UOverlay;
class UWidget;
enum class ECrewPurchaseButtonState : uint8;
enum class EMcpSubscriptionState : uint8;

UENUM(BlueprintType)
enum class ECrewPurchaseButtonState : uint8
{
	None = 0,
	Purchase = 1,
	Rejoin = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UCrewPurchaseScreen : public UCMSBackgroundWidget, public IBattlePassCrewContentInterface, public IFortSubscriptionContentInterface, public ICrewScreenContentBlockingInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BeginProgress(const FText& ProgressLabel);

	UFUNCTION(BlueprintImplementableEvent)
	void EndProgress();

	UFUNCTION(BlueprintImplementableEvent)
	void OnContainerTabVisibilityUpdated(const bool bTabsVisible, const float SpacingAdjustmentForTabs);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetNavButtonNotificationText(const FText& NotificationText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPaymentLegalText(const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowNavButtonNotification(const bool bShowNotification);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatePurchaseButtonState(ECrewPurchaseButtonState ButtonState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateVBuckRefundVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUserInformationTextsUpdated(const FText& UserInformationText1, const FText& UserInformationText2, EMcpSubscriptionState SubscriptionState);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="CrewPurchaseScreen")
	bool bManagementModeEnabled;

	UPROPERTY(BlueprintReadWrite, Export, Category="CrewPurchaseScreen", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchasedFocusWidget;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> FocusWidget;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_BenefitsTiles;

	UPROPERTY(EditDefaultsOnly, Category="CrewPurchaseScreen")
	TSoftClassPtr<UFortSubscriptionCancellationModal> CancellationInfoModalClass;

	UPROPERTY(EditDefaultsOnly, Category="CrewPurchaseScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> LegalInfoModalClass;

	UPROPERTY(EditDefaultsOnly, Category="CrewPurchaseScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> ResolveIssueModalClass;

	UPROPERTY(EditDefaultsOnly, Category="CrewPurchaseScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> RejoinModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ToBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_Rejoin;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ResolvePayment;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_WatchTrailer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Terms;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CancellationInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="CrewRewardTile"))
	TObjectPtr<UDynamicEntryBox> EntryBox_RecurringRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="CrewRewardTile"))
	TObjectPtr<UDynamicEntryBox> EntryBox_LimitedTimeRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCrewTileDetails> Details_CurrentCrewTile;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LimitedTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_UserInformation;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UserInformation;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CrewDisclaimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewPurchaseScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Disclaimer;

};

