// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "FortCreativeIslandDetailsPanel.generated.h"

class UCommonTextBlock;
class UFortGameActivity;
class UImage;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ClearLinkCodeVisuals();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLinkCodeVisuals(UFortGameActivity* Activity);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Island;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LoadingSpinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Creator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PublishedIslandCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MaximumNumberOfPlayers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingDescription;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandDetailsPanel")
	FSlateBrush DefaultImageIslandBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandDetailsPanel")
	FText MaxNumberOfPlayerTextFormat;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandDetailsPanel")
	FText MatchmakingOffText;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandDetailsPanel")
	FText MatchmakingKeepFullText;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeIslandDetailsPanel")
	FText MatchmakingRespectPartiesTextFormat;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandDetailsPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ScrollUpInputRowHandle;

	UPROPERTY(EditAnywhere, Category="FortCreativeIslandDetailsPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ScrollDownInputRowHandle;

};

