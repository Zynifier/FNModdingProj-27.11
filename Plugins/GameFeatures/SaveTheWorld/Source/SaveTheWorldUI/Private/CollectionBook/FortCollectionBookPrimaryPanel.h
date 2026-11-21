// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "FortCollectionBookPrimaryPanel.generated.h"

class UCommonTileView;
class UFortCollectionBookOverviewWidget;
class UFortCollectionBookPage;
class UFortCollectionBookSection;

UENUM()
enum class ECollectionBookPrimaryNavTarget : uint8
{
	Overview = 0,
	SectionTileView = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBookPageClicked, const UFortCollectionBookPage*, ClickedPage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBookPageSelected, const UFortCollectionBookPage*, SelectedPage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBookSectionClicked, const UFortCollectionBookSection*, ClickedSection);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookPrimaryPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnBackActionExecuted();

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

