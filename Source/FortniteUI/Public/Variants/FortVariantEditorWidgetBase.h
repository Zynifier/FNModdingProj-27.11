// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortVariantEditorWidgetBase.generated.h"

class UWidget;

UCLASS(MinimalAPI, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortVariantEditorWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> LogicalOuter;

};

