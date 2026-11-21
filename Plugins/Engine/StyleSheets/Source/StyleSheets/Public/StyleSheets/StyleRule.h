// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PropertyBag.h"
#include "UObject/NoExportTypes.h"
#include "StyleSheets/StyleClass.h"
#include "StyleSheets/StyleSelector.h"
#include "StyleRule.generated.h"

class UStyleRule;
class UWidget;

/**
 * Wrapper struct to store preview related information.
 */
USTRUCT()
struct FStyleRulePreviewInfo
{
	GENERATED_BODY()

public:
	/** Class used to preview this widget. Also determines properties listed on left. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TSubclassOf<UWidget> PreviewWidgetClass;

	/** Property bag that stores style properties, but only used for preview. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FInstancedPropertyBag PreviewPropertyBag;

};

/**
 * Contains style selectors and corresponding style class.
 */
UCLASS(MinimalAPI)
class UStyleRule : public UObject
{
	GENERATED_BODY()

public:
	/** Style selector item for this rule. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FStyleSelectorItem StyleSelectorItem;

	/** Parent rule. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TWeakObjectPtr<UStyleRule> Parent;

	/** Style that corresponds to the style rule. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FStyleClass Style;

#if WITH_EDITORONLY_DATA
	/** Stores preview related information. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FStyleRulePreviewInfo PreviewInfo;
#endif

private:
	/** Child rules. */
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TArray<TObjectPtr<UStyleRule>> Children;

};

