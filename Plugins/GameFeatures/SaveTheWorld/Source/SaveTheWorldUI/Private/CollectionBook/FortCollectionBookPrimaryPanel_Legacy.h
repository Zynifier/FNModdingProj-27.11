// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "CollectionBook/FortCollectionBookPrimaryPanel.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortCollectionBookPrimaryPanel_Legacy.generated.h"

class UCommonTileView;
class UFortCollectionBookOverviewWidget;
class UFortCollectionBookPage;
class UFortCollectionBookSection;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookPrimaryPanel_Legacy : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnBackActionExecuted(bool& bPassThrough);

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnBookPageSelected OnCollectionBookPageSelectedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnBookPageClicked OnCollectionBookPageClickedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnBookSectionClicked OnCollectionBookSectionClickedDelegate;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookPageClicked(const UFortCollectionBookPage* ClickedPage);

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookPageSelected(const UFortCollectionBookPage* SelectedPage);

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnCollectionBookSectionClicked(const UFortCollectionBookSection* ClickedSection);

	UFUNCTION()
	void OnInputMethodChanged(ECommonInputType CurrentInputType);

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnSummonInfoPanelExecuted(bool& bPassThrough);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SummonInfoPanelActionRowHandle;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookOverviewWidget> OverviewWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> SectionTileViewWidget;

	UPROPERTY(Transient)
	ECollectionBookPrimaryNavTarget CurrentNavTarget;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookSection> LastClickedSection;

};

