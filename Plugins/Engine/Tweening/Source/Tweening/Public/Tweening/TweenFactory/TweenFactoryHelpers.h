// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Tweening/Tween.h"
#include "TweenFactoryHelpers.generated.h"

USTRUCT(BlueprintType)
struct TWEENING_API FTweenDelayOptions
{
	GENERATED_BODY()

public:
	/**
	 * An optional delay in seconds at the beginning of the Tween.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	float DelayAtBeginning;

	/**
	 * An optional delay in seconds at the end of the Tween.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	float DelayAtEnd;

	/**
	 * Controls whether the Tween will initialize the To/From values and update the Target before or after the initial Delay. It defaults to "AfterDelay".
	 * The From value is initialized if one is not explicitly set. The To value is calculated if the Tween is relative.
	 * The "OnPlay" option is useful if you are using a delay but you want the Target to be set to the From value as soon as the Tween starts playing.
	 * It may also be useful if something else (like another Tween) might change the Target property during the delay and you want to "lock in" the current
	 * From value without explicitly setting it. However, the most reliable option is to just set the From value explicitly.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	ETweenInitializationPoint InitializationPoint;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenLoopOptions
{
	GENERATED_BODY()

public:
	/**
	 * Indicates how the Tween should loop.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	ETweenLoopType LoopType;

	/**
	 * The number of times this Tween should play. A negative value means infinite looping, while a Loop Count of 0 is treated as 1.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	int32 LoopCount;

};

// Structs for providing optional values to configure tweens in Blueprints

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalFloat
{
	GENERATED_BODY()

public:
	/**
		* The specific value to use for the tween.
		*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	float Value;

	/**
	 * Indicates whether to use the provided value for the tween.
	 * If left false, the current value at the time the tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalLinearColor
{
	GENERATED_BODY()

public:
	/**
		* The specific value to use for the tween.
		*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	FLinearColor Value;

	/**
	 * Indicates whether to use the provided value for the tween.
	 * If left false, the current value at the time the tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalRotator
{
	GENERATED_BODY()

public:
	/**
	* The specific value to use for the Tween.
	*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	FRotator Value;

	/**
	 * Indicates whether to use the provided value for the Tween.
	 * If left false, the current value at the time the Tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalVector
{
	GENERATED_BODY()

public:
	/**
		* The specific value to use for the tween.
		*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	FVector Value;

	/**
	 * Indicates whether to use the provided value for the tween.
	 * If left false, the current value at the time the tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalVector2D
{
	GENERATED_BODY()

public:
	/**
		* The specific value to use for the tween.
		*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	FVector2D Value;

	/**
	 * Indicates whether to use the provided value for the tween.
	 * If left false, the current value at the time the tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

USTRUCT(BlueprintType)
struct TWEENING_API FTweenOptionalVector4
{
	GENERATED_BODY()

public:
	/**
		* The specific value to use for the tween.
		*/
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	FVector4 Value;

	/**
	 * Indicates whether to use the provided value for the tween.
	 * If left false, the current value at the time the tween starts playing will be used.
	 */
	UPROPERTY(BlueprintReadWrite, Category="Tweening")
	bool bUseSpecificValue;

};

