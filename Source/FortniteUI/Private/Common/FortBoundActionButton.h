// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/CommonBoundActionButton.h"
#include "FortBoundActionButton.generated.h"

class UCommonButtonStyle;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBoundActionButton : public UCommonBoundActionButton
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> KeyboardStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> LargeKeyboardStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> GamepadStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> LargeGamepadStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> MobileStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> LargeMobileStyle;

};

