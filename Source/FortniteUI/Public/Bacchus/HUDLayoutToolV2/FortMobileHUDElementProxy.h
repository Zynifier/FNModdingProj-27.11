// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Bacchus/FortMobileHUDElement.h"
#include "FortMobileHUDElementProxy.generated.h"

class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMobileHUDElementProxy : public UFortMobileHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDElementProxy")
	FText WidgetName;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDElementProxy")
	bool AppendWidgetAndBehaviorNames;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDElementProxy")
	FLinearColor InBoundsHighlightColor;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDElementProxy")
	FLinearColor OutOfBoundsProxyHighlightColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SelectionHighlight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_OutOfBoundsIndicator;

};

