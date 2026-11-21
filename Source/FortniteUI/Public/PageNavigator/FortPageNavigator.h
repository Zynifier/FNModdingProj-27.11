// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonButtonBase.h"
#include "Layout/Margin.h"
#include "FortPageNavigator.generated.h"

class UAthenaScrollBox;
class UCommonButtonGroupLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortPageNavigationButton;
class UFortTextButton;
class UVerticalBox;

UCLASS(Abstract)
class UFortPageNavigationButton : public UCommonButtonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPageNavigationButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ButtonLabel;

};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortPageNavigator : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Pages")
	void ClearPages();

	UFUNCTION(BlueprintCallable, Category="Navigation")
	void RequestNextPage();

	UFUNCTION(BlueprintCallable, Category="Navigation")
	void RequestPreviousPage();

	UFUNCTION(BlueprintCallable, Category="Pages")
	void SelectPage(const int32 PageIndex, const bool bSkipAnimation = false, const bool bForceFocusRefresh = false);

protected:
	UFUNCTION()
	void HandleScrollCompleted(float ScrollAmount);

	UFUNCTION()
	void HandleUserScrolled(float ScrollAmount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPipButtonCreated(UFortTextButton* NewPipButton);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scroll")
	bool bEnableRightStickScrolling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Scroll")
	bool bEnableNavigationButtons;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPageNavigator", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPageNavigationButton> Button_Next;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPageNavigator", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPageNavigationButton> Button_Previous;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Pages;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Pages;

	UPROPERTY(EditAnywhere, Category="Scroll")
	bool bEnableSnapScrolling;

	UPROPERTY(EditAnywhere, Category="Scroll")
	float SnapScrollingThreshold;

	UPROPERTY(EditAnywhere, Category="Pages")
	FMargin PagePadding;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PagesPips;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_PagesPips;

};

