// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "StyleSheetsEditorSubsystem.generated.h"

class UStyleTagFinder;

/**
 * Editor subsystem for Style Sheets feature.
 */
UCLASS()
class UStyleSheetsEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UStyleTagFinder> EditorStyleTagFinder;

};

