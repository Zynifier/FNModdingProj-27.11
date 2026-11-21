// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortEditorToolsSettings.generated.h"

class USpotLightComponent;

UCLASS(Config=EditorPerProjectUserSettings, meta=(DisplayName="Editor Tools"))
class UFortEditorToolsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Transient, Instanced, Category="Flashlight")
	TObjectPtr<USpotLightComponent> EditorFlashlightComponent;

	UPROPERTY(Config)
	FString EditorFlashlightComponentSettings;

	UPROPERTY(Config)
	bool bEditorFlashlightEnabled;

};

