// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "FortConversationOptionsPanel.generated.h"

class UPanelSlot;
class UWidget;

UCLASS(meta=(DisableNativeTick))
class UFortConversationOptionsPanel : public UPanelWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Widget")
	UPanelSlot* AddChildToDynamicPanel(UWidget* Content);

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	int32 MaxRows;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 MiddleColumnWidth;

};

