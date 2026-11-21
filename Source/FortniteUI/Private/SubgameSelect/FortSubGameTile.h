// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "Context/CMSContext.h"
#include "FortSubGameTile.generated.h"

class UBorder;
class UCommonTextBlock;
class UEpicCMSImage;
class UImage;
class UMaterialInstance;
class UTexture2D;

UENUM(BlueprintType)
enum class ESubgameLoadFromCMS : uint8
{
	/**/
	DoNotLoadFromCMS = 0,
	/**/
	LoadImageFromCMS = 1,
};

UENUM(BlueprintType)
enum class ESubgameTileType : uint8
{
	Campaign = 0,
	Athena = 1,
	Creative = 2,
};

UCLASS(Abstract)
class UFortSubgameTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	bool TryGetSubgameDataFromCMS(FSubgameDisplayData& SubgameData);

	UFUNCTION(BlueprintCallable)
	bool TrySetSubgameImageFromCMS();

	UPROPERTY(EditAnywhere, Category="Content")
	ESubgameTileType SubgameType;

	UPROPERTY(EditAnywhere, Category="Content")
	ESubgameLoadFromCMS CMS_LoadType;

	UPROPERTY(EditAnywhere, Category="Content")
	TObjectPtr<UTexture2D> KeyArt;

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="TRUE"))
	FText Title;

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="TRUE"))
	FText Description;

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="TRUE"))
	FText StandardMessageLine1;

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="TRUE"))
	FText StandardMessageLine2;

	UPROPERTY(EditAnywhere, Category="Content")
	FLinearColor StandardMessageBackgroundColor;

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="TRUE"))
	FText SpecialMessage;

	UPROPERTY(EditAnywhere, Category="Content")
	FLinearColor SpecialMessageBackgroundColor;

	UPROPERTY(EditAnywhere, Category="Content")
	FLinearColor UnfocusedOverlayColor;

	UPROPERTY(EditAnywhere, Category="Content")
	TObjectPtr<UMaterialInstance> GradientBrush;

	UPROPERTY(EditAnywhere, Category="Content")
	FLinearColor GradientColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_KeyArt;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StandardMessageLine1;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StandardMessageLine2;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_StandardMessageBackground;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SpecialMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_SpecialMessageBackground;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_UnfocusedOverlay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Gradient;

};

