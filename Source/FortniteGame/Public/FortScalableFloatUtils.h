// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScalableFloat.h"
#include "FortScalableFloatUtils.generated.h"

class UCurveTable;
class UObject;

UCLASS(MinimalAPI)
class UFortScalableFloatUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ScalableFloat", meta=(DisplayName="Get Scalable Float Multiplier"))
	static float GetValue(const FScalableFloat& Input);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static bool GetValueAsBool(const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat", meta=(WorldContext="WorldContextObject"))
	static bool GetValueAsBoolWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static bool GetValueAsBoolWithContextParam(const UObject* WorldContextObject, const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static int32 GetValueAsInteger(const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat", meta=(WorldContext="WorldContextObject"))
	static int32 GetValueAsIntegerWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static float GetValueAtLevel(const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat", meta=(WorldContext="WorldContextObject"))
	static float GetValueAtLevelWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static bool IsSettingCurveValid(const FScalableFloat& Input);

	UFUNCTION(BlueprintPure, Category="ScalableFloat")
	static bool IsStatic(const FScalableFloat& Input);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="ScalableFloat", meta=(CustomStructureParam="OverrideValue", DisplayName="Set Value with Context", WorldContext="WorldContextObject"))
	static bool K2_SetValueWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, const int32& OverrideValue, bool bShouldApply = true);
	DECLARE_FUNCTION(execK2_SetValueWithContext);

	UFUNCTION(BlueprintCallable, Category="ScalableFloat")
	static void ScaleValue(UPARAM(ref) FScalableFloat& Input, float Multiplier);

	UFUNCTION(BlueprintCallable, Category="ScalableFloat")
	static void SetScalingValue(UPARAM(ref) FScalableFloat& Input, float InCoeffecient, const FName InRowName, UCurveTable* InTable);

	UFUNCTION(BlueprintCallable, Category="ScalableFloat")
	static void SetValue(UPARAM(ref) FScalableFloat& Input, float NewValue);

	UFUNCTION(BlueprintCallable, Category="ScalableFloat", meta=(WorldContext="WorldContextObject"))
	static FString ToSimpleString(const FScalableFloat& Input);

};

