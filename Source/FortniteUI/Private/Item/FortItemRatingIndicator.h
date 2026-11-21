// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMultiSize.h"
#include "FortUITypes.h"
#include "FortItemRatingIndicator.generated.h"

class IFortItemViewContextInterface;
class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemRatingIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetItemToCompareWith(const UFortItem* ItemToCompareWith);

	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable)
	void SetItemViewContext(TScriptInterface<IFortItemViewContextInterface> ItemViewContext);

	UPROPERTY(BlueprintReadOnly, Category="FortItemRatingIndicator")
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(BlueprintReadOnly, Category="FortItemRatingIndicator")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleViewModelChanged();

	UPROPERTY(BlueprintReadOnly, Category="View Model")
	FFortMultiSizeBrush RatingTypeIcon;

	UPROPERTY(BlueprintReadOnly, Category="View Model")
	int32 RatingValue;

	UPROPERTY(BlueprintReadOnly, Category="View Model")
	EFortBuffState ComparisonResult;

	UPROPERTY(BlueprintReadOnly, Category="View Model")
	bool ShouldAppearEnchanted;

};

