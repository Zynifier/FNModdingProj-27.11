// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortMVVMHelpers.generated.h"

UCLASS()
class UFortMVVMHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="Fortnite UI|MVVM Utilities", meta=(DisplayName="Select (Name)"))
	static FName SelectName(bool bCondition, FName TrueValue, FName FalseValue);

	UFUNCTION(BlueprintPure, Category="Fortnite UI|MVVM Utilities", meta=(DisplayName="Select (Text)"))
	static FText SelectText(bool bCondition, FText TrueValue, FText FalseValue);

};

