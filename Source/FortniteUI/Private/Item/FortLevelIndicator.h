// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortBrushSize.h"
#include "FortLevelIndicator.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;
class UCommonTextStyle;
class UFortItem;

UCLASS(BlueprintType)
class UFortLevelIndicator : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Level Indicator|Comparison")
	void SetItemForComparison(UFortItem* ItemForComparison);

	UFUNCTION(BlueprintCallable, Category="Level Indicator")
	void SetItemToRepresent(UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Level Indicator")
	void SetShouldShowMaximumLevel(bool InShouldShowMaximumLevel);

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator|Comparison")
	TWeakObjectPtr<UFortItem> ItemForComparison;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	bool ShouldShowLabel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	TSubclassOf<UCommonTextStyle> TextStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	bool ShouldShowMaximumLevel;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator", meta=(ExposeOnSpawn))
	int32 MaximumLevel;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator|Comparison")
	bool IsComparingLevels;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level Indicator|Comparison")
	TEnumAsByte<EFortBrushSize::Type> ComparisonResultIndicatorSize;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator|Comparison")
	int32 CurrentLevelForComparison;

	UPROPERTY(BlueprintReadOnly, Category="Level Indicator|Comparison")
	int32 MaximumLevelForComparison;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bStyleNoLongerNeedsConversion;
#endif

private:
	UFUNCTION()
	void HandleItemForComparisonChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION()
	void HandleItemToRepresentChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonTextBlock> LabelTextBlock;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> CurrentLevelNumericTextBlock;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonTextBlock> DivisionOperatorTextBlock;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> MaximumLevelNumericTextBlock;

};

