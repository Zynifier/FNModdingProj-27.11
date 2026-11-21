// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "DownloadOnDemandAddProjectModal.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UDownloadOnDemandProject;
class UDownloadOnDemandProjectTileImage;
class UEditableTextBox;
class UOverlay;

UCLASS()
class VKDOWNLOADONDEMANDUI_API UDownloadOnDemandAddProjectModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLightningViolator(ESlateVisibility InVisibility, const FText& InText);

private:
	UFUNCTION()
	void HandleDownloadLinkIdTextChanged(const FText& InputLinkCode);

	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProject> Project;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditableTextBox_DownloadLinkCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddProject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDownloadOnDemandProjectTileImage> ProjectTileImage_Preview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ProjectTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_ProjectTitle;

};

