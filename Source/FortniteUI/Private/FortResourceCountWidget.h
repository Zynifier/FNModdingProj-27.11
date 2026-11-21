// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortResourceCountWidget.generated.h"

class UCommonTextBlock;
class UFortLazyImage;
class UFortResourceItemDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortResourceCountWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResourceCount;

private:
	UPROPERTY(EditAnywhere, Category="FortResourceCountWidget")
	TObjectPtr<UFortResourceItemDefinition> ResourceItemDefinition;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResourceName;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_ResourceIcon;

};

