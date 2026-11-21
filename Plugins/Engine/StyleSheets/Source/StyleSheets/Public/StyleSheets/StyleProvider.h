// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StyleProvider.generated.h"

class UStyleAnimationProvider;
class UStyleRuleTree;

/**
 * Applies styles to given widget based on given style tags.
 */
UCLASS(MinimalAPI)
class UStyleProvider : public UObject
{
	GENERATED_BODY()

private:
	/** Style rule tree that will be used for fast matching of style rules of widgets. */
	UPROPERTY(VisibleAnywhere, Category="Style Sheets")
	TWeakObjectPtr<UStyleRuleTree> StyleRuleTree;

	/** Animates animated properties. */
	UPROPERTY(VisibleAnywhere, Category="Style Sheets")
	TWeakObjectPtr<UStyleAnimationProvider> StyleAnimationProvider;

};

