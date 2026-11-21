// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "StyleThemeProvider.generated.h"

class UObject;
class UStyleRuleTree;
class UStyleSheetCollection;
class UStyleThemeConfig;

/** Stores mapping from style theme name to style sheet collection. */
USTRUCT()
struct FStyleThemeConfigEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Style Sheets")
	FName ThemeName;

	UPROPERTY(EditAnywhere, Category="Style Sheets")
	TSoftObjectPtr<UStyleSheetCollection> Theme;

	UPROPERTY(Transient)
	TObjectPtr<UStyleSheetCollection> ThemeInstance;

};

/** Stores style theme configuration entries. */
UCLASS()
class UStyleThemeConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Style Sheets")
	TArray<FStyleThemeConfigEntry> Entries;

};

/**
 * Responsible for changing active theme and rebuilding the style rule tree.
 */
UCLASS(MinimalAPI)
class UStyleThemeProvider : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="Style Sheets")
	TWeakObjectPtr<UStyleRuleTree> StyleRuleTree;

	UPROPERTY(VisibleAnywhere, Category="Style Sheets")
	TMap<TWeakObjectPtr<UObject>, TObjectPtr<UStyleThemeConfig>> ThemeConfigSourceMap;

	UPROPERTY(VisibleAnywhere, Category="Style Sheets")
	TSet<FName> ActiveThemeNames;

};

