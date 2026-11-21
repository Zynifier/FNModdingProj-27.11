// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "PictureInPicturePartnerSource.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "PictureInPictureSourcePicker.generated.h"

class UCommonTextBlock;
class UFortPickerOverlay;
class UOverlay;
class UPictureInPictureMediaController;
class UPictureInPicturePartnerControls;
class UTexture2D;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UPictureInPictureSourcePicker : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="PictureInPictureSourcePicker")
	FVector2D FullScreenTranslation;

	UPROPERTY(EditAnywhere, Category="PictureInPictureSourcePicker")
	FVector2D StandardTranslation;

	UPROPERTY(BlueprintReadWrite, Export, Category="PictureInPictureSourcePicker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_Main;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PictureInPictureSourcePicker")
	FSlateBrush FullScreenActionBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PictureInPictureSourcePicker")
	FSlateBrush StandardScreenActionBrush;

private:
	UFUNCTION()
	void HandleOnPartnerChanged(UPictureInPicturePartnerControls* NewPartner);

	UFUNCTION()
	void HandleOnPartnerSourceChanged(const TArray<FPiPPartnerSource>& CurrentSources);

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPickerOverlay> PickerOverlay_MediaSource;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Main;

	UPROPERTY(EditAnywhere, Category="PictureInPictureSourcePicker")
	TObjectPtr<UTexture2D> DefaultItemTexture;

	UPROPERTY()
	TObjectPtr<UPictureInPictureMediaController> CurrentPartner;

};

