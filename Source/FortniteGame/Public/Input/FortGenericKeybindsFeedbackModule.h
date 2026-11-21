// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGenericKeybindsFeedbackModule.generated.h"

USTRUCT()
struct FInputActionTextArray
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortGenericKeybindsFeedbackModule
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<FName, FInputActionTextArray> KeyActionsDisplayMap;

	UPROPERTY()
	TMap<FName, FInputActionTextArray> GamepadActionsDisplayMap;

	UPROPERTY()
	TMap<FName, FInputActionTextArray> InputActionsDisplayMap;

};

