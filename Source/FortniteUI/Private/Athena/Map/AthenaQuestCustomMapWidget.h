// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaQuestCustomMapWidget.generated.h"

class UUserWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaQuestCustomMapWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaQuestCustomMapWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnWidgetComponentClassLoaded"))
	void BP_OnWidgetComponentClassLoaded(FName WidgetComponentId, TSubclassOf<UUserWidget> WidgetClass);

};

