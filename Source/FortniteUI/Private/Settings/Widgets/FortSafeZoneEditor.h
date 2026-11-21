// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortSafeZoneEditor.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UFortSetting;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSafeZoneEditor : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Settings")
	void SetChildSettingReference(UFortSetting* SettingReference);

protected:
	UPROPERTY(EditAnywhere, Category="Restrictions")
	bool bCanCancel;

private:
	UFUNCTION()
	void HandleBackClicked();

	UFUNCTION()
	void HandleDoneClicked();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSafeZoneEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_SafeZoneMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSafeZoneEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Default;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSafeZoneEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SwitchHandheldWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSafeZoneEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSafeZoneEditor", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Done;

};

