// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PropertyBag.h"
#include "StylePropertyStore.generated.h"

class UWidget;

/**
 * Manages storing and applying values of properties that are going to be changed by applying a style.
 */
USTRUCT()
struct FStylePropertyStore
{
	GENERATED_BODY()

private:
	/**
	 * Map that stores current style values of a widget which are overridden by applied style.
	 */
	UPROPERTY()
	TMap<TObjectPtr<UWidget>, FInstancedPropertyBag> WidgetToPropertyBagMap;

};

