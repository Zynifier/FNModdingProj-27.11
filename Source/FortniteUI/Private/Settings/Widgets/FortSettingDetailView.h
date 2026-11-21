// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/UserWidgetPool.h"
#include "FortSettingDetailView.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortSetting;
class UFortSettingVisualData;
class UVerticalBox;

UCLASS(Abstract)
class UFortSettingDetailView : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSettingDetailView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="FortSettingDetailView")
	TObjectPtr<UFortSettingVisualData> VisualData;

	UPROPERTY(Transient)
	FUserWidgetPool ExtensionWidgetPool;

	UPROPERTY(Transient)
	TObjectPtr<UFortSetting> CurrentSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SettingName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_DynamicDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_WarningDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_DisabledDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingDetailView", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UVerticalBox> Box_DetailsExtension;

};

