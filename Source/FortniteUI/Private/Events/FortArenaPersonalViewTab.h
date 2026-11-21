// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Showdown/FortShowdownDivisionEventView.h"
#include "FortArenaPersonalViewTab.generated.h"

class UCommonTextBlock;
class UFortArenaPersonalDivisionView;
class UFortLazyImage;
class UProgressBar;
class URichTextBlock;

UCLASS()
class UFortArenaPersonalDivisionView : public UFortShowdownDivisionEventView
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_CurrentDivisionFancy;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_CurrentDivisionPlain;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> Bar_DivisionProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_DivisionProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_NextDivision;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_TitleName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_DivisionRank;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalDivisionView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_TotalHype;

};

UCLASS(meta=(DisableNativeTick))
class UFortArenaPersonalViewTab : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortArenaPersonalViewTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortArenaPersonalDivisionView> EventView_PersonalHype;

};

