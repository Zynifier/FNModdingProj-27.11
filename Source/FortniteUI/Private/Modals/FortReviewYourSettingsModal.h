// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortReviewYourSettingsModal.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortGameSettingRegistry;
class UFortSetting;
class UFortSettingDetailView;
class UFortSettingsListView;
class UScrollBox;

USTRUCT()
struct FReviewYourSettingsData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText Title;

	UPROPERTY()
	FText Description;

	UPROPERTY()
	TArray<UFortSetting*> Settings;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortReviewYourSettingsModal : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameSettingRegistry> Registry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonTextBlock* Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonRichTextBlock* RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UFortSettingsListView* ListView_Settings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortReviewYourSettingsModal", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	UFortSettingDetailView* Details_Settings;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	UScrollBox* ScrollBox_Details;

};

