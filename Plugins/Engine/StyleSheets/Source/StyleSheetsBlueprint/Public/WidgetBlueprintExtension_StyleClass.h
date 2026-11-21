// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprintExtension.h"
#include "WidgetBlueprintExtension_StyleClass.generated.h"

class UStyleClassBlueprintData;

/**
 * This class is created to store style class blueprint data as part of WBP.
 * It also helps compiling this WBP data into UWidgetBlueprintGeneratedClassExtension
 * that is going to be used during runtime.
 */
UCLASS(MinimalAPI)
class UWidgetBlueprintExtension_StyleClass : public UWidgetBlueprintExtension
{
	GENERATED_BODY()

private:
	/** Style class blueprint data that stores style tag assignments of widgets in WBP. */
	UPROPERTY(Instanced)
	TObjectPtr<UStyleClassBlueprintData> BlueprintData;

};

