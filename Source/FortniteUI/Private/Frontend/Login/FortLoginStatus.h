// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortLoginStatus.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLoginStatus : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetContinueButtonText(const FText& ContinueText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetQuitButtonText(const FText& QuitText);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLoginStatus", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Continue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLoginStatus", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Quit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Status;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Status;

};

