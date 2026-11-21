// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortUIExtensionSlot.h"
#include "FortExtensionWidgetContainer.generated.h"

class UUserWidget;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortExtensionWidgetContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortExtensionWidgetContainer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(UUserWidget* InUserWidget);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortExtensionWidgetContainer")
	EUIExtensionSlot ExtensionSlot;

};

