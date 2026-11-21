// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUITypes.h"
#include "CommonInputTypes.generated.h"

UENUM(BlueprintType)
enum class ECommonGamepadType : uint8
{
	XboxOneController = 0,
	PS4Controller = 1,
	SwitchController = 2,
	GenericController = 3,
	XboxSeriesXController = 4,
	PS5Controller = 5,
	Count = 6,
};

UENUM(BlueprintType)
enum class ECommonPlatformType : uint8
{
	PC = 0,
	Mac = 1,
	PS4 = 2,
	XBox = 3,
	IOS = 4,
	Android = 5,
	Switch = 6,
	XSX = 7,
	PS5 = 8,
	Count = 9,
};

USTRUCT(BlueprintType)
struct COMMONUILEGACY_API FCommonInputActionData : public FCommonInputActionDataBase
{
	GENERATED_BODY()

protected:
	/**
	* Override the input state for each input method, this is legacy & will override GamepadInputOverrides
	*/
	UPROPERTY(EditAnywhere, Category="CommonInput")
	TMap<ECommonGamepadType, FCommonInputTypeInfo> GamepadInputTypeInfoOverrides;

	/**
	* Override the input state for each input method
	*/
	UPROPERTY(meta=(ArraySizeEnum="/Script/CommonUILegacy.ECommonGamepadType"))
	FCommonInputTypeInfo GamepadInputTypeInfos_DEPRECATED[6];

};

