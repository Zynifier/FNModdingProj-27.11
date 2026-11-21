// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCollectionBookWidget_Legacy.generated.h"

class UCommonWidgetSwitcherLegacy;
class UFortCollectionBookPage;
class UFortCollectionBookPrimaryPanel_Legacy;
class UFortCollectionBookProgressWidget;
class UFortCollectionBookSection;
class UFortCollectionBookSectionPanel;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookWidget_Legacy : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookPageClicked(const UFortCollectionBookPage* ClickedPage);

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookPageSelected(const UFortCollectionBookPage* SelectedPage);

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookSectionClicked(const UFortCollectionBookSection* ClickedSection);

protected:
	UFUNCTION()
	void OnCollectionBookSectionCloseRequest();

	UFUNCTION()
	void OnPreviewXPChangeRequest(int32 XPChange);

	UFUNCTION(BlueprintCallable)
	void RequestToClose();

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookProgressWidget> ProgressWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> MainWidgetSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookPrimaryPanel_Legacy> PrimaryPanelWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookSectionPanel> SectionPanelWidget;

	UPROPERTY(Transient)
	int32 PrimaryPanelIdx;

	UPROPERTY(Transient)
	int32 SectionPanelIdx;

};

