// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Tweening/TweenFactory/TweenFactoryHelpers.h"
#include "ActorTweening.generated.h"

class AActor;
class UCurveFloat;
class UObject;
class USplineComponent;
enum class ETweenBuiltInEasing : uint8;
enum class ETweenSplineAlignmentOption : uint8;

UENUM(BlueprintType)
enum class ETweenSplineAlignmentOption : uint8
{
	/** The Actor is not aligned to the Spline. */
	NoAlignment = 0,
	/** The Actor is aligned in the direction of the Spline, regardless of the Tween direction. */
	AlignWithSpline = 1,
	/** The Actor is aligned with the Spline in the direction of the Tween. */
	AlignWithTween = 2,
};

/**
 * Convenience functions for creating Tweens that operate on properties of Actors and Actor Components
 */
UCLASS()
class TWEENING_API UActorTweening : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Tweens the position of an Actor along the path of a Spline
	 *
	 * @param OutTweenId		A unique ID for the created Tween which can be used to control it via the Tween Manager
	 * @param ContextObject		The world context object
	 * @param Target			The Actor to manipulate with this Tween
	 * @param Spline			The Spline to follow
	 * @param Alignment			Options for whether and how to align the Actor to the Spline during the Tween
	 * @param bIgnorePitch		Causes the Tween to leave the Pitch axis unaffected when aligning the Actor to the Spline
	 * @param bIgnoreYaw		Causes the Tween to leave the Yaw axis unaffected when aligning the Actor to the Spline
	 * @param bIgnoreRoll		Causes the Tween to leave the Roll axis unaffected when aligning the Actor to the Spline
	 * @param FromOptions		Optionally specify a normalized position along the spline at the beginning of the Tween. If not specified, the current value at the time the Tween starts playing will be used.
	 * @param ToValue			The normalized position along the spline at the end of the Tween
	 * @param bIsRelative		Indicates that the To Value should be treated as an offset of the From Value, instead of an absolute value.
	 * @param Duration			The intended duration of the Tween
	 * @param DelayOptions		Optional delays for before or after the Tween manipulates the target
	 * @param EasingFunction	The easing function to use for this Tween. This is ignored if an easing curve is also supplied.
	 * @param EasingCurve		An easing curve to use for this Tween, overriding the easing function.
	 * @param LoopOptions		Optional delays for before or after the Tween manipulates the target
	 * @param bAutoPlay			Starts playing the Tween immediately
	 * @param bAutoKill			Cleans up the Tween when it completes. Only set this to false if you plan to play the Tween more than once and kill it when you're done, by making calls to the Tween Manager subsystem.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(AutoCreateRefTerm="OnComplete", DisplayName="Tween Actor Transform Along Spline", WorldContext="ContextObject", CPP_Default_Duration="1.000000", CPP_Default_DelayOptions="()", CPP_Default_EasingFunction="Linear", CPP_Default_EasingCurve="None", CPP_Default_LoopOptions="()"))
	static void BP_TransformAlongSplineTo(UPARAM(DisplayName="Tween ID") int32& OutTweenId, UObject* ContextObject, UPARAM(ref) AActor*& Target, USplineComponent* Spline, ETweenSplineAlignmentOption Alignment, bool bIgnorePitch, bool bIgnoreYaw, bool bIgnoreRoll, FTweenOptionalFloat FromOptions, float ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay = true, bool bAutoKill = true);

};

/**
 * A context object for Tweens along a spline
 */
UCLASS()
class UTweenSplineInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Export)
	TWeakObjectPtr<USplineComponent> Spline;

	UPROPERTY()
	ETweenSplineAlignmentOption Alignment;

	UPROPERTY()
	bool bIgnorePitch;

	UPROPERTY()
	bool bIgnoreYaw;

	UPROPERTY()
	bool bIgnoreRoll;

};

