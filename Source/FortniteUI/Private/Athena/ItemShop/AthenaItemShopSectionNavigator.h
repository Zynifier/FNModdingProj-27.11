// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaItemShopSectionNavigator.generated.h"

class UAthenaItemShopNavigationButton;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopSectionNavigator : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Navigation Button")
	void RequestNextSection();

	UFUNCTION(BlueprintCallable, Category="Navigation Button")
	void RequestPreviousSection();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopNavigationButton> Button_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopNavigationButton> Button_Previous;

};

