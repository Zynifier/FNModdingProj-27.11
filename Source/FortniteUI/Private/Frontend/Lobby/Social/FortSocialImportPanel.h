// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortSocialImportPanel.generated.h"

class UBorder;
class UCommonButtonLegacy;
class UWidgetSwitcher;
enum class ESocialImportPanelPlatform : uint8;
enum class ESocialImportPanelType : uint8;

UENUM(BlueprintType)
enum class ESocialImportPanelType : uint8
{
	Athena = 0,
	SaveTheWorld = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSocialImportPanelClosedDelegate);

UCLASS(meta=(DisableNativeTick))
class UFortSocialImportPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetSocialPlatform(ESocialImportPanelPlatform& OutPlatform) const;

	UFUNCTION(BlueprintCallable)
	void ShowPanel();

	UPROPERTY(BlueprintAssignable)
	FSocialImportPanelClosedDelegate OnSocialImportPanelClosed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnClaimViewRequested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnImportViewRequested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIncentivizedSet(bool bIncentivized);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLauncherImportOpened();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPanelTypeSet(ESocialImportPanelType NewType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingViewRequested();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialImportPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_AddFriends;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialImportPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Import;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialImportPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Add;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NotNow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_OptOut;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OuterBorder;

};

