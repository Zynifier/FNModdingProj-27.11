// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonBorder.h"
#include "Components/SlateWrapperTypes.h"
#include "CommonVisibilityWidgetLegacy.generated.h"

/**
 * Legacy. Please use CommonVisibilityWidgetBase instead.
 *
 * Note: Unlike other legacy classes this does not derive from 
 * it's non-legacy equivalent. This is since doing so would present
 * two interfaces to the user, and beyond removal of NDA platforms
 * the legacy and non-legacy do not differ functionally. So you should
 * use the non-legacy version.
 *
 */
UCLASS()
class COMMONUILEGACY_API UCommonVisibilityWidgetLegacy : public UCommonBorder
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForGamepad;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForMouseAndKeyboard;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForTouch;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForPC;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForMac;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForPS4;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForPS5;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForXBox;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForXSX;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForIOS;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForAndroid;

	UPROPERTY(EditAnywhere, Category="Visibility")
	bool bShowForErebus;

	UPROPERTY(EditAnywhere, Category="Visibility")
	ESlateVisibility VisibleType;

	UPROPERTY(EditAnywhere, Category="Visibility")
	ESlateVisibility HiddenType;

};

