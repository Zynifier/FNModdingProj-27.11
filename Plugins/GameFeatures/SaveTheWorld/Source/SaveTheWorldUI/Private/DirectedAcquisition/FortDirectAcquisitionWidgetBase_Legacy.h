// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "MtxStore/FortMtxStoreRootBase_Legacy.h"
#include "FortDirectAcquisitionWidgetBase_Legacy.generated.h"

class UFortAccountItemDefinition;
class UGridPanel;
class UHorizontalBox;
class UScaleBox;
class UUserWidget;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"))
class UFortDirectAcquisitionWidgetBase_Legacy : public UFortMtxStoreRootBase_Legacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FDateTime GetDailyStoreEndDate() const;

	UFUNCTION(BlueprintPure)
	FDateTime GetSeasonStoreEndDate() const;

	UFUNCTION(BlueprintPure)
	TArray<UFortAccountItemDefinition*> GetStoreCurrencies() const;

	UFUNCTION(BlueprintPure)
	FDateTime GetWeeklyStoreEndDate() const;

	UFUNCTION(BlueprintCallable)
	void HandleAffiliateButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void IsTabsLayout(bool bShouldDisplayTabs);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayToast(const bool bDisplayToast);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortDirectAcquisitionWidgetBase_Legacy")
	bool bShowIneligible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortDirectAcquisitionWidgetBase_Legacy", meta=(EditInline="true"))
	TObjectPtr<UUserWidget> FirstOfferGenerated;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortDirectAcquisitionWidgetBase_Legacy", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_LargeTile;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortDirectAcquisitionWidgetBase_Legacy", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_SmallTile;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_ReorderedItems;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_FeatureItems;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_DailyItems;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_Main;

};

