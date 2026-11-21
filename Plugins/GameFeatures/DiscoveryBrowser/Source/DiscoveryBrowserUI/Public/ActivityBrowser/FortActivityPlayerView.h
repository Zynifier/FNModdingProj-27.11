// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserView.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortActivityPlayerView.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UFortActivityPlayerBrowserView;
class UFortTabListWidgetBase_Legacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityPlayerView : public UFortActivityBrowserView, public IFortTabInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="Tab Interface")
	TSubclassOf<UCommonButtonBase> TabButtonClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_PlayerViewTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityPlayerView", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_PlayerBrowserViews;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityPlayerBrowserView> BrowserView_Favorites;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityPlayerBrowserView> BrowserView_History;

};

