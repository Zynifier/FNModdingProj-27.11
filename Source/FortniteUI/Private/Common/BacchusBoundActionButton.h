// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/CommonBoundActionButton.h"
#include "BacchusBoundActionButton.generated.h"

class UCommonButtonStyle;

UCLASS()
class UBacchusBoundActionButton : public UCommonBoundActionButton
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Styles")
	TSubclassOf<UCommonButtonStyle> KeyboardStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Styles")
	TSubclassOf<UCommonButtonStyle> LargeKeyboardStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Styles")
	TSubclassOf<UCommonButtonStyle> GamepadStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Styles")
	TSubclassOf<UCommonButtonStyle> LargeGamepadStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additional Styles")
	bool bUseAdditionalStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additional Styles")
	TSubclassOf<UCommonButtonStyle> KeyboardAdditionalStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additional Styles")
	TSubclassOf<UCommonButtonStyle> LargeKeyboardAdditionalStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additional Styles")
	TSubclassOf<UCommonButtonStyle> GamepadAdditionalStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additional Styles")
	TSubclassOf<UCommonButtonStyle> LargeGamepadAdditionalStyle;

};

