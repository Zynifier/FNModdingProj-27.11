// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DownloadOnDemandProjectTileImage.generated.h"

class UDownloadOnDemandProject;
class UImage;
class UTexture;

UCLASS()
class UDownloadOnDemandProjectTileImage : public UUserWidget
{
	GENERATED_BODY()

public:
	UDownloadOnDemandProjectTileImage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="DownloadOnDemandProjectTileImage")
	TObjectPtr<UTexture> EmptyProjectTexture;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandProjectTileImage", meta=(InlineEditConditionToggle))
	uint8 bOverrideGrayScale : 1;

	UPROPERTY(EditAnywhere, Category="DownloadOnDemandProjectTileImage", meta=(editcondition="bOverrideGrayScale"))
	float GreyScaleOverride;

	UPROPERTY(Transient)
	TObjectPtr<UDownloadOnDemandProject> Project;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ProjectPreview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LoadingImageSpinner;

};

