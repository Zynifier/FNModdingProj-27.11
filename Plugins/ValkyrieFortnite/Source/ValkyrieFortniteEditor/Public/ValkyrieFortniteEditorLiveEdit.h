// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieFortniteEditorLiveEdit.generated.h"

UCLASS(Config=Editor, DefaultConfig)
class UValkyrieFortniteEditorLiveEditSettings : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<TFieldPath<FProperty>> ExplicitlySupportedProperties;

};

