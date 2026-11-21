// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EpicHardSurfaceQCEditorFunctions.generated.h"

UCLASS(meta=(ScriptName="EpicHardSurfaceQCEditorFunctions"))
class EPICHARDSURFACEQCEDITOR_API UEpicHardSurfaceQCEditorFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="EpicHardSurfaceQCEditorFunctions")
	static void ExecuteConsoleCommandFromEditor(const FString& ConsoleCommand);

	UFUNCTION(BlueprintCallable, Category="EpicHardSurfaceQCEditorFunctions")
	static FString HelloWorld();

};

