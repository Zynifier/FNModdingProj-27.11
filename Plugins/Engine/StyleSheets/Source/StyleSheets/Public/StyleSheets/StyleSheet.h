// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StyleSheet.generated.h"

class UStyleRule;
class UWidget;

/** Stores settings of individual style sheet asset. */
USTRUCT(BlueprintType)
struct FStyleSheetSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets", meta=(AllowAbstract="true"))
	TArray<TSubclassOf<UWidget>> StylableWidgetClasses;

};

/**
 * This class is used to group style rules.
 */
UCLASS(MinimalAPI)
class UStyleSheet : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	TArray<TObjectPtr<UStyleRule>> StyleRules;

	UPROPERTY(EditDefaultsOnly, Category="Style Sheets")
	FStyleSheetSettings Settings;

};

