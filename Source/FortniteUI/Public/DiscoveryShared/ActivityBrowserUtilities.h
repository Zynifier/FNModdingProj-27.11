// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActivityBrowserUtilities.generated.h"

UCLASS()
class UActivityBrowserBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Activity Browser")
	static bool IsSubModeSelectVisualsEnabled();

};

