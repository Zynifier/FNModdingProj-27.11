// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortniteEditorSettings.generated.h"

UCLASS(Config=EditorSettings, GlobalUserConfig)
class UFortniteEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="LevelEditor")
	bool bKeepCurrentBuildingActorTexturesOnEditorReplace;
#endif

};

