// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortServerBrowser.generated.h"

class UCommonButtonLegacy;
class UFortServerBrowserActionData;
class UFortServerBrowserListView;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortServerBrowser : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Data")
	TArray<TObjectPtr<UFortServerBrowserActionData>> SupportedActions;

	UPROPERTY(Config)
	TArray<TSoftObjectPtr<UFortServerBrowserActionData>> ExcludedSupportedActions;

	UPROPERTY(EditDefaultsOnly, Category="Listview Navigation")
	TSoftObjectPtr<UFortServerBrowserActionData> DefaultSelectedAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortServerBrowserListView> ListView_ServerBrowser;

private:
	UPROPERTY(EditDefaultsOnly, Category="Listview Navigation Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NavigateLeftInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Listview Navigation Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NavigateRightInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseTouch;

};

