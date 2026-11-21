// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Types/SlateEnums.h"
#include "Athena/AthenaMapScreenAnalyticsInterface.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "AthenaFullScreenQuestMapPanel.generated.h"

class UAthenaFullScreenMapControlsWidget;
class UAthenaFullScreenMapProductContainer;
class UAthenaFullScreenQuestMapContent;
class UAthenaScrollBox;
class UCommonButtonBase;
class UPanelWidget;
class UWidget;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFrontendQuestMapPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFullScreenQuestMapPanel : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface, public IAthenaMapScreenAnalyticsInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitButtonClicked);

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

	UPROPERTY(BlueprintAssignable)
	FOnExitButtonClicked OnExitButtonClicked;

protected:
	UFUNCTION(BlueprintPure)
	bool IsQuestsTabActive() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateScrollPosition(UWidget* WidgetToScroll);

	UPROPERTY(EditDefaultsOnly, Category="Map")
	float SafeZoneOpacityInterpolationInDuration;

	UPROPERTY(EditDefaultsOnly, Category="Map")
	float SafeZoneOpacityInterpolationOutDuration;

	UPROPERTY(EditDefaultsOnly, Category="Behavior")
	bool bResetSelectionWhenParentDeactivates;

private:
	UFUNCTION()
	void HandleExitPressed();

	UFUNCTION()
	UWidget* HandleQuestMapNavigateLeft(EUINavigation InNavigation);

	UFUNCTION()
	void HandleRequestPrevious();

	UFUNCTION()
	void HandleScrollCompleted(float ScrollAmount);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapControlsWidget> ControlsPanel;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Frontend;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Progression;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapProductContainer> Widget_ProductContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenQuestMapPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenQuestMapContent> Widget_QuestMapContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_ContentRoot;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Previous;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Next;

	UPROPERTY(EditAnywhere, Category="Scroll")
	bool bEnableSnapScrolling;

	UPROPERTY(EditAnywhere, Category="Scroll")
	float SnapScrollingThreshold;

};

