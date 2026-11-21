// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortWebLoginWidget.generated.h"

class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortWebLoginWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DismissWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DisplayWidget(UWidget* WebWidget);

};

