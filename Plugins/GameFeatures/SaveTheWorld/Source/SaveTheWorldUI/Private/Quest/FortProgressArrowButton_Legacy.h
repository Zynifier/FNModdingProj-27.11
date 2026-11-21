// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "CommonButtonLegacy.h"
#include "FortProgressArrowButton_Legacy.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortProgressArrowButton_Legacy : public UCommonButtonLegacy
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
	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton_Legacy")
	FSlateColor ArrowColor;

	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton_Legacy")
	FSlateColor HoverColor;

	UPROPERTY(BlueprintReadOnly, Category="FortProgressArrowButton_Legacy")
	FSlateColor ShadowColor;

};

