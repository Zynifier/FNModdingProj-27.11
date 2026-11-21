// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PropertyBag.h"
#include "Tweening/TweenEasingEnums.h"
#include "StyleClass.generated.h"

/**
 * Stores animation information for a property.
 */
USTRUCT(BlueprintType)
struct FStyleAnimationData
{
	GENERATED_BODY()

public:
	/** Delay in seconds before playing the animation. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	float Delay;

	/** Duration in seconds. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	float Duration;

	/** Built-in easing function. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	ETweenBuiltInEasing Easing;

};

/**
 * Stores style information for a widget by using property path and value pairs.
 */
USTRUCT(BlueprintType)
struct FStyleClass
{
	GENERATED_BODY()

private:
	/** Property bag that stores style properties. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FInstancedPropertyBag StylePropertyBag;

	/** Stores animation data by property path. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TMap<FName, FStyleAnimationData> PropertyAnimations;

	/** Stores material parameters by material property path. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TMap<FName, FInstancedPropertyBag> MaterialParameters;

};

