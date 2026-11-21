// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "AthenaSkewedTabButton.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;
class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaSkewedTabButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSkewedTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSkewedTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Bang;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSkewedTabButton", meta=(AllowPrivateAccess))
	bool bUseMobileSize;

};

