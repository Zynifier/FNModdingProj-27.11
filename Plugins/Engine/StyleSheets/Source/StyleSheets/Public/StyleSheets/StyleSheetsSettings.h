// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "StyleSheetsSettings.generated.h"

class UStyleThemeConfig;
class UWidget;

USTRUCT()
struct FWidgetTypeEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Style Sheets", meta=(Categories="StyleSheet.Widget"))
	FGameplayTag WidgetType;

	UPROPERTY(EditAnywhere, Config, Category="Style Sheets", meta=(AllowAbstract="true"))
	TArray<TSubclassOf<UWidget>> WidgetClasses;

};

/**
 * Settings for Style Sheets.
 */
UCLASS(Config=Game, DefaultConfig)
class STYLESHEETS_API UStyleSheetsSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Style Sheets")
	bool bAllowAssigningStyleTagsToWidgets;

private:
	UPROPERTY(EditAnywhere, Config, Category="Style Sheets")
	TArray<FWidgetTypeEntry> WidgetTypes;

	UPROPERTY(EditAnywhere, Config, Category="Style Sheets")
	TSoftObjectPtr<UStyleThemeConfig> StyleThemeConfig;

};

