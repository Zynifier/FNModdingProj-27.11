// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "Tweening/TweenFactory/TweenFactoryHelpers.h"
#include "MaterialTweening.generated.h"

class UCurveFloat;
class UMaterialInstanceDynamic;
class UObject;
enum class ETweenBuiltInEasing : uint8;

/**
 * Convenience functions for creating Tweens that operate on Material Instances
 */
UCLASS()
class TWEENING_API UMaterialTweening : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Tweens a Vector Parameter of a material using a color value
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The material instance to manipulate with this Tween
	 * @param ParameterName		The name of the material parameter to modify
	 * @param FromOptions		Optionally specify a color at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended color at the end of the Tween
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Material Parameter Color", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_ColorParamTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UPARAM(ref) UMaterialInstanceDynamic*& Target, FName ParameterName, FTweenOptionalLinearColor FromOptions, FLinearColor ToValue, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens a Vector Parameter of a material using a scalar value
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The material instance to manipulate with this Tween
	 * @param ParameterName		The name of the material parameter to modify
	 * @param FromOptions		Optionally specify a value at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended value at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Material Parameter Scalar", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_ScalarParamTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UPARAM(ref) UMaterialInstanceDynamic*& Target, FName ParameterName, FTweenOptionalFloat FromOptions, float ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

};

/**
 * A context object for material parameter Tweens
 */
UCLASS()
class UTweenMaterialParameterInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ParameterName;

};

