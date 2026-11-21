// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "FortResponsivePanel.generated.h"

class UFortResponsivePanelSlot;
class UWidget;

UCLASS()
class UFortResponsivePanel : public UPanelWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Widget")
	UFortResponsivePanelSlot* AddChildToFortResponsivePanel(UWidget* Content);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behavior")
	bool bCanStackVertically;

};

