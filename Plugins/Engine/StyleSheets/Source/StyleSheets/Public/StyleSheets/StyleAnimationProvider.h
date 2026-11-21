// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StyleAnimationProvider.generated.h"

class UWidget;

/** Stores widget and property couple to identify a unique tween. */
USTRUCT()
struct FWidgetProperty
{
	GENERATED_BODY()

public:
	/** Owner widget of the property. */
	UPROPERTY(Export)
	TWeakObjectPtr<UWidget> Widget;

	/** Property path of the widget. */
	UPROPERTY()
	FName PropertyPath;

};

/** Used for passing additional data to Tween. */
UCLASS()
class UPropertyTweenContext : public UObject
{
	GENERATED_BODY()

public:
	/** Property path to be used in the tweening as context. */
	UPROPERTY()
	FName PropertyPath;

};

/**
 * Responsible for managing Tweens for widget properties based on styles.
 */
UCLASS(MinimalAPI)
class UStyleAnimationProvider : public UObject
{
	GENERATED_BODY()

};

