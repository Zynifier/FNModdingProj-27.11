// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DownloadOnDemandProjectManagementTab.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonTileView;
class UCommonVisibilitySwitcher;
class UDownloadOnDemandProject;
class UImage;

UCLASS()
class UDownloadOnDemandProjectManagementTab : public UUserWidget
{
	GENERATED_BODY()

public:
	UDownloadOnDemandProjectManagementTab(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void RemoveProjectConfirmed();

	UFUNCTION(BlueprintCallable)
	void UpdateProjectConfirmed();

private:
	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProject> Project;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_ProjectTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_LinkCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_VersionNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_LatestVersionNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LatestVersionSpinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="DownloadOnDemandProjectManagementTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_RemoveProject;

	UPROPERTY(BlueprintReadOnly, Export, Category="DownloadOnDemandProjectManagementTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_UpdateProject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Props;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> CommonTileView_ProjectAssetTiles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NoPropsMessage;

};

