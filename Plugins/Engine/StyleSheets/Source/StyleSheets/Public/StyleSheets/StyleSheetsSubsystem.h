// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "StyleSheetsSubsystem.generated.h"

class UStyleAnimationProvider;
class UStyleProvider;
class UStyleRuleTree;
class UStyleTagFinder;
class UStyleThemeProvider;

/**
 * Subsystem for Style Sheets feature.
 */
UCLASS(MinimalAPI, BlueprintType)
class UStyleSheetsSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	//~ End UEngineSubsystem interface

	UPROPERTY()
	TObjectPtr<UStyleTagFinder> EditorStyleTagFinder;

private:
	UPROPERTY()
	TObjectPtr<UStyleRuleTree> StyleRuleTree;

	UPROPERTY()
	TObjectPtr<UStyleAnimationProvider> StyleAnimationProvider;

	UPROPERTY()
	TObjectPtr<UStyleProvider> StyleProvider;

	UPROPERTY()
	TObjectPtr<UStyleThemeProvider> StyleThemeProvider;

	UPROPERTY()
	TObjectPtr<UStyleTagFinder> StyleTagFinder;

};

