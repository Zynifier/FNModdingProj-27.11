// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookOverviewWidget.generated.h"

class UCommonTreeView;
class UFortCollectionBookCategory;
class UFortCollectionBookManager;
class UFortCollectionBookPage;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectionBookPageClicked, const UFortCollectionBookPage*, ClickedPage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectionBookPageSelected, const UFortCollectionBookPage*, SelectedPage);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookOverviewWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnActivated();

	UFUNCTION(BlueprintNativeEvent, Category="CollectionBook")
	void OnDeactivated();

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnCollectionBookPageSelected OnCollectionBookPageSelected;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnCollectionBookPageClicked OnCollectionBookPageClicked;

private:
	UFUNCTION()
	void HandlePagesChanged(UFortCollectionBookManager* CBManager);

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookPage> LastSelectedPage;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookCategory> LastSelectedCategory;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCollectionBookCategory>> CategoryObjectPool;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTreeView> PageTreeViewWidget;

};

