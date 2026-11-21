// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widgets/Layout/SScrollBox.h"
#include "FortMPItemShopContent.generated.h"

class UAthenaScrollBox;
class UGridPanel;
class UUserWidget;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMPItemShopContent : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ClearRows();

	UFUNCTION(BlueprintNativeEvent)
	UWidget* GetScrollTarget(UWidget* TargetWidget) const;

	UFUNCTION(BlueprintPure)
	bool HasLoadedRowsForAnimatedScroll(const int32 DestinationIndex, const int32 NumRows) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeRow(UUserWidget* RowWidget, const int32 RowIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScrollComplete(const int32 DestinationIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScrollInput(float ScrollAmount);

	UFUNCTION(BlueprintCallable)
	void ScrollToRowIndex(const int32 DestinationIndex, const int32 NumRows, const bool bRefreshAll = false);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMPItemShopContent", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Content;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMPItemShopContent", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_Content;

	UPROPERTY(EditDefaultsOnly, Category="FortMPItemShopContent")
	TSubclassOf<UUserWidget> RowWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="FortMPItemShopContent")
	EDescendantScrollDestination ScrollDestination;

	UPROPERTY(EditDefaultsOnly, Category="FortMPItemShopContent")
	float ScrollPadding;

	UPROPERTY(EditAnywhere, Category="FortMPItemShopContent", meta=(ClampMin="0"))
	int32 NumRowsVisibleFromCentered;

	UPROPERTY(BlueprintReadOnly, Category="FortMPItemShopContent", meta=(AllowPrivateAccess))
	int32 FirstRowIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortMPItemShopContent", meta=(AllowPrivateAccess))
	int32 CurrentScrolledRowIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMPItemShopContent", meta=(AllowPrivateAccess))
	float TouchScrollThreshold;

};

