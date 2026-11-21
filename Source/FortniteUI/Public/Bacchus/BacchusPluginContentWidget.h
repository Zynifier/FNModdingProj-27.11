// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "BacchusPluginContentWidget.generated.h"

class UOverlay;
class UWidget;

UCLASS(meta=(DisableNativeTick))
class UBacchusPluginContentWidget : public UBacchusHUDElement
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPluginHUDWidgetAdded(FGameplayTag WidgetTag, TSoftClassPtr<UWidget> SoftWidgetClass);

	UFUNCTION()
	void OnPluginHUDWidgetRemoved(FGameplayTag WidgetTag);

	UPROPERTY(EditAnywhere, Category="BacchusPluginContentWidget")
	FName PluginContentTagName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> MyOverlay;

};

