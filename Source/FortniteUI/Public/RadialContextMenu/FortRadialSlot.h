// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortRadialSlot.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;
class UTexture2D;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortRadialSlot : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortRadialSlot", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRadialSlot", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Main;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_EquippedItem;

	UPROPERTY(EditAnywhere, Category="FortRadialSlot", meta=(AllowPrivateAccess))
	TSoftObjectPtr<UTexture2D> LockedTexture;

};

