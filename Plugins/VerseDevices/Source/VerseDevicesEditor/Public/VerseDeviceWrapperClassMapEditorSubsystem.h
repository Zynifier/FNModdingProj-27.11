// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "VerseDeviceWrapperClassMapEditorSubsystem.generated.h"

class UVerseDeviceWrapperClassMap;

UCLASS()
class VERSEDEVICESEDITOR_API UVerseDeviceWrapperClassMapEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UVerseDeviceWrapperClassMap>> RegisteredMappings;

};

