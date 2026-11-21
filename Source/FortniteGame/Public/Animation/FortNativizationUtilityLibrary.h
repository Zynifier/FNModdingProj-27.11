// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortNativizationUtilityLibrary.generated.h"

class UObject;

USTRUCT()
struct FNativizationCachedFieldsToCompare
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFortNativizationUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Nativization Utility", meta=(DefaultToSelf="Target"))
	static bool CompareAndValidateFields(const UObject* Target, const FString& Suffix, float Tolerance = 0.000100f, float TextSize = 2.000000f, bool bDisplayNamingWarning = true);

};

