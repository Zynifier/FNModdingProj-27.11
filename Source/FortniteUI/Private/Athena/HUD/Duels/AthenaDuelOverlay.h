// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortRarityData.h"
#include "FortTypes.h"
#include "AthenaDuelOverlay.generated.h"

class UCommonRichTextBlock;
class UImage;
class USoundBase;
enum class EDuelState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaDuelOverlay : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOutroOverlay();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupForActivation(const EDuelState DuelState, const FFortColorPalette& RarityColorPalette);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowOverlay();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SubTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ChallengedNPCPortrait;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ElimPortrait;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Reward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaDuelOverlay")
	TSoftObjectPtr<USoundBase> DuelStartedSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaDuelOverlay")
	FFortPrioritizedWidgetData PrioritizedWidgetData;

private:
	UFUNCTION()
	void HandleDuelUpdate(const EDuelState DuelState, const FDuelOverlayData& DuelOverlayData);

};

