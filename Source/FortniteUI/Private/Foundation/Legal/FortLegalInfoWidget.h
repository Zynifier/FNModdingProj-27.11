// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortLegalInfoWidget.generated.h"

class UCommonButtonBase;
class UCommonWidgetSwitcherLegacy;
class UFortTabListWidgetBase_Legacy;

UCLASS(meta=(DisableNativeTick))
class UFortLegalInfoWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="SpecialTabs")
	void AddJapaneseEULATabs();

	UFUNCTION(BlueprintCallable)
	void Close();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLegalInfoWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> WidgetSwitcher_Legal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLegalInfoWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_LegalOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PrivacyPolicy;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_FanContentPolicy;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TermsOfService;

};

