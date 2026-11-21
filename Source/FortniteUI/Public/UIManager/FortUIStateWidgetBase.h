// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortUIStateWidgetBase.generated.h"

class UCommonActivatableWidgetStack;

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class FORTNITEUI_API UFortUIStateWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetStack> WidgetStack_PrimaryContent;

};

