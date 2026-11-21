// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TweenEasingEnums.generated.h"

UENUM(BlueprintType)
enum class ETweenBuiltInEasing : uint8
{
	// Linear easing

	Linear = 0 UMETA(DisplayName="Linear", Grouping="Linear"),
	// Sinusoidal easing

	SinIn = 1 UMETA(DisplayName="Sinusoidal In", Grouping="Sinusoidal"),
	SinOut = 2 UMETA(DisplayName="Sinusoidal Out", Grouping="Sinusoidal"),
	SinInOut = 3 UMETA(DisplayName="Sinusoidal InOut", Grouping="Sinusoidal"),
	// Quadratic easing

	QuadIn = 4 UMETA(DisplayName="Quadratic In", Grouping="Quadratic"),
	QuadOut = 5 UMETA(DisplayName="Quadratic Out", Grouping="Quadratic"),
	QuadInOut = 6 UMETA(DisplayName="Quadratic InOut", Grouping="Quadratic"),
	// Cubic easing

	CubicIn = 7 UMETA(DisplayName="Cubic In", Grouping="Cubic"),
	CubicOut = 8 UMETA(DisplayName="Cubic Out", Grouping="Cubic"),
	CubicInOut = 9 UMETA(DisplayName="Cubic InOut", Grouping="Cubic"),
	// Quartic easing

	QuartIn = 10 UMETA(DisplayName="Quartic In", Grouping="Quartic"),
	QuartOut = 11 UMETA(DisplayName="Quartic Out", Grouping="Quartic"),
	QuartInOut = 12 UMETA(DisplayName="Quartic InOut", Grouping="Quartic"),
	// Quintic easing

	QuintIn = 13 UMETA(DisplayName="Quintic In", Grouping="Quintic"),
	QuintOut = 14 UMETA(DisplayName="Quintic Out", Grouping="Quintic"),
	QuintInOut = 15 UMETA(DisplayName="Quintic InOut", Grouping="Quintic"),
	// Exponential easing

	ExpoIn = 16 UMETA(DisplayName="Exponential In", Grouping="Exponential"),
	ExpoOut = 17 UMETA(DisplayName="Exponential Out", Grouping="Exponential"),
	ExpoInOut = 18 UMETA(DisplayName="Exponential InOut", Grouping="Exponential"),
	// Circular easing

	CircIn = 19 UMETA(DisplayName="Circular In", Grouping="Circular"),
	CircOut = 20 UMETA(DisplayName="Circular Out", Grouping="Circular"),
	CircInOut = 21 UMETA(DisplayName="Circular InOut", Grouping="Circular"),
	// Back easing

	BackIn = 22 UMETA(DisplayName="Back In", Grouping="Back"),
	BackOut = 23 UMETA(DisplayName="Back Out", Grouping="Back"),
	BackInOut = 24 UMETA(DisplayName="Back InOut", Grouping="Back"),
	// Elastic easing

	ElasticIn = 25 UMETA(DisplayName="Elastic In", Grouping="Elastic"),
	ElasticOut = 26 UMETA(DisplayName="Elastic Out", Grouping="Elastic"),
	ElasticInOut = 27 UMETA(DisplayName="Elastic InOut", Grouping="Elastic"),
	// Bounce easing

	BounceIn = 28 UMETA(DisplayName="Bounce In", Grouping="Bounce"),
	BounceOut = 29 UMETA(DisplayName="Bounce Out", Grouping="Bounce"),
	BounceInOut = 30 UMETA(DisplayName="Bounce InOut", Grouping="Bounce"),
};

