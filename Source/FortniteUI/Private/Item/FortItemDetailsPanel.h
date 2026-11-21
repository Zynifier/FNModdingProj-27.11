// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemDetailsPanel.generated.h"

class UFortItem;
class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Management|Details")
	void SetItemToCompareWith(const UFortItem* ItemToCompareWith);

	UFUNCTION(BlueprintCallable, Category="Item Management|Details")
	void SetItemToDetail(const UFortItem* ItemToDetail);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToCompareSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToDetailSet();

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

private:
	UFUNCTION()
	void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UFUNCTION()
	void HandleItemToCompareWithChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION()
	void HandleItemToDetailChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

};

