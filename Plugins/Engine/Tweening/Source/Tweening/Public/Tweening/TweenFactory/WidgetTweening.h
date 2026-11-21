// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Tweening/TweenFactory/TweenFactoryHelpers.h"
#include "WidgetTweening.generated.h"

class UCurveFloat;
class UObject;
class UWidget;
enum class ETweenBuiltInEasing : uint8;

/**
 * Convenience functions for creating Tweens that operate on properties of UWidgets
 */
UCLASS()
class TWEENING_API UWidgetTweening : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Tweens the Render Opacity of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify an opacity at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended opacity at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Opacity", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_OpacityTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalFloat FromOptions, float ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens the Transform Angle of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify an angle at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended angle at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Transform Angle", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TransformAngleTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalFloat FromOptions, float ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens the Transform Pivot of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify a pivot at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended pivot at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Transform Pivot", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TransformPivotTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalVector2D FromOptions, FVector2D ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens the Transform Scale of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify a scale at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended scale at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Transform Scale", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TransformScaleTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalVector2D FromOptions, FVector2D ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens the Transform Shear of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify a shear at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended shear at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Transform Shear", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TransformShearTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalVector2D FromOptions, FVector2D ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

	/**
	 * Tweens the Transform Translation of the target Widget
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The widget to manipulate with this Tween
	 * @param FromOptions		Optionally specify an opacity at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The intended translation at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Tween Widget Translation", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TranslationTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UWidget* Target, FTweenOptionalVector2D FromOptions, const FVector2D ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

};

