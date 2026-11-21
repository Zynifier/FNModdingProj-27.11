// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "Engine/DataTable.h"
#include "UIKitTabGroup.generated.h"

class UCommonButtonBase;
class UUIKitTabGroupButtonViewModel;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UUIKitTabGroup : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UIKit|Tab Group")
	void DeselectAll();

	UFUNCTION(BlueprintPure, Category="UIKit|Tab Group")
	int32 GetSelectedTabIndex() const;

	UFUNCTION(BlueprintPure, Category="UIKit|Tab Group")
	int32 GetTabIndexByID(FName TabNameID) const;

	UFUNCTION(BlueprintPure, Category="UIKit|Tab Group")
	UUIKitTabGroupButtonViewModel* GetTabViewModelByID(FName TabNameID) const;

	UFUNCTION(BlueprintCallable, Category="UIKit|Tab Group")
	void SelectNextTab();

	UFUNCTION(BlueprintCallable, Category="UIKit|Tab Group")
	void SelectPreviousTab();

	UFUNCTION(BlueprintCallable, Category="UIKit|Tab Group")
	bool SelectTabByIndex(int32 Index, bool bSuppressClickFeedback = false);

	UPROPERTY(BlueprintAssignable, Category="UIKit|Tab Group")
	UCommonTabListWidgetBase::FOnTabSelected OnTabClicked;

protected:
	UFUNCTION()
	void HandleTabButtonClicked(UCommonButtonBase* SelectedTabButton, int32 ButtonIndex);

	UFUNCTION(BlueprintPure, Category="UIKit Tabs")
	bool IsTabViewModelValid(const UUIKitTabGroupButtonViewModel* TabVM) const;

	UFUNCTION(BlueprintCallable, Category="UIKit Tabs")
	void SetInputActions(FDataTableRowHandle NextTab, FDataTableRowHandle PreviousTab);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="UIKit|Tab Group", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UUIKitTabGroupButtonViewModel>> LocalTabsViewModels;

};

