// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Styling/SlateBrush.h"
#include "CommonButtonLegacy.h"
#include "DownloadOnDemandProjectTile.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UDownloadOnDemandProject;
class UDownloadOnDemandProjectTileImage;
class UImage;
class USizeBox;

UCLASS()
class UDownloadOnDemandProjectTile : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateLabel(bool bShowLabel);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLabelUpdated();

private:
	UPROPERTY(EditAnywhere, Category="DownloadOnDemandProjectTile")
	FSlateBrush SelectedHighlightBrush;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandProjectTile")
	FSlateBrush HoveredHighlightBrush;

	UPROPERTY(BlueprintReadOnly, Category="DownloadOnDemandProjectTile", meta=(AllowPrivateAccess))
	bool bIsSelected;

	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProject> Project;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDownloadOnDemandProjectTileImage> ProjectTileImage_Preview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_UpdatePending;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_AddProject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Spinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Label;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Label;

	UPROPERTY(BlueprintReadWrite, Export, Category="DownloadOnDemandProjectTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Highlight;

};

