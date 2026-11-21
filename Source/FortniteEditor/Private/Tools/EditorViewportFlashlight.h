// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EditorViewportFlashlight.generated.h"

class USpotLightComponent;

UCLASS(Config=EditorPerProjectUserSettings)
class UEditorViewportFlashlight : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USpotLightComponent> SpotLightComponent;

	UPROPERTY(Config)
	FString EditorFlashlightSettings;

};

