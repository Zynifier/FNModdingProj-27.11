// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortUITypes.h"
#include "UIManager/AthenaFrontendFlowInterruptInterface.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "CrewSubscriptionContentContainer.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonGroupBase;
class UDynamicEntryBox;
class UWidget;

USTRUCT(BlueprintType)
struct FCrewSubscriptionContentTabData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CrewSubscriptionContentTabData")
	FText TabName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CrewSubscriptionContentTabData")
	ESubscriptionContentTab TabType;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCrewSubscriptionContentContainer : public UCommonActivatableWidget, public IFortPrimaryContentInterface, public IAthenaFrontendFlowInterruptInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTabSelected(int32 TabIndex);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess))
	TArray<FCrewSubscriptionContentTabData> TabsData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="AthenaSkewedTabButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Tabs;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess))
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_Tabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSubscriptionContentContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_Tabs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_TabsContainer;

	UPROPERTY(EditDefaultsOnly, Category="CrewSubscriptionContentContainer")
	float SpacingAdjustmentForTabs;

	UPROPERTY()
	FPrimaryContentSetup ContentSetup;

};

