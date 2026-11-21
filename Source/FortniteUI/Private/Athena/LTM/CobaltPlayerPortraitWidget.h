// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltPlayerPortraitWidget.generated.h"

class AFortPlayerState;
class UCommonTextBlock;
class UFortLazyImage;

UCLASS()
class UCobaltPlayerPortraitWidget : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> AvatarImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="CobaltPlayerPortraitWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PlayerNameTextWidget;

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerState> PlayerState;

};

