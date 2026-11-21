// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Styling/SlateColor.h"
#include "FortProgressArrowButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortProgressArrowButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnArrowColorSet();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsInteractiveSet(bool bIsInteractive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShadowColorSet();

	UFUNCTION(BlueprintCallable)
	void UpdateArrowColor(FSlateColor Color, FSlateColor HoverColor);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton")
	FSlateColor ArrowColor;

	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton")
	FSlateColor HoverColor;

	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton")
	FSlateColor ShadowColor;

};

