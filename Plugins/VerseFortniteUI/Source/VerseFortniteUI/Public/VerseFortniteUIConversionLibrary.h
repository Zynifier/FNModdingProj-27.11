// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VerseFortniteUIConversionLibrary.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisplayName="Conversion Library"))
class UVerseFortniteUIAllowedConversionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="Widget", meta=(DisplayName="To Visibility (Boolean)"))
	static ESlateVisibility Conv_BoolToSlateVisibility(bool bIsVisible, ESlateVisibility TrueVisibility = ESlateVisibility::Visible, ESlateVisibility FalseVisibility = ESlateVisibility::Collapsed);

};

UCLASS(Abstract, MinimalAPI, meta=(DisplayName="Conversion Library (NOT APPROVED)"))
class UVerseFortniteUIConversionLibrary : public UVerseFortniteUIAllowedConversionLibrary
{
	GENERATED_BODY()

};

