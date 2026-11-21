// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StyleSheets/StyleTag.h"
#include "StyleClassBlueprintData.generated.h"

/**
 * Stores assigned style tags for widget names. When WBP compiled, this information is
 * copied into UWidgetBlueprintGeneratedClassExtension_StyleClass.
 */
UCLASS(MinimalAPI)
class UStyleClassBlueprintData : public UObject
{
	GENERATED_BODY()

private:
	/** Stores assigned style tag by widget name. */
	UPROPERTY()
	TMap<FName, FStyleTag> WidgetStyleTagMap;

};

