// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Extensions/WidgetBlueprintGeneratedClassExtension.h"
#include "StyleSheets/StyleTag.h"
#include "WidgetBlueprintGeneratedClassExtension_StyleClass.generated.h"

/**
 * Shared between every instances of the same widget blueprint class.
 * It is used during runtime to apply assigned styles to widgets.
 */
UCLASS()
class STYLESHEETS_API UWidgetBlueprintGeneratedClassExtension_StyleClass : public UWidgetBlueprintGeneratedClassExtension
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FName, FStyleTag> WidgetStyleTagMap;

};

