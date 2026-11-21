// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMainMenu.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonUserWidget;
class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortMainMenu : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMainMenuRequestCloseDynamic);

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnMainMenuRequestCloseDynamic OnMainMenuRequestCloseDynamic;

protected:
	UFUNCTION(BlueprintPure)
	bool NeedsCenterWidget() const;

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* OnGetMainMenuFocusWidget() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenSettings(FName TabNameId, const FString& SettingToSelect);

	UFUNCTION(BlueprintCallable)
	void RequestCloseMainMenu();

	UFUNCTION(BlueprintPure)
	bool ShouldShowLeaveExperienceButton() const;

	UPROPERTY(BlueprintReadOnly, Category="FortMainMenu")
	FText DefaultHelpText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountDownTimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMainMenu", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_LeaveExperience;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMainMenu", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> LeaveButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMainMenu", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ContextualHelpText;

};

