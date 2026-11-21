// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortNullHUD.generated.h"

class UCommonUserWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortNullHUD : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonUserWidget* ActionBar_BottomBar;

};

