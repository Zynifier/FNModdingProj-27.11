// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "VerseEditorSettings.generated.h"

/** Parameters for creating a verse file */
UCLASS(Config=EditorSettings)
class SOLARISEDITOR_API UVerseEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="Code", meta=(DisplayName="Use Insiders Version of VSCode (if available)"))
	bool bUseInsidersVSCodeIfAvailable;

};

