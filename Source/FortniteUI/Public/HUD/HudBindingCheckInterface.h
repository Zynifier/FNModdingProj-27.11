// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HudBindingCheckInterface.generated.h"

UINTERFACE(BlueprintType)
class UHudBindingCheckInterface : public UInterface
{
	GENERATED_BODY()
};

class IHudBindingCheckInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BindingCheckInterface")
	void GetBindActions(TArray<FName>& OutActions) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BindingCheckInterface")
	void HideBindWidgets();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BindingCheckInterface")
	bool ShouldShowPromptInHud();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BindingCheckInterface")
	void ShowBindWidgets();

};

