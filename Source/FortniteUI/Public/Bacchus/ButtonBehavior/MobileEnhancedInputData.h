// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MobileEnhancedInputData.generated.h"

class UInputAction;
class UInputModifier;
class UInputTrigger;

USTRUCT(BlueprintType)
struct FMobileEnhancedInputData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Enhanced Inputs")
	TObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditAnywhere, Instanced, Category="Enhanced Inputs")
	TArray<TObjectPtr<UInputModifier>> Modifiers;

	UPROPERTY(EditAnywhere, Instanced, Category="Enhanced Inputs")
	TArray<TObjectPtr<UInputTrigger>> Triggers;

};

