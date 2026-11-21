// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/AthenaLoadingScreenPreviewPanel.h"
#include "AthenaLoadingScreenPreviewPanelBase.generated.h"

class UCommonButtonBase;
class UNativeWidgetHost;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaLoadingScreenPreviewPanelBase : public UAthenaLoadingScreenPreviewPanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaLoadingScreenPreviewPanelBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNativeWidgetHost> LoadingScreenSlot;

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

};

